#define PIN_TEMP    2
#define PIN_DATA    3
#define PIN_CLOCK   4
#define INTERVAL    6000
#define TIME_OUT    2000
#define ITERATIONS  50

int test = 9;

void setup() {
    test++;
    uint16_t n_err[3];
    n_err[0] = n_err[1] = n_err[2] = 0;

    pinMode(PIN_CLOCK, OUTPUT);
    pinMode(PIN_DATA, OUTPUT);

    Serial.begin(9600);
    Serial.println("Begin");
    delay(4000);
    
    for (int it = 0; it < ITERATIONS; it++) {
        Serial.println(it);
        for (uint8_t i = 0; i < 3; i++) {
            set_address(i);
            Serial.print(i);
            delay(1);
            read_with_error_handling(i, n_err);
            delay(6000);
        }
        delay(3 * INTERVAL);
        Serial.println("");
    }
    Serial.print("Errors of sensors 0, 1, 2: ");
    Serial.print(n_err[0]);
    Serial.print(", ");
    Serial.print(n_err[1]);
    Serial.print(", ");
    Serial.println(n_err[2]);
}

void loop() {}

void set_address(uint8_t addr) {
    for(uint8_t i = 1; i < 9; i++) {
        if ((addr >> (8 - i)) & 0x01) {
            digitalWrite(PIN_DATA, HIGH);
        } else {
            digitalWrite(PIN_DATA, LOW);
        }
        delay(1);
        digitalWrite(PIN_CLOCK, HIGH);
        delay(1);
        digitalWrite(PIN_CLOCK, LOW);
    }
    delay(1);
    digitalWrite(PIN_DATA, LOW);
}

int8_t read_DHT22(uint8_t pin, float *temp, float *r_h) {
    uint16_t input[80];
    uint16_t high_pulse, low_pulse;
    uint8_t data[5];
    int8_t sign = 1;
    // sending start signal
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
    delayMicroseconds(1100);
    // timing critical code - waiting for response
    noInterrupts();
    pinMode(pin, INPUT_PULLUP);
    delayMicroseconds(30);
    // measuring the first low pulse
    if (pulse_length(LOW, pin) == TIME_OUT) {
        return -1;
    }
    // measuring the first high pulse
    if (pulse_length(HIGH, pin) == TIME_OUT) {
        return -1;
    }
    // measuring the transmitted data
    for (int i = 0; i < 80; i += 2) {
        input[i] = pulse_length(LOW, pin);
        input[i + 1] = pulse_length(HIGH, pin);
    }
    interrupts();
    // setting data to 0
    data[0] = data[1] = data[2] = data[3] = data[4] = 0;
    for (int j = 0; j < 80; j += 2) {
        low_pulse = input[j];
        high_pulse = input[j + 1];
        if (low_pulse == TIME_OUT || high_pulse == TIME_OUT) {
            return -2;
        }
        data[j / 16] <<= 1;
        // if the input is a "1"
        if (high_pulse > low_pulse) {
            data[j / 16] |= 1;
        }
    }
    if ((data[0] + data[1] + data[2] +data[3]) & data[4] != data[4]) {
        return -3;
    }
    if (data[2] & 0x80) {
        data[2] &= 0x7F;
        sign = -1;
    }
    // return the results through pointers
    *r_h = ((data[0] << 8) + data[1]) / 10.0;
    *temp = sign * ((data[2] << 8) + data[3]) / 10.0;
    return 0;
}

// counting the amount of cycles that the bus is LOW or HIGH
uint16_t pulse_length (bool pulse_type, uint8_t pin) {
    uint16_t count = 0;
    while (pulse_type == digitalRead(pin)) {
        if (count++ >= TIME_OUT) {
            return TIME_OUT;
        }
    }
    return count;
}

void read_with_error_handling(uint8_t number, uint16_t n_err[]) {
    float temp, rel_hum;
    bool error = false;
    int8_t message_code = read_DHT22(PIN_TEMP, &temp, &rel_hum);
    switch (message_code) {
        case -1:
            error = true;
            Serial.println("Initial pulse timed out.");
            break;
        case -2:
            Serial.println("Time out during measuring.");
            error = true;
            break;
        case -3: 
            Serial.println("Checksum error.");
            error = true;
            break;
        case 0:
            // Serial.println("Measuring successful.");
            Serial.print(" - T: ");
            Serial.print(temp);
            Serial.print("; RH: ");
            Serial.println(rel_hum);
            break;
        default:
            Serial.println("Behavior not defined.");
            error = true;
            break;
    }
    
    if (error) {
        n_err[number]++;
        delay(5000);
    }
}