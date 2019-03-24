#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"

using namespace std;

template <typename T>
void insertionSort(T arr[], int n) {
    for (int i = 1; i < n; i ++) {
        // Insert arr[i] in right position.
        T e = arr[i];
        int j;
        for (j = i; j > 0 && arr[j-1] > e; j --) {
//            swap(arr[j], arr[j-1]);
            arr[j] = arr[j-1];
        }
        arr[j] = e;
    }
}

template<typename T>
void selectionSort( T arr[], int n) {
    for (int i = 0; i < n; i ++) {
        // Find out min in [i, n)
        int minIndex = i;
        for (int j = i + 1; j < n; j ++) {
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    int n = 10000;
    int *arr = SortTestHelper::generateNearlyOrderedArray(n, 10);
    int *arr2 = SortTestHelper::copyIntArray(arr, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr, n);
    SortTestHelper::testSort("Selection Sort", selectionSort, arr2, n);
    delete[] arr;
    delete[] arr2;
    return 0;
}