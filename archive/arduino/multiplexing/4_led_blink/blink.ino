#define LED_PIN         5
#define PIN_A           2
#define PIN_B           3
#define PIN_C           4
#define BLINK_INTERVAL  1000
#define N_CONNECTIONS   4

void setup() {
    Serial.begin(9600);
    Serial.println("Begin");
    pinMode(LED_PIN, OUTPUT);
    pinMode(PIN_A, OUTPUT);
    pinMode(PIN_B, OUTPUT);
    pinMode(PIN_C, OUTPUT);
}

void loop() {
    for (uint8_t i = 0; i < N_CONNECTIONS; i++) {
        set_port(i);
        digitalWrite(LED_PIN, HIGH);
        Serial.println(i);
        delay(BLINK_INTERVAL);
        digitalWrite(LED_PIN, LOW);
        delay(BLINK_INTERVAL / 2);
    }
}

void set_port(uint8_t number) {
    if (number < 8 && number >= 0) {
        if (number & 0b00000001) {
            digitalWrite(PIN_A, HIGH);
        } else {
            digitalWrite(PIN_A, LOW);
        }
        if (number & 0b00000010) {
            digitalWrite(PIN_B, HIGH);
        } else {
            digitalWrite(PIN_B, LOW);
        }
        if (number & 0b00000100) {
            digitalWrite(PIN_C, HIGH);
        } else {
            digitalWrite(PIN_C, LOW);
        }
    }
}