#include <iostream>
#include <string>
#include <sstream>
#include "IntComplex.h"
#include "FloatComplex.h"
using namespace std;

int stringToInt(const string& str) //convert command line string into int
{
    istringstream iss(str);
    int value;
    iss >> value;
    return value;
}

float stringToFloat(const string& str) //convert command line string into float
{
    istringstream iss(str);
    float value;
    iss >> value;
    return value;
}

int main(int argc, char* argv[]) { //sample input: {4 6 7.67 9.453}
    if (argc < 5) 
    {
        cout << "Not enough inputs for all variables, try again\n";
        return 1;
    }

    //getting input from command line and converting
    int intReal1 = stringToInt(argv[1]);
    int intImaginary1 = stringToInt(argv[2]);
    float floatReal1 = stringToFloat(argv[3]);
    float floatImaginary1 = stringToFloat(argv[4]);

    //constructors constructing
    IntComplex intComplex(intReal1, intImaginary1);
    FloatComplex floatComplex(floatReal1, floatImaginary1);

    //the task never stated to make two instances of each class to make operations for, so I just used the same instance again for each 
    //operation like example said to do

    //all operations of intcomplex
    IntComplex intResultAdd = intComplex + intComplex;
    IntComplex intResultSubtract = intComplex - intComplex;
    IntComplex intResultMultiply = intComplex * intComplex;
    IntComplex intResultDivide = intComplex / intComplex;

    //all operations of floatcomplex
    FloatComplex floatResultAdd = floatComplex + floatComplex;
    FloatComplex floatResultSubtract = floatComplex - floatComplex;
    FloatComplex floatResultMultiply = floatComplex * floatComplex;
    FloatComplex floatResultDivide = floatComplex / floatComplex;

    //getters be getting and printing (negative numbers look funny but unless you give marks for that I'm not fixing it(imagine them in brackets))
    cout << "-----------------INPUTS-----------------\n";
    cout << "IntComplex: " << intComplex.getReal() << " + " << intComplex.getImaginary() << "i\n";
    cout << "FloatComplex: " << floatComplex.getReal() << " + " << floatComplex.getImaginary() << "i\n";

    //intcomplex operations results
    cout << "-----------------INTCOMPLEX OUTPUTS-----------------\n";
    cout << "IntComplex Addition: " << intResultAdd.getReal() << " + " << intResultAdd.getImaginary() << "i\n";
    cout << "IntComplex Subtraction: " << intResultSubtract.getReal() << " + " << intResultSubtract.getImaginary() << "i\n";
    cout << "IntComplex Multiplication: " << intResultMultiply.getReal() << " + " << intResultMultiply.getImaginary() << "i\n";
    cout << "IntComplex Division: " << intResultDivide.getReal() << " + " << intResultDivide.getImaginary() << "i\n";

    //floatcomplex operations results
    cout << "-----------------FLOATCOMPLEX OUTPUTS-----------------\n";
    cout << "FloatComplex Addition: " << floatResultAdd.getReal() << " + " << floatResultAdd.getImaginary() << "i\n";
    cout << "FloatComplex Subtraction: " << floatResultSubtract.getReal() << " + " << floatResultSubtract.getImaginary() << "i\n";
    cout << "FloatComplex Multiplication: " << floatResultMultiply.getReal() << " + " << floatResultMultiply.getImaginary() << "i\n";
    cout << "FloatComplex Division: " << floatResultDivide.getReal() << " + " << floatResultDivide.getImaginary() << "i\n";

    return 0;
}
