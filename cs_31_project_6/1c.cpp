#include <iostream>
using  namespace std;

void computeCube(int n, int* ncubed)
{
    *ncubed = n * n * n;
}

int main()
{
    int a;
    int* ptr = &a;
    computeCube(5, ptr);
    cout << "Five cubed is " << *ptr << endl;
}
