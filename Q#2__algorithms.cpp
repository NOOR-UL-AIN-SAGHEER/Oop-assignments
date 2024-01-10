#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace chrono;

void bubbleSort(vector<int>& arr) 
{
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1]) 
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    const int size = 100000;
    vector<int> data(size);

    // Initialize the vector in descending order
    for (int i = size; i > 0; --i) {
        data.push_back(i);
    }

    // Measure execution time for Bubble Sort
    auto startBubbleSort = high_resolution_clock::now();
    bubbleSort(data);
    auto stopBubbleSort = high_resolution_clock::now();
    auto durationBubbleSort = duration_cast<milliseconds>(stopBubbleSort - startBubbleSort);

    // Print execution time for Bubble Sort
    cout << "Bubble Sort Execution Time: " << durationBubbleSort.count() << " milliseconds" << endl;

    // Verify that the vector is sorted
    cout << "First 10 integers: ";
    for (int i = 0; i < 10; ++i) 
    {
        cout << data[i] << " ";
    }
    cout << endl;

    cout << "Last 10 integers: ";
    for (int i = size - 10; i < size; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;

    // Reset the vector to descending order
    reverse(data.begin(), data.end());

    // Measure execution time for STL sort
    auto startSTLSort = high_resolution_clock::now();
    sort(data.begin(), data.end());
    auto stopSTLSort = high_resolution_clock::now();
    auto durationSTLSort = duration_cast<milliseconds>(stopSTLSort - startSTLSort);

    // Print execution time for STL sort
    cout << "STL Sort Execution Time: " << durationSTLSort.count() << " milliseconds" << endl;

    return 0;
}
