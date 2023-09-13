// Quick Sort
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int partition(int arr[], int start, int end)
{

    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
            count++;
    }

    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex)
    {

        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{

    // base case
    if (start >= end)
        return;

    // partitioning the array
    int p = partition(arr, start, end);

    // Sorting the left part
    quickSort(arr, start, p - 1);

    // Sorting the right part
    quickSort(arr, p + 1, end);
}

void display(int *array, int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

int main()
{

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n]; // create an array with given number of elements
    cout << "Enter elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Array before Sorting: ";
    display(arr, n);
    // Start the timer
    auto start = high_resolution_clock::now();

    // Sort the array using merge sort
    quickSort(arr, 0, n - 1); //(n-1) for last index

    // Stop the timer
    auto end = high_resolution_clock::now();

    // Get the duration
    auto duration = duration_cast<microseconds>(end - start);

    cout << "Array after Sorting: ";
    display(arr, n);

    // Print the time taken to sort the array
    cout << "Time taken to sort the array using merge sort: " << duration.count() << " microseconds" << endl;
    return 0;
}
