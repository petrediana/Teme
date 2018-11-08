#include <iostream>
using namespace std;

class Student{
private:
    float *scores;

public:
    Student();
    void input(float *scores);
    float calculateTotalScore();
    ~Student();
};


int main() {

    int n, i, j, count = 0;
    float total[5], max;
    cout << "Enter number of students: ";
    cin >> n;

    float scores[5];
    Student *students = new Student[n];

    cout << "\tEnter grades: ";
    cout << endl;
    for(i = 0; i < n; i++){
        cout << "Grades for student " << i << " : ";
        for(j = 0; j < 5; j++){
            cin >> scores[j];
           // cout << scores[j] << " ";
        }

        students[i].input(scores);

        total[i] = students[i].calculateTotalScore();
        //cout << total[i] << " ";
    }
    max = total[0];

    for(i = 1; i < n; i++){
        if(max  < total[i])
            count  = i;
    }

    if(count == 0)
        cout << "Kristen has the higher score!";
    else
        cout << "\nThe student " << count << " has the best score";


    delete[] students;
    return 0;
}

Student ::Student() {
    this -> scores = NULL;
}

void Student ::input(float *scores) {
    if(scores != NULL){
        this -> scores = new float [5];
        for(int i = 0; i < 5; i++){
            if(scores[i] > 0)
                this -> scores[i] = scores[i];
        }
    }
}

float Student ::calculateTotalScore() {
    float sum = 0;
    for(int i = 0; i < 5; i++) {
        sum += (this -> scores[i]);
        //cout << sum << " ";
    }

    return sum;
}

Student ::~Student() {
    delete[] this -> scores;
   // cout << "\n\n\tDestroyed";
}