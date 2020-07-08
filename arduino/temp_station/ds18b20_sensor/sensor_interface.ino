#define DS18B20_PIN 2
#define SKIP_ROM    0xCC
#define READ_ROM    0x33
#define CONV_T      0x44
#define READ_SP     0xBE
#define WRITE_SP    0x4E
#define COPY_SP     0x48

float temp;

void setup() {
    Serial.begin(9600);
    // uint32_t data[2];
    // data[0] = data[1] = 0;
    // if (read_rom(DS18B20_PIN, data) == 0) {
    //     Serial.println("OK");
    // } else {
    //     Serial.println("Error");
    // }
    // Serial.println("ROM code");
    // Serial.print(data[0], HEX);
    // Serial.println(data[1], HEX);

    // if (read_temp(DS18B20_PIN, &temp) == 0) {
    //     Serial.print("Temp: ");
    //     Serial.println(temp);
    // } else {
    //     Serial.println("Error");
    // }
}

void loop() {
    if (read_temp(DS18B20_PIN, &temp) == 0) {
        Serial.print("Temp: ");
        Serial.println(temp);
    } else {
        Serial.println("Error");
    }
    delay(10000);
}

uint8_t read_rom(uint8_t pin, uint32_t *data) {
    //send the signal to reset
    if (tx_reset(pin) == 1) {
        return 1;
    }
    //send ignore rom command
    // tx_byte(READ_ROM, pin);
    tx_byte(pin, SKIP_ROM);
    tx_byte(pin, READ_SP);
    // tx_byte(CONV_T, pin);
    // bool rx = 0;
    noInterrupts();
    //read all 8 bytes of the rom code
    uint32_t received = 0;
    data++;
    for (int i = 0; i < 8; i++) {
        *data >>= 8;
        received = rx_byte(pin);
        *data |= (received << 24);
        if (i == 3) {
            Serial.println("First 4 bytes:");
            Serial.println(*data, HEX);
            Serial.println("");
            data--;
        }
    }
    Serial.println("Second 4 bytes:");
    Serial.println(*data, HEX);
    Serial.println("");
    interrupts();
    if (tx_reset(pin) == 1) {
        return 1;
    }
    return 0;
}

uint8_t read_temp(uint8_t pin, float *temp) {
    uint16_t rx_bytes = 0;
    //measure temperature
    {
        //send the signal to reset
        if (tx_reset(pin) == 1) {
            return 1;
        }
        //send ignore rom command
        tx_byte(pin, SKIP_ROM);
        tx_byte(pin, CONV_T);
    }
    //wait for conversion
    delay(800);
    //read temperature
    {
        if (tx_reset(pin) == 1) {
            return 1;
        }
        //initialize temp data
        uint16_t received = 0;
        //send ignore rom command
        tx_byte(pin, SKIP_ROM);
        //send read scratchpad command
        tx_byte(pin, READ_SP);
        noInterrupts();
        //read the first two bytes of the scratchpad
        for (int i = 0; i < 2; i++) {
            rx_bytes >>= 8;
            received = rx_byte(pin);
            rx_bytes |= (received << 8);
        }
        if (tx_reset(pin) == 1) {
            return 1;
        }
        interrupts();
    }
    //convert temperature
    {
        rx_bytes <<= 4;
        *temp = rx_bytes / 256.0;
    }
    return 0;
}

//transmit a reset pulse
uint8_t tx_reset(uint8_t pin) {
    noInterrupts();
    //send reset signal
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
    delayMicroseconds(500);
    //wait for response signal
    pinMode(pin, INPUT);
    delayMicroseconds(100);
    //send error if no response
    if (digitalRead(pin) != 0) {
        return 1;
    }
    delayMicroseconds(400);
    interrupts();
    return 0;
}

//transmit one byte of data
void tx_byte(uint8_t pin, uint8_t byte) {
    noInterrupts();
    for (int i = 0; i < 8; i++) {
        //transmission is least significant bit first
        switch ((byte >> i) & 0b00000001) {
            case 0: //bit is a "0"
                pinMode(pin, OUTPUT);
                digitalWrite(pin, LOW);
                delayMicroseconds(65);
                digitalWrite(pin, HIGH);
                delayMicroseconds(5);
                break;
            case 1: //bit is a "1"
                pinMode(pin, OUTPUT);
                digitalWrite(pin, LOW);
                delayMicroseconds(10);
                digitalWrite(pin, HIGH);
                delayMicroseconds(60);
                break;
        }
        delayMicroseconds(5);
    }
    interrupts();
}

//receive one byte of output
uint8_t rx_byte(uint8_t pin) {
    uint8_t byte = 0;
    bool rx_bit;
    noInterrupts();
    for (int i = 0; i < 8; i++) {
        //right shift byte
        byte >>= 1;
        //send start signal
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
        delayMicroseconds(3);
        //read response
        pinMode(pin, INPUT);
        delayMicroseconds(10);
        rx_bit = digitalRead(pin);
        delayMicroseconds(53);
        //add rx_bit to byte
        byte |= (rx_bit << 7);
    }
    interrupts();
    return byte;
}