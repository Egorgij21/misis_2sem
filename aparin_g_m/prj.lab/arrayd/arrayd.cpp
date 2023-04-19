#include <arrayd/arrayd.hpp>


#include <iostream>


ArrayD::ArrayD() {
    data_ = nullptr;
    size_ = 0;
    capacity = 0;
}

ArrayD::ArrayD(const std::ptrdiff_t& size) {
    if(size < 0) {
        throw std::invalid_argument("size must be >= 0.");
    }
    else if(size == 0) {
        data_ = new double[0];
    }
    else {
        capacity = size;
        size_ = size;
        data_ = new double[capacity];
        for(std::ptrdiff_t i = 0; i < capacity; i++) {
            data_[i] = 0.0;
        }
    }

}

ArrayD::ArrayD(const ArrayD& arr) {
    if (this == &arr) {
        return;
    }
    data_ = new double[capacity];
    if (arr.data_ == nullptr) {
        data_ = nullptr;
    }
    else {
        std::copy(arr.data_, arr.data_ + arr.size_, data_);
    }
}

ArrayD::~ArrayD(){
    delete[]data_;
}


double& ArrayD::operator[](const std::ptrdiff_t i) {
    
    if(i < 0 || i >= size_) {
        throw std::out_of_range("index out of range.");
    }
    
    return data_[i];
}


const double& ArrayD::operator[](const std::ptrdiff_t i) const {

    if (i < 0 || i >= size_) {
        throw std::out_of_range("Index out of range");
    }

    return data_[i];
}


ArrayD& ArrayD::operator=(const ArrayD& arr) {
    if (this == &arr) {
        return *this;
    }
    size_ = arr.size_;
    capacity = arr.capacity;
    delete[] data_;
    data_ = new double[capacity];
    for (std::ptrdiff_t i = 0; i < ssize(); ++i) {
        new (data_ + i) double (arr.data_[i]);
    }
    return *this;
}


std::ptrdiff_t ArrayD::ssize() const noexcept {
    return size_;
}

void ArrayD::resize(const std::ptrdiff_t new_size) {
    if(new_size <= 0) {
        throw std::invalid_argument("size must be > 0.");
    }
    if (new_size > capacity) {
        capacity = new_size;
        if (capacity < ssize()) {
            size_ = capacity;
            return;
        }
        double* newData_ = new double[capacity];
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

void ArrayD::insert(const std::ptrdiff_t index, const double value) {
    if(index < 0 || index > ssize()) {
        throw std::invalid_argument("index must be <= size and >= 0.");
    }
    resize(ssize() + 1);
    for (std::ptrdiff_t i = ssize() - 1; i > index; --i) {
        data_[i] = data_[i - 1];
    }
    data_[index] = value;
}

void ArrayD::remove(const std::ptrdiff_t index) {
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
