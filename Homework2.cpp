#include <iostream>
#include <cmath>
using namespace std;



class Mat22
{
	//the class for 2 by 2 matrices
public:

	Mat22(); // default constructor
	Mat22(int a, int b, int c, int d); // set the matrix as the input
	Mat22(const Mat22 &x); // copy constructor


	void operator=(const Mat22 &x); // assignment operator
	Mat22 operator+(const Mat22 &x);// add two matrices
	Mat22 operator-(const Mat22 &x);// similar as above
	Mat22 operator*(const Mat22 &x);// matrix multiplication

	Mat22 fastexp(int n);// compute matrix to the power of n
	void display(ostream &out);// print the matrix, whatever way you like as long as it makes sense
	void input(ifstream &in);//use in to get user input for the matrix

private:

	int a, b, c, d;// store matrix  [a,b]
				   //               [c,d]


};


//implement operator<< and operator>> so that the following operations are possible
// cout << a and  cin >> a
// make sure they can be chained

int FastFib(int n);//implement the Fast Fibonacci function


int main()
{
	Mat22 one;
	Mat22 two;
	Mat22 three = one;
	three = three + two;
	Mat22 four = one;
	four = four - two;
	Mat22 five = one;
	five = five * two;
	
	
	
	
	return 0;
}


//Task 1
Mat22::Mat22()
{
	cout << "Please enter Matrix information" << endl;
	cout << "1 x 1:  ";
	cin >> a;
	cout << "1 x 2:  ";
	cin >> b;
	cout << "2 x 1:  ";
	cin >> c;
	cout << "2 x 2:  ";
	cin >> d;
	//Mat22(a, b, c, d);
}
Mat22::Mat22(int a, int b, int c, int d)
{
	//i have no idea what i am supposed to do with this yet

}
Mat22::Mat22(const Mat22 &x)
{
	a = x.a;
	b = x.b;
	c = x.c;
	d = x.d;
}

//Task 2
Mat22 Mat22::operator+(const Mat22 &x)
{
	cout << "Matrix Addition:" << endl;
	a = a + x.a;
	b = b + x.b;
	c = c + x.c;
	d = d + x.d;
	return *this;
}
Mat22 Mat22::operator-(const Mat22 &x)
{
	cout << "Matrix Subtraction:" << endl;
	a = a - x.a;
	b = b - x.b;
	c = c - x.c;
	d = d - x.d;
	return *this;
}
Mat22 Mat22::operator*(const Mat22 &x)
{
	cout << "Matrix division:" << endl;
	int tempa = a;
	int tempc = c;
	a = tempa * x.a + b * x.c;
	b = tempa * x.b + b * x.d;
	c = tempc * x.a + d * x.c;
	d = tempc * x.b + d * x.d;
	return *this;
}

void Mat22::operator=(const Mat22 &x)
{
	cout << x.a << "\t" << x.b << endl << x.c << "\t" << x.d << endl;
}
