/*
1. Start from the second element and assume that first element is already sorted.
2. Compare the current elemnt with the previous elements.
3. Shift all elements grater then the current element one position ahead.
4. Insert the current element at its current position in the sorted part of the array.
5. Repeat the process for all elements.
*/
#include <iostream>
using namespace std;
void insertionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > arr[i])
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int array[] = {12, 11, 13, 5, 6};
    int n = sizeof(array) / sizeof(array[0]);
    cout << "\nOrignal Array : ";
    display(array, n);
    insertionSort(array, n);
    cout << "\nSorted Array : ";
    display(array, n);
    return 0;
}