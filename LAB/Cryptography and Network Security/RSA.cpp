#include <iostream>
#include <cmath>
using namespace std;

// Function to compute GCD
int gcd(int a, int h) {
    int temp;
    while (1) {
        temp = a % h;
        if (temp == 0)
            return h;
        a = h;
        h = temp;
    }
}

// Extended Euclidean Algorithm to find modular inverse of e mod phi
int modInverse(int e, int phi) {
    int m0 = phi, t, q;
    int x0 = 0, x1 = 1;

    if (phi == 1)
        return 0;

    while (e > 1) {
        q = e / phi;
        t = phi;

        phi = e % phi, e = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

// Function for modular exponentiation
int modExp(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    // Two random prime numbers
    int p = 61; // Example prime number
    int q = 53; // Example prime number

    // Compute n and phi(n)
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    // Public key (e, n)
    int e = 17; // Commonly used small prime number
    while (gcd(e, phi) != 1) {
        e++;
    }

    // Private key (d, n), where d is the modular inverse of e modulo phi(n)
    int d = modInverse(e, phi);

    // Input message
    int msg;
    cout << "Enter the message to encrypt (as an integer): ";
    cin >> msg;

    // Encryption: c = (msg ^ e) % n
    int c = modExp(msg, e, n);
    cout << "Encrypted message: " << c << endl;

    // Decryption: m = (c ^ d) % n
    int m = modExp(c, d, n);
    cout << "Decrypted message: " << m << endl;

    return 0;
}
