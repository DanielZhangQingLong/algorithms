#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"


// 将arr[l...mid] 和 arr[mid+1...r]两部分进行归并
template <typename T>
void __merge(T arr[], int l, int mid, int r) {
    // 将当前数组复制一份
    T aux[r-l+1];
    for (int i = l; i <= r; ++i) {
        aux[i-l] = arr[i];
    }
    int i = l, j = mid + 1;
    // 将数组aux两部分的元素比较，决定数组arr的下一个元素arr[k]是较小的
    for (int k = l; k <= r ; ++k) {
        // 判断数组是否越界
        // 左边部分的数组已经遍历完成, 直接把右边部分数组元素赋值即可。
        if( i > mid ){
            arr[k] = aux[j-l];
            j++;
        // 右边部分的数组已经遍历完成，直接把左边的数组元素赋值即可。
        } else if(j > r) {
            arr[k] = aux[i-l];
            i ++;
        // 当左边部分的元素比较小时，元素组当前位置为左边的元素.
        } else if(aux[i-l] < aux[j-l]) {
            arr[k] = aux[i-l];
            i ++;
        // 当右边部分的元素比较小时，元素组当前位置为右边的元素.
        } else {
            arr[k] = aux[j-l];
            j++;
        }
    }
}

// 递归使用归并排序，对arr[l...r]的范围进行排序
template <typename T>
void __mergeSort(T arr[], int l, int r) {
    // l >= r 数组只剩下一个元素
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid+1, r);
    //如果左边的元素大于右边才需要合并
    if(arr[mid] > arr[mid+1])
        __merge(arr, l, mid, r);
}

template<typename T>
void mergeSort(T arr[], int n) {

    __mergeSort(arr, 0, n - 1);
}

// 第二种非递归实现方法，自底向上。
template <typename T>
void mergeSortBU(T arr[], int n) {

    // 对[0...sz-1], [sz...2sz-1]归并
    for(int sz = 1; sz <= n; sz += sz) {
        // [2sz...3sz-1], [3sz...4sz-1]
        for(int i = 0; i + sz < n; i += sz + sz) {
            __merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
        }
    }
}

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

int main() {
    int n = 50000;
    cout << "Test for Random Array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;

    int* arr1 = SortTestHelper::genenrateRandomArray(0, n, n);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr2, n);

    delete[] arr1;
    delete[] arr2;
    cout<<endl;

    int swapTimes = 0;

    cout << "Test for Random Array, size = "<<n<<", swap times [0, "<<swapTimes<<"]"<<endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr2, n);
    return 0;
}