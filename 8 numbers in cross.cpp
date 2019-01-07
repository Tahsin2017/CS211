/**
 * Prints 8 number in a '+' in such a way that no two adjacent numbers have a value difference of 1
 * Prints all the possible solutions
 */

#include<iostream>
#include<cmath>

using namespace std;

bool ok(int q[8], int c)
{
	int a[][8] = {{-1},				//Adjacent array with neighour indexes(2d array with irregular shape)
				{0,-1},
				{0,-1},
				{0,1,2,-1},
				{0,1,3,-1},
				{1,4,-1},
				{2,3,4,-1},
				{3,4,5,6,-1}};
				
	for(int i=0; i<c; i++)
	{
		if(q[i] == q[c])			//check for the same number
		return false;
	}
	
	for(int i=0; a[c][i] != -1; i++)
	{
		if(abs(q[c]-q[a[c][i]])==1)	//check if the neighour number - given number == 0
		return false;
	}
	
	return true;					//returns true if the number is okay
}

void print(int q[8])
{
	int static solutions = 0;
	
	cout<<"Solution#"<<++solutions<<":\n";
	for(int i=0; i<8; i++)
	{	
		if(i==0)	cout<<"  ";
		
		if(i==2)	cout<<endl;
		
		if(i==6)	cout<<endl<<"  ";
		
		cout<<q[i]+1<<" ";
	}
	
	cout<<endl<<endl;
}

int main()
{
	int q[8]={0};
	int c=0;
	
	while(c>=0)			//outer loop
	{
		c++;

		if(c==8)
		{
			print(q);
			c--;		//backtracking
		}
		else q[c] = -1;		
		
		
		while(c>=0)		//inner loop
		{
			q[c]++;
			
			if(q[c]==8)	c--;	//backtracking
			
			else if(ok(q,c))	//if the number is okay, the inner loop breaks 
			break;
		}
	}
	return 0;
}
