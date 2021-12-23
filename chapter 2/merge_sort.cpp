#include <iostream>

#include "utils.h"

void merge(int arr[], int left_begin, int right_begin, int right_end) {
    // copying elements of arr
    int n1 = right_begin - left_begin + 1;
    int n2 = right_end - right_begin;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left_begin + i];
    for (int i = 0; i < n2; i++) R[i] = arr[right_begin + 1 + i];

    // inserting values from copies into the original array
    int i = 0;
    int j = 0;

    while (i < n1 && j < n2) {
        (L[i] <= R[j]) ? arr[left_begin++] = L[i++]
                       : arr[left_begin++] = R[j++];
    }

    while (i < n1) {
        arr[left_begin++] = L[i++];
    }
    while (j < n2) {
        arr[left_begin++] = R[j++];
    }
};

void merge_sort(int arr[], int begin_idx, int end_idx) {
    /**
     * Function splits range of [begin_idx..end_idx]
     * into halved ranges with the help of recursion.
     *
     * Once given array is halved until the end it is
     * then merged.
     */

    if (begin_idx >= end_idx) return;

    int half_idx = (begin_idx + end_idx) / 2;
    merge_sort(arr, begin_idx, half_idx);
    merge_sort(arr, half_idx + 1, end_idx);
    merge(arr, begin_idx, half_idx, end_idx);
};

// Driver program
int main() {
    int arr[] = {6, 5, 12, 10, 9, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    merge_sort(arr, 0, size - 1);

    std::cout << "\nSorted array: \n";
    print_array(arr, size);  // 1 5 6 9 10 12
    return 0;
}