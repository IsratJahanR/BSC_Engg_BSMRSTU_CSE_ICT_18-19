#include <iostream>

using namespace std;

// Utility function for modular exponentiation
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// GCD function for coprimeness check
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to find modular inverse using the extended Euclidean algorithm
long long modInverse(long long a, long long mod) {
    if(gcd(a, mod) > 1)return -1;

    for (int x = 1; x < mod; x++)
        if (((a % mod) * (x % mod)) % mod == 1)return x;
}

// Generate a random coprime with the given number
long long generateCoprime(long long n) {

    long long coprime=2;
    do {
        coprime++;
    } while (gcd(coprime, n) != 1);

    return coprime;
}

// Blinding phase
long long blindMessage(long long message, long long e, long long n, long long r) {
    return (message * modExp(r, e, n)) % n;
}

// Signing phase
long long signMessage(long long blindedMessage, long long d, long long n) {
    return modExp(blindedMessage, d, n);
}

// Unblinding phase
long long unblindSignature(long long signedBlindedMessage, long long r, long long n) {
    long long rInv = modInverse(r, n);  // Compute modular inverse of r
    return (signedBlindedMessage * rInv) % n;
}

// Verification phase
bool verifySignature(long long message, long long signature, long long e, long long n) {
    return modExp(signature, e, n) == message;
}

int main() {
    long long p = 61;  // A prime number
    long long q = 53;  // Another prime number
    long long n = p * q;  // RSA modulus
    long long phi = (p - 1) * (q - 1);

    long long e = 17;  // Public exponent
    long long d = 2753;  // Private exponent

    // Message to be signed
    cout<<"Enter the message :";
    long long message;
    cin>>message;

    // Blinding factor
    long long r = generateCoprime(n);
    cout << "Blinding factor (r): " << r << endl;

    // Blind the message
    long long blindedMessage = blindMessage(message, e, n, r);
    cout << "Blinded message: " << blindedMessage << endl;

    // Sign the blinded message (signer does this step)
    long long signedBlindedMessage = signMessage(blindedMessage, d, n);
    cout << "Signed blinded message: " << signedBlindedMessage << endl;

    // Unblind the signature
    long long signature = unblindSignature(signedBlindedMessage, r, n);
    cout << "Signature: " << signature << endl;

    // Verify the signature
    if (verifySignature(message, signature, e, n)) {
        cout << "Signature is valid!" << endl;
    } else {
        cout << "Signature is invalid!" << endl;
    }

    return 0;
}
