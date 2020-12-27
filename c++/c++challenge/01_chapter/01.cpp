// sum of all natural numbers divisible by 3 and 5 up to a user defined upper
// limit

#include <iostream>

int main(int argc, char **argv) {

    using namespace std;

    unsigned long upper_limit, sum = 0;

    cout << "Sum of all number divisible by 3 and 5 up to limit" << endl;

    cout << "Please enter the upper limit: ";

    cin >> upper_limit;

    for (unsigned long i = 0; i <= upper_limit; i += 3)
        sum += i;

    for (unsigned long i = 0; i <= upper_limit; i += 5) {
        if (i % 3 != 0) {
            sum += i;
        }
    }

    cout << "Sum is: " << sum << endl;

    return 0;
}
