// C++ program to overload the binary operator +
// This program adds two complex numbers

/* NOTE : These operators cannot be overloaded in C++ i.e 1) :: (scope resolution operator) , 2) . (member selection) , 3) .* (member selection using pointer to function) and 4) ternary operators ?, :
Also = and & operators are already overloaded, so they need not be used. */

#include <iostream>
using namespace std;

class ComplexNumber {
   private:
    float real;
    float imag;

   public:
    // Constructor to initialize real and imag to 0
    ComplexNumber() : real(0), imag(0) {}

    void Input() {
        cout << "Enter real and imaginary parts respectively: ";
        cin >> real;
        cin >> imag;
    }

    // Overload the + operator
    ComplexNumber operator + (const ComplexNumber& obj) {
        ComplexNumber temp;
        temp.real = real + obj.real;
        temp.imag = imag + obj.imag;
        return temp;
    }

    void output() {
        if (imag < 0)
            cout << "Output Complex number: " << real << imag << "i";
        else
            cout << "Output Complex number: " << real << "+" << imag << "i";
    }
};

int main() 
{
   ComplexNumber complex1, complex2, result;

    cout << "Enter first complex number:\n";
    complex1.Input();

    cout << "Enter second complex number:\n";
    complex2.Input();

   // complex1 calls the operator function
   // complex2 is passed as an argument to the function
    result = complex1 + complex2;
    result.output();

    return 0;
}

/* 
OUTPUT
------------------
  Enter first complex number:
Enter real and imaginary parts respectively: 2
4
Enter second complex number:
Enter real and imaginary parts respectively: 4
8
Output Complex number: 6+12i
    
