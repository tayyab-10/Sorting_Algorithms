#include <iostream>
#include <vector>

using namespace std;

// A utility function to get the maximum value in arr[]
int getMax(const std::vector<int> &arr)
{
    int max = arr[0];
    for (int i = 1; i < arr.size(); ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void countingSort(std::vector<int> &arr, int exp)
{
    const int n = arr.size();
    vector<int> output(n);
    vector<int> count(10, 0);

    // Count the occurrences of each digit in the current place
    for (int i = 0; i < n; ++i)
    {
        count[(arr[i] / exp) % 10]++;
    }

    // Modify count to store the position of the next occurrence of each digit
    for (int i = 1; i < 10; ++i)
    {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; --i)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr
    for (int i = 0; i < n; ++i)
    {
        arr[i] = output[i];
    }
}

// The main function to implement Radix Sort
void radixSort(std::vector<int> &arr)
{
    int max = getMax(arr);

    // Apply counting sort to sort elements based on individual digits
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countingSort(arr, exp);
    }
}

int main()
{
    // Example usage
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    int arr_size = arr.size();

    cout << "Given array is \n";
    for (int i = 0; i < arr_size; i++)
    {
        cout << arr[i] << " ";
    }

    radixSort(arr);

    cout << "\nSorted array is \n";
    for (int i = 0; i < arr_size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
