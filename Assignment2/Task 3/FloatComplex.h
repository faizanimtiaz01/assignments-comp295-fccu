#ifndef FLOATCOMPLEX_H
#define FLOATCOMPLEX_H

#include "IntComplex.h"//for your inheritence needs

class FloatComplex : public IntComplex //inheritance of intcomplex as question asked for it
{
private:
    float real;
    float imaginary;

public:

    FloatComplex(float r, float i);//constructor


    //operators for math operations
    FloatComplex operator+(const FloatComplex& rightHand) const;
    FloatComplex operator-(const FloatComplex& rightHand) const;
    FloatComplex operator*(const FloatComplex& rightHand) const;
    FloatComplex operator/(const FloatComplex& rightHand) const;

    //no getters? because they are inherited from intcomplex, you stupid
};

#endif
