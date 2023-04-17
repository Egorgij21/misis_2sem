#pragma once

#pragma once

#ifndef ARRAYD_HPP
#define ARRAYD_HPP



#include<iosfwd>


class ArrayD{
public:
    ptrdiff_t size_ = 0;
    double* data_;
    int capacity = 0;

public:

    ArrayD(const ptrdiff_t& size);
    ArrayD(const ArrayD& arr);
    ~ArrayD();


    double& operator[](const ptrdiff_t i);
    ArrayD& operator=(const ArrayD& arr);

    ptrdiff_t ssize() const;

    void resize(const ptrdiff_t new_size);

    void insert(const ptrdiff_t index, const double value);

    void remove(const ptrdiff_t index);
};

#endif