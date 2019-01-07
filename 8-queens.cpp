/**
 * 8 queens are placed in a chess board in such a way where no queen can kill another
 * goto and backtracking is intentionally used for learning purpose here
 * Prints all the possible solutions
 */

#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
  int b[8][8]={0};
  b[0][0]=1;
  int c=0; 
  //int r=-1;
  int solutions=0;
  
  nextcolumn:c++;
  int r=-1;
  if(c==8){
  goto print; 
  }
  
  nextrow: r++;
  if(r==8) goto backtrack;
  
  //up diagonal
  for(int i=1;(r-i)>=0 && (c-i)>=0;i++){
  if(b[r-i][c-i]==1){
    goto nextrow;              //move on to next row
  }
  }
  //down diagonal
  for(int i=1; (r+i)<8 && (c-i)>=0; i++){
  if(b[r+i][c-i]==1){
    goto nextrow;              //next row
  }
  }
  //row test
  for(int i=0; i<c; i++){
  if(b[r][i]==1){
  goto nextrow;    //next row 
}
}

b[r][c]=1;
goto nextcolumn;

  backtrack: c--;
  if(c==-1) return 0;
  r=0;//added
  while(b[r][c]!=1){
  r++;}
  b[r][c]=0;
  goto nextrow;
  
  print: solutions++;
  for(int i=0; i<8; i++){
  for(int j=0; j<8; j++){
    cout<<b[i][j];
  }
  cout<<endl;
}
cout<<solutions<<endl;
goto backtrack;
}
