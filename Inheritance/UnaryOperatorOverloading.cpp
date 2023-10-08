#include <iostream>
using namespace std;

// C++ Implementation for operator overloading of unary operators.
class Number
{
    private:
    int value;
    public:
    Number(int argValue):value(argValue){}
    // Simple way of performing operator overloading
    /*
    // Prefix operator overloading
    void operator ++()
    {
       ++value;
    }
    
    // Postfix operator overloading
    void operator ++(int)
    {
        value++;
    }
    */
    // Modified operator overloading to return Number type
    Number operator ++()
    {
        Number temp(0);
        temp = ++value;
        return temp;
    }
    
    // Modified operator overloading to return Number type
    Number operator ++(int)
    {
        Number temp(0);
        temp = value++;
        return temp;
    }
    
    void display()
    {
        cout << "value : " << value << endl;
    }
};
int main() 
{
   Number num(5);
   ++num;
   num++;
   num.display();
   
   Number num2 = ++num;
   num2.display();
   num2 = num++;
   num2.display();
   /* NOTE: Following code Number num2 = ++num; would throw a compilation error
   as the return value of these operator overloading methods are void. */
}

/*
OUTPUT
--------------------
value : 7
value : 8
value : 8
*/

