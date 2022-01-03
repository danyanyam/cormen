#include <iostream>

using namespace std;
template <typename T, size_t cap = 1>
class DynamicArray {
   private:
    size_t size_;
    size_t capacity_;
    T* arr;

   public:
    DynamicArray();
    ~DynamicArray();

    void push_back(T& data);
    void clear();
    void print();
    T& pop_back();
    T& operator[](size_t idx);
    constexpr size_t size();
};

template <typename T, size_t cap>
DynamicArray<T, cap>::DynamicArray() {
    arr = new T[cap];
    capacity_ = cap;
    size_ = 0;
}

template <typename T, size_t cap>
DynamicArray<T, cap>::~DynamicArray() {
    delete[] arr;
}

template <typename T, size_t cap>
void DynamicArray<T, cap>::push_back(T& data) {
    if (size_ == capacity_) {
        // pointing to the temporary array
        T* temp = new T[capacity_ = capacity_ * 2];

        // copying the current array to the temporary
        for (size_t i = 0; i < size_; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
    }

    arr[size_++] = data;
}

template <typename T, size_t cap>
void DynamicArray<T, cap>::print() {
    if (size_ == 0) {
        return;
    }

    for (size_t i = 0; i < size_; i++) {
        std::cout << arr[i] << ' ';
    }
};

template <typename T, size_t cap>
void DynamicArray<T, cap>::clear() {
    delete[] arr;
    size_ = 0;
    capacity_ = 1;
    arr = new T[capacity_];
}

template <typename T, size_t cap>
T& DynamicArray<T, cap>::operator[](size_t idx) {
    if (idx > size_ - 1) {
        throw logic_error("Index is out of range");
    }
    return arr[idx];
}

template <typename T, size_t cap>
constexpr size_t DynamicArray<T, cap>::size() {
    return size_;
}

template <typename T, size_t cap>
T& DynamicArray<T, cap>::pop_back() {
    return this->operator[](size_);
}

int main() {
    DynamicArray<int> v;
    int num = 2;
    int num_2 = 3;
    v.push_back(num);
    v.push_back(num_2);
    v.print();
    cout << '\n' << v.size() << '\n';

    cout << "Popped" << v.pop_back() << '\n';
    v.print();
    return 0;
}
