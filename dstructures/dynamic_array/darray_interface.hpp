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
    size_t size_;              // length of an array
    size_t capacity_;          // maximum size of an array
    T *arr_;                    // pointer to memory where data is kept

public:
    DynamicArray();            // initializes array with type T and capacity cap
    ~DynamicArray();           // deletes pointers to memory

    void push_back(T &data);   // pushes back an existing element of data
    void push_back(T data);    // pushes back a copy of data
    void clear();              // clears the array from data
    void print();              // prints the info about capacity and size and content of arr_
    T &pop_back();             // removes and returns the last element of an array
    T &operator[](size_t idx); // accessing elements of an array by indexes
    constexpr size_t size();   // length of an array
};
