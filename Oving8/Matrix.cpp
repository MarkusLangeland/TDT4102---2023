
#include "Matrix.h"
#include <cassert>
#include <iostream>

Matrix::Matrix(int nRows, int nColumns)
{
    assert(nRows > 0);    // Check if row greater or equal to 1, if not throw an error
    assert(nColumns > 0); // Check if columns greater or equal to 1, if not throw an error
    rows = nRows;
    columns = nColumns;

    matrix = new double *[rows];
    for (int row = 0; row < rows; row++)
    {
        matrix[row] = new double[columns];
        for (int col = 0; col < columns; col++)
        {
            matrix[row][col] = 0.0;
        }
    }
}

Matrix::Matrix(int nRows) : Matrix(nRows, nRows)
{
    for (int row = 0; row < nRows; row++)
    {
        matrix[row][row] = 1.0;
    }
}

Matrix::~Matrix()
{
    for (int row = 0; row < rows; row++)
    {
        delete[] matrix[row];
        matrix[row] = nullptr;
    }
    delete[] matrix;
    matrix = nullptr;
}

double Matrix::get(int row, int col) const
{
    return matrix[row][col];
}
void Matrix::set(int row, int col, double value)
{
    matrix[row][col] = value;
}

double *Matrix::operator[](int row)
{
    assert(row >= 0);
    assert(row < rows);
    return matrix[row];
}

int Matrix::getRows() const
{
    return rows;
}
int Matrix::getColumns() const
{
    return columns;
}

std::ostream &operator<<(std::ostream &os, const Matrix &m)
{
    for (int row = 0; row < m.getRows(); row++)
    {
        for (int col = 0; col < m.getColumns(); col++)
        {
            os << m.get(row, col) << "\t";
        }
        os << "\n";
    }
    return os;
}

Matrix::Matrix(const Matrix &rhs) : Matrix(rhs.getRows(), rhs.getColumns())
{
    for (int row = 0; row < rhs.getRows(); row++)
    {
        for (int col = 0; col < rhs.getRows(); col++)
        {
            matrix[row][col] = rhs.get(row, col);
        }
    }
}

Matrix &Matrix::operator=(Matrix m)
{
    std::swap(this->rows, m.rows);
    std::swap(this->columns, m.columns);
    std::swap(this->matrix, m.matrix);

    return *this;
}

Matrix &Matrix::operator+=(const Matrix &m)
{
    assert(this->getRows() == m.getRows());
    assert(this->getColumns() == m.getColumns());
    for (int row = 0; row < m.getRows(); row++)
    {
        for (int col = 0; col < m.getRows(); col++)
        {
            this->matrix[row][col] = m.matrix[row][col] + this->matrix[row][col];
        }
    }
    return (*this);
}

Matrix Matrix::operator+(const Matrix &m) const
{
    assert(this->getRows() == m.getRows());
    assert(this->getColumns() == m.getColumns());
    return Matrix{*this} += m;
}

Matrix &Matrix::operator-=(const Matrix &m)
{
    assert(this->getRows() == m.getRows());
    assert(this->getColumns() == m.getColumns());
    for (int row = 0; row < m.getRows(); row++)
    {
        for (int col = 0; col < m.getRows(); col++)
        {
            this->matrix[row][col] = m.matrix[row][col] - this->matrix[row][col];
        }
    }
    return (*this);
}

Matrix Matrix::operator-(const Matrix &m) const
{
    assert(this->getRows() == m.getRows());
    assert(this->getColumns() == m.getColumns());
    return Matrix{*this} -= m;
}


Matrix &Matrix::operator*=(const Matrix &m)
{
    assert(this->getRows() == m.getRows());
    assert(this->getColumns() == m.getColumns());
    for (int row = 0; row < m.getRows(); row++)
    {
        for (int col = 0; col < m.getRows(); col++)
        {
            this->matrix[row][col] = m.matrix[row][col] * this->matrix[row][col];
        }
    }
    return (*this);
}

Matrix Matrix::operator*(const Matrix &m) const
{
    assert(this->getRows() == m.getRows());
    assert(this->getColumns() == m.getColumns());
    return Matrix{*this} *= m;
}