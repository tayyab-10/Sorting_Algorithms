#include <iostream>

using namespace std;

void conquer(int arr[], int si, int mid, int ei)
{
    int MergedArray[ei - si + 1];
    int size = ei - si + 1;
    int idx1 = si;
    int idx2 = mid + 1;
    int idx = 0;

    while (idx1 <= mid && idx2 <= ei)
    {
        if (arr[idx1] <= arr[idx2])
        {
            MergedArray[idx++] = arr[idx1++];
        }
        else
        {
            MergedArray[idx++] = arr[idx2++];
        }
    }

    while (idx1 <= mid)
    {
        MergedArray[idx++] = arr[idx1++];
    }

    while (idx2 <= ei)
    {
        MergedArray[idx++] = arr[idx2++];
    }

    for (int i = 0, j = si; i < size; i++, j++)
    {
        arr[j] = MergedArray[i];
    }
}

void divide(int arr[], int si, int ei)
{
    if (si >= ei)
    {
        return;
    }

    int mid = si + (ei - si) / 2;
    divide(arr, si, mid);
    divide(arr, mid + 1, ei);
    conquer(arr, si, mid, ei);
}

int main()
{
    // Example usage
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    for (int i = 0; i < arr_size; i++)
    {
        cout << arr[i] << " ";
    }

    divide(arr, 0, arr_size - 1);

    cout << "\nSorted array is \n";
    for (int i = 0; i < arr_size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}