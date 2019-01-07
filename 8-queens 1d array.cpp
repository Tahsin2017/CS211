/**
 * Solving the 8 queen problem using 1D array using backtrack and goto
 * The result comes out in the form of array index
 * Prints all the possible solutions
 */
#include <iostream>
#include<cstdlib>
using namespace std;
              
int main(){

        int q[8],c,i;
        q[0] = 0;
        c = 0;
      

nextColumn:
        c++;
        if(c == 8) 
			goto print;
        
		q[c] = -1;
              

nextRow:
        q[c]++; 
        if(q[c] == 8) 
			goto backTrack;
        
        for (i = 0; i < c; i++) 
		{
                if((q[i] == q[c]) || ((c - i) == abs(q[c] - q[i]))) //row and the diagonal test
					goto nextRow;
		}
		
        goto nextColumn;


backTrack:
        c--;
        if (c == -1) return 0;
        goto nextRow;

print:
		static int count = 1;
        cout << endl;
        cout << "Solution No. " << count << endl<<endl;
        for(i = 0;i < 8; i++){
                cout << q[i] << " ";
        }
        cout << endl;
        count++;
        goto backTrack;

        return 0;
}
