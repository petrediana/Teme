#include <iostream>
#include "Array.h"

using namespace std;

/*
void something(int count, float *arr) {
    for (int i = 0; i < count; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
*/

int main() {

    float vec[] = {11.0, 12.0, 13.0, 14.0};

    // something(2, vec);

    Array a = Array(2, vec);
    Array c(2, vec);

    Array b(4, vec);
    Array d;
    cout << a;

    a = b;
    cout << a;

    a += b;
    cout << a;

    a -= b;
    cout << a;

    cout << a(a);

    cout << "Does a and c have the same length? ";
    cout << (a == c);

    cout << "\nDoes a have a bigger length than c? ";
    cout << (a > c);

    cout << "\nDoes c have a smaller length than a? ";
    cout << (c < a);

    c = a + 10;
    cout << c;

    c = a - 10;
    cout << c;

    cout << !d;
    cout << a;
    ++a;

    cout << a++;
    cout << a;

    cout << a;
    --a;
    cout << a;
    cout << (a--);
    cout << a;


    return 0;
}
