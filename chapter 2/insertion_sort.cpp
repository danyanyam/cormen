#include <iostream>
#include <vector>

#include "utils.h"

template <typename T>
void insertion_sort(std::vector<T>& input, bool descending = false) {
    /*
     * Performs insertion sort as proposed by book in chapter 2.
     * The main idea behind is card sorting. We pick one card
     * and put it in the left hand in the appropriate position.
     */

    for (int current = 1; current < input.size(); current++) {
        T current_number = input[current];
        int i = current - 1;

        // comparing previous and current values
        // depending on sorting mode
        auto compare = [descending](T& prev, T& current) {
            if (descending) {
                return prev > current;
            };
            return prev < current;
        };

        // while previous number is bigger than the current number
        // swapping the values in the array
        while (i >= 0 and compare(input[i], current_number)) {
            input[i + 1] = input[i];
            i--;
        }
        // finding right place for insertion
        input[i + 1] = current_number;
    }
}

int main(int argc, char const* argv[]) {
    // int = 4 bytes
    int n = 6;
    std::vector<float> a = {31, 41, 59.2, 26, 41, 58};
    std::vector<float> result = {26, 31, 41, 41, 58, 59.2};

    insertion_sort(a);
    print_vector(a);  // 59.2 58 41 41 31 26

    insertion_sort(a, true);
    print_vector(a);  // 26 31 41 41 58 59.2

    assert_equal_vectors(a, result);
    return 0;
}
