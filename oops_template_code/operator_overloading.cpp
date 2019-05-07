#include <bits/stdc++.h>

using  namespace std;

template <typename T>
class Complex {
private:
	T real, imaginary;
public:
	Complex(T real, T imaginary) {
		this->real = real;
		this->imaginary = imaginary;
	}

	Complex operator +(Complex &other) {
		return Complex(this->real + other.real, this->imaginary + other.imaginary);
	}

	Complex operator -(Complex &other) {
		return Complex(this->real - other.real, this->imaginary - other.imaginary);
	}

	friend ostream& operator <<(ostream &obj, Complex<T> &c);
};

ostream& operator << (ostream &obj, Complex<int> &c) {
	obj << c.real << " + " << c.imaginary << "i" << endl;
}



int main() {
	Complex<int> c1(10,20);
	Complex<int> c2(20,30);
	Complex<int> c3 = c1 + c2 - c1;
	cout << c3 << endl;
}
