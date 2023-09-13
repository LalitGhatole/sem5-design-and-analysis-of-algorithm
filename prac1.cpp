#include <iostream>

using namespace std;

int binarySearch(int arr[], int low, int high, int x) {
  if (low > high) {
    return -1;
  }

  int mid = low + (high - low) / 2;

  if (arr[mid] == x) {
    return mid;
  } else if (arr[mid] < x) {
    return binarySearch(arr, mid + 1, high, x);
  } else {
    return binarySearch(arr, low, mid - 1, x);
  }
}

int main() {
  int arr[] = {1, 3, 5, 7, 9};
  cout << "Enter the element to search: ";
  int x;
  cin >> x;
  int index = binarySearch(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1, x);

  if (index != -1) {
    cout << "The element is found at index " << index+1 << endl;
  } else {
    cout << "The element is not found" << endl;
  }

  return 0;
}
