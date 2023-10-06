/* Bubble sort using Generics (Optimized i.e halts execution at 1st pass for already sorted input)*/
#include <iostream>
#include <vector>
using namespace std;

template <class T>
void bubbleSort(vector<T>& arr)
{
  int n = arr.size();
  for(int i = 0; i < n-1; i++)
  {
    bool swapDone = false;
    for(int j = 0; j < n-1-i; j++)
    {
        if(arr[j] > arr[j+1])
        {
           T temp = arr[j];
           arr[j] = arr[j+1];
           arr[j+1] = temp;
           swapDone = true;
        }
    }
    if(!swapDone)
    {
        return;
    }
  }
}

int main()
{
vector<double> vectorDouble = {0.75, 0.71, 0.755, 0.72, 0.722, 0.71, 0.70};
    bubbleSort(vectorDouble);
    for (int i = 0; i < vectorDouble.size(); i++) {
    cout << vectorDouble[i] << " ";
    }
    cout << endl;
}
