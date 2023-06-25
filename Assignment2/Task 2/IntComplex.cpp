#include "IntComplex.h"

IntComplex::IntComplex(int r, int i) //constructor
{
    real = r;
    imaginary = i;
}

IntComplex IntComplex::operator+(const IntComplex& rightHand) const
{
    int sumReal = real + rightHand.real;
    int sumImaginary = imaginary + rightHand.imaginary;

    return IntComplex(sumReal, sumImaginary); //return new intcomplex with new vals
}

IntComplex IntComplex::operator-(const IntComplex& rightHand) const 
{
    int diffReal = real - rightHand.real;
    int diffImaginary = imaginary - rightHand.imaginary;
    
    return IntComplex(diffReal, diffImaginary);
}

//multiplying and dividing complex numbers
//https://www.coursesidekick.com/mathematics/study-guides/ivytech-collegealgebra/multiply-and-divide-complex-numbers

IntComplex IntComplex::operator*(const IntComplex& rightHand) const 
{
    int multReal = (real * rightHand.real) - (imaginary * rightHand.imaginary);
    int multImaginary = (real * rightHand.imaginary) + (imaginary * rightHand.real);

    return IntComplex(multReal, multImaginary);
}

IntComplex IntComplex::operator/(const IntComplex& rightHand) const 
{
    int divReal = ((real * rightHand.real) + (imaginary * rightHand.imaginary)) / (rightHand.real * rightHand.real + rightHand.imaginary * rightHand.imaginary);
    int divImaginary = ((imaginary * rightHand.real) - (real * rightHand.imaginary)) / (rightHand.real * rightHand.real + rightHand.imaginary * rightHand.imaginary);

    return IntComplex(divReal, divImaginary);
}

//getters
int IntComplex::getReal() const {return real;}
int IntComplex::getImaginary() const {return imaginary;}
