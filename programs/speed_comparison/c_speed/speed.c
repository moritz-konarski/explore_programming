#include <stdio.h>
#include <time.h>
#include <stdint.h>

int main(void) {

    double pi = 1.0;
    int8_t sign = -1;

    for (int n = 0; n < 10; ++n) {
        pi = 1.0f;
        sign = -1;
        clock_t begin = clock();
        for (int i = 1; i < 10000000; ++i) {
            pi += (sign) / (double)(2 * i + 1);
            sign *= -1;
        }
        clock_t end = clock();
        printf("time:   %lf\n", (double)(end - begin) / CLOCKS_PER_SEC);
    }
    printf("result: %f\n", pi * 4.0f);
}
