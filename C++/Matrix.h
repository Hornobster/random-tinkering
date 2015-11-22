//
// Created by Carlo Vespa on 22/11/15.
//

#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>
#include <iostream>

template<class T>
class Matrix {
public:
    Matrix(size_t width, size_t height);

    ~Matrix();

    T *operator[](const size_t) const;

    friend std::ostream &operator<<(std::ostream & ostream, const Matrix<T> & matrix) {
        for (size_t i = 0; i < matrix._height; i++) {
            for (size_t j = 0; j < matrix._width; j++) {
                ostream << matrix[i][j];
                if (j != matrix._width - 1)
                    ostream << "\t";
            }
            ostream << std::endl;
        }

        return ostream;
    }

    void clear(T);

    size_t getWidth() const { return _width; }

    size_t getHeight() const { return _height; }

private:
    T *_matrix;
    size_t _width;
    size_t _height;
};

template<class T>
Matrix<T>::Matrix(size_t width, size_t height) {
    _matrix = new T[width * height];
    _width = width;
    _height = height;
}

template<class T>
Matrix<T>::~Matrix() {
    delete _matrix;
}

template<class T>
T *Matrix<T>::operator[](const size_t i) const {
    return _matrix + i * _width;
}

template<class T>
void Matrix<T>::clear(T t) {
    for (T *it = _matrix; it < _matrix + _height * _width; it++)
        *it = T(t);
}

#endif // MATRIX_H
