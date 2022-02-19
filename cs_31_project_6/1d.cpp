#include <iostream>
using namespace std;
    
    
    bool strequal(const char str1[], const char str2[])
    {
        while (*str1 != 0  &&  *str2 != 0)  // zero bytes at ends
        {
            if (*str1 != *str2)  // compare corresponding characters
                return false;
            str1++;            // advance to the next character
            str2++;
        }
        return *str1 == *str2;   // both ended at same time?
    }

    int main()
    {
        char a[15] = "Wang, A.";
        char b[15] = "Wang, R.";

        if (strequal(a,b))
            cout << "They're the same person!\n";
    }