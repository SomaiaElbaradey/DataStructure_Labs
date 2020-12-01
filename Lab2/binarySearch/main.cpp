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
int binarySearch(int* arr, int size, int searchednum)
{
    int min = 0;
    int max = size - 1;
    int mid;
    while(min <= max)
    {
        mid = (min + max) / 2;
        if(arr[mid] == searchednum)
        {
            cout << "the searched number exist in index: ";
            return mid;
        }
        else if(arr[mid] > searchednum)
        {
            max = mid - 1;
        }
        else
        {
            min = mid + 1;
        }
    }
    cout << "the searched number doesn't exist " << endl;
    return -16546323;
}
int main()
{
    int arr[] = {5, 9, 3, 3, 10, 60, 8};
    selectionSort(arr, 7);
    cout << binarySearch(arr, 7, 9);
    return 0;
}
