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

template <typename T, typename F>
void assert_equal_vectors(std::vector<T>& first, std::vector<F>& second) {
    if (!std::equal(first.begin(), first.end(), second.begin())) {
        throw(std::logic_error("Vectors are not equal!"));
    }
}

template <typename T, typename F>
void assert_equal_number(T& lhs, F& rhs) {
    if (lhs != rhs) {
        throw(std::logic_error("Numbers are not equal!"));
    }
}

template <typename T>
void print_array(T arr[], size_t size) {
    for (size_t i = 0; i < size; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;
};
