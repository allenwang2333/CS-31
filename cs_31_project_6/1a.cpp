#include <iostream>
using namespace std;

int main() {
    int arr[3] = {5, 10, 15};
    int* ptr = arr;
    *ptr = 30;
    *(ptr + 1) = 20;
    ptr += 2;
    ptr[0] = 10;

    while (ptr - 2 <= arr + 2) {
        cout << *(ptr - 2) << endl; 
        ptr++;
    }
}