#include<bits/stdc++.h>
using namespace std;

class Complex{
public:
	int real, imaginary;

public:
	Complex(int r, int i) {
		this->real = r;
		this->imaginary = i;
	}

	Complex operator +(const Complex &other) {
		return Complex(real + other.real, imaginary + other.imaginary); 
	}
};

ostream& operator <<(ostream &o, const Complex &c) {
	o << c.real << " + " << c.imaginary << "i";
}

Complex operator -(const Complex &me, const Complex &other) {
	return Complex(me.real - other.real, me.imaginary - other.imaginary); 
}

int x(int a, int b) {
	if(b == 0) {
		throw "Div by zero!";
	}
	return a/b;
}

int main() {
	Complex c1(5,10);
	Complex c2(10,20);
	c1 = c1 + c2;
	cout << c1 << endl;
	c1 = c1 - c2;
	cout << c1 << endl;
	try {
		int y = x(2,0);
	} catch(const char* e) {
		cout << e << endl;
	}
	cout << "over" << endl;
}