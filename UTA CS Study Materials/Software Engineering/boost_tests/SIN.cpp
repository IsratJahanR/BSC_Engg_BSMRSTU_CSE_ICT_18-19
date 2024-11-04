#include <math.h>
unsigned long long fact(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

double sin(float X, int *errorflag) {

    *errorflag = 0;
    if (X < 0.0 || X > 2 * M_PI) {
        *errorflag = 1;
        return 0.0;
    }


    double sinX = 0.0;

    sinX = X - pow(X,3)/fact(3)+ pow(X,5)/fact(5) - pow(X,7)/fact(7) + pow(X,9)/fact(9)- pow(X,11)/fact(11);

    return sinX;
}