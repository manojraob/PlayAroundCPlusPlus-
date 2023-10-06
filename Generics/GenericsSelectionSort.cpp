/* C++ Implementation of selection sort using Generics */

#include <iostream>
#include <vector>
using namespace std;

template <class T>
void swapData(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp; 
}

template <class T>
void printData(vector<T> list)
{
    for(int i = 0; i < list.size(); i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}

template <class T>
void selectionSort(vector<T>& vc)
{
    int n = vc.size();
    for(int i = 0; i < n - 1; i++)
    {
        T min = i;
        for(int j = i+1; j < n; j++)
        {
            if(vc[j] < vc[min])
                min = j;
        }
         //T temp = vc[min];
         //vc[min] = vc[i] ;
         //vc[i] = temp; 
        swapData(vc[min], vc[i]);
    }
}

int main() {
    vector<float> vcf = {5.5, 6.5, 4.0, 4.25, 9.05, 8.89};
    selectionSort(vcf);
    printData(vcf);
}
