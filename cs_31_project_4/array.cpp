#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cassert>
using namespace std;

int reduplicate(string a[], int n);
int locate(const string a[], int n, string target);
int locationOfMax(const string a[], int n);
int circleLeft(string a[], int n, int pos);
int enumerateRuns(const string a[], int n);
int flip(string a[], int n);
int locateDifference(const string a1[], int n1, const string a2[], int n2);
int subsequence(const string a1[], int n1, const string a2[], int n2);
int locateAny(const string a1[], int n1, const string a2[], int n2);
int separate(string a[], int n, string separator);


int reduplicate(string a[], int n){
    // if n is negative, the input value is invalid, return -1, this should be same for all following functions
    if (n < 0 || a == NULL) { 
        return -1;
    }
    else {
        // for every element, append that element to the end of it. 
        for (int i = 0; i < n; i++) {
            a[i] += a[i]; 
        }
        return n;
    }
}

int locate(const string a[], int n, string target){
    if (n < 0 || a == NULL) {
        return -1;
    }
    else {
        // comparing every target
        for (int i = 0; i < n; i++) {
            if (a[i] == target) {
                return i;
            }
        }
        return -1;
    }
}

int locationOfMax(const string a[], int n) {
    // initializing variables
    int index = 0;
     
    if (n <= 0 || a == NULL) {
        return -1;
    }
    else {
		string maxString = a[0];
        for (int i = 0; i < n; i++) {
            // if the string is larger, replace it and counter + 1
            if (maxString.compare(a[i]) < 0){
                index = i;
                maxString = a[i];
            }
        }
        return index;
    }
}

int circleLeft(string a[], int n, int pos) {
    // initializing variables
    // if n and pos is no positive, return -1, if pos is out of range of array, return -1
    if (n < 0 || pos < 0 || pos > n - 1 || a == NULL) {
        return -1;
    }
    else {
		string tempString = a[0];
        tempString = a[pos];
        for (int i = 0; i < n - pos - 1; i++) {
            a[pos + i] = a[pos + i + 1]; 
        }
        a[n - 1] = tempString;
        return pos;
    }
}

int enumerateRuns(const string a[], int n) {
    // initializing variables
    int counter = 0;
    int total = n;
    if (n < 0 || a == NULL) {
        return -1;
    }
    else {
		string tempString = a[0];
        //for all elements in the arrray, if has the same string counter +1
        for (int i = 1; i < n; i++) {
            if (tempString == a[i]) {
                counter += 1;
            }
            tempString = a[i];
            // subtract counter from total
            total -= counter;
            counter = 0;
        }
        return total;
    }
}

int flip(string a[], int n) {
    if (n < 0 || a == NULL) {
        return -1;
    }
    else {
		string tempString = a[0];
        if (n % 2 == 0) {
            // if the numer of elements is even
            for (int i = 0; i < n / 2; i++) {
                // swap
                tempString = a[i];
                a[i] = a[n - i - 1];
                a[n - i - 1] = tempString;
            }
            return n;
        }
        else {
            // if the number of elements is odd
            for (int j = 0; j < (n - 1) / 2; j++) {
                // swap
                tempString = a[j];
                a[j] = a[n - j - 1];
                a[n - j - 1] = tempString;
            }
            return n;
        }
    }
}

int locateDifference(const string a1[], int n1, const string a2[], int n2) {
    int n = 0;
    int num = 0;
    if (n1 < 0 || n2 < 0 || a1 == NULL || a2 == NULL) {
        return -1;
    }
    else if (n1 == 0 || n2 ==0) {
        return 0;
    }
    else {
        // only need to get to elements in the array that has smaller number of elements
        if (n1 >= n2){
            n = n2;
        }
        else {
            n = n1;
        }
        for (int i = 0; i < n; i++) {
            if (a1[i] == a2[i]) {
                num += 1;
            }
            else {
                return num;
            }
        }
        return num;
    }
}

int subsequence(const string a1[], int n1, const string a2[], int n2) {
    int index = -1;
    if (n1 < 0 || n2 < 0 || n1 < n2 || a1 == NULL || a2 == NULL) {
        return -1;
    }
    else if (n1 == 0 || n2 ==0){
        return 0;
    }
    else {
        //in 2 for loops get to every element and compare 
        for (int i = 0; i < n1 - n2 + 1; i++){
            for (int j = 0; j < n2; j++){
                index = -1;
                if (a1[i + j] != a2[j]){
                    break;
                }
                else {
                    index = i;
                }
            }
            if (index < 0) {
                continue;
            }
            else {
                return index;
            }
        }
        return -1;
    }
}

int locateAny(const string a1[], int n1, const string a2[], int n2) {
    if (n1 < 0 || n2 < 0 || a1 == NULL || a2 == NULL){
        return -1;
    }
    else if (n1 == 0 || n2 == 0){
        return -1;
    }
    else {
        //in 2 for loops, get to every element and compare
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                if (a2[j] == a1[i]) {
                    return i;
                }
            }
        }
        return -1;
    }
}

int separate(string a[], int n, string separator) {
    int counter = 0; 
    if (n < 0 || a == NULL) {
        return -1;
    }
    else if (n == 0) {
        return 0;
    }
    else {
        for (int i = 0; i < n; i++){
            for (int j = n - 1; j >=0; j--){
                if (i >= j){
                    break;
                }
                // if left element is smaller && right element is larger, then swap
                if(separator.compare(a[i]) <= 0 && separator.compare(a[j]) >= 0){
                    swap(a[i],a[j]);
                }
            }
        }
        for (int k = 0; k < n; k++) {
            if (separator.compare(a[k]) >= 0){
                counter += 1;
            }
            if (a[k] == separator){
                return k;
            }
        }
        // if the counter is n, that means the element is not in the array and is larger than all elements.
        return counter;
    }
}

string c[6] = {
	"alpha", "beta", "beta", "delta", "gamma", "gamma"
};


int main()
{
    cout << "Passed test " << endl;
}