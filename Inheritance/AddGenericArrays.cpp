/* C++ program that demonstrates concept of Inheritance, Constructor, Destructor, Memory management */

#include <iostream>
using namespace std;

/* Here 'IArithmeticFunction' is a generic interface that provides pure virtual function 'performOperation'
  which has to be implemented by the derieved class */
template <typename T>
class IArithmeticFunction
{
    
    protected:
        T* m_array;
        int m_size;
    public:
        virtual void performOperation(T* var1, T* var2) = 0;
};

/* AdditionFunction class implements the pure virtual function declared by its parent, which 
adds 2 generic arrays*/
template <typename T>
class AdditionFunction : public IArithmeticFunction<T>
{
    private:
    void set(int index, T value)
    {
        m_array[index] = value;
    }
    public :
    
    AdditionFunction(int size)
    {
        m_size = size;
        m_array = new T[size];
    }
    
    ~AdditionFunction()
    {
        if(m_array != nullptr)
        {
            delete m_array;
        }
    }
    
    void performOperation(T* var1, T* var2) override
    {
        for (int i = 0; i < m_size; i++)
        {
            m_array[i] = var1[i] + var2[i];
        }
    }
    
    T* get()
    {
        return m_array;
    }
};

int main() {
   AdditionFunction<float> addFn(10);
   float array1[10] = {1.1, 2.7, 3.5, 4.4, 5.21, -6.23, 7.19, 8.44, 9.0, 10.01};
   float array2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   addFn.performOperation(array1, array2);
   float* result = addFn.get();
   for (int j = 0; j < 10; j++)
   {
       cout << result[j] << "\t";
   }
}
