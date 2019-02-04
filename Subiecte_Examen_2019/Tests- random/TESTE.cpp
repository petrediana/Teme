// TESTE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Invalid_number_ex : public exception {
public:
	string message() {
		return "Number of elements can't be negative!";
	}
};

class Number {
private:
	int x;
public:
	Number() { this->x = 0;}
	Number(int v_x) { this->x = v_x; }
	Number(const Number &copy) { this->x = copy.x; }
	Number &operator=(const Number &copy) {
		this->x = copy.x;
	return *this;
	}
	
	friend ostream &operator<<(ostream &out, Number &no) {
		out << "\n\tContent of class Number: ";
		out << "\nValue: " << no.x;

		return out;
	}
};

class Array {
private:
	int no_of_elements;
	Number  **numbers;

public:
	void set_no_of_elements(int new_no_elements) {
			this->no_of_elements = new_no_elements;
	}

	int get_no_of_elements() {
		return this->no_of_elements;
	}

	Array() {
		this->no_of_elements = 0;
		this->numbers = NULL;
	}

	Array(int no_elements, Number **v_numbers) {
		this->no_of_elements = no_elements;

		if (v_numbers != NULL) {
			this -> numbers = new Number*[no_of_elements];
			for (int i = 0; i < this->no_of_elements; i++)
				this->numbers[i] = v_numbers[i];
		}
	}

	Array(const Array &copy) {
		this->no_of_elements = copy.no_of_elements;

		if (copy.numbers != NULL) {
			this->numbers = new Number*[this->no_of_elements];
			for (int i = 0; i < this->no_of_elements; i++)
				this->numbers[i] = copy.numbers[i];
		}
	}
	Array &operator=(const Array &copy) {
		if (this->numbers != NULL) {
			for (int i = 0; i < this->no_of_elements; i++)
				delete[]this->numbers[i];
			delete[]this->numbers;
		}
		this->no_of_elements = copy.no_of_elements;

		if (copy.numbers != NULL) {
			this->numbers = new Number*[this->no_of_elements];
			
			for (int i = 0; i < this->no_of_elements; i++)
				this->numbers[i] = copy.numbers[i];
		}

		return *this;
	}

	friend ostream &operator<<(ostream &out, Array &arr) {
		out << "\n\tContent of Array class: ";
		out << "\nNumber of elements: " << arr.no_of_elements;
		out << "\nThe elements: ";
		for (int i = 0; i < arr.no_of_elements; i++)
			out << *(arr.numbers)[i]<< " ";

		return out;
	}

	Array &operator +=(Number x) {
		Number **aux_numbers;
		aux_numbers = new Number*[this->no_of_elements + 1];

		for (int i = 0; i < this->no_of_elements; i++) {
			aux_numbers[i] = new Number();
			*aux_numbers[i] = *this->numbers[i];
		}
		

		for (int i = 0; i < this->no_of_elements; i++)
			delete[] this->numbers[i];
		delete[] this->numbers;

		aux_numbers[this->no_of_elements] = new Number();

		*aux_numbers[this->no_of_elements] = x;
	
		this->numbers = aux_numbers;
		++this->no_of_elements;
		return *this;

	}
};

template <typename T>
class Temp_ARR {
private:
	string name;
	vector<T> numbers;
public:
	Temp_ARR() {
		this->name = "Anonim";
		this->numbers = vector<T>();
	}

	Temp_ARR(string v_name, vector<T> v_numbers) {
		if (v_name.length() > 0)
			this->name = v_name;
		this->numbers = v_numbers;
	}

	Temp_ARR(const Temp_ARR &copy) {
		if (copy.name.length() > 0)
			this->name = copy.name;

		this->numbers = copy.numbers;
	}

	void add_element(T new_element) {
		this -> numbers.push_back(new_element);
	}

	friend ostream &operator<<(ostream &out, Temp_ARR &tarr) {
		out << "\nName: " << tarr.name;
		out << "\nElements: ";
		
		for (int i = 0; i < tarr.numbers.size(); i++)
			out << tarr.numbers[i];

		return out;
	}
};


int main()
{
	Number x1(10);
	Number x2(11);
	Number x3(12);
	Number x4(13);
	

	//cout << x1 << x2 << x3;

	Number *arr[3] = { new Number(x1), new Number(x2), new Number(x3) };
	Array arr1(3, arr);
	Array arr2;
	//cout << "\nArr1 has: " << arr1.get_no_of_elements() << " elements\n";

	
	/*int values = 0; bool ok = true;
	do {
		try {
			cout << "\nInput how many values: "; cin >> values;
			arr2.set_no_of_elements(values);

			if (values > 0) {
				cout << "Arr2 has: " << arr2.get_no_of_elements() << " elements";
				ok = true;
			}
			else {
				throw Invalid_number_ex();

			}
		}
		catch (Invalid_number_ex &e) {
			cout << e.message();
			ok = false;
		}
	} while (!ok);*/
	
	//cout << arr1;
	//arr1 += x4;
	//cout << arr1;

	int key_count = 0;
	map <int, Number> mapNumber;
	mapNumber.insert(pair <int, Number>(key_count, x1));
	key_count++;
	mapNumber.insert(pair <int, Number>(key_count, x2));

	map <int, Number> ::iterator it;

	cout << "\nMap Number stuff: ";
	for (it = mapNumber.begin(); it != mapNumber.end(); it++) {
		cout << it->first << endl;
		cout << it->second << endl;
	}
	
	vector<Number> v_nrs;
	v_nrs.push_back(x1);
	v_nrs.push_back(x2);
	v_nrs.push_back(x3);

	Temp_ARR <Number> y("Random name", v_nrs);
	y.add_element(x4);
	cout << y;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
