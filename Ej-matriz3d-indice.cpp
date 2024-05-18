// Example program
#include <iostream>
#include <string>
using namespace std;

int main()
{
//int A[3][5][8]
int ***A;
A = new int**[3];
  
for(int i = 0; i < 3; i++)
{
   A[i] = new int*[5];
   for(int j = 0; j < 5; j++)
    A[i][j] = new int[8];
}
for(int i = 0; i < 3; i++)
{
    for(int j = 0; j < 5; j++)
        delete[] A[i][j];
    delete[] A[i];
}
delete[] A;
}
