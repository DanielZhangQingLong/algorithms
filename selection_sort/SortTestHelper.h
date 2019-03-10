//
// Created by daniel on 2019-03-10.
//

#ifndef SELECTION_SORT_SORTTESTHELPER_H
#define SELECTION_SORT_SORTTESTHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

namespace SortTestHelper{

    // random in [rangeL, rangeR]
    int* genenrateRandomArray(int n, int rangeL, int rangeR) {

        assert(rangeL <= rangeR);
        int *arr = new int[n];
        srand(time(NULL));
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }

    template<typename T>
    void printArray(T arr[], int n) {
        for (int i = 0; i < n; ++i) {
            cout << arr[i]<< " ";
        }
        cout << endl;
        return;
    }
}

#endif //SELECTION_SORT_SORTTESTHELPER_H
