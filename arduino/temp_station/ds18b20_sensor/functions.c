// #include <stdint.h>

// //TODO: add initialization function, setting the resolution, make the temp conversion resolution independent

// #define SKIP_ROM    0xCC
// #define READ_ROM    0x33
// #define CONV_T      0x44
// #define READ_SP     0xBE
// #define WRITE_SP    0x4E
// #define COPY_SP     0x48

// //transmit a "0"
// void tx_0(uint8_t pin) {
//     pinMode(pin, OUTPUT);
//     //pull low
//     digitalWrite(pin, LOW);
//     //wait >60 us
//     delayMicroseconds(65);
//     //release
//     pinMode(pin, INPUT_PULLUP);
//     //wait to 70 us
//     delayMicroseconds(5);
// }

// //transmit a "1"
// void tx_1(uint8_t pin) {
//     pinMode(pin, OUTPUT);
//     //pull low
//     digitalWrite(pin, LOW);
//     //wait <15 us
//     delayMicroseconds(10);
//     //release
//     pinMode(pin, INPUT_PULLUP);
//     //wait to 70 us
//     delayMicroseconds(60);
// }

// //transmit a reset pulse
// uint8_t tx_reset(uint8_t pin) {
//     pinMode(pin, OUTPUT);
//     //pull low
//     digitalWrite(pin, LOW);
//     //wait >480 us
//     delayMicroseconds(500);
//     pinMode(pin, INPUT_PULLUP);
//     delayMicroseconds(100);
//     //if bus is not high, return an error
//     //TODO: check if this is correct for this config
//     if (digitalRead(pin) != 1) {
//         return 1;
//     }
//     delayMicroseconds(400);
//     return 0;
// }

// //transmit one byte of data (one command)
// void tx_byte(uint8_t byte, uint8_t pin) {
//     for (int i = 0; i < 8; i++) {
//         //transmission is least significant byte first
//         if ((byte >> i) & 0b00000001) {
//             tx_0(pin);
//         } else {
//             tx_1(pin);
//         }
//     }
// }

// //receive on bit of ouput
// uint8_t rx_bit(uint8_t pin) {
//     pinMode(pin, OUTPUT);
//     //pull low
//     digitalWrite(pin, LOW);
//     //delay for ~3 us
//     delayMicroseconds(3);
//     //set pin to input
//     pinMode(pin, INPUT_PULLUP);
//     //wait for sampling
//     delayMicroseconds(9);
//     //read the value
//     return digitalRead(pin);
// }

// //receive one byte of output
// void rx_byte(uint8_t pin, uint8_t *data) {
//     for (int i = 0; i < 8; i++) {
//         *data <<= 1;
//         *data |= rx_bit(pin);
//     }
// }

// uint8_t instruct_slave(uint8_t command, uint8_t pin) {
//     //send the signal to reset
//     if (tx_reset(pin) != 0) {
//         return 1;
//     }
//     //send ignore rom command
//     tx_byte(SKIP_ROM, pin);
//     //send the tx_command_one_slave
//     tx_byte(command, pin);
//     return 0;
// }

// uint64_t read_rom(uint8_t pin) {
//     //send the signal to reset
//     if (tx_reset(pin) != 0) {
//         return 1;
//     }
//     //send ignore rom command
//     tx_byte(READ_ROM, pin);
//     //create the data
//     uint8_t rx_data;
//     uint64_t rom_code = 0;
//     //read all 8 bytes of the rom code
//     for (int i = 0; i < 8; i++) {
//         rom_code <<= 8;
//         rx_byte(pin, &rx_data);
//         rom_code |= rx_data;
//     }
//     return rom_code;
// }

// float read_temp(uint8_t pin) {
//     float temp = 0;
//     uint8_t data[2];
//     data[0] = data[1] = 0;
//     //send the temp conversion command
//     instruct_slave(CONV_T, pin);
//     //send the signal to reset
//     tx_reset(pin);
//     //send ignore rom command
//     tx_byte(SKIP_ROM, pin);
//     tx_byte(READ_SP, pin);
//     for (int i = 0; i < 2; i++) {
//         rx_byte(pin, data[i]);
//     }
//     //TODO: convert the data to the correct temperature, with the given resolution
// }