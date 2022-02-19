#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <cassert>
using namespace std;

bool decrypt(const char ciphertext[], const char crib[]);
void clearArray(char tempArray[]);

void runtest(const char ciphertext[], const char crib[])
	{
	    cout << "====== " << crib << endl;
	    bool result = decrypt(ciphertext, crib);
	    cout << "Return value: " << result << endl;
	}

bool decrypt(const char ciphertext[], const char crib[]) {
    
    //if strlen of ciphertext is larger than 6390 return false. 
    if (ciphertext == NULL || crib == NULL) {
        return false;
    }
    // initializing hash
    // setting all values 
    int myHash[26];
    for (int zz = 0; zz < 26; zz++) {
        myHash[zz] = -1;
    }
    // initializing cleared crib sting, cleared ciphertext string, and output string
    char cribString[100];
    char ciphertextString[6500];
    char decipherOutput[6500];

    //initializing an index value for comparison, and an tempInt
    int index = -1;
    int tempInt = 0;

    strcpy(ciphertextString, ciphertext); //copy ciphertext to ciphertextString, which is writable
    int nonAlphaCount = 0; //initializing a counter for non alpha count.
    int arrayIndex = 0; //initializing index for new array
    
    //washing crib
    for (int i = 0; i < strlen(crib); i++) {
        if(arrayIndex > 92) { 
            // length after wash should be smaller than 90
            return false;
        }
        if (isalpha(crib[i])){
            //if isalpha, non alphacount = 0, write this char to cribString, array index ++
            nonAlphaCount = 0;
            cribString[arrayIndex] = tolower(crib[i]);
            arrayIndex += 1;
        }
        else {
            // if not alpha, non alpha count ++
            nonAlphaCount += 1;
        }
        // if there are more than one non alpha, count them as one space
        if (nonAlphaCount == 1) {
            cribString[arrayIndex] = ' ';
            arrayIndex += 1;
        }
    }
    // if the start is a space, remove it
    while (cribString[0] == ' '){
        for(int j = 1; j < strlen(cribString); j++){
            cribString[j - 1] = cribString[j];
        }
         arrayIndex -= 1;
        if (arrayIndex < 0){
            break;
        }
    }
    // if end is space, remove it
    while(strlen(cribString) >=1 && cribString[strlen(cribString) - 1] == ' '){
        cribString[strlen(cribString) - 1] = '\0';
    }
    // for all char outside of index remove them.
    for (int k = arrayIndex; k < strlen(cribString); k++){
        cribString[k] = '\0';
    }
    // if end is space, remove it.
    while(strlen(cribString) >=1 && cribString[strlen(cribString) - 1] == ' '){
        cribString[strlen(cribString) - 1] = '\0';
    }
    if (strlen(cribString) > 90) {
        return false;
    }


    clearArray(ciphertextString); // this function is basically the same as above except from the 90 counter

    if (strlen(cribString) > strlen(ciphertextString)) {
        return false; // if the length of crib after wash is larger than the length of ciphertext after wash
                    // there is no chance to match
    }

    if (strlen(cribString) == 0 || strlen(ciphertextString) == 0){
        return false; // when one of them is empty, return false
    }
    
    for(int i = 0; i < strlen(ciphertextString) - strlen(cribString) + 1; i++) {
        // for every cribString in ciphertextString
        if (ciphertextString[i] == '\n') {
            // if is a newline character, omit. 
            // index is -1 indicate not match
            index = -1;
            continue; 
        }
        if (i > 0 && isalpha(ciphertextString[i - 1])){
            // if the previous char is aplha, can't match either
            index = -1;
            continue;
        }
        if ((i + strlen(cribString) < strlen(ciphertextString)) && isalpha(ciphertextString[i + strlen(cribString)])){
            // if the char after the lenghth of cribString is alpha, then is not match
            index = -1;
            continue;
        }
        for (int j = 0; j < strlen(cribString); j++){
            if ((isalpha(ciphertextString[i + j]) && isalpha(cribString[j])) || ((!isalpha(ciphertextString[i + j]) && !isalpha(cribString[j])))) {
                // if both alpha, or both non alpha
                if (ciphertextString[i + j] == '\n'){
                    // if there is a newline character in the middle, them no match
                    index = -1;
                    break;
                }
                index = i;
            }
            else {
                // if not, then no match
                index = -1;
                break;
            }
        }
        // if index is larger than 0, that means there is match
        if (index >= 0) {
            for (int k = 0; k < strlen(cribString); k++) {
                if (isalpha(ciphertextString[k + index])){
                    if (myHash[int(ciphertextString[index + k] - 'a')] == -1){
                        // if the hash table doesn't have this value before, the value is -1
                        myHash[int(ciphertextString[index + k] - 'a')] = int(cribString[k] - 'a');
                        tempInt = myHash[int(ciphertextString[index + k] - 'a')]; // them temInt is used to store the value now and compare in the hash table
                        for (int fa = 0; fa < 26; fa++) {
                            // checking if the value is stored before.
                            if (fa == int(ciphertextString[index + k] - 'a')) {
                                continue;
                            }
                            else if (myHash[fa] == tempInt) {
                                // if the value is stored twice, reset the hash table, index to -2
                                index = -2;
                                for (int fb = 0; fb < 26; fb++) {
                                    myHash[fb] = -1;
                                }
                                break; 
                            }
                        }
                        // continue the loop
                        if (index == -2) {
                            break;
                        }
                    }
                    else {
                        if(myHash[int(ciphertextString[index + k] - 'a')] != int(cribString[k] - 'a')){
                            // if the previous stored value is not equal to the value, reset hash table, set index to -2
                            for (int ff = 0; ff < 26; ff++) {
                                myHash[ff] = -1;
                            }
                            index = -2;
                            break;
                        }
                    }
                    
                }
            }
            if (index == -2){
                continue;
            }
            else {
                break;
            }
        }
    }
    if (index < 0) {
        return false;
    }

    // initializing output char array
    strcpy(decipherOutput, ciphertext);
    for (int m = 0; m < strlen(decipherOutput); m++) {
        if (isalpha(decipherOutput[m])){
            if (myHash[int(tolower(decipherOutput[m]) - 'a')] == -1){
                // if value is not stored, then make the char lower case
                decipherOutput[m] = tolower(decipherOutput[m]);
                continue;
            }
            else {
                // else make it upper case
                decipherOutput[m] = tolower(decipherOutput[m]);
                decipherOutput[m] = toupper(char(myHash[int(decipherOutput[m] - 'a')] + int('a')));
            }
        }
    }
    cout << decipherOutput;
    return true;
}

void clearArray(char tempArray[]) {
    // this function is basically the same as the previous clearing crib
    int nonAlphaCount = 0;
    int arrayIndex = 0;

    for (int i = 0; i < strlen(tempArray); i++) {
        if (isalpha(tempArray[i])){
            //if isalpha, non alphacount = 0, write this char to cribString, array index ++
            nonAlphaCount = 0;
            tempArray[arrayIndex] = tolower(tempArray[i]);
            arrayIndex += 1;
        }
        else if (tempArray[i] == '\n') {
            // if newline character, index ++
            nonAlphaCount = 0;
            tempArray[arrayIndex] = '\n';
            arrayIndex += 1;
        }
        else {
            // if not alpha, non alpha count ++
            nonAlphaCount += 1;
        }
        if (nonAlphaCount == 1) {
            // if there are more than one non alpha, count them as one space
            tempArray[arrayIndex] = ' ';
            arrayIndex += 1;
        }
    }
    while (tempArray[0] == ' '){
        // if the first chracter is space, remove it
        for(int j = 1; j < strlen(tempArray); j++){
            tempArray[j - 1] = tempArray[j];
        }
         arrayIndex -= 1;
        if (arrayIndex < 0){
            break;
        }
    }
    while(strlen(tempArray) >= 1 && tempArray[strlen(tempArray) - 1] == ' '){
        //if end is space, remove it.
        tempArray[strlen(tempArray) - 1] = '\0';
    }
    for (int k = arrayIndex; k < strlen(tempArray); k++){
        // for all char outside of index remove them.
        tempArray[k] = '\0';
    }
    while(strlen(tempArray) >= 1 && tempArray[strlen(tempArray) - 1] == ' '){
        tempArray[strlen(tempArray) - 1] = '\0';
    }
}

const int OKTEXT = 3;

bool appendNewline = false;

bool decrypt(const char ciphertext[], const char crib[]);

int dotest(const char* ciphertext, const char* crib, const char* plaintext)
{
	string s;
	if (appendNewline)
	{
		s.reserve(strlen(ciphertext) + 1);
		ciphertext = s.assign(ciphertext).append(1, '\n').c_str();
	}
	ostringstream oss;
	streambuf *sb = cout.rdbuf(oss.rdbuf());
	bool result = decrypt(ciphertext, crib);
	cout.rdbuf(sb);
	if (plaintext == nullptr)
		return result ? 0 : 1;  // 1 point if returns false when should
	int retval = 0;
	if (result)
		retval++;  // 1 point if returns true when should
	s = oss.str();
	if (s == plaintext)
		retval += OKTEXT;  // plus OKTEXT points for correct output text
	else if (!s.empty()  &&  s.back() == '\n')
	{
		s.pop_back();
		if (s == plaintext)
			retval += OKTEXT;  // plus OKTEXT points for correct output text
	}
	return retval;
}

void testone(int n)
{
	int res;

	switch (n)
	{
			         default: {
		cout << "Bad argument" << endl;
			} break; case  1: {
		res = dotest("", "", nullptr);
			} break; case  2: {
		res = dotest("", "a", nullptr);
			} break; case  3: {
		res = dotest("a", "", nullptr);
			} break; case  4: {
		res = dotest("ab", "b", nullptr);
			} break; case  5: {
		res = dotest("abc", "de f", nullptr);
			} break; case  6: {
		res = dotest("abc", "de-f", nullptr);
			} break; case  7: {
		res = dotest("abc", "ded", nullptr);
			} break; case  8: {
		res = dotest("aba", "def", nullptr);
			} break; case  9: {
		res = dotest("agbhc\nabcd", "def", nullptr);
			} break; case 10: {
		res = dotest("ab cd", "ef ge", nullptr);
			} break; case 11: {
		res = dotest("ab ca", "ef gh", nullptr);
			} break; case 12: {
		res = dotest("ab\ncd", "ef gh", nullptr);
			} break; case 13: {
		res = dotest("a", "b", "B");
			} break; case 14: {
		res = dotest("ab", "ba", "BA");
			} break; case 15: {
		res = dotest("aba", "ded", "DED");
			} break; case 16: {
		res = dotest("ab a", "c", "Cb C");
			} break; case 17: {
		res = dotest("abc ab bca", "de",
                               "DEc DE EcD");
			} break; case 18: {
		res = dotest("abc ab bc a", "de",
                               "DEc DE Ec D");
		if (res < OKTEXT)
		{
			int res2 = dotest("abc ab bc a", "de",
                                            "aDE aD DE a");
			if (res2 > res)
				res = res2;
		}
			} break; case 19: {
		res = dotest("abccd abccc abccb abcca", "xyzzy",
			       "XYZZd XYZZZ XYZZY XYZZX");
			} break; case 20: {
		res = dotest("abc abc", "def",
			       "DEF DEF");
			} break; case 21: {
		res = dotest("abc", "dEf", "DEF");
			} break; case 22: {
		res = dotest("abC", "dEf", "DEF");
			} break; case 23: {
		res = dotest("aba", "dED", "DED");
			} break; case 24: {
		res = dotest("abA", "ded", "DED");
			} break; case 25: {
		res = dotest("abc", "def ", "DEF");
			} break; case 26: {
		res = dotest("abc", "def!32", "DEF");
			} break; case 27: {
		res = dotest("abc", "32!def", "DEF");
			} break; case 28: {
		res = dotest("abc!", "def", "DEF!");
			} break; case 29: {
		res = dotest("@@abc!", "def", "@@DEF!");
			} break; case 30: {
		res = dotest("abc\nagbhc", "def",
			       "DEF\nDgEhF");
			} break; case 31: {
		res = dotest("agbhc\nabc", "def",
			       "DgEhF\nDEF");
			} break; case 32: {
		res = dotest("abc de fab cde", "gh ijk",
			       "JKc GH IJK cGH");
			} break; case 33: {
		res = dotest("abc de fabc ef ab cde fg", "gh ijk",
			       "GHI JK fGHI Kf GH IJK fg");
			} break; case 34: {
		res = dotest("abc de fab de abd de abc", "gh ijg",
			       "IJc GH fIJ GH IJG GH IJc");
			} break; case 35: {
		res = dotest("ab cd", "ef#$% gh", "EF GH");
			} break; case 36: {
		res = dotest("ab#$% cd", "ef gh", "EF#$% GH");
			} break; case 37: {
		res = dotest("ab\nbc", "de",
                               "DE\nEc");
		if (res < OKTEXT)
		{
			int res2 = dotest("ab\nbc", "de",
                               	            "aD\nDE");
			if (res2 > res)
				res = res2;
		}
			} break; case 38: {
		string cs;
		for (int k = 0; k < 45; k++)
			cs += " a";
		cs += '\n';
		string ct("ab");
		for (int k = 0; k < 44; k++)
			ct += " a";
		ct += '\n';
		string ps;
		for (int k = 0; k < 45; k++)
			ps += " C";
		ps += '\n';
		string pt("CD");
		for (int k = 0; k < 44; k++)
			pt += " C";
		pt += '\n';
		for (int k = 0; k < 69; k++)
		{
			ct += cs;
			pt += ps;
		}
		ct.pop_back();
		pt.pop_back();
		res = dotest(ct.c_str(), "cd", pt.c_str());
			} break; case 39: {
		string crib;
		crib.reserve(1000003);
		crib.append(500000,':');
		crib += "def";
		crib.append(500000,':');
		res = dotest("abc", crib.c_str(), "DEF");
			} break; case 40: {
		string crib;
		crib.reserve(1000003);
		crib.append(500000,':');
		crib += "def";
		crib.append(500000,':');
		res = dotest("abc", crib.c_str(), "DEF");
		if (res > 0)
		{
			string crib2;
			crib2.reserve(1000082);
			for (int k = 0; k < 45; k++)
				crib2 += "b ";
			crib2.append(1000000, ' ');
			crib2 += "b ";
			string ct;
			for (int k = 0; k < 45; k++)
				ct += "a ";
			res = dotest(ct.c_str(), crib2.c_str(), nullptr);
			res *= (2+OKTEXT);
		}
			} break;
	}
	cout << res << endl;
}

int main()
{
	cout << "Enter a test number (1 to 40): ";
	int n;
	cin >> n;
	if (n < 1  ||  n > 40)
	{
		cout << "Bad test number" << endl;
		return 1;
	}
	testone(n);
}