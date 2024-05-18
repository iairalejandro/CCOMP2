// Example program
#include <iostream>
#include <string>
using namespace std;

int tran(int M, int N)
{
}

int main()
{

int A[5][2] = {{1,2},{3,4},{5,6},{7,8},{9,10}};

A = new int*[5];
  
for(int** i = A; i < A+3; i++)
{
   *i = new int[5];
}
for(int** i = A; i < A+3; i++)
{
    delete[] *i;
}
delete[] A;
}

}
