/**
 * Solving 8 queen problem using 1d array
 * Use of backtrack and goto is prohibited
 * Result comes out in the form of array index
 */
#include<iostream>
#include<cmath>

using namespace std;

bool ok(int q[], int c)
{
	for(int i=0; i<c; i++)
	{
		if(q[c]==q[i] || (c-i) == abs(q[c]-q[i]))
		return false;
	}
	return true;
}

void print(int q[])
{
	static int numSolutions = 0;
	cout<<"Solution #"<<++numSolutions<<": ";
	
	for(int i=0; i<8; i++)
	cout<<q[i];
	
	cout<<endl;
}

int main()
{
	int q[8] = {0};
	int c = 0;
	
	while(c >= 0)
	{	
		c++;
			
		if(c == 8)	
		{
			print(q);
			c--;
		} 
		
		else	q[c] = -1;
		
		while(c>=0)
		{
			q[c]++;
			
			if(q[c]==8)
			{
				c--;
			}
			
			else if(ok(q,c))	break;
		}
		
		
	}
	return 0;
}

