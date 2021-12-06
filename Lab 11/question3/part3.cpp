#include <iostream>
#include <vector>

class Matrix
{
public:
    std::vector<std::vector<int>> matrixHolder;
    int x;
    int y;

    Matrix()
    {
        int num = 1;
        x = 3;
        y = 3;
        for (int i = 0; i < x; i++)
        {
            std::vector<int> tmp;
            for (int j = 0; j < y; j++)
            {
                tmp.push_back(num);
                num += 1;
            }
            matrixHolder.push_back(tmp);
        }
    }
    friend std::ostream &operator<<(std::ostream &out, const Matrix &m);
    // adding two matrices together operator+(const Matrix&, const Matrix&) doesnt work
    Matrix operator+(const Matrix &n)
    {
        Matrix tmp;
        for (int i = 0; i < n.x; i++)
        {
            for (int j = 0; j < n.y; j++)
            {
                tmp.matrixHolder[i][j] = matrixHolder[i][j] + n.matrixHolder[i][j];
            }
        }
        return tmp;
    };
    // multiplying matrix by vector (const Matrix &m, const std::vector<int> *v) doesnt work
    Matrix operator*(const std::vector<int> *v)
    {
        Matrix tmp;
        //std::cout << tmp.matrixHolder[1][0] << std::endl;
        int count = 0;
        int tmp2 = 0;
        int tmp3 = 0;
        tmp.y = 1;
        std::vector<int> tmp4;
        for (int k = 0; k < x; k++)
        {
            for (int i = 0; i < x; i++)
            {
                tmp2 = matrixHolder[k][i] * v->at(i);
                tmp3 += tmp2;
                for (int j = 0; j < y; j++)
                {
                    if (i == x - 1)
                    {
                        tmp.matrixHolder[k][j] = tmp3;
                    }
                }

                //}
            }
            tmp3 = 0;
        }
        //std::cout << tmp << std::endl;
        return tmp;
    }; // 14, 32, 50
    // multiplying matrix by matrix (const Matrix &m, const Matrix &n) doesnt work
    Matrix operator*(const Matrix &n)
    {
        Matrix tmp;
        for (int i = 0; i < n.x; i++)
        {
            for (int j = 0; j < n.x; j++)
            {
                for (int k = 0; k < n.y; k++)
                {
                    tmp.matrixHolder[i][j] += matrixHolder[i][k] * n.matrixHolder[k][j];
                }
            }
        }
        return tmp;
    };
};

std::ostream &operator<<(std::ostream &out, const Matrix &m)
{
    for (int i = 0; i < m.x; i++)
    {
        for (int j = 0; j < m.y; j++)
        {
            out << m.matrixHolder[i][j] << " ";
        }
        out << std::endl;
    }
    return out;
}
int main()
{
    Matrix stuff;
    Matrix stuff2;

    std::cout << stuff;
    // std::cout << stuff2;

    Matrix stuff3;
    stuff3 = stuff2 + stuff;
    std::cout << stuff3;

    std::vector<int> data;
    for (int i = 0; i < 3; i++)
    {
        data.push_back(i + 1);
    }

    Matrix stuff4;
    stuff4 = stuff * &data;
    std::cout << stuff4;

    Matrix stuff5;
    std::cout << stuff5;
    stuff5 = stuff5 * stuff;
    std::cout << stuff5;
    return 0;
}

// https://www.geeksforgeeks.org/vector-of-vectors-in-c-stl-with-examples/
// https://www.programiz.com/cpp-programming/operator-overloading
// https://stackoverflow.com/questions/6946217/how-to-access-the-contents-of-a-vector-from-a-pointer-to-the-vector-in-c
// https://hadrienj.github.io/posts/Deep-Learning-Book-Series-2.2-Multiplying-Matrices-and-Vectors/
// https://www.mathsisfun.com/algebra/matrix-multiplying.html
// https://www.geeksforgeeks.org/c-program-multiply-two-matrices/
// TA looked the code and says it looks good