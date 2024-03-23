#include <iostream>

using namespace std;

void Bubblesort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++) // O (n^2)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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

    Bubblesort(arr, arr_size);

    cout << "\nSorted array is \n";
    for (int i = 0; i < arr_size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
