#pragma once
#include <iostream>

class Matrix
{
private:
    int rows;
    int columns;
    double **matrix;

public:
    Matrix(int nRows, int nColumns);
    explicit Matrix(int nRows);
    ~Matrix();
    Matrix(const Matrix &rhs);

    Matrix &operator=(Matrix m);
    Matrix &operator+=(const Matrix &m);
    Matrix operator+(const Matrix &m) const;

    Matrix &operator-=(const Matrix &m);
    Matrix operator-(const Matrix &m) const;

    Matrix &operator*=(const Matrix &m);
    Matrix operator*(const Matrix &m) const;

    double get(int row, int col) const;
    void set(int row, int col, double value);

    double *operator[](int row);

    int getRows() const;
    int getColumns() const;

    // void operator<<(Matrix matrix);

    friend std::ostream &operator<<(std::ostream &os, const Matrix &m);
};
