/**
 * Solution for the shorest path without recursion
 * The starting point is the (0,0) index of the array and moves to the right
 * Searches for the path which costs the least
 * Condition: It has to move through the adjacent element of the next column(right/ top-right/ down-right)
 * The result should be the sum of the path elements and printing the shortest path array indices
 */

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

const int NUM_ROWS = 5, NUM_COLS = 6;

void calculateCosts()
{
    static int weight[NUM_ROWS][NUM_COLS] = {{3,4,1,2,8,6},
                                             {6,1,8,2,7,4},
                                             {5,9,3,9,9,5},
                                             {8,4,1,3,2,6},
                                             {3,7,2,8,6,4}};
                                             
    static int cost[NUM_ROWS][NUM_COLS] = {0};
    string path[NUM_ROWS][NUM_COLS];
    
    for(int i=0; i<NUM_ROWS; i++)
    {
        cost[i][0] = weight[i][0];
        path[i][0] = to_string(i);
    }
    
    for(int j = 1; j<NUM_COLS; j++)
    {
        for(int i=0; i<NUM_ROWS; i++)
        {
            int up = cost[(i+NUM_ROWS-1)%NUM_ROWS][j-1];
            int left = cost[i%NUM_ROWS][j-1];
            int down = cost[(i+1)%NUM_ROWS][j-1];
            int minCost = min(min(up,left),down);
            
            if(minCost == up)
                path[i][j] = path[(i+NUM_ROWS-1)%NUM_ROWS][j-1] + to_string(i);
            
            else if(minCost == left)
                path[i][j] = path[i%NUM_ROWS][j-1] + to_string(i);
                
            else 
                path[i][j] = path[(i+1)%NUM_ROWS][j-1] + to_string(i);
                
            cost[i][j] = minCost + weight[i][j];
        }
    }
    
    int minRow = 0, minLength = cost[0][NUM_COLS-1];
    
    for(int i=0; i<NUM_ROWS; i++)
    {
        if(cost[i][NUM_COLS-1]<minLength)
            minRow = i, minLength = cost[i][NUM_COLS-1];
    }
    
    cout<<"The shortest Path is  "<<minLength<<endl;
    cout<<"The shortest path from left to right is: "<<path[minRow][NUM_COLS-1]<<endl;
}
int main()
{
    calculateCosts();
    return 0;
}
