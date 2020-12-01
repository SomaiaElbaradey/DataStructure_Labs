#include <iostream>

using namespace std;
void InsertionSort(int *arr, int size)
{
    int key, i;
    for(int counter=1; counter < size; counter++)
    {
        key = arr[counter];
        i = counter - 1;
        while (arr[i] > key)
        {
            arr[i+1] = arr[i];
            i--;
        }
        arr[i + 1] = key;
    }
}
int main()
{
    int arr[] = {5, 9, 3, 3, 10, 60, 8};
    InsertionSort(arr, 7);
    for(int index = 0; index < 7; index++)
    {
        cout << arr[index] << endl;
    }
    return 0;
}
