#include<iostream>
using namespace std;
class vector{

    private:
    int size;
    int currentsize;
    int *vectorarray;
    public:
    vector(int size);
    ~vector();
    friend ostream & operator <<(ostream &output,vector v);
    friend istream & operator >> (istream &input, vector v);
    int operator * (int x);
    void pushback(int t);
    int pop();
    int &operator[](int index)
    {
        if (index >= size)
        {
            cout << "Array index out of bound, exiting";
            exit(0);
        }
        return vectorarray[index];
    }

};
vector :: vector(int size=0){
    this->size=size;
    this->currentsize=size;
    vectorarray =  new int[size];
    for(int i=0;i<size;i++){
        vectorarray[i]=0;
    }
}
vector :: ~vector(){
    delete[] vectorarray; 
}
ostream & operator <<(ostream &output,vector v){
    output << v.vectorarray;
    return output;
}
istream & operator >>(istream &input, vector v){
    input >> *(v.vectorarray);
    return input;
}
void vector ::  pushback(int t)
{
    if (currentsize == size)
    {
        int array[size];
        for (int i = 0; i < size; i++)
        {
            array[i] = vectorarray[i];
        }
        size++;
        currentsize++;
        delete[] vectorarray;
        vectorarray = new int[size];
        for (int i = 0; i < size - 1; i++)
        {
            vectorarray[i] = array[i];
        }
        vectorarray[size - 1] = t;
    }
    else
    {
        vectorarray[currentsize] = t;
        currentsize++;
    }
}

int vector ::  pop()
{
    int temp = vectorarray[currentsize - 1];
    vectorarray[currentsize - 1] = 0;
    currentsize--;
    return temp;
}
int vector :: operator * (int x){
    return x*(*vectorarray);
}

int main()
{
    vector v1(10);
    v1[1] = 10;
    cout << "Enter value of v1[1] and v2[2]"<<endl;
    cin >> v1[1] >> v1[2];
    cout << v1[1] << " " << v1[2] << endl;
    v1[2] = 2 * v1[2];
    cout << v1[2] << endl;
    // cout << v1[11];
    v1.pushback(10);
    cout << v1[10] << endl;
    cout << v1.pop() << endl;
    v1.pushback(15);
    cout << v1[10] << endl;
    v1.pushback(12);
    cout << v1[11] << endl;
    return 0;
}