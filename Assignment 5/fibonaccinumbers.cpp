#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

//Naive recursive
int fib_1 (int n ) {
    if ( n <= 1)
    return n;
    return fib_1(n-1) + fib_1 (n-2);
}

//Bottom up approach
int fib_2 (int n) {
	long long fibTable[n+1];
	fibTable[0] = 0;
	fibTable[1] = 1;
	for(int i = 2; i<=n; i++){
		fibTable[i] = fibTable[i-1]+ fibTable[i-2];
	}
	return fibTable[n];
}

//Closed-Form
long double fib_3(int n)
{
	long double phi = (1+sqrt(5))/2;
	return round((pow(phi,n))/sqrt(5));
}

//Matrix representation

//Multiplying two matrices
void multiply (long long A[2][2], long long B[2][2]) {
  long long x = A[0][0] * B[0][0] + A[0][1] * B[1][0];
  long long y = A[0][0] * B[0][1] + A[0][1] * B[1][1];
  long long z = A[1][0] * B[0][0] + A[1][1] * B[1][0];
  long long w = A[1][0] * B[0][1] + A[1][1] * B[1][1];
  A[0][0] = x;
  A[0][1] = y;
  A[1][0] = z;
  A[1][1] = w;
}

//Calculating power of a matrix
void power (long long A[2][2], int n ) {
  if (n == 0 || n == 1)
  return;
  long long C[2][2] = {{1,1},{1,0}};
  power (A, n/2);
  multiply (A,A);
  if (n%2 != 0)
  multiply(A,C);
}


//Matrix representation: Function that returns nth Fibonacci number
long long fib_4 (int n) {
  long long A[2][2] = {{1,1},{1,0}};
  if (n==0)
  return 0;
  power (A, n-1);
  return A[0][0];
}


int main () {
    int n; 
    clock_t begin, end;

   while (true) {

    cin >> n;

    cout << "The " << n << "th number in the Fibonacci series is :" << endl;
    
    cout<< "Using naive recursion: "<< fib_1(n) << endl;

    begin = clock();
    fib_1(n);
    end = clock();
    double t1 = (double)(begin-end)*1000000/CLOCKS_PER_SEC; // Time in microseconds
    cout << "Time taken in naive recursion : " << t1 << endl;

    
    cout<< "Using bottom up approach: "<< fib_2(n) << endl;

    begin = clock();
    fib_2(n);
    end = clock();
    double t2 = (double)(begin-end)*1000000/CLOCKS_PER_SEC; // Time in microseconds
    cout << "Time taken in bottom up approach: " << t2 << endl;


    cout << "Using closed-form: " << fib_3(n) << endl;

    begin = clock();
    fib_3(n);
    end = clock();
    double t3 = (double)(begin-end)*1000000/CLOCKS_PER_SEC; // Time in microseconds
    cout << "Time taken in closed-form : " << t3 << endl;


    cout << "Using matrix representation: " << fib_4(n) << endl;

    begin = clock();
    fib_4(n);
    end = clock();
    double t4 = (double)(begin-end)*1000000/CLOCKS_PER_SEC; // Time in microseconds
    cout << "Time taken in matrix representation : " << t4 << endl;
  
    if((t1 > 1000) && (t2 > 1000) && (t3 > 1000) && (t4 > 1000))
    {
      cout << endl << "The running times exceed 1000 microseconds" << endl;
      break;
    }
   }

    return 0;

}