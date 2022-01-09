// https://internalpointers.com/post/writing-custom-iterators-modern-cpp

/**
 *
 * Modern c++ has 6 following iterators:
 * * can scan container:
 *   1. Input         iterator: only once, read-only
 *   2. Output        iterator: only once, write-only
 *   3. Forward       iterator: forward muptiple times, read-write
 *   4. Bidirectional iterator: back and forth
 *   5. Random Access iterator: non-sequentially
 *   6. Contigious    iterator: logically adjacent elements are also physically
 * adjacent in memory
 *
 * Read-only are constant iterators.
 * C++ expects some properties from iterators:
 *   1. *iterator_category* - one of six categories above (all of them are
 * there: (https://en.cppreference.com/w/cpp/iterator/iterator_tags)
 *   2. *difference_type* - a signed integer type that can be used to identify
 * distance between iterator steps
 *   3. *value_type* - the type the iterator iterates over. int in our case;
 *   4. *pointer* — defines a pointer to the type iterated over. int* in our
 * case;
 *   5. *reference* — defines a reference to the type iterated over. int& in our
 * case;
 *
 *
 * All iterators must be constructible, copy-constructible, copy-assignable,
 * destructible and swappable.
 */

#include <algorithm>
#include <iostream>
#include <iterator>

class Integers {
   private:
    int m_data[200];

   public:
    struct Iterator {
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = int;
        using pointer = value_type*;
        using reference = value_type&;

       public:
        Iterator(pointer ptr) : m_ptr(ptr) {
            //    The custom constructor satisfies the constructible
            //    requirement,
            //    while all others are covered by the implicitly-declared
            //    constructors and operators kindly provided by the compiler.
        }
        reference operator*() const { return *m_ptr; }
        pointer operator->() const { return m_ptr; }

        // prefix increment
        Iterator& operator++() {
            m_ptr++;
            return *this;
        }
        // postfix increment
        Iterator operator++(int) {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }
        friend bool operator==(const Iterator& a, const Iterator& b) {
            return a.m_ptr == b.m_ptr;
        };
        friend bool operator!=(const Iterator& a, const Iterator& b) {
            return a.m_ptr != b.m_ptr;
        };

       private:
        pointer m_ptr;
    };
    Iterator begin() { return Iterator(&m_data[0]); }
    Iterator end() { return Iterator(&m_data[200]); }
};

int main() {
    Integers ints;
    std::fill(ints.begin(), ints.end(), 3);

    for (auto&& i : ints) {
        std::cout << i << '\n';
    }
}
