// Example program
#include <iostream>
#include <string>
using namespace std;

int main()
{
//int A[3][5][8]
int ***A;
A = new int**[3];
  
for(int*** i = A; i < A+3; i++)
{
   *i = new int*[5];
   for(int** j = *i; j < (*i)+5; j++)
    *j = new int[8];
}
for(int*** i = A; i < A+3; i++)
{
    for(int** j = *i; j < (*i)+5; j++)
        delete[] *j;
    delete[] *i;
}
delete[] A;
}
