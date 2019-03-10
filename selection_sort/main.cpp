#include <iostream>

using namespace std;

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
    int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    selectionSort(a, 10);
    for(int i = 0; i < 10; i ++)
        cout<< a[i] <<" ";
    cout<<endl;

    float b[10] = {1.0, 9.3, 8.3, 1.7, 6.3, 5.4, 3.4, 3.9, 20, 13.3};
    selectionSort(b, 10);
    for(int i = 0; i < 10; i ++)
        cout<< b[i] <<" ";
    cout<<endl;
    return 0;
}