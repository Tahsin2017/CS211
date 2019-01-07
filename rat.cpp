/**
 * Rat class is a class in c++ which performs the arithmetic actions between two rational numbers
 * It takes numerator and denominator of two fractions as parameters
 * Performs the '+' , '-' , '*' , '/' between two fractions
 * Shows the results in a fraction. If the fraction is improper, it converts it into a mixed fraction
 */

#include <iostream>
#include <cmath>
using namespace std;

class Rat
{
private:
	int n;
   	int d;
   
public:
   // constructors
   
   // default constructor
  	Rat()
	{
    	n=0;
       	d=1;
    }
   
   // 2 parameter constructor
   Rat(int i, int j)
   {
      	n=i;
      	d=j;
   }
   
   // conversion constructor
   Rat(int i)
   {
        n=i;
        d=1;
   }
   
   //accessor functions (usually called get() and set(...) )
   int getN(){ return n;}
   int getD(){ return d;}
   
   void setN(int i){ n=i;}
   void setD(int i){ d=i;}
   
   //arithmetic operators
   Rat operator+(Rat r)
   {
       Rat t;
       t.n = n*r.d + d*r.n;
       t.d = d*r.d;
       return t;
   }
   
   // Write the other 3 operators (operator-, operator*, operator/).
   Rat operator-(Rat r)
   {
   	  Rat t;	
   	  t.n = n*r.d - d*r.n;
   	  t.d = d*r.d;
   	  return t;
   }
   
   Rat operator*(Rat r)
   {
   	  Rat t;
   	  t.n = n*r.n;
   	  t.d = d*r.d;
   	  return t;
   }
   
   Rat operator/(Rat& r)
   {
   	  Rat t;
   	  t.n = n*r.d;
   	  t.d = d*r.n;
   	  return t;
   }
   // Write a function to reduce the Rat to lowest terms, and then you can call this function from other functions.
   // Also make sure that the denominator is positive.  Rats should be printed in reduced form.
   // Calculate the GCD (Euclid's algorithm)

   /*int gcd(int n, int d)
   {
      return d == 0 ? n : gcd(d, n%d);
   }*/

   // 2 overloaded i/o operators
   friend ostream& operator<<(ostream& os, Rat r);
   friend istream& operator>>(istream& is, Rat& r);
}; //end Rat

int gcd(int n, int d)
{
   return d == 0 ? n : gcd(d, n%d);
}
// operator<<() is NOT a member function but since it was declared a friend of Rat
// it has access to its private parts.
ostream& operator<<(ostream& os, Rat r)
{
	while(gcd(r.n, r.d) != 1)
	{
		for(int i=2; i<=r.d; i++)
		{
			if(r.n%i==0 && r.d%i == 0)
			{
				r.n/= i;
				r.d /= i;
			}
		}
	}
	
	if(r.n == 0)
		os<<0;
	else if(r.d == 1)
		os<<r.n;
	
	else if(r.n%r.d == 0)
		os<<r.n/r.d;
	else
	{
		if(r.n>r.d)
		{
			os<<r.n/r.d<<" "<<(r.n%r.d)<<"/"<<r.d;
		}
		else
			os<<r.n<<"/"<<r.d;
	}
   // Rewrite this function so that improper fractions are printed as mixed numbers.  For example:
   // 3/2 should be printed as 1 1/2
   // 1/2 should be printed as 1/2
   // 2/1 should be printed as 2
   // 0/1 should be printed as 0
   // Negative numbers should be printed the same way, but beginning with a minus sign
   return os;
}

// operator>>() is NOT a member function but since it was declared a friend of Rat
// it has access to its private parts.
istream& operator>>(istream& is, Rat& r){
   is >> r.n >> r.d;
   return is;
}

int main() 
{
   Rat r1(5, 2), r2(3, 2);
   
   cout << "r1: " << r1 << endl;
   cout << "r2: " << r2 << endl;
   cout << "r1 + r2: " << r1 + r2 << endl;
   cout << "r1 - r2: " << r1 - r2 << endl;
   cout << "r1 * r2: " << r1 * r2 << endl;
   cout << "r1 / r2: " << r1 / r2 << endl;
   cout << endl;
   
   r1 = r2;
   
   //cout<<r1<<endl;
   r2 = r1 * r2;
   //cout<<r2;
   cout << "r1: " << r1 << endl;
   cout << "r2: " << r2 << endl;
   cout << "r1 + r2: " << r1 + r2 << endl;
   cout << "r1 - r2: " << r1 - r2 << endl;
   cout << "r1 * r2: " << r1 * r2 << endl;
   cout << "r1 / r2: " << r1 / r2 << endl;
   cout << endl;
   
   r1 = r2 + r1 * r2 / r1;
   r2 = r2 + r1 * r2 / r1;
   
   cout << "r1: " << r1 << endl;
   cout << "r2: " << r2 << endl;
   cout << "r1 + r2: " << r1 + r2 << endl;
   cout << "r1 - r2: " << r1 - r2 << endl;
   cout << "r1 * r2: " << r1 * r2 << endl;
   cout << "r1 / r2: " << r1 / r2 << endl;
   
   return 0;
}
