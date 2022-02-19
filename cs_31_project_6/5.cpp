#include <iostream>
using namespace std;

void removeS(char* str) {
    char* temp = str;
    while (*temp != 0) {
        if (*temp == 's' || *temp == 'S'){
            str = temp;
            while (*str != 0) {
                *str = *(str + 1);
                str++;
            }
            temp--;
        }
        temp++;
    }
}

int main() {
    char msg[50] = "She'll be a massless princess.";
    removeS(msg);
    cout << msg << endl;
}
