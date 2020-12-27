// algorithm to find gcd of two positive natural numbers

#include <iostream>

unsigned int bad_gcd(unsigned int x, unsigned int y) {

    unsigned int max = x > y ? x : y;
    unsigned int min = x > y ? y : x;

    for (unsigned int i = min; i >= 1; --i)
        if (max % i == 0 && min % i == 0)
            return i;
    
    return -1;
}

unsigned int good_gcd(unsigned int x, unsigned int y) {

    unsigned int max = x > y ? x : y;
    unsigned int min = x > y ? y : x;

    for (unsigned int i = min; i >= 1; --i)
        if (max % i == 0 && min % i == 0)
            return i;
    
    return -1;
}

int main(int argc, char **argv) {

    using namespace std;

    unsigned int x, y;

    cout << "Find the greatest common denominator.\nEnter the two numbers" 
         << endl;
    cout << "First number:  ";
    cin  >> x;
    cout << "Second number: ";
    cin  >> y;

    unsigned int gcd = bad_gcd(x, y);

    cout << "The gcd of " << x << " and " << y << " is: " << gcd << endl;

    return 0;
}

