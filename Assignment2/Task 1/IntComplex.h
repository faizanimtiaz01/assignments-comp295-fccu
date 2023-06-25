#ifndef INTCOMPLEX_H
#define INTCOMPLEX_H

class IntComplex 
{
private:
    int real;
    int imaginary;

public:
    IntComplex(int r, int i); //constructor

    //operators for math operations
    IntComplex operator+(const IntComplex& rightHand) const;
    IntComplex operator-(const IntComplex& rightHand) const;
    IntComplex operator*(const IntComplex& rightHand) const;
    IntComplex operator/(const IntComplex& rightHand) const;

    //getters
    int getReal() const;
    int getImaginary() const;
    
};

#endif
