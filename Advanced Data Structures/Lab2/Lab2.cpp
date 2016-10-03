/**************************
Justin Meeken
Thomas Nguyen
Tuesday, 2:15
**************************/

#include <iostream>
using namespace std;

// Interface
class Complex {
	private:
		double a,b;
	public:
        Complex ();
		Complex (double, double);
		double re();
		double im();
		void setRe(double);
		void setIm(double);
        friend Complex operator+(const Complex&, const Complex&);
        friend Complex operator*(const Complex&, const Complex&);
        friend istream& operator>>(istream&, Complex&);
        friend ostream& operator<<(ostream&, Complex&);
};

// Constructor that includes two arguments for real and imaginary
Complex :: Complex (double x, double y) {
	a = x;
	b = y;
}

// Default constructor when no arguments are passed
Complex :: Complex () {
	a = 0;
    b = 0;
}

// Get the real number
double Complex :: re () {
	return a;
}

// Get the imaginary number
double Complex :: im () {
	return b;
}

// Sets the real number to the argument passed
void Complex :: setRe (double x) {
	a = x;
}

// Sets the imaginary number to the argument passed
void Complex :: setIm (double x) {
	b = x;
}

// Overloads the addition operator to add two complex numbers
Complex operator+(const Complex& c1, const Complex& c2){
	Complex c3;
	c3.a = c1.a + c2.a;
	c3.b = c1.b + c2.b;
	return c3;
}

// Overloads the multiplication operator to multiply two complex numbers
Complex operator*(const Complex& c1, const Complex& c2){
	Complex c3;
	c3.a = c1.a*c2.a - c1.b*c2.b;
	c3.b = c1.a*c2.b + c1.b*c2.a;
	return c3;
}

// Overloads the output stream to work with complex numbers
ostream& operator<<(ostream& out, Complex& c1){
    out << c1.a << "+" << c1.b << "i";
    return out;
}

// Overloads the input stream to work with complex numbers
istream& operator>>(istream& in, Complex& c1){
    in >> c1.a;
    in >> c1.b;
    return in;
}

int main () {
	Complex c1;
    
	Complex c2(1.0,2.0);
	c1.setRe(3.0);
	
	Complex c3;
	c3 = c1 + c2;
	cout << c1 << endl; // 3+0
	cout << c2 << endl; // 1+2
	cout << c3 << endl; // 4+2

	c3 = c1 * c2;
	cout << c1 << endl; // 3+0
	cout << c2 << endl; // 1+2
	cout << c3 << endl; // 3 + 6i

	return 0;
}
