#define PIN 2
#define TIME_OUT 2000

uint16_t input[80];
uint8_t data[5];
float rel_hum, temp;
uint16_t checksum;

void setup() {
    //set pin to output
    Serial.begin(9600);
    pinMode(PIN, OUTPUT);
    //send activation signal
    digitalWrite(PIN, LOW);
    delayMicroseconds(1100);
    //read the input from the sensor
    noInterrupts();
    pinMode(PIN, INPUT_PULLUP);
    delayMicroseconds(30);
    if (pulse_length(LOW) == TIME_OUT) {
        Serial.println("Low pulse timed out");
    }
    if (pulse_length(HIGH) == TIME_OUT) {
        Serial.println("High pulse timed out");
    }
    for (int i = 0; i < 80; i += 2) {
        input[i] = pulse_length(LOW);
        input[i + 1] = pulse_length(HIGH);
    }
    interrupts();
    // for (int i = 0; i < 500; i++) {
    //     values[i] = digitalRead(PIN);
    //     delayMicroseconds(1);
    // }
    // for (int i = 0; i < 500; i++) {
    //     curr_val = values[i];
    //     binary[index++] = curr_val;
    //     while (values[++i] == curr_val) {
    //         binary[index] = binary[index] + 1;
    //     }
    //     index++;
    // }
    // binary[index] = 3;
    // index = 0;
    // while (binary[index] != 3) {
    //     Serial.print(binary[index++]);      //1 or 0
    //     Serial.print(" ");
    //     val = 3 * binary[index++];
    //     Serial.print(val);    //how many cycles
    //     if (val < 45) {
    //         Serial.println("  0");
    //     } else if (val > 55 && val < 76) {
    //         Serial.println("  1");
    //     } else {
    //         Serial.println(" ");
    //     }
    // }
    data[0] = data[1] = data[2] = data[3] = data[4] = 0;
    for (int j = 0; j < 80; j += 2) {
        data[j / 16] <<= 1;
        // if the input is a "1"
        if (input[j + 1] > input[j]) {
            data[j / 16] |= 1;
        }
    }
    checksum = data[0] + data[1] + data[2] + data[3];
    if (checksum & data[4] == data[4]) {
        Serial.println("checksum is ok");
    } else {
        Serial.println("checksum is not ok");
    }
    rel_hum = ((data[0] << 8) + data[1]) / 10.0;
    temp = ((data[2] << 8) + data[3]) / 10.0;
    Serial.print("temp: ");
    Serial.println(temp);
    Serial.print("hum: ");
    Serial.println(rel_hum);
}

void loop() {


}

// counting the amount of cycles that the bus is LOW or HIGH
// is used to determine if the bit is "1" (long pulse) or "0" (short pulse)
uint16_t pulse_length(bool pulse_type) {
    uint16_t count = 0;
    while (pulse_type == digitalRead(PIN)) {
        if (count++ >= TIME_OUT) {
            return TIME_OUT;
        }
    }
    return count;
}