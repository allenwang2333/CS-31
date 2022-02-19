#include <iostream>
using namespace std;

double mean(const double* scores, int numScores) {
    const double* ptr = scores;
    double tot = 0;
    for (int i = 0; i < numScores; i++) {
        tot += *(ptr + i);
    }
    return tot/numScores;
}
/*
    const char* findTheChar(const char* str, char chr)
    {
        for (int k = 0; *(str + k) != 0; k++)
            if (*(str + k) == chr)
                return str + k;
        return nullptr;
    }
*/

const  char* findTheChar(const char* str, char chr) {
    while (*str != 0) {
        if (*str == chr) {
            return str;
        }
        str++;
    }
    return NULL;
}

int main() {
    double a[6] = {1.0, 1.0, 2.1, 2.0, 3.0, 3.0};
    cout << mean(a, 6) << endl;
    const char b[10] = "Hello";
    const char* p = findTheChar(b,'a');
    cout <<  p << endl;
}