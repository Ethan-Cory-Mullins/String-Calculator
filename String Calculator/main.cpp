#include <iostream>
#include <string>
#include <limits>
#include "./string_calculator.h"

using std::cout, std::endl, std::cin;
using std::string;

int main() {
    cout << "String Calculator" << endl;
    cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl;
    string inp1, inp2, inp3;
    cin >> inp1;
    if (inp1 != "quit" && inp1 != "q") {
        while (inp1 != "quit" && inp1 != "q") {
            cin >> inp2 >> inp3;
            if (inp2 == "+") {
                cout <<  ">>" << endl << "ans =" << endl << endl << "    " << add(inp1,inp3) << endl << endl;
            } else if (inp2 == "*") {
                cout<< ">>" << endl << "ans =" << endl << endl << "    " << multiply(inp1,inp3) << endl << endl;
            }
            cin >> inp1;
        }
        cout << ">>" << endl << "farvel!";
    }

    // TODO(student): implement the UI
    // this basically checks for input until q or quit is read and does the math with them. 
}

