#include <iostream>
using namespace std;

int main(){
    double* cat;
    double mouse[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    cat = mouse + 4;
    *cat = 25;
    *(mouse + 3) = 54;
    cat -= 3;
    cat[1] = 27;
    cat[0] = 42;
    bool d = (cat == mouse);
    bool b = (*cat == *(cat + 1));
    for (int i = 0; i < 5; i++) {
        cout << mouse[i] << endl;
    }
    cout << d << endl;
}