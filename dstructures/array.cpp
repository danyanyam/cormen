#include <iostream>
#include <sstream>

/**
 * @brief Declares interface of DynamicArray. Dynamic array is a type of container
 *        which is based on constant size arrays and resizes automatically once new
 *        data is pushed. Resizing is based on arrays capacity and current array size.
 *        Data is kept in constant-size arrays. Once the whole array is filled with data,
 *        the copy of that array with doubled capacity is created.
 *
 * @tparam T type of data is kept in constant-size array
 * @tparam cap initial capacity of dynamic array (defaults to 1)
 */
template <typename T, size_t cap = 1>
class DynamicArray
{
private:
    size_t size_;
    size_t capacity_;
    T *arr;

public:
    DynamicArray();
    ~DynamicArray();

    void push_back(T &data);
    void push_back(T data);
    void clear();
    void print();
    T &pop_back();
    T &operator[](size_t idx);
    constexpr size_t size();
};

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
    arr = new T[cap];
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
    delete[] arr;
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
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
    }

    arr[size_++] = data;
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

    if (size_ == 0)
        return;
    if (size_ > 10)
    {
        for (size_t i = 0; i < 5; i++)
        {
            content << arr[i] << ' ';
        }

        content << "... ";

        for (size_t i = size_ - 5; i != size_; i++)
        {
            content << arr[i];
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
        content << arr[i];
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
    delete[] arr;
    size_ = 0;
    capacity_ = 1;
    arr = new T[capacity_];
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
        throw logic_error("Index is out of range");
    return arr[idx];
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

int main()
{
    DynamicArray<int> v;

    v.push_back(2);
    v.push_back(3);
    v.print();
    std::cout << '\n'
              << v.size() << '\n';

    std::cout << "Popped" << v.pop_back() << '\n';
    v.print();

    for (size_t i = 0; i < 100; i++)
    {
        v.push_back(i);
        v.print();
    }
    v.clear();
    v.print();

    return 0;
}
