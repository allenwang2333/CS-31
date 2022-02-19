#include "grid.cpp"
#include "grid.h"
#include <iostream>
#include <cassert>
#include <string>
#include <cctype>

using namespace std;

bool hasCorrectForm(string plan);
int determineSafeDistance(int r, int c, char dir, int maxSteps);
int obeyPlan(int sr, int sc, int er, int ec, char dir, string plan, int& nsteps);
char setDirection(char dir, char command);


int main()
{
    int len = 0;
    setSize(25,30);
    setWall(1,1);
    setWall(1,7);
    setWall(1,8);
    setWall(1,9);
    setWall(1,10);
    setWall(1,13);
    setWall(1,17);
    setWall(1,20);
    setWall(1,26);
    setWall(1,27);
    setWall(1,29);
    setWall(2,1);
    setWall(2,4);
    setWall(2,8);
    setWall(2,9);
    setWall(2,10);
    setWall(2,15);
    setWall(2,17);
    setWall(2,21);
    setWall(2,22);
    setWall(2,25);
    setWall(2,26);
    setWall(2,27);
    setWall(2,28);
    setWall(2,30);
    setWall(3,1);
    setWall(3,4);
    setWall(3,5);
    setWall(3,6);
    setWall(3,7);
    setWall(3,11);
    setWall(3,12);
    setWall(3,14);
    setWall(3,18);
    setWall(3,21);
    setWall(3,22);
    setWall(3,24);
    setWall(3,25);
    setWall(3,26);
    setWall(3,27);
    setWall(3,28);
    setWall(4,1);
    setWall(4,5);
    setWall(4,6);
    setWall(4,15);
    setWall(4,17);
    setWall(4,20);
    setWall(4,21);
    setWall(4,24);
    setWall(4,25);
    setWall(4,26);
    setWall(4,27);
    setWall(4,28);
    setWall(4,30);
    setWall(5,5);
    setWall(5,9);
    setWall(5,13);
    setWall(5,18);
    setWall(5,23);
    setWall(5,24);
    setWall(5,25);
    setWall(5,26);
    setWall(5,27);
    setWall(5,28);
    setWall(5,29);
    setWall(6,3);
    setWall(6,4);
    setWall(6,7);
    setWall(6,10);
    setWall(6,13);
    setWall(6,15);
    setWall(6,20);
    setWall(6,22);
    setWall(6,25);
    setWall(6,26);
    setWall(6,27);
    setWall(6,28);
    setWall(6,29);
    setWall(6,30);
    setWall(7,6);
    setWall(7,12);
    setWall(7,13);
    setWall(7,22);
    setWall(7,25);
    setWall(7,26);
    setWall(7,27);
    setWall(8,12);
    setWall(8,13);
    setWall(8,18);
    setWall(8,19);
    setWall(8,22);
    setWall(8,25);
    setWall(8,26);
    setWall(8,27);
    setWall(8,30);
    setWall(9,2);
    setWall(9,4);
    setWall(9,7);
    setWall(9,8);
    setWall(9,10);
    setWall(9,12);
    setWall(9,13);
    setWall(9,15);
    setWall(9,21);
    setWall(9,23);
    setWall(9,24);
    setWall(9,25);
    setWall(9,26);
    setWall(9,27);
    setWall(9,28);
    setWall(9,29);
    setWall(9,30);
    setWall(10,1);
    setWall(10,3);
    setWall(10,4);
    setWall(10,6);
    setWall(10,10);
    setWall(10,11);
    setWall(10,18);
    setWall(10,20);
    setWall(10,22);
    setWall(10,23);
    setWall(10,24);
    setWall(10,25);
    setWall(10,26);
    setWall(10,27);
    setWall(10,28);
    setWall(10,29);
    setWall(11,6);
    setWall(11,10);
    setWall(11,11);
    setWall(11,12);
    setWall(11,17);
    setWall(11,19);
    setWall(11,21);
    setWall(11,22);
    setWall(11,23);
    setWall(11,24);
    setWall(11,25);
    setWall(11,26);
    setWall(11,27);
    setWall(11,28);
    setWall(11,29);
    setWall(12,9);
    setWall(12,10);
    setWall(12,11);
    setWall(12,12);
    setWall(12,22);
    setWall(12,23);
    setWall(12,24);
    setWall(12,25);
    setWall(12,26);
    setWall(12,27);
    setWall(12,28);
    setWall(12,30);
    setWall(13,2);
    setWall(13,6);
    setWall(13,10);
    setWall(13,11);
    setWall(13,12);
    setWall(13,13);
    setWall(13,18);
    setWall(13,19);
    setWall(13,21);
    setWall(13,23);
    setWall(13,24);
    setWall(13,25);
    setWall(13,26);
    setWall(13,27);
    setWall(13,28);
    setWall(13,29);
    setWall(14,2);
    setWall(14,5);
    setWall(14,9);
    setWall(14,11);
    setWall(14,12);
    setWall(14,13);
    setWall(14,15);
    setWall(14,17);
    setWall(14,18);
    setWall(14,20);
    setWall(14,24);
    setWall(14,25);
    setWall(14,26);
    setWall(14,27);
    setWall(14,28);
    setWall(14,29);
    setWall(14,30);
    setWall(15,2);
    setWall(15,5);
    setWall(15,6);
    setWall(15,12);
    setWall(15,13);
    setWall(15,14);
    setWall(15,22);
    setWall(15,24);
    setWall(15,25);
    setWall(15,26);
    setWall(15,27);
    setWall(15,30);
    setWall(16,1);
    setWall(16,5);
    setWall(16,6);
    setWall(16,12);
    setWall(16,13);
    setWall(16,16);
    setWall(16,17);
    setWall(16,22);
    setWall(17,2);
    setWall(17,6);
    setWall(17,7);
    setWall(17,11);
    setWall(17,14);
    setWall(17,19);
    setWall(17,25);
    setWall(17,28);
    setWall(17,29);
    setWall(18,1);
    setWall(18,2);
    setWall(18,3);
    setWall(18,4);
    setWall(18,5);
    setWall(18,6);
    setWall(18,7);
    setWall(18,9);
    setWall(18,11);
    setWall(18,29);
    setWall(18,30);
    setWall(19,1);
    setWall(19,2);
    setWall(19,4);
    setWall(19,5);
    setWall(19,6);
    setWall(19,10);
    setWall(19,14);
    setWall(19,15);
    setWall(19,17);
    setWall(19,18);
    setWall(19,20);
    setWall(19,21);
    setWall(19,23);
    setWall(19,25);
    setWall(19,29);
    setWall(19,30);
    setWall(20,1);
    setWall(20,5);
    setWall(20,9);
    setWall(20,10);
    setWall(20,11);
    setWall(20,12);
    setWall(20,13);
    setWall(20,14);
    setWall(20,15);
    setWall(20,16);
    setWall(20,17);
    setWall(20,18);
    setWall(20,26);
    setWall(20,27);
    setWall(20,29);
    setWall(21,2);
    setWall(21,7);
    setWall(21,10);
    setWall(21,11);
    setWall(21,12);
    setWall(21,13);
    setWall(21,14);
    setWall(21,15);
    setWall(21,16);
    setWall(21,17);
    setWall(21,19);
    setWall(21,23);
    setWall(21,26);
    setWall(21,27);
    setWall(21,28);
    setWall(21,30);
    setWall(22,3);
    setWall(22,4);
    setWall(22,5);
    setWall(22,7);
    setWall(22,10);
    setWall(22,11);
    setWall(22,12);
    setWall(22,13);
    setWall(22,14);
    setWall(22,15);
    setWall(22,16);
    setWall(22,21);
    setWall(22,26);
    setWall(22,27);
    setWall(22,30);
    setWall(23,2);
    setWall(23,3);
    setWall(23,4);
    setWall(23,5);
    setWall(23,8);
    setWall(23,13);
    setWall(23,14);
    setWall(23,15);
    setWall(23,16);
    setWall(23,26);
    setWall(23,27);
    setWall(24,2);
    setWall(24,3);
    setWall(24,4);
    setWall(24,7);
    setWall(24,14);
    setWall(24,20);
    setWall(24,21);
    setWall(24,26);
    setWall(24,27);
    setWall(25,2);
    setWall(25,3);
    setWall(25,11);
    setWall(25,12);
    setWall(25,17);
    setWall(25,20);
    setWall(25,26);

    draw(1,1,25,30);
    cout <<obeyPlan(22, 29, 24, 30, 'E', "0R1l1R4R", len) << endl;
    len = -999; assert(obeyPlan(22, 29, 24, 30, 'E', "0R1l1R4R", len) == 3 && len == 4);
    
   
    len = -999; assert(obeyPlan(11, 14, 17, 17, 's', "l2R4l2R2r1L", len) == 0 && len == 11);
    len = -999; assert(obeyPlan(16, 15, 4, 11, 's', "l0L1r1L2l2R9l4L", len) == 1 && len == 19);
    len = -999; assert(obeyPlan(7, 14, 18, 13, 's', "l2R8r1L3r2L", len) == 0 && len == 16);
    len = -999; assert(obeyPlan(17, 21, 5, 17, 's', "lLL1R1l2R1l2R10L", len) == 1 && len == 17);
    len = -999; assert(obeyPlan(20, 22, 18, 13, 's', "lLL3R2l7L", len) == 1 && len == 12);

    cout << "Congrats! You made it!" << endl;
    return 0;

}


bool hasCorrectForm(string plan) {  
    int planLength = plan.size();
    int counter = 0; 
    /*  Use the counter to count number of consecutive integers in the string. 
        When the counter is larger than 2 in the for loop below, which means that there are 2 consecutive integers. The function will return false.
        When the counter is non zero when the for loop is finished, which means that the last portion ends with an integer. The function will return false.
    */            
    for (int i = 0; i < planLength; i++) {
        if (plan[i] == 'R' || plan[i] == 'r' || plan[i] == 'L' || plan[i] == 'l') { // only 4 charecters are legal here 
            counter = 0; // when the function reads to a correct form of string, the counter will be set to zero
        }
        else if (isdigit(plan[i])) {
            counter = counter + 1; // when the function reads to an integer, the counter will add 1
            if (counter > 2) {
                return false;
            }
        }
        else {
            return false;
        }
    }
    if (counter == 0){
        return true; // if conter is non zero, the last portion is not in the correct form
    }
    else {
        return false;
    }
}

int determineSafeDistance(int r, int c, char dir, int maxSteps) {
    /* 
        This functions takes r, c, dir, and maxStpes
        If the r and c are not in the grid, or the point is a wall, or the maxStep is zero, the functon will return -1.
        If the car is going to hit the grid or the wall, the function will calculate the maximum step that the car is not going to hit a wall or the grid
        If the car is not going to hit the grid or the wall, the function will return the step. 
    */
    if (r < 1 || r > getRows() || c < 1 || c > getCols() || isWall(r,c) || maxSteps < 0){
        return -1;
    }
    else if (dir == 'N' || dir == 'n'){ // if go north
        if (r - maxSteps <= 0) {
            for (int i = 0; i < r; i++) {
                if (isWall(r - i, c)) {
                    return i - 1; // return the number of steps the car can go
                }
            }
            return (r - 1);
        }
        else {
            for (int j = 0; j < maxSteps + 1; j++){
                if (isWall(r - j, c)) {
                    return j - 1; // return the number of steps the car can go
                }
            }
            return maxSteps;
        }
    }
    else if (dir == 'S' || dir == 's'){ // if go south
        if (r + maxSteps > getRows()) {
            for (int i = 0; i < getRows() - r + 1; i++) {
                if (isWall(r + i,c)) {
                    return i - 1;
                }
            }
            return (getRows() - r);  
        }
        else {
            for (int j = 0; j < maxSteps + 1; j++){
                if (isWall(r + j,c)) {
                    return j - 1; // return the number of steps the car can go
                }
            }
            return maxSteps;
        }
    }
    else if (dir == 'W' || dir == 'w'){ // if go west
        if (c - maxSteps <= 0) { 
            for (int i = 0; i < c; i++) {
                if (isWall(r, c - i)) {
                    return i - 1; // return the number of steps the car can go
                }
            }
            return (c - 1);  
        }
        else {
            for (int j = 0; j < maxSteps + 1; j++){
                if (isWall(r, c - j)) {
                    return j - 1; // return the number of steps the car can go
                }
            }
            return maxSteps;
        }
    }
    else if (dir == 'E' || dir == 'e'){ // if go east
        if (c + maxSteps > getCols()) {
            for (int i = 0; i < getCols() - c + 1; i++) {
                if (isWall(r, c + i)) {
                    return i - 1; // return the number of steps the car can go
                }
            }
            return (getCols() - c);  
        }
        else {
            for (int j = 0; j < maxSteps + 1; j++){
                if (isWall(r, (c + j))) {
                    return j - 1; // return the number of steps the car can go
                }
            }
            return maxSteps;
        }
    }
    else { // if the direction is in correct.
        return -1;
    }
}

int obeyPlan(int sr, int sc, int er, int ec, char dir, string plan, int& nsteps) {
    char finalDir = dir;
    int counter = 0; // counting number of steps
    int numCount = 0; // counting number of consecutive number of integers
    int steps = 0; // calculate steps when there are two digits.
    if(!hasCorrectForm(plan) || sr < 1 || sr > getRows() || sc < 1 || sc > getCols() || isWall(sr,sc) || er < 1 || er > getRows() || ec < 1 || ec > getCols() || isWall(er,ec)){
        return 2;
    }
    else if (dir == 'N' || dir =='n') {
        /*  1. test the initial direction.
            2. operate the plan. 
            3. see if that meets the end point.
        */
       for (int i = 0; i < plan.size(); i++){
           if (plan[i] == 'L' || plan[i] == 'l' || plan[i] == 'R' || plan[i] == 'r'){
               finalDir = setDirection(finalDir,plan[i]);
               steps = 0; // initializing steps and integer count
               numCount = 0;
           }
           else {
               numCount = numCount + 1; // counting number of consecutive integers.
               if (numCount == 1) {
                   if (isdigit(plan[i+1])) {
                       steps = int(plan[i] - '0') * 10 + int(plan[i + 1] - '0'); // when the number of integers is 2, calculate the number of steps
                   }
                   else {
                       steps = int(plan[i] - '0'); // when the number of integers is one.
                   }
                }
                if (numCount == 2) { // when the number is two, continue.
                    continue;
                }
               if (determineSafeDistance(sr, sc, finalDir, steps) >= steps){ // if the safedistance is larger to or equal to the number of stpes. This means that the step number is safe. 
                    if (finalDir == 'N' || finalDir == 'n'){
                        sr = sr - steps;
                    }
                    else if (finalDir == 'S' || finalDir == 's') {
                        sr = sr + steps;
                    }
                    else if (finalDir == 'W' || finalDir == 'w') {
                        sc = sc - steps;
                    }
                    else {
                        sc = sc + steps;
                    }
                    counter = counter + steps;
                }
                else {
                    counter = counter + determineSafeDistance(sr, sc, finalDir, steps);
                    nsteps = counter; // passing value of counter to number of steps.
                    return 3;
                }
            }
        }
        nsteps = counter;
        if ((er == sr) && (ec == sc)) {
            return 0;
        }
        else {
            return 1;
        }
    }
    else if (dir == 'S' || dir == 's') { // basically same as previous
        for (int i = 0; i < plan.size(); i++){
           if (plan[i] == 'L' || plan[i] == 'l' || plan[i] == 'R' || plan[i] == 'r'){
               finalDir = setDirection(finalDir,plan[i]);
               steps = 0;
               numCount = 0;
           }
           else {
               numCount = numCount + 1;
               if (numCount == 1) {
                   if (isdigit(plan[i+1])) {
                       steps = int(plan[i] - '0') * 10 + int(plan[i + 1] - '0');
                   }
                   else {
                       steps = int(plan[i] - '0');
                   }
                }
                if (numCount == 2) {
                    continue;
                }
               if (determineSafeDistance(sr, sc, finalDir, steps) >= steps){
                    if (finalDir == 'N' || finalDir == 'n'){
                        sr = sr - steps;
                    }
                    else if (finalDir == 'S' || finalDir == 's') {
                        sr = sr + steps;
                    }
                    else if (finalDir == 'W' || finalDir == 'w') {
                        sc = sc - steps;
                    }
                    else {
                        sc = sc + steps;
                    }
                    counter = counter + steps;
                }
                else {
                    counter = counter + determineSafeDistance(sr, sc, finalDir, steps);
                    nsteps = counter;
                    return 3;
                }
            }
        }
        nsteps = counter;
        if ((er == sr) && (ec == sc)) {
            return 0;
        }
        else {
            return 1;
        }
    }
    else if (dir == 'W' || dir == 'w') { // basically same as previous
        for (int i = 0; i < plan.size(); i++){
           if (plan[i] == 'L' || plan[i] == 'l' || plan[i] == 'R' || plan[i] == 'r'){
               finalDir = setDirection(finalDir,plan[i]);
               steps = 0;
               numCount = 0;
           }
           else {
               numCount = numCount + 1;
               if (numCount == 1) {
                   if (isdigit(plan[i+1])) {
                       steps = int(plan[i] - '0') * 10 + int(plan[i + 1] - '0');
                   }
                   else {
                       steps = int(plan[i] - '0');
                   }
                }
                if (numCount == 2) {
                    continue;
                }
               if (determineSafeDistance(sr, sc, finalDir, steps) >= steps){
                    if (finalDir == 'N' || finalDir == 'n'){
                        sr = sr - steps;
                    }
                    else if (finalDir == 'S' || finalDir == 's') {
                        sr = sr + steps;
                    }
                    else if (finalDir == 'W' || finalDir == 'w') {
                        sc = sc - steps;
                    }
                    else {
                        sc = sc + steps;
                    }
                    counter = counter + steps;
                }
                else {
                    counter = counter + determineSafeDistance(sr, sc, finalDir, steps);
                    nsteps = counter;
                    return 3;
                }
            }
        }
        nsteps = counter;
        if ((er == sr) && (ec == sc)) {
            return 0;
        }
        else {
            return 1;
        }
    }
    else if (dir == 'E' || dir == 'e') { // basically same as previous
        for (int i = 0; i < plan.size(); i++){
           if (plan[i] == 'L' || plan[i] == 'l' || plan[i] == 'R' || plan[i] == 'r'){
               finalDir = setDirection(finalDir,plan[i]);
               steps = 0;
               numCount = 0;
           }
           else {
               numCount = numCount + 1;
               if (numCount == 1) {
                   if (isdigit(plan[i+1])) {
                       steps = int(plan[i] - '0') * 10 + int(plan[i + 1] - '0');
                   }
                   else {
                       steps = int(plan[i] - '0');
                   }
                }
                if (numCount == 2) {
                    continue;
                }
               if (determineSafeDistance(sr, sc, finalDir, steps) >= steps){
                    if (finalDir == 'N' || finalDir == 'n'){
                        sr = sr - steps;
                    }
                    else if (finalDir == 'S' || finalDir == 's') {
                        sr = sr + steps;
                    }
                    else if (finalDir == 'W' || finalDir == 'w') {
                        sc = sc - steps;
                    }
                    else {
                        sc = sc + steps;
                    }
                    counter = counter + steps;
                }
                else {
                    counter = counter + determineSafeDistance(sr, sc, finalDir, steps);
                    nsteps = counter;
                    return 3;
                }
            }
        }
        nsteps = counter;
        if ((er == sr) && (ec == sc)) {
            return 0;
        }
        else {
            return 1;
        }
    }
    else {
        return 2;
    }
}

char setDirection(char dir, char command) { // a function that takes the original dir and command that the string gives. changing the direction of the car. 
    if (dir == 'W' || dir == 'w') {
        if (command == 'L' || command == 'l') {
            return 'S';
        }
        else {
            return 'N';
        }
    }
    else if (dir == 'E' || dir == 'e') {
        if (command == 'L' || command == 'l') {
            return 'N';
        }
        else {
            return 'S';
        } 
    }
    else if (dir == 'N' || dir == 'n') {
        if (command == 'L' || command == 'l') {
            return 'W';
        }
        else {
            return 'E';
        } 
    }
    else {
        if (command == 'L' || command == 'l') {
            return 'E';
        }
        else {
            return 'W';
        } 
    }
}