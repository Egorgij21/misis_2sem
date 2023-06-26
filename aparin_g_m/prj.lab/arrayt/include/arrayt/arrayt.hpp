#pragma once

#ifndef ARRAYT_HPP
#define ARRAYT_HPP



#include <iostream>

template <typename T>
class ArrayT{
public:
    std::ptrdiff_t size_;
    std::ptrdiff_t capacity_;
    T* data_;
    static const char separator = ',';
public:
    ArrayT();
    explicit ArrayT(const std::ptrdiff_t len);
    ArrayT(const ArrayT<T>&);
    ArrayT(std::ptrdiff_t sizeInp, T number);
    ~ArrayT();

    T& operator[](std::ptrdiff_t i);
    const T& operator[](std::ptrdiff_t i) const;

    ArrayT<T>& operator=(const ArrayT<T>& arr);

    std::ptrdiff_t ssize() const;

    void reserve(std::ptrdiff_t new_capacity);
    void resize(const std::ptrdiff_t new_size);

    void insert(const std::ptrdiff_t, T value);

    void remove(const std::ptrdiff_t);  

    std::ostream& writeTo(std::ostream& ostrm) const;
};

template<typename T>
ArrayT<T>::ArrayT() {
    data_ = nullptr;
    size_ = 0;
    capacity_ = 0;
}

template<typename T>
ArrayT<T>::ArrayT(std::ptrdiff_t size) {
    if (size < 0) {
        throw std::out_of_range("Index out of range");
    }
    size_ = size;
    capacity_ = size;
    data_ = new T[capacity_];
    for (std::ptrdiff_t i = 0; i < ssize(); ++i) {
        data_[i] = 0;
    }
}


template<typename T>
ArrayT<T>::ArrayT(const ArrayT<T>& arr) : size_(arr.size_), capacity_(arr.capacity_), data_(nullptr) {
    if (this == &arr) {
        return;
    }
    data_ = new T[capacity_];
    if (arr.data_ == nullptr) {
        data_ = nullptr;
    }
    else {
        std::copy(arr.data_, arr.data_ + arr.size_, data_);
    }
}


template <typename T>
ArrayT<T>::~ArrayT(){
    delete[] data_;
}

template <typename T>
std::ptrdiff_t ArrayT<T>::ssize() const {
    return size_;
}

template<typename T>
T& ArrayT<T>::operator[](std::ptrdiff_t index) {
    if (index < 0 || index >= ssize()) {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

template<typename T>
const T& ArrayT<T>::operator[](std::ptrdiff_t index) const {
    if (index < 0 || index >= ssize()) {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

template<typename T>
ArrayT<T>& ArrayT<T>::operator=(const ArrayT<T>& rhs) {
    if (this == &rhs) {
        return *this;
    }
    size_ = rhs.size_;
    capacity_ = rhs.capacity_;
    delete[] data_;
    data_ = new T[capacity_];
    for (std::ptrdiff_t i = 0; i < ssize(); ++i) {
        new (data_ + i) T(rhs.data_[i]);
    }
    return *this;
}

template<typename T>
void ArrayT<T>::reserve(std::ptrdiff_t new_capacity) {
    capacity_ = new_capacity;
    if (capacity_ < ssize()) {
        size_ = capacity_;
        return;
    }
    T* newMemory_ = new T[capacity_];
    if (data_ == nullptr) {
        data_ = nullptr;
    }
    else {
        std::copy(data_, data_ + ssize(), newMemory_);
    }
    for (std::ptrdiff_t i = ssize(); i < capacity_; ++i) {
        newMemory_[i] = 0;
    }
    delete[] data_;
    data_ = newMemory_;
}


template<typename T>
void ArrayT<T>::resize(std::ptrdiff_t new_size) {
    if (new_size <= 0) {
        throw std::invalid_argument("Expected positive");
    }
    if (new_size > capacity_) {
        reserve(new_size);
    }
    if (new_size > ssize()) {
        for (std::ptrdiff_t i = ssize(); i < new_size; ++i) {
            data_[i] = 0;
        }
    }
    size_ = new_size;
}


template<typename T>
void ArrayT<T>::insert(std::ptrdiff_t index, T num) {
    if (index < 0 || index > ssize()) {
        throw std::out_of_range("Wrong position");
    }
    resize(ssize() + 1);
    for (std::ptrdiff_t i = ssize() - 1; i > index; --i) {
        data_[i] = data_[i - 1];
    }
    data_[index] = num;
}


template<typename T>
void ArrayT<T>::remove(std::ptrdiff_t index)
{
    if (index < 0 || index >= ssize()) {
        throw std::out_of_range("Wrong position");
    }
    for (std::ptrdiff_t i = index + 1; i < ssize(); ++i) {
        data_[i - 1] = data_[i];
    }
    resize(ssize() - 1);
}


#endif