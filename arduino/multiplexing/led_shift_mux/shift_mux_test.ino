#define PIN_LED     2
#define PIN_DATA    3
#define PIN_CLOCK   4
#define INTERVAL    300

void setup() {
    pinMode(PIN_CLOCK, OUTPUT);
    pinMode(PIN_DATA, OUTPUT);
    pinMode(PIN_LED, OUTPUT);
    digitalWrite(PIN_CLOCK, LOW);
    digitalWrite(PIN_DATA, LOW);
    digitalWrite(PIN_LED, LOW);

    Serial.begin(9600);
    Serial.println("Begin");
}

void loop() {
    for (uint8_t i = 0; i < 8; i++) {
        set_address(i);
        Serial.println(i);
        digitalWrite(PIN_LED, HIGH);
        delay(INTERVAL);
        digitalWrite(PIN_LED, LOW);
        delay(INTERVAL);
    }
}

void set_address(uint8_t addr) {
    for(uint8_t i = 3; i < 10; i--) {
        if ((addr >> i) & 0x01) {
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