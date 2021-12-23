#include <algorithm>
#include <vector>

#include "utils.h"

// task 2.2.-2

template <typename T>
void selection_sort(std::vector<T>& v, bool descending = false) {
    // https://en.wikipedia.org/wiki/Selection_sort

    // comparison of previous and current values depending on sorting mode
    auto compare = [descending](T& prev, T& current) {
        return (descending) ? prev > current : prev < current;
    };

    size_t v_size = v.size();

    for (size_t current_idx = 0; current_idx < v_size; current_idx++) {  // n
        for (size_t tail_idx = current_idx + 1; tail_idx < v_size;
             tail_idx++) {                               // (n-1+1)(n-1)/2
            if (compare(v[tail_idx], v[current_idx])) {  // (n-1+1)(n-1)/2
                std::swap(v[current_idx], v[tail_idx]);  // 0...n
            }
        }
    }
    // overall complexity us \theta(n^2) in the worst and best cases
    // since \sum_{i=1}^{n-1}i = (1+n-1)(n-1)/2
}

int main() {
    std::vector<float> a = {31, 41, 59.2, 26, 41, 58};
    std::vector<float> result = {26, 31, 41, 41, 58, 59.2};

    selection_sort(a);
    print_vector(a);  // 26 31 41 41 58 59.2
    assert_equal_vectors(a, result);

    selection_sort(a, true);
    print_vector(a);  // 59.2 58 41 41 31 26

    return 0;
}
