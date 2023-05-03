#pragma once

#ifndef MATRIXS_MATRIXS_HPP
#define MATRIXS_MATRIXS_HPP

#include <iosfwd>
#include <tuple>


class MatrixS {
public:
    ptrdiff_t rows_;
    ptrdiff_t cols_;
    ptrdiff_t len_;
    int* data_;
    using SizeType = std::tuple<std::ptrdiff_t, std::ptrdiff_t>;
public:
    MatrixS();
    explicit MatrixS(const SizeType& dims);
    MatrixS(ptrdiff_t inputRows_, ptrdiff_t inputCols_);
    MatrixS(ptrdiff_t inputRows_, ptrdiff_t inputCols_, int num);
    MatrixS(std::initializer_list<std::initializer_list<int>> initMatrix);
    MatrixS(const MatrixS&);
    ~MatrixS();

    [[nodiscard]] const int& at(const std::ptrdiff_t, const std::ptrdiff_t) const;
    [[nodiscard]] int& at(const std::ptrdiff_t, const std::ptrdiff_t);
    [[nodiscard]] const int& at(const SizeType) const;
    [[nodiscard]] int& at(const SizeType);

    [[nodiscard]] std::ptrdiff_t nRows() const noexcept;
    [[nodiscard]] std::ptrdiff_t nCols() const noexcept;

    [[nodiscard]] SizeType ssize() const noexcept;

    MatrixS& operator=(const MatrixS&);

    MatrixS& operator+=(int);
    MatrixS& operator-=(int);
    MatrixS& operator*=(int);


};




#endif