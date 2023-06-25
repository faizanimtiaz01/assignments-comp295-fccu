#ifndef INTCOMPLEX_H
#define INTCOMPLEX_H

class IntComplex {
private:
    int real;
    int imaginary;

public:
    IntComplex(int realPart, int imaginaryPart);
    IntComplex operator+(const IntComplex& other) const;
    IntComplex operator-(const IntComplex& other) const;
    IntComplex operator*(const IntComplex& other) const;
    IntComplex operator/(const IntComplex& other) const;
    int getReal() const;
    int getImaginary() const;
};

#endif // INTCOMPLEX_H
