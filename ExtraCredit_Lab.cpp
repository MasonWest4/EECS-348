#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

double extractNumeric(const string& input) {

    bool hasDecimal = false, hasSign = false, valid = true;
    double result = 0.0 ;
    double decimalMultiplier = 0.1;
    size_t length = input.length();
    int sign = 1; //1 for positive, -1 for negative

    //Handle empty string or too long input
    if (length == 0 || length > 20) return -999999.99;

    for (size_t i = 0; i < length; ++i) {
        char ch = input[i];

        if (i == 0 && (ch == '+' || ch == '-')) {
            //Handle the sign at the beginning of the string
            hasSign = true;
            sign = (ch == '-') ? -1 : 1;
        } 
        //Checks if decimal is true. If it is, it changes the char to a double.
        else if (isdigit(ch)) {
            if (hasDecimal) {
                result += (ch - '0') * decimalMultiplier;
                decimalMultiplier *= 0.1;
            } else {
                result = result * 10 + (ch - '0');
            }
        } 
        //Checks for decimal
        else if (ch == '.' && !hasDecimal) {
            hasDecimal = true;
        } 
        else {
            valid = false;
            break;
        }
    }

    //Reject inputs with invalid signs or only a decimal point
    if (input == "+" || input == "-" || input == "." || input == "+." || input == "-.") {
        valid = false;
    }

    //Return the computed result or error code
    return valid ? result * sign : -999999.99;
}

int main() {
    string input;

    cout << "Enter a string to extract a number (type 'END' to quit):" << endl;

    while (true) {
        cout << "Input: ";
        getline(cin, input);

        //Exit condition
        if (input == "END") {
            cout << "Exiting program." << endl;
            break;
        }

        //Process the input
        double result = extractNumeric(input);
        if (result == -999999.99) {
            cout << "The input is invalid." << endl;
        } else {
            cout << "The input is: " << fixed << setprecision(4) << result << endl;
        }
    }
    return 0;
}
