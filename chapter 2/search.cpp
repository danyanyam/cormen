#include <iostream>
#include <optional>
#include <vector>

#include "utils.h"

template <typename T>
std::optional<size_t> linear_search(std::vector<T>& vector, T number) {
    /*
     * Task 2.1-3
     * Performs linear search for a given element in the
     * vector. If element is found -- returns its index.
     */

    std::optional<size_t> position;
    for (size_t i = 0; i < vector.size(); i++) {
        if (vector[i] == number) {
            position.emplace(i);
            break;
        }
    }
    return position;
}

int main() {
    std::vector<int> a = {1, 2, 3, 4, 5, 6};
    std::optional<size_t> index;

    index = linear_search(a, 10);
    std::cout << index.has_value();  // false

    index = linear_search(a, 2);
    std::cout << index.value();  // 1

    index = linear_search(a, 4);
    std::cout << index.value();  // 3

    index = linear_search(a, 5);
    std::cout << index.value();  // 4
}
