#include <iostream>
#include <string>
using namespace std;

// setting constants
const int BASE_NON_LUXURY_CHARGE = 43;
const int BASE_LUXURY_CHARGE = 71;
const double FIRST_100_MILES_CHARGE = 0.27;
const double NEXT_400_MILES_CHARGE_DECEMBER_TO_MARCH = 0.27;
const double NEXT_400_MILES_CHARGE = 0.21;
const double ABOVE_500_MILES_CHARGE = 0.17;

int main() {
    int startOdometerReading;
    int endOdometerReading;
    int rentalDays;
    string customerName;
    string luxuryCar;
    int month;
    double totalCharge;
    int distanceTravel; 

    cout << "Odometer at start: ";
    cin >> startOdometerReading;

    cout << "Odometer at end: ";
    cin >> endOdometerReading;

    cout << "Rental days: ";
    cin >> rentalDays;
    cin.ignore(10000,'\n');

    cout << "Customer name: ";
    getline(cin, customerName);
    
    cout << "Luxury car? (y/n): ";
    getline(cin, luxuryCar);
    
    cout << "Month (1=Jan, 2=Feb, etc.): ";
    cin >> month;

    cout << "---" << endl;

    distanceTravel = endOdometerReading - startOdometerReading;

    if (luxuryCar == "n") {
        if (distanceTravel <= 100) {
            totalCharge = BASE_NON_LUXURY_CHARGE * rentalDays + distanceTravel * FIRST_100_MILES_CHARGE;
        }
        else if (distanceTravel > 100 && distanceTravel <= 500 ) {
            if (month == 12 || month == 1 || month == 2 || month == 3){
                totalCharge = BASE_NON_LUXURY_CHARGE * rentalDays + FIRST_100_MILES_CHARGE * 100.00 + (distanceTravel - 100) * NEXT_400_MILES_CHARGE_DECEMBER_TO_MARCH;
            }
            else {
                totalCharge = BASE_NON_LUXURY_CHARGE * rentalDays + FIRST_100_MILES_CHARGE * 100.00 + (distanceTravel - 100) * NEXT_400_MILES_CHARGE;
            }
        }
        else {
            if (month == 12 || month == 1 || month == 2 || month == 3){
                totalCharge = BASE_NON_LUXURY_CHARGE * rentalDays + FIRST_100_MILES_CHARGE * 100.00 + (distanceTravel - 100) * NEXT_400_MILES_CHARGE_DECEMBER_TO_MARCH + (distanceTravel -500) * ABOVE_500_MILES_CHARGE;
            }
            else {
                totalCharge = BASE_NON_LUXURY_CHARGE * rentalDays + FIRST_100_MILES_CHARGE * 100.00 + (distanceTravel - 100) * NEXT_400_MILES_CHARGE + (distanceTravel -500) * ABOVE_500_MILES_CHARGE;
            }
        }
    }

    if (luxuryCar == "y") {
        if (distanceTravel <= 100) {
            totalCharge = BASE_LUXURY_CHARGE * rentalDays + distanceTravel * FIRST_100_MILES_CHARGE;
        }
        else if (distanceTravel > 100 && distanceTravel <= 500 ) {
            if (month == 12 || month == 1 || month == 2 || month == 3){
                totalCharge = BASE_LUXURY_CHARGE * rentalDays + FIRST_100_MILES_CHARGE * 100.00 + (distanceTravel - 100) * NEXT_400_MILES_CHARGE_DECEMBER_TO_MARCH;
            }
            else {
                totalCharge = BASE_LUXURY_CHARGE * rentalDays + FIRST_100_MILES_CHARGE * 100.00 + (distanceTravel - 100) * NEXT_400_MILES_CHARGE;
            }
        }
        else {
            if (month == 12 || month == 1 || month == 2 || month == 3){
                totalCharge = BASE_LUXURY_CHARGE * rentalDays + FIRST_100_MILES_CHARGE * 100.00 + (distanceTravel - 100) * NEXT_400_MILES_CHARGE_DECEMBER_TO_MARCH + (distanceTravel -500) * ABOVE_500_MILES_CHARGE;
            }
            else {
                totalCharge = BASE_LUXURY_CHARGE * rentalDays + FIRST_100_MILES_CHARGE * 100.00 + (distanceTravel - 500) * NEXT_400_MILES_CHARGE + (distanceTravel -500) * ABOVE_500_MILES_CHARGE;
            }
        }
    }
    
    // results for unexpected input
    if (startOdometerReading < 0) {
        cout << "The starting odometer reading must not be negative." << endl;
        return 1;
    } 
    else if (endOdometerReading < startOdometerReading){
        cout << "The ending odometer reading must be at least as large as the starting reading." << endl;
        return 1;
    }
    else if (rentalDays <= 0) {
        cout << "The number of rental days must be positive." << endl;
        return 1;
    }
    else if (customerName == "") {
        cout << "You must enter a customer name." << endl;
        return 1;
    }
    else if (luxuryCar != "n" && luxuryCar != "y") {
        cout << "You must enter y or n." << endl;
        return 1;
    }  
    else if (month < 1 || month > 12 ) {
        cout << "The month number must be in the range 1 through 12." << endl;
        return 1;
    }
    else {
        cout.setf(ios::fixed); // setting precision
        cout.precision(2);

        cout << "The rental charge for " << customerName << " is $" << totalCharge << endl; // when input form is correct
        return 0;
    }
}
