#include "utils.h"

template <typename T>
void bubble_sort(T arr[], int size, bool descending = false) {
    /**
     * Function sorts the passsed array of data
     * with the help of bubble_sort algorithm.
     *
     * Complexity is O(n^2) because
     * an + bn(n-1) +cn(n-1) proportional to n^2
     */

    auto compare = [descending](T lhs, T rhs) {
        return (descending) ? lhs < rhs : lhs > rhs;
    };

    for (int i = 0; i < size; i++) {           // n
        for (int j = size - 1; j >= i; j--) {  // n(n-1)
            if (compare(arr[i], arr[j])) std::swap(arr[i], arr[j]);
        }
    }
}

int main() {
    int arr[] = {2, 5, 6, 7, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    bubble_sort(arr, size);
    print_array(arr, size);  // 1 2 5 6 7

    bubble_sort(arr, size, true);
    print_array(arr, size);  // 7 6 5 2 1
}
