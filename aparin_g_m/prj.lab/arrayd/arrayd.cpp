#include <arrayd/arrayd.hpp>


#include <iostream>




ArrayD::ArrayD(const std::ptrdiff_t& size = 0) {
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

ArrayD::ArrayD(const ArrayD& arr) {
    *this = arr;
}

ArrayD::~ArrayD(){
    delete[]data_;
}


double& ArrayD::operator[](const std::ptrdiff_t i) {
    
    if(i < 0 || i >= capacity) {
        throw std::out_of_range("index out of range.");
    }
    
    return data_[i];
}

std::ptrdiff_t ArrayD::ssize() const {
    return capacity;
}

void ArrayD::resize(const std::ptrdiff_t new_size) {
    if(new_size <= 0) {
        throw std::invalid_argument("size must be > 0.");
    }
    double* newarr = new double[new_size];
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

void ArrayD::insert(const std::ptrdiff_t index, const double value) {
    if(index >= 0 && index < capacity) {
        if(value != 0.0) {
            data_[index] = value;
            size_ += 1;
        }
    }
    else if(index == capacity) {
            double* newarr = new double[index + 1];
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

void ArrayD::remove(const std::ptrdiff_t index) {
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

/*

int main() {
    ArrayD a(5);
    for(int i = 0; i < a.ssize(); i++) {
        a.insert(i, i*i);
    }

    a.insert(5, 25);
    for(int i = 0; i < a.ssize(); i++) {
        std::cout << a[i] << '\n';
    }
    
    //std::cout << a.ssize() << '\n';
}
*/