#include <iostream>
#include <sstream>
#include "darray_interface.hpp"

/**
 * @brief Initializes array with type T and
 *        capacity of cap
 *
 * @tparam T type of data is kept in constant-size array
 * @tparam cap initial capacity of dynamic array (defaults to 1)
 */
template <typename T, size_t cap>
DynamicArray<T, cap>::DynamicArray()
{
    arr_ = new T[cap];
    capacity_ = cap;
    size_ = 0;
}

/**
 * @brief Deletes pointer to constant size array
 *
 * @tparam T type of data is kept in constant-size array
 * @tparam cap initial capacity of dynamic array (defaults to 1)
 */
template <typename T, size_t cap>
DynamicArray<T, cap>::~DynamicArray()
{
    delete[] arr_;
}

/**
 * @brief Pushes back element of type T
 *
 * @tparam T type of data is kept in constant-size array
 * @tparam cap initial capacity of dynamic array (defaults to 1)
 */
template <typename T, size_t cap>
void DynamicArray<T, cap>::push_back(T data)
{
    if (size_ == capacity_)
    {
        // pointing to the temporary array
        T *temp = new T[capacity_ = capacity_ * 2];

        // copying the current array to the temporary
        for (size_t i = 0; i < size_; i++)
        {
            temp[i] = arr_[i];
        }
        delete[] arr_;
        arr_ = temp;
    }

    arr_[size_++] = data;
}

/**
 * @brief Prints the array's content and info
 *
 * @tparam T type of data is kept in constant-size array
 * @tparam cap initial capacity of dynamic array (defaults to 1)
 */
template <typename T, size_t cap>
void DynamicArray<T, cap>::print()
{
    std::stringstream info;    // Meta info of the array
    std::stringstream content; // Cotent of the array

    info << "[DynamicArray] len: " << size_ << ". Capacity: " << capacity_ << ". Content:\n";
    std::cout << info.str();

    content << '[';

    if (size_ == 0){
        content << ']';
        std::cout << content.str() << '\n';
        return;
    }

    if (size_ > 10)
    {
        for (size_t i = 0; i < 5; i++)
        {
            content << arr_[i] << ' ';
        }

        content << "... ";

        for (size_t i = size_ - 5; i != size_; i++)
        {
            content << arr_[i];
            if (i != size_ - 1)
            {
                content << ' ';
            }
        }
        std::cout << content.str() << ']' << '\n';
        return;
    }

    for (size_t i = 0; i < size_; i++)
    {
        content << arr_[i];
        if (i != size_ - 1)
        {
            content << ' ';
        }
    }
    std::cout << content.str() << ']' << '\n';
};
/**
 * @brief Clears the content of the DynamicArray
 *
 * @tparam T type of data is kept in constant-size array
 * @tparam cap initial capacity of dynamic array (defaults to 1)
 */
template <typename T, size_t cap>
void DynamicArray<T, cap>::clear()
{
    delete[] arr_;
    size_ = 0;
    capacity_ = 1;
    arr_ = new T[capacity_];
}
/**
 * @brief Allows to access arrays elements by indexing
 *
 * @tparam T type of data is kept in constant-size array
 * @tparam cap initial capacity of dynamic array (defaults to 1)
 * @param idx position of data in the array
 * @return T& the data kept in the array
 */
template <typename T, size_t cap>
T &DynamicArray<T, cap>::operator[](size_t idx)
{
    if (idx >= size_)
        throw std::logic_error("Index is out of range");
    return arr_[idx];
}
/**
 * @brief returns the current size of an array
 *
 * @tparam T type of data is kept in constant-size array
 * @tparam cap initial capacity of dynamic array (defaults to 1)
 * @return constexpr size_t
 */
template <typename T, size_t cap>
constexpr size_t DynamicArray<T, cap>::size()
{
    return size_;
}
/**
 * @brief Removes and returns the last element of an array
 *
 * @tparam T type of data is kept in constant-size array
 * @tparam cap initial capacity of dynamic array (defaults to 1)
 * @return T&
 */
template <typename T, size_t cap>
T &DynamicArray<T, cap>::pop_back()
{
    T &last_element = this->operator[](size_ - 1);
    size_--;
    return last_element;
}
