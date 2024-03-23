#include <iostream>

using namespace std;

void InsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int j = i - 1;
        while (j >= 0 && current < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}

int main()
{
    // Example usage
    int arr[] = {10, 7, 8, 9, 1, 5};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    for (int i = 0; i < arr_size; i++)
    {
        cout << arr[i] << " ";
    }

    InsertionSort(arr, arr_size);

    cout << "\nSorted array is \n";
    for (int i = 0; i < arr_size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
