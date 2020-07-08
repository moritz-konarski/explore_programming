// #define PIN 2
// #define N_READS 1000

// bool data[N_READS];
// uint8_t reading[N_READS / 2];
// uint8_t curr, index = 0;

// void setup() {
//     pinMode(PIN, OUTPUT);
//     Serial.begin(9600);
//     Serial.println("Begin");
//     digitalWrite(PIN, LOW);
//     delayMicroseconds(750);
//     noInterrupts();
//     pinMode(PIN, INPUT_PULLUP);
//     for (int i = 0; i < N_READS; i++) {
//         data[i] = digitalRead(PIN);
//     }
//     interrupts();
//     for (int j = 0; j < N_READS; ) {
//         curr = data[j];
//         reading[index++] = curr;
//         while (data[++j] == curr) {
//             reading[index]++;
//         }
//         index++;
//     }
//     for (int m = 0; m < N_READS / 2; ) {
//         Serial.print("Status ");
//         Serial.println(reading[m++]);
//         Serial.print("Cycles ");
//         Serial.println(reading[m++]);
//         Serial.println("--------");
//     }
// }

// void loop() {}