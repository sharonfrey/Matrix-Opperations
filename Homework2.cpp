#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;



class Mat22
{
	//the class for 2 by 2 matrices
public:

	Mat22(); // default constructor
	Mat22(int w, int x, int y, int z); // set the matrix as the input
	Mat22(const Mat22 &x); // copy constructor


	void operator=(const Mat22 &x); // assignment operator
	Mat22 operator+(const Mat22 &x);// add two matrices
	Mat22 operator-(const Mat22 &x);// similar as above
	Mat22 operator*(const Mat22 &x);// matrix multiplication


	Mat22 fastexp(int n, Mat22 one);// compute matrix to the power of n
	void display(ostream &out);// print the matrix, whatever way you like as long as it makes sense
	void input(ifstream &in);//use in to get user input for the matrix

	int display();//used for the fib sequence

private:

	int a, b, c, d;// store matrix  [a,b]
				   //               [c,d]


};

//implement operator<< and operator>> so that the following operations are possible
// cout << a and  cin >> a
// make sure they can be chained
ostream &operator<< (ostream &out, Mat22 &x);
istream &operator>> (istream &in, Mat22 &x);

int FastFib(int n);//implement the Fast Fibonacci function


int main()
{
	//Executing tasks 6: testing function code
	ifstream in;
	in.open("matrix.txt"); //function prototype given calls for a txt file which i have created myself in my program folder
	Mat22 one;
	one.input(in);
	cout << "One:" << endl << one << endl;

	Mat22 two;
	cout << "Two:" << endl;
	cin >> two;

	Mat22 three = one;
	Mat22 four = one;
	Mat22 five = one;

	//Executing Task 2 & 3
	//Chaining with operator overload
	cout << endl << "Matrix Addition:" << endl << three + two
		<< endl << "Matrix Subtraction:"  << endl << four - two
		<< endl << "Matrix Multiplication:" << endl << five * two << endl;

	//Executing task 4
	cout << "Matrix One to the power of user input:  ";
	int n;
	cin >> n;
	cout << one.fastexp(n, one) << endl;

	//Executing task 5	
	cout << "Fbonacci Sequence for number:  ";
	cin >> n;
	cout << "Fibonacci number is :  " << FastFib(n) << endl << endl;
	
	//in.close();
	return 0;
}


//Task 1
Mat22::Mat22()
{
	cout << "New Matrix ";

}
Mat22::Mat22(int w, int x, int y, int z)
{
	a = w;
	b = x;
	c = y;
	d = z;
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
	a = a + x.a;
	b = b + x.b;
	c = c + x.c;
	d = d + x.d;
	return *this;
}
Mat22 Mat22::operator-(const Mat22 &x)
{
	a = a - x.a;
	b = b - x.b;
	c = c - x.c;
	d = d - x.d;
	return *this;
}
Mat22 Mat22::operator*(const Mat22 &x)
{
	
	int tempa = a;
	int tempc = c;

	int xa = x.a;
	int xb = x.b;
	int xc = x.c;
	int xd = x.d;

	a = a * xa + b * xc;
	b = tempa * xb + b * xd;
	c = c * xa + d * xc;
	d = tempc * xb + d * xd;
	return *this;
}
void Mat22::operator=(const Mat22 &x)
{
	a = x.a;
	b = x.b;
	c = x.c;
	d = x.d;
}

//Task 3
void Mat22::display(ostream &out)
{
	cout << a << "\t" << b << endl << c << "\t" << d << endl;
}
void Mat22::input(ifstream &in)
{
	in >> a >> b >> c >> d;
}
ostream &operator<< (ostream &out, Mat22 &x)
{
	x.display(out);
	return out;
}
istream &operator>> (istream &in, Mat22 &x)
{
	int a, b, c, d;
	cout << "1 X 1:  ";
	cin >> a;
	cout << "1 X 2:  ";
	cin >> b;
	cout << "2 X 1:  ";
	cin >> c;
	cout << "2 X 2:  ";
	cin >> d;
	Mat22 y(a, b, c, d);
	x = y;

	return in;
}

//Task 4
Mat22 Mat22::fastexp(int n, Mat22 one)
{
	if (n == 1)
	{
		return one;
	}
		
	if (n % 2 == 0)
	{
		return one.fastexp(n / 2, one * one);
	}
	if (n % 2 != 0)
	{
		Mat22 x = one;
		return x * one.fastexp((n - 1) / 2, one * one);
	}
}

//Task 5
int FastFib(int n)
{
	Mat22 fib(1, 1, 1, 0);
	if (n == 0)
		return 0;
	fib = fib.fastexp(n-1, fib);
	return fib.display();
}
int Mat22::display()
{
	return a;
}



