#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float coTET[] = {1.5e-4, 1.02e-3, 9.27e-4, 4.49e-4, 2.8e-4, 6.8e-4};
    float coOCT[] = {1.4e-3, 5.29e-4, 6.24e-4, 1.1e-3, 1.3e-3, 8.71e-4};
    float p[] = {10.4, 9.8, 9.14, 8.49, 7.84, 9.14};
    float m[] = {2.5, 3.7, 4.9, 6.2, 7.4, 4.9};

    for (int i = 0; i < 6; i++) {
        float numerator = coOCT[i] * p[i];
        float denominator = coTET[i] * pow(m[i], 3);
        float ans = numerator / denominator;
        cout << ans << endl;
    }
}