#include<iostream>
#include<time.h>

#define N 10
int tmp[N];
using namespace std;

void print(int *arr) {
    for (int i = 0; i < N; i++)
    cout << arr[i] << " ";
    cout << endl << endl;
}

void ArrayMerge(int start, int end, int* arr){
    int mid = (start + end) / 2;
    int i = start;
    int j = mid + 1;
    int k = start;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            tmp[k] = arr[i];
            i++;
        }
        else {
            tmp[k] = arr[j];
            j++;
        }
        k++;
        print(arr);
    }

    int t;
    if (i > mid)
        t = j;
    else
        t = i;

    for (k; k <= end; k++, t++)
        tmp[k] = arr[t];
    for (k = 0; k <= end; k++)
        arr[k] = tmp[k];
    print(arr);
}

void MergeSort(int start, int end, int*arr) {
    int mid;
    if (start < end) {
        mid = (start + end) / 2;
        MergeSort(start, mid, arr);
        MergeSort(mid + 1, end, arr);
        ArrayMerge(start, end, arr);
    }
}

int main() {
    srand(time(NULL));
    int arr[N];

    for (int j = 0; j < N; j++)
        arr[j] = rand() % 100 + 1;

    print(arr);
    MergeSort(0, N - 1, arr);
    print(arr);
    cout << endl;

    return 0;
}