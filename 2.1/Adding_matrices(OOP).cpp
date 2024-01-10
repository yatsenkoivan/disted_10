#include <iostream>

class Matrix
{
    private:
        int x;
        int y;
        
        int** arr;
        
        
    public:
        Matrix(int y, int x) : y{y}, x{x}
        {
            arr = new int*[y];
            for (int i=0; i<y; i++)
            {
                arr[i] = new int[x]{};
            }
        }
        Matrix() : Matrix(0,0) {}
        Matrix(const Matrix& m) : y{m.size_y()}, x{m.size_x()}
        {
            arr = new int*[y];
            for (int i=0; i<y; i++)
            {
                arr[i] = new int[x]{};
                for (int j=0; j<x; j++)
                {
                    arr[i][j] = m.arr[i][j];
                }
            }
        }
        ~Matrix()
        {
            for (int i=0; i<y; i++)
            {
                delete[] arr[i];
            }
            delete[] arr;
        }
        int size_x() const
        {
            return x;
        }
        int size_y() const
        {
            return y;
        }
        friend std::istream& operator>>(std::istream& in, Matrix& m)
        {
            for (int i=0; i<m.size_y(); i++)
            {
                for (int j=0; j<m.size_x(); j++)
                {
                    in >> m.arr[i][j];
                }
            }
            return in;
        }
        friend std::ostream& operator<<(std::ostream& out, const Matrix& m)
        {
            for (int i=0; i<m.size_y(); i++)
            {
                for (int j=0; j<m.size_x(); j++)
                {
                    out << m.arr[i][j] << ' ';
                }
                out << '\n';
            }
            return out;
        }
        friend Matrix operator+(const Matrix& m1, const Matrix& m2)
        {
            if (m1.size_x() != m2.size_x() || m1.size_y() != m2.size_y()) return Matrix();
            Matrix res(m1.size_y(), m1.size_x());
            for (int i=0; i<m1.size_y(); i++)
            {
                for (int j=0; j<m1.size_x(); j++)
                {
                    res.arr[i][j] = m1.arr[i][j] + m2.arr[i][j];
                }
            }
            return res;
        }
        friend Matrix operator*(const Matrix& m1, const Matrix& m2)
        {
            if (m1.size_x() != m2.size_y()) return Matrix();
            Matrix res(m1.size_y(), m2.size_x());
            
            for (int i=0; i<m1.size_y(); i++)
            {
                for (int j=0; j<m2.size_x(); j++)
                {
                    int temp = 0;
                    for (int k=0; k<m1.size_x(); k++)
                    {
                        temp += m1.arr[i][k]*m2.arr[k][j];
                    }
                    res.arr[i][j] = temp;
                }
            }
            return res;
        }
};

int main()
{
    int m, n;
    std::cin >> m >> n;
    Matrix a(m,n);
    Matrix b(m,n);
    
    std::cin >> a >> b;
    
    Matrix c(a+b);
    
    std::cout << c << '\n';
}
