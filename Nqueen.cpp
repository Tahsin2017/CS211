#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c) 
{
	for(int i=0; i<c; i++)
	{
		if(q[i]==q[c] || (c-i)==abs(q[c]-q[i]))	
		return false;  
	}	
	return true;
}

int nqueens(int n) 
{
	
	int noOfSolutions = 0;
	int* q = new int[n];	
	q[0] = 0;
   	
	int c = 0;
	
	while(c >= 0)
	{	
		c++;
			
		if(c == n)	
		{
			noOfSolutions++;
			c--;
		} 
		
		else	q[c] = -1;
		
		while(c>=0)
		{
			q[c]++;
			
			if(q[c]==n)
			{
				c--;
			}
			else if(ok(q,c))	break;
		}
	}
	
	delete[] q;
    
   return noOfSolutions;
}

int main() 
{
   int n = 12;
   for (int i = 1; i <= n; ++i)
      cout << "There are " << nqueens(i) << " solutions to the " << i << " queens problem.\n";
   return 0;
}
