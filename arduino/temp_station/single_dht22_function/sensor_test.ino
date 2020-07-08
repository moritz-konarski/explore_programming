/*A program for reading the DHT22 temperature sensor*/
#define PIN 4
#define TIME_OUT 2000           //amount of cycles before time out
#define ITERATIONS 100         //iterations of the loop
#define INTERVAL 5              //seconds between measurements

uint16_t err_count = 0;

void setup() {
    Serial.begin(9600);
    Serial.println("Begin");
    for (uint16_t i = 1; i <= ITERATIONS; i++) {
        delay(1000 * INTERVAL);
        Serial.print(i);
        Serial.println("----------------------");
        Serial.print("Errors: ");
        Serial.println(err_count);
        read_with_error_handling();
    }
    Serial.print("Number of Errors out of ");
    Serial.print(ITERATIONS);
    Serial.print(": ");
    Serial.print(err_count);
    Serial.print("(");
    Serial.print(1.0f * err_count / ITERATIONS);
    Serial.println(" %)");
    Serial.println("End");
}

void loop() {
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

void read_with_error_handling() {
    float temp, rel_hum;
    int8_t message_code= read_DHT22(PIN, &temp, &rel_hum);
    switch (message_code) {
        case -1:
            Serial.println("Initial pulse timed out.");
            delay(5000);
            err_count++;
            break;
        case -2:
            Serial.println("Time out during measuring.");
            delay(5000);
            err_count++;
            break;
        case -3: 
            Serial.println("Checksum error.");
            err_count++;
            break;
        case 0:
            // Serial.println("Measuring successful.");
            Serial.print("Temp: ");
            Serial.println(temp);
            Serial.print("Relative Humidity: ");
            Serial.println(rel_hum);
            break;
        default:
            Serial.println("Behavior not defined.");
            err_count++;
            break;
    }
    Serial.println("");
}