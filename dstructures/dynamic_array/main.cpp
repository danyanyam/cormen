#include "darray.hpp"

int main()
{
    // constructing array of capacity 1 and type ints
    DynamicArray<int> v;

    v.push_back(2);
    v.push_back(3);
    v.print(); // [DynamicArray] len: 2. Capacity: 2. Content: [2 3]

    for (size_t i = 0; i < 100; i++) v.push_back(i);

    v.print();  // [DynamicArray] len: 102. Capacity: 128. Content:\n [2 3 0 1 2 ... 95 96 97 98 99]
    v.clear();
    v.print();  // [DynamicArray] len: 0. Capacity: 1. Content: []

    return 0;
}