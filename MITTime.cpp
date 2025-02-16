// Problem #1: MIT Time

// Written by Aayush Sood

// Score: 100/100

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int base = 5;
    int exponent = 0;
    int answer = 0;

    while (n--) {
        int number;
        cin >> number;

        for (int i = 0; i < 100; i++) {
            answer = pow(base, exponent);

            if (number <= answer) {
                if (exponent == 0 || exponent == 1) {
                    cout << "MIT time" << endl;
                    break;
                } else {
                    cout << "MIT" << "^" << exponent << " time" << endl;
                    break;
                }
            }

            exponent++;
        }

        exponent = 0;
        answer = 0;
    }
}