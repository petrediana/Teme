#include "Array.h"

Array::Array(int no_of_elements, float *arr) {
    cout << "inside constructor, something: ";
    this->no_of_elements = no_of_elements;
    this->arr = new float[no_of_elements];

    for (int i = 0; i < this->no_of_elements; i++)
        this->arr[i] = arr[i];
}

Array::Array() {
    this->no_of_elements = 0;
    this->arr = NULL;
}

Array::Array(const Array &arr) {
    this->no_of_elements = arr.no_of_elements;

    if (arr.no_of_elements > 0 && arr.arr != NULL) {
        this->arr = new float[arr.no_of_elements];
        for (int i = 0; i < arr.no_of_elements; i++)
            this->arr[i] = arr.arr[i];
    }
}

Array::~Array() {
    if (this->arr != NULL)
        delete[] this->arr;
}

ostream &operator<<(ostream &out, const Array &arr) {
    out << "\tOperator << overload: ";
    out << "\nNumber of elements: " << arr.no_of_elements;
    out << "\nThe array: ";
    for (int i = 0; i < arr.no_of_elements; i++)
        out << arr.arr[i] << " ";
    out << "\n\n";
    return out;
}

float Array::operator[](int offset) {
    if ((this->arr != NULL) && (offset >= 0) && (offset < this->no_of_elements))
        return this->arr[offset];
    else
        return -1;

}

/*
Array& Array ::operator=(Array& arr){
    this -> no_of_elements = arr.no_of_elements;

    delete[] this -> arr;
    this -> arr = new float [arr.no_of_elements];
    for(int i = 0; i < arr.no_of_elements; i++)
        this -> arr[i] = arr.arr[i];

    return *this;
}*/

Array &Array::operator=(const Array &arr) {
    if (this != &arr) {
        this->no_of_elements = arr.no_of_elements;
        delete[] this->arr;

        this->arr = new float[arr.no_of_elements];
        for (int i = 0; i < arr.no_of_elements; i++)
            this->arr[i] = arr.arr[i];
    }
    cout << "\n\tOperator = overload";
    return *this;
}

Array &Array::operator+=(const Array &arr) {
    if (this->no_of_elements == arr.no_of_elements) {
        for (int i = 0; i < this->no_of_elements; i++)
            this->arr[i] += arr.arr[i];
    }
    cout << "\n\tOperator +=";
    return *this;
}

Array &Array::operator-=(const Array &arr) {
    if (this->no_of_elements == arr.no_of_elements) {
        for (int i = 0; i < no_of_elements; i++)
            this->arr[i] -= arr.arr[i];
    }
    cout << "\n\tOperator -=";
    return *this;
}

float Array::operator()(const Array &arr) {
    float sum = 0;
    if (arr.arr != NULL && arr.no_of_elements >= 0) {
        for (int i = 0; i < arr.no_of_elements; i++)
            sum += arr.arr[i];
    }
    cout << "\n\tOperator ()";
    return sum;
}

bool Array::operator==(const Array &arr) {
    if (this->no_of_elements == arr.no_of_elements)
        return true;
    else
        return false;
}

bool Array::operator>(const Array &arr) {
    if (this->no_of_elements > arr.no_of_elements)
        return true;
    else
        return false;
}

bool Array::operator<(const Array &arr) {
    if (this->no_of_elements < arr.no_of_elements)
        return true;
    else
        return false;
}

bool Array::operator!() {
    if (this->no_of_elements < 0)
        return true;
    else
        return false;
}

Array &Array::operator-(float number) {
    for (int i = 0; i < this->no_of_elements; i++)
        this->arr[i] -= number;

    cout << "\n\tOperator - ";
    return *this;
}

Array &Array::operator+(float number) {
    for (int i = 0; i < this->no_of_elements; i++)
        this->arr[i] += number;

    cout << "\n\tOperator + ";
    return *this;
}

Array &Array::operator++() {
    for (int i = 0; i < this->no_of_elements; i++)
        this->arr[i]++;
    return *this;
}

Array Array::operator++(int) {
    Array copie = *this;

    for (int i = 0; i < this->no_of_elements; i++)
        this->arr[i]++;

    return copie;
}

Array &Array::operator--() {
    for (int i = 0; i < this->no_of_elements; i++)
        this->arr[i]--;

    return *this;
}

Array Array::operator--(int) {
    Array copie = *this;

    for (int i = 0; i < this->no_of_elements; i++)
        this->arr[i]--;

    return copie;
}

Array::operator double() {
    return this->no_of_elements;
}
