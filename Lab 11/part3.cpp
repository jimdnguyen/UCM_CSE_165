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

        int count = 0;
        int tmp2 = 0;
        int tmp3 = 0;
        tmp.y = 1;
        y = 1;
        for (int i = 0; i < x; i++)
        {
            // std::cout << matrixHolder[0][i] << std::endl;
            // std::cout << v->at(i) << std::endl;
            tmp2 = matrixHolder[2][i] * v->at(i);
            tmp3 += tmp2;
            std::cout << tmp2 << std::endl;
            count++;
        }
        tmp.matrixHolder[0][0] = tmp3;
        std::cout << tmp3 << std::endl;
        return tmp;
    };                                 // 14, 32, 50
    Matrix operator*(const Matrix &n); // multiplying matrix by matrix (const Matrix &m, const Matrix &n) doesnt work
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
    return 0;
}

// https://www.geeksforgeeks.org/vector-of-vectors-in-c-stl-with-examples/
// https://www.programiz.com/cpp-programming/operator-overloading
// https://stackoverflow.com/questions/6946217/how-to-access-the-contents-of-a-vector-from-a-pointer-to-the-vector-in-c