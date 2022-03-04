
#include <iostream>
using namespace std;

class Vector
{
private:
    int size;
    int currentSize; // required for push operataion to see if space is present or new space has to be allocated
    int *vecArray;

public:
    Vector(int);
    ~Vector();

    friend istream &operator>>(istream &input, Vector &obj)
    {
        input >> *(obj.vecArray);
        return input;
    }

    friend ostream &operator<<(ostream &output, Vector obj)
    {
        output << obj.vecArray;
        return output;
    }

    int &operator[](int index)
    {
        if (index >= size)
        {
            cout << "Array index out of bound, exiting";
            exit(0);
        }
        return vecArray[index];
    }

    float operator*(float x1)
    {
        return x1 * (*vecArray);
    }

    void pushBack(int x)
    {
        if (currentSize == size)
        {
            int temp[size];
            for (size_t i = 0; i < size; i++)
            {
                temp[i] = vecArray[i];
            }
            size++;
            currentSize++;
            delete[] vecArray;
            vecArray = new int[size];
            for (size_t i = 0; i < size - 1; i++)
            {
                vecArray[i] = temp[i];
            }
            vecArray[size - 1] = x;
        }
        else
        {
            vecArray[currentSize] = x;
            currentSize++;
        }
    }

    int pop()
    {
        int temp = vecArray[currentSize - 1];
        vecArray[currentSize - 1] = 0;
        currentSize--;
        return temp;
    }
};

Vector::Vector(int size = 0)
{
    this->size = size;
    this->currentSize = size;
    vecArray = new int[size];
    for (size_t i = 0; i < size; i++)
    {
        vecArray[i] = 0;
    }
}

Vector::~Vector()
{
    delete[] vecArray;
}

int main()
{
    Vector v1(10);
    v1[1] = 10;
    cout << "Enter v1[1] and v2[2]"<<endl;
    cin >> v1[1] >> v1[2];
    cout << v1[1] << " " << v1[2] << endl;
    v1[2] = 2 * v1[2];
    cout << v1[2] << endl;
    // cout << v1[11];
    v1.pushBack(10);
    cout << v1[10] << endl;
    cout << v1.pop() << endl;
    v1.pushBack(15);
    cout << v1[10] << endl;
    v1.pushBack(12);
    cout << v1[11] << endl;
    return 0;
}