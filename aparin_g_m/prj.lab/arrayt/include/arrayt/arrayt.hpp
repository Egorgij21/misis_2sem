#pragma once

#ifndef ARRAYT_HPP
#define ARRAYT_HPP



#include <iostream>

template <typename T>
class ArrayT{
    public:
        std::ptrdiff_t size_ = 0;
        T* data_;
        int capacity = 0;
    public:
        ArrayT();
        explicit ArrayT(const ptrdiff_t size);
        ArrayT(const ArrayT<T>&);
        ~ArrayT();

        T& operator[](std::ptrdiff_t i);
        const T& operator[](std::ptrdiff_t i) const;
        ArrayT<T>& operator=(const ArrayT<T>& arr);

        std::ptrdiff_t ssize() const;

        void resize(const ptrdiff_t new_size);

        void insert(const ptrdiff_t, T value);

        void remove(const ptrdiff_t);  
};

template<typename T>
ArrayT<T>::ArrayT() {
    data_ = nullptr;
    size_ = 0;
    capacity = 0;
}

template <typename T>
ArrayT<T>::ArrayT(const std::ptrdiff_t size) {
    if(size < 0) {
        throw std::invalid_argument("size must be >= 0.");
    }
    else {
        capacity = size;
        size_ = 0;
        data_ = new T[capacity];
        for(std::ptrdiff_t i = 0; i < capacity; i++) {
            data_[i] = 0.0;
        }
    }

}


template <typename T>
ArrayT<T>::ArrayT(const ArrayT& arr) {
    if (this == &arr) {
        return;
    }
    data_ = new T[capacity];
    if (arr.data_ == nullptr) {
        data_ = nullptr;
    }
    else {
        std::copy(arr.data_, arr.data_ + arr.size_, data_);
    }
}


template <typename T>
ArrayT<T>::~ArrayT(){
    delete[]data_;
}

template <typename T>
T& ArrayT<T>::operator[](const std::ptrdiff_t i) {
    if(i < 0 || i >= ssize()) {
        throw std::out_of_range("index out of range.");
    }
    return data_[i];
}

template<typename T>
const T& ArrayT<T>::operator[](std::ptrdiff_t i) const {
    if(i < 0 || i >= ssize()) {
        throw std::out_of_range("index out of range.");
    }
    return data_[i];
}

template<typename T>
ArrayT<T>& ArrayT<T>::operator=(const ArrayT<T>& arr) {
    if (this == &arr) {
        return *this;
    }
    size_ = arr.size_;
    capacity = arr.capacity;
    delete[] data_;
    data_ = new T[capacity];
    for (std::ptrdiff_t i = 0; i < ssize(); ++i) {
        new (data_ + i) T(arr.data_[i]);
    }
    return *this;
}

template <typename T>
std::ptrdiff_t ArrayT<T>::ssize() const {
    return size_;
}


template <typename T>
void ArrayT<T>::resize(std::ptrdiff_t new_size) {
    if(new_size <= 0) {
        throw std::invalid_argument("size must be > 0.");
    }
    if (new_size > capacity) {
        capacity = new_size;
        if (capacity < ssize()) {
            size_ = capacity;
            return;
        }
        double* newData_ = new T[capacity];
        if (data_ == nullptr) {
            data_ = nullptr;
        }
        else {
            std::copy(data_, data_ + ssize(), newData_);
        }
        for (std::ptrdiff_t i = ssize(); i < capacity; ++i) {
            newData_[i] = 0;
        }
        delete[] data_;
        data_ = newData_;
    }
    if (new_size > ssize()) {
        for (std::ptrdiff_t i = ssize(); i < new_size; ++i) {
            data_[i] = 0;
        }
    }
    size_ = new_size;
}


template <typename T>
void ArrayT<T>::insert(std::ptrdiff_t index, T value) {
    if(index < 0 || index > ssize()) {
        throw std::invalid_argument("index must be <= size and >= 0.");
    }
    resize(ssize() + 1);
    for (std::ptrdiff_t i = ssize() - 1; i > index; --i) {
        data_[i] = data_[i - 1];
    }
    data_[index] = value;
}


template <typename T>
void ArrayT<T>::remove(const std::ptrdiff_t index) {
    if(index >= 0 && index < ssize()) {
        for (std::ptrdiff_t i = index + 1; i < ssize(); ++i) {
            data_[i - 1] = data_[i];
        }
        resize(ssize() - 1);       
    }
    else {
        throw std::out_of_range("index out of range.");
    }
}


#endif