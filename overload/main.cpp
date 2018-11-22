#include <bits/stdc++.h>
using namespace std;

class Array{
private:
    int no_of_elements;
    float *arr;

public:
    Array();
    Array(int no_of_elements, float *arr);
    Array(const Array &arr);
    ~Array();

    friend ostream &operator <<(ostream &out, Array arr);

    float operator[](int offset);

    Array &operator =(const Array& arr);
    Array &operator +=(const Array &arr);
    Array &operator -=(const Array &arr);

    float operator()(Array arr);

    bool operator ==(const Array arr);
    bool operator >(const Array arr);
    bool operator <(const Array arr);
    bool operator !();

    Array operator -(float number);
    Array operator +(float number);

    Array &operator ++();
    Array &operator ++(int);

    Array &operator --();
    Array &operator --(int);

    explicit operator double();


};


int main(){

    float vec[] = {11.0, 12.0, 13.0, 14.0};

    Array a(2, vec);
    Array c(2, vec);

    Array b(4, vec);
    Array d;
    //cout << a;

    //a = b;
    //cout << a;

    //a += b;
    //cout << a;

   // a -= b;
    //cout << a;

    //cout <<a(a);

    //cout << "Does a and c have the same length? ";
    //cout << (a == c);

    //cout << "\nDoes a have a bigger length than c? ";
    //cout << (a > c);

    //cout << "\nDoes c have a smaller length than a? ";
    //cout << (c < a);

   //c = a + 10;
    //cout << c;

    //c = a - 10;
    //cout << c;

    //cout << !d;
    //cout << a;
    //++ a;

    //cout << a ++;
    //cout << a;

    //cout << a;
    //-- a;
    //cout << a;
    //cout << (a--);
    //cout << a;


    return 0;
}
Array ::Array() {
    this -> no_of_elements = 0;
    this -> arr = NULL;
}

Array ::Array(int no_of_elements, float *arr) {
    this -> no_of_elements = no_of_elements;
    this -> arr = new float [no_of_elements];

    for(int i = 0 ; i < this ->no_of_elements; i++)
        this -> arr[i] = arr[i];
}

Array ::Array(const Array &arr){
    this -> no_of_elements = arr.no_of_elements;

    if(this -> arr != NULL)
        delete[] this -> arr;

    if(arr.no_of_elements > 0 && arr.arr != NULL){
        this -> arr = new float[arr.no_of_elements];
        for(int i = 0; i < arr.no_of_elements; i++)
            this -> arr[i] = arr.arr[i];
    }
}

Array ::~Array() {
    delete[] this -> arr;
}

ostream &operator <<(ostream &out, Array arr){
    out << "\tOperator << overload: ";
    out << "\nNumber of elements: " << arr.no_of_elements;
    out << "\nThe array: ";
    for(int i = 0; i < arr.no_of_elements; i++)
        out << arr.arr[i] << " ";
    out <<"\n\n";
    return out;
}

float Array ::operator[](int offset){
    if((this -> arr != NULL) && (offset >= 0) && (offset < this -> no_of_elements))
        return this -> arr[offset];
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

Array& Array ::operator=(const Array &arr) {
    if(this != &arr){
        this -> no_of_elements = arr.no_of_elements;
        delete[] this -> arr;

        this -> arr = new float [arr.no_of_elements];
        for(int i = 0; i < arr.no_of_elements; i++)
            this -> arr[i] = arr.arr[i];
    }
    cout<< "\n\tOperator = overload";
    return *this;
}

Array &Array ::operator+=(const Array &arr){
        if(this ->no_of_elements == arr.no_of_elements) {
            for (int i = 0; i < this->no_of_elements; i++)
                this->arr[i] += arr.arr[i];
        }
    cout << "\n\tOperator +=";
    return *this;
}

Array &Array ::operator -=(const Array &arr){
    if(this -> no_of_elements == arr.no_of_elements){
        for(int i = 0; i < no_of_elements; i++)
            this -> arr[i] -= arr.arr[i];
    }
    cout <<"\n\tOperator -=";
    return *this;
}

float Array ::operator()(Array arr){
    float sum = 0;
    if(arr.arr != NULL && arr.no_of_elements >= 0){
        for(int i = 0; i < arr.no_of_elements; i++)
            sum += arr.arr[i];
    }
    cout<<"\n\tOperator ()";
    return sum;
}

bool Array ::operator ==(const Array arr){
    if(this -> no_of_elements == arr.no_of_elements)
        return true;
    else
        return false;
}

bool Array ::operator >(const Array arr){
    if(this -> no_of_elements > arr.no_of_elements)
        return true;
    else
        return false;
}

bool Array ::operator <(const Array arr){
    if(this -> no_of_elements < arr.no_of_elements)
        return true;
    else
        return false;
}

bool Array ::operator !(){
    if(this -> no_of_elements < 0)
        return true;
    else
        return false;
}

Array Array ::operator -(float number){
    for(int i = 0; i < this -> no_of_elements; i++)
        this -> arr[i] -= number;

    cout << "\n\tOperator - ";
    return *this;
}

Array Array ::operator +(float number){
    for(int i = 0; i < this -> no_of_elements; i++)
        this -> arr[i] += number;

    cout << "\n\tOperator + ";
    return *this;
}

Array &Array ::operator++() {
    for (int i = 0; i < this->no_of_elements; i++)
        this->arr[i]++;
    return *this;
}

Array &Array ::operator++(int){
    Array copie = *this;

    for (int i = 0; i < this->no_of_elements; i++)
        this->arr[i]++;

    return copie;
}

Array &Array ::operator --(){
    for (int i = 0; i < this->no_of_elements; i++)
        this->arr[i] --;

    return *this;
}

Array &Array ::operator--(int){
    Array copie = *this;

    for (int i = 0; i < this->no_of_elements; i++)
        this->arr[i]--;

    return copie;
}

Array ::operator double(){
    return this -> no_of_elements;
}
