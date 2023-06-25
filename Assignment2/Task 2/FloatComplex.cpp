#include "FloatComplex.h"

FloatComplex::FloatComplex(float r, float i) : IntComplex(r, i) //constructor
{
    real = r;
    imaginary = i;
}

FloatComplex FloatComplex::operator+(const FloatComplex& other) const {
    float sumReal = real + other.real;
    float sumImaginary = imaginary + other.imaginary;
    return FloatComplex(sumReal, sumImaginary);
}

FloatComplex FloatComplex::operator-(const FloatComplex& other) const {
    float diffReal = real - other.real;
    float diffImaginary = imaginary - other.imaginary;
    return FloatComplex(diffReal, diffImaginary);
}

FloatComplex FloatComplex::operator*(const FloatComplex& other) const {
    float multReal = (real * other.real) - (imaginary * other.imaginary);
    float multImaginary = (real * other.imaginary) + (imaginary * other.real);
    return FloatComplex(multReal, multImaginary);
}

FloatComplex FloatComplex::operator/(const FloatComplex& other) const {
    float divReal = ((real * other.real) + (imaginary * other.imaginary)) / (other.real * other.real + other.imaginary * other.imaginary);
    float divImaginary = ((imaginary * other.real) - (real * other.imaginary)) / (other.real * other.real + other.imaginary * other.imaginary);
    return FloatComplex(divReal, divImaginary);
}
