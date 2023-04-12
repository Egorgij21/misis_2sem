#pragma once

#pragma once

#ifndef ARRAYT_HPP
#define ARRAYT_HPP



#include <iostream>

template <typename T>
class ArrayT{
    private:
        ptrdiff_t size_ = 0;
        T* data_;
        int capacity = 0;
    public:

        ArrayT(const ptrdiff_t& size);
        ArrayT(const ArrayT& arr);
        ~ArrayT();

        T& operator[](const ptrdiff_t i);

        ptrdiff_t ssize() const;

        void resize(const ptrdiff_t new_size);

        void insert(const ptrdiff_t index, const T value);

        void remove(const ptrdiff_t index);  
};

template <typename T>
ArrayT<T>::ArrayT(const std::ptrdiff_t& size) {
    if(size < 0) {
        throw std::invalid_argument("size must be >= 0.");
    }
    else if(size == 0) {
        data_ = new double[0];
    }
    else {
        capacity = size;
        size_ = 0;
        data_ = new double[capacity];
        for(std::ptrdiff_t i = 0; i < capacity; i++) {
            data_[i] = 0.0;
        }
    }

}


template <typename T>
ArrayT<T>::ArrayT(const ArrayT& arr) {
    *this = arr;
}


template <typename T>
ArrayT<T>::~ArrayT(){
    delete[]data_;
}

template <typename T>
T& ArrayT<T>::operator[](const std::ptrdiff_t i) {
    
    if(i < 0 || i >= capacity) {
        throw std::out_of_range("index out of range.");
    }
    
    return data_[i];
}

template <typename T>
std::ptrdiff_t ArrayT<T>::ssize() const {
    return capacity;
}


template <typename T>
void ArrayT<T>::resize(const std::ptrdiff_t new_size) {
    if(new_size <= 0) {
        throw std::invalid_argument("size must be > 0.");
    }
    T* newarr = new T[new_size];
    for(std::ptrdiff_t i = 0; i < capacity; ++i) {
        newarr[i] = data_[i];
    }
    for(std::ptrdiff_t i = capacity; i < new_size; ++i) {
        newarr[i] = 0.0;
    }
    capacity = new_size;
    delete [] data_;
    data_ = newarr;
    delete [] newarr;
}


template <typename T>
void ArrayT<T>::insert(const std::ptrdiff_t index, const T value) {
    if(index >= 0 && index < capacity) {
        if(value != 0.0) {
            data_[index] = value;
            size_ += 1;
        }
    }
    else if(index == capacity) {
            T* newarr = new T[index + 1];
            for(std::ptrdiff_t i = 0; i < capacity; ++i) {
                newarr[i] = data_[i];
            }
            for(std::ptrdiff_t i = capacity; i < index + 1; ++i) {
                newarr[i] = 0.0;
            }
            capacity = index + 1;
            size_ += 1;
            delete[]data_;
            data_ = newarr;
            data_[index] = value;
        }
    else {
        throw std::invalid_argument("index must be <= size and >= 0.");
    }
}


template <typename T>
void ArrayT<T>::remove(const std::ptrdiff_t index) {
    if(index >= 0 && index < capacity) {
        if(0 < data_[index] + 1e-6 && 0 > data_[index] - 1e-6) {
            data_[index] = 0.0;
        }
        else {
            data_[index] = 0.0;
            size_ -= 1;
        }
        
    }
    else {
        throw std::out_of_range("index out of range.");
    }
}


#endif