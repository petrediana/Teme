#include <iostream>
using namespace std;

class Array {
private:
    int no_of_elements;
    float *arr;

public:
    Array();
    Array(int no_of_elements, float *arr);
    Array(const Array &arr);
    ~Array();

    friend ostream &operator<<(ostream &out, const Array &arr);
    float operator[](int offset);
    Array &operator=(const Array &arr);
    Array &operator+=(const Array &arr);
    Array &operator-=(const Array &arr);
    float operator()(const Array &arr);
    bool operator==(const Array &arr);
    bool operator>(const Array &arr);
    bool operator<(const Array &arr);
    bool operator!();
    Array &operator-(float number);
    Array &operator+(float number);
    Array &operator++();
    Array operator++(int);
    Array &operator--();
    Array operator--(int);
    explicit operator double();
};
