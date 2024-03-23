#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bucketSort(std::vector<float> &arr)
{
    int n = arr.size();

    // create Buckets :
    std::vector<std::vector<float>> Buckets(n);

    // Insert Elements into the buckets
    for (int i = 0; i < n; i++)
    {
        int BucketIndex = n * arr[i];
        Buckets[BucketIndex].push_back(arr[i]);
    }

    // sort the elements in the buckets
    for (int i = 0; i < n; i++)
    {
        sort(Buckets[i].begin(), Buckets[i].end());
    }

    // Concatenate the buckets
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < Buckets[i].size(); j++)
        {
            arr[index++] = Buckets[i][j];
        }
    }
}

int main()
{
    // Example usage
    vector<float> arr = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int arr_size = arr.size();

    cout << "Given array is \n";
    for (int i = 0; i < arr_size; i++)
    {
        cout << arr[i] << " ";
    }

    bucketSort(arr);

    cout << "\nSorted array is \n";
    for (int i = 0; i < arr_size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
