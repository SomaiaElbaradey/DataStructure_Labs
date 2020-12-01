#include <iostream>

using namespace std;
void swap(int& x, int& y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}
void bubbleSort(int *arr, int size)
{
    int sorted = 0;
    for(int counter=0; counter < size - 1  && !sorted; counter++)
    {
        sorted = 1;
        for(int i = 0; i < size - 1 - counter; i++)
        {
            if (arr[i] > arr[i+1])
            {
                swap(arr[i], arr[i+1]);
                sorted = 0;
            }
        }
    }
}
int main()
{
    int arr[] = {5, 9, 3, 3, 10, 60, 8};
    bubbleSort(arr, 7);
    for(int index = 0; index < 7; index++)
    {
        cout << arr[index] << endl;
    }
    return 0;
}
