#include <iostream>

using namespace std;

void SelectionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int smallest = i;
        for (int j = i + 1; j < n; j++) // O (n^2)
        {
            if (arr[smallest] > arr[j])
            {
                smallest = j;
            }
        }
        int temp = arr[smallest];
        arr[smallest] = arr[i];
        arr[i] = temp;
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

    SelectionSort(arr, arr_size);

    cout << "\nSorted array is \n";
    for (int i = 0; i < arr_size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
