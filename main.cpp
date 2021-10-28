#include <iostream>
using namespace std;

class IntArray{
private:
    int* m_data;
    int m_len;
public:
    /*IntArray(char) = delete;
    IntArray(int) = delete;*/
    explicit IntArray(int = 0, int = 0);
    IntArray(IntArray const &);
    ~IntArray();
    void print();
    void set(int, int);
    friend void reverse(const IntArray&);
    friend void negative(const IntArray&);
    friend void multiply(const IntArray&, int);
};
IntArray::IntArray(int size, int init) {
    if (size <= 0){
        m_data = nullptr;
        m_len = 0;
    }
    else {
        m_data = new int[size];
        m_len = size;
        for (int idx = 0; idx < m_len; ++idx)
            *(m_data + idx) = init;
    }
}
IntArray::IntArray(IntArray const &copy) {
    m_data = new int[copy.m_len];
    m_len = copy.m_len;
    for (int idx = 0; idx < m_len; ++idx)
        *(m_data + idx) = *(copy.m_data + idx);
}
IntArray::~IntArray() {
    delete[]m_data;
}
void IntArray::print() {
    for (int idx = 0; idx < m_len; ++idx){
        cout << *(m_data + idx) << ' ';
    }
    cout << endl;
}
void IntArray::set(int idx, int value) {
    for (int i = 0; i < m_len; i++){
        if (i == idx)
            *(m_data + i) = value;
    }
}
void reverse(const IntArray &arr) {
    int temp;
    for(int i = 0; i < arr.m_len/2; i++ ){
        temp = *(arr.m_data + i);
        *(arr.m_data + i) = *(arr.m_data + arr.m_len - i - 1);
        *(arr.m_data + arr.m_len - i - 1) = temp;
    }
}
void negative(const IntArray &arr) {
    for(int i = 0; i < arr.m_len; i++)
        *(arr.m_data+i) *= -1;
}
void multiply(const IntArray &arr, int multiplier) {
    for(int i = 0; i < arr.m_len; i++)
        *(arr.m_data+i) *= multiplier;
}

int main() {
    cout << "a1: ";
    IntArray a1{10, 100};
    a1.print();

    cout << "a2: ";
    IntArray a2{a1};
    a2.set (1, 999);
    a2.set (9, 123);
    reverse(a2);
    negative(a2);
    multiply(a2, 3);
    a2.print();
    return 0;
}
