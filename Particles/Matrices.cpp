#include "Matrices.h"
#include <cmath>

using namespace std;

namespace Matrices
{
    Matrix::Matrix(int _rows, int _cols)
    {
        rows = _rows;
        cols = _cols;
        a.resize(rows);
        for (size_t i = 0; i < rows; i++)
        {
            a[i].resize(cols);
            for (size_t j = 0; j < cols; j++)
            {
                a[i][j] = 0;
            }
        }
        a.resize(rows, vector<double>(cols, 0));
    }

    ostream& operator<<(ostream& os, const Matrix& a)
    {
        for (int i = 0; i < a.getRows(); i++)
        {
            for (int j = 0; j < a.getCols(); j++)
            {
                os << setw(15) << a(i, j) << " ";
            }
            os << endl;
        }
        return os;
    }

    Matrix operator+(const Matrix& a, const Matrix& b)
    {
        if (a.getCols() != b.getCols() || a.getRows() != b.getRows())
        {
            throw runtime_error("Error: dimensions don't match");
        }
        Matrix c(a.getRows(), a.getCols());
        for (int i = 0; i < a.getRows(); i++)
        {
            for (int j = 0; j < a.getCols(); j++)
            {
                c(i, j) = a(i, j) + b(i, j);
            }
        }
        return c;
    }

    Matrix operator*(const Matrix& a, const Matrix& b)
    {
        if (a.getCols() != b.getRows())
        {
            throw runtime_error("Error: dimensions must agree");
        }
        Matrix d(b.getRows(), b.getCols());
        for (int i = 0; i < a.getRows(); i++)
        {
            for (int j = 0; j < b.getCols(); j++)
            {
                for (int k = 0; k < a.getCols(); k++)
                {
                    d(i, j) += a(i, k) * b(k, j);
                }
            }
        }
        return d;
    }

    bool operator==(const Matrix& a, const Matrix& b)
    {
        if (a.getCols() != b.getCols() || b.getCols() != b.getCols())
        {
            return false;
        }
        for (int i = 0; i < a.getRows(); i++)
        {
            for (int j = 0; j < a.getCols(); j++)
            {
                if (fabs(a(i, j) - b(i, j)) < 0.001)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }

    bool operator!=(const Matrix& a, const Matrix& b)
    {
        if (a.getCols() == b.getCols() || b.getCols() == b.getCols())
        {
            return false;
        }
        for (int i = 0; i < a.getRows(); i++)
        {
            for (int j = 0; j < a.getCols(); j++)
            {
                if (fabs(a(i, j) - b(i, j)) < 0.001)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
        }
    }
}
