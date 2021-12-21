#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
void print_vector(std::vector<T>& a) {
    for (T& i : a) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}

template <typename T>
void assert_equal_vectors(std::vector<T>& first, std::vector<T>& second) {
    if (!std::equal(first.begin(), first.end(), second.begin())) {
        throw (std::logic_error("Vectors are not equal!"));
    }
}