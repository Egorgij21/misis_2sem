#include <arrayd/arrayd.hpp>


#include <iostream>


ArrayD::ArrayD() {
    data_ = nullptr;
    size_ = 0;
    capacity_ = 0;
}

ArrayD::ArrayD(const std::ptrdiff_t sizeInp) {
    if (sizeInp < 0) {
        throw std::out_of_range("Index out of range");
    }
    size_ = sizeInp;
    capacity_ = sizeInp;
    data_ = new double[capacity_];
    for (std::ptrdiff_t i = 0; i < ssize(); ++i) {
        data_[i] = 0;
    }
}

ArrayD::ArrayD(const ArrayD& prev) : size_(prev.size_), capacity_(prev.capacity_), data_(nullptr){
    if (this == &prev) {
        return;
    }
    data_ = new double[capacity_];
    if (prev.data_ == nullptr) {
        data_ = nullptr;
    }
    else {
        std::copy(prev.data_, prev.data_ + prev.size_, data_);
    }
}

ArrayD::~ArrayD(){
    delete[] data_;
}

std::ptrdiff_t ArrayD::ssize() const noexcept {
    return size_;
}

double& ArrayD::operator[](const std::ptrdiff_t i) {
    if (i < 0 || i >= ssize()) {
        throw std::out_of_range("Index out of range");
    }
    return data_[i];
}


const double& ArrayD::operator[](const std::ptrdiff_t i) const{
    if (i < 0 || i >= ssize()) {
        throw std::out_of_range("Index out of range");
    }
    return data_[i];
}


ArrayD& ArrayD::operator=(const ArrayD& arr) {
    if (this == &arr) {
        return *this;
    }
    size_ = arr.size_;
    capacity_ = arr.capacity_;
    delete[] data_;
    data_ = new double[capacity_];
    for (std::ptrdiff_t i = 0; i < ssize(); ++i) {
        new (data_ + i) double (arr.data_[i]);
    }
    return *this;
}

void ArrayD::reserve(const std::ptrdiff_t newCapacity_) {
    capacity_ = newCapacity_;
    if (capacity_ < ssize()) {
        size_ = capacity_;
        return;
    }
    double* newMemory_ = new double[capacity_];
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

void ArrayD::resize(const std::ptrdiff_t newSsize_) {
    if (newSsize_ <= 0) {
        throw std::invalid_argument("Expected positive");
    }
    if (newSsize_ > capacity_) {
        reserve(newSsize_);
    }
    if (newSsize_ > ssize()) {
        for (std::ptrdiff_t i = ssize(); i < newSsize_; ++i) {
            data_[i] = 0;
        }
    }
    size_ = newSsize_;
}


void ArrayD::insert(const std::ptrdiff_t index, const double num)
{
    if (index < 0 || index > ssize()) {
        throw std::out_of_range("Wrong position");
    }
    resize(ssize() + 1);
    for (std::ptrdiff_t i = ssize() - 1; i > index; --i) {
        data_[i] = data_[i - 1];
    }
    data_[index] = num;
}

void ArrayD::remove(const std::ptrdiff_t index)
{
    if (index < 0 || index >= ssize()) {
        throw std::out_of_range("Wrong position");
    }
    for (std::ptrdiff_t i = index + 1; i < ssize(); ++i) {
        data_[i - 1] = data_[i];
    }
    resize(ssize() - 1);
}
