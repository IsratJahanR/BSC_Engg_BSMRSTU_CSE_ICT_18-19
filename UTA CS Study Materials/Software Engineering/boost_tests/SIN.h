#pragma once

// Function declaration for computing sin(X) using Taylor series
// - X: The input angle in radians (should be between 0.0 and 2 * M_PI).
// - errorflag: Pointer to an integer to indicate an error if X is out of range (1 if error, 0 otherwise).
double sin(float X, int *errorflag);