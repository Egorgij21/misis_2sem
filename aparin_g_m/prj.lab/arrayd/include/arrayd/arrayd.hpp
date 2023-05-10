#pragma once


#ifndef ARRAYD_HPP
#define ARRAYD_HPP


#include<iosfwd>
#include <cstddef>


class ArrayD{
public:
    std::ptrdiff_t size_ = 0;
    double* data_;
    int capacity = 0;

public:
    ArrayD();
    explicit ArrayD(const std::ptrdiff_t& size);
    ArrayD(const ArrayD&);
    ~ArrayD();

    std::ptrdiff_t ssize() const noexcept;

    double& operator[](const std::ptrdiff_t i);
    const double& operator[](const std::ptrdiff_t i) const;
    ArrayD& operator=(const ArrayD& arr);

    void resize(const std::ptrdiff_t new_size);

    void insert(const std::ptrdiff_t, const double value);

    void remove(const std::ptrdiff_t);
};

#endif