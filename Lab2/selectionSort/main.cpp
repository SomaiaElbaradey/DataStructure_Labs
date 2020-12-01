#include <iostream>

using namespace std;
void swap(int& x, int& y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}
void selectionSort(int *arr, int size)
{
    int min;
    for(int counter = 0; counter < size - 1; counter++)
    {
        min = counter;
        for(int i = counter + 1; i < size; i++)
        {
            if(arr[i] < arr[min])
            {
                min = i;
            }
        }
        if(counter != min)
        {
            swap(arr[counter], arr[min]);
        }
    }
}
int main()
{
    int arr[] = {5, 9, 3, 3, 10, 60, 8};
    selectionSort(arr, 7);
    for(int index = 0; index < 7; index++)
    {
        cout << arr[index] << endl;
    }
    return 0;
}
