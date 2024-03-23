#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void countingSort(std::vector<int> &arr)
{
    // Find the maximum element in the array
    int max_element = *std::max_element(arr.begin(), arr.end());

    // Create a count array to store the count of each element
    vector<int> count(max_element + 1, 0);

    // Count the occurrences of each element
    for (int i = 0; i < arr.size(); ++i)
    {
        count[arr[i]]++;
    }

    // Update the count array to store the position of each element
    for (int i = 1; i < count.size(); ++i)
    {
        count[i] += count[i - 1];
    }

    // Create a temporary array to store the sorted result
    vector<int> result(arr.size());
    for (int i = arr.size() - 1; i >= 0; --i)
    {
        result[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted result back to the original array
    for (int i = 0; i < arr.size(); ++i)
    {
        arr[i] = result[i];
    }
}

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

int main()
{
    // Example usage
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    int arr_size = arr.size();

    cout << "Given array is \n";
    for (int i = 0; i < arr_size; i++)
    {
        cout << arr[i] << " ";
    }

    countingSort(arr);

    cout << "\nSorted array is \n";
    for (int i = 0; i < arr_size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
