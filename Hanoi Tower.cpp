/**
 * Solves the problem of 'Hanoi Tower' using vectors
 * There are 3 towers and n rings in tower 'A'
 * Have to move n rings to tower 'B' using the help of tower 'C'
 * Condition is, a bigger ring cannot sit on a smaller ring
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
   vector<int> t[3];
   int n;
   cout << "Please enter the number of rings to move: ";
   cin >> n;
   cout << endl;
   // The initial value of to depends on whether n is odd or even
   int from = 0, to, candidate = 1, move = 0;
   
   if(n%2==0)	
   	to = 2;
   
   else
   	to = 1;
   
   // Initialize the towers
   for(int i = n + 1; i >= 1; --i)
      t[0].push_back(i);
   t[1].push_back(n+1);
   t[2].push_back(n+1);
   
   while (t[1].size() <n+1){ // while t[1] does not contain all of the rings
      cout << "Move #" << ++move << ": Transfer ring " << candidate << " from tower " << char(from+'A') << " to tower " << char(to+'A') << "\n";
      
      // Move the ring from the "from tower" to the "to tower" (first copy it, then delete it from the "from tower")
      t[from].pop_back();//_____
      t[to].push_back(candidate);//_____
      
      // from = the index of the tower with the smallest ring that has not just been moved: (to+1)%3 or (to+2)%3
      if (t[(to+1)%3].back() > t[(to+2)%3].back())
         from = (to+2)%3;	//0
      else
         from = (to+1)%3; 
         
      // candidate = the ring on top of the t[from] tower
      candidate =t[from].back();	//2
         
      // to = the index of the closest tower on which the candidate can be placed: (from+1)%3 or (from+2)%3
      // (compare the candidate with the ring on the closer tower; which tower is "closer" depends on whether n is odd or even)
    	
      if(n%2==0)
      	if(candidate<t[(from+2)%3].back())		//1<2
      		to = (from+2)%3;
      		else
      		to = (from+1)%3;
      else
      	if(candidate<t[(from+1)%3].back())
      	to = (from+1)%3;
      	else	to = (from+2)%3;
   }
   return 0;
}

