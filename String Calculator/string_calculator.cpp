#include <iostream>
#include <string>
#include "./string_calculator.h"

using std::cout, std::endl;
using std::string;

unsigned int digit_to_decimal(char digit) {
    if (digit != ' ' && digit != '0' && digit != '1' && digit != '2' && digit != '3' && digit != '4' && digit != '5' && digit != '6' && digit != '7' && digit != '8' && digit != '9') {
        throw std::invalid_argument("The charcter entered into the functions isn't a digit!"); // makes sure that the char holds a single digit number
    } else {
        return (digit - '0'); // returns the number as an integer
    }
}

char decimal_to_digit(unsigned int decimal) {
    // TODO(student): implement
    if (decimal != 0 && decimal != 1 && decimal != 2 && decimal != 3 && decimal != 4 && decimal != 5 && decimal != 6 && decimal != 7 && decimal != 8 && decimal != 9) {
        throw std::invalid_argument("The digit needs to be a number 0-9!"); // checks to make sure that it is a single digit number, if not then it tells the user to change the number
    } else {
        return (decimal + '0'); // returns the number as a character 
    }
}

string trim_leading_zeros(string num) {
    int i = 0;
    while (num[i] == '0') { // counts how many zeros at the beginning there are 
        i++;
    }
    if (num == "00000") { // makes sure it doesn't erase all of the zeros if the number is actually 0
        return "0";
    } else {
            num.erase(0,i); // erases all of the i number leading zeros
    return num; // returns the string without the leading zeros 
    }
}

string add(string lhs, string rhs) {
    // TODO(student): implement
    int i = 1;
    int rhs_len = rhs.length(); // gets the length of the rhs string
    int lhs_len = lhs.length(); // gets the length of the lhs string
    int carry = 0; // this is going to be the carry of the addition process (ex. 7 + 5 = 12, so the carry of this would be 1 to go to the next addition process)
    string sum = ""; // this is the new string that the new number is being created into 
    if (rhs_len > lhs_len) { 
        while (i <= lhs_len) { // does addition with both numbers beacause at this point both strings have this index and are long enough
        sum = decimal_to_digit(( (lhs[lhs_len - i] - 48) + (rhs[rhs_len - i] - 48) + carry) % 10) + sum; // adding signle digits to the right side of sum
        carry = (((lhs[lhs_len - i] - 48) + (rhs[rhs_len - i] - 48) + carry) / 10);
        i++;
        }
        while (i <= rhs_len) { // after the lhs is out of digits, then it only adds the carry with the rhs
            sum = decimal_to_digit(((rhs[rhs_len - i] - 48) + carry) % 10) + sum;
            carry = ((rhs[rhs_len - i] - 48) + carry) / 10; // same opperation here, but without the adding of lhs beacuse it doesn't have any more digts to add at this point.
            i++; // i had to subtract 48 from all the index calls beacuse of how the ASCII numbers work
        }
    } else if (lhs_len > rhs_len) {
        while (i <= rhs_len) { // goes until rhs has no more digits 
           sum = decimal_to_digit(( (lhs[lhs_len - i] - 48) + (rhs[rhs_len - i] - 48) + carry) % 10) + sum;
           carry = (((lhs[lhs_len - i] - 48) + (rhs[rhs_len - i] - 48) + carry) / 10); // same operations here but flipped 
           i++;
        }
        while (i <= lhs_len) {
            sum = decimal_to_digit(((lhs[lhs_len - i] - 48) + carry) % 10) + sum; // rhs has no more digits, so just adds lhs and carry
            carry = ((lhs[lhs_len - i] - 48) + carry) / 10;
            i++;
        }
    } else {
        while (i <= rhs_len) { // this is the case when the strings are the same size
           sum =  decimal_to_digit(( (lhs[lhs_len - i] - 48)  +      (rhs[rhs_len - i] - 48)  +    carry)  % 10 ) + sum ;
           carry = (( (lhs[lhs_len - i] - 48)  + (rhs[rhs_len - i] - 48) + carry ) / 10);
           i++;
        }
    }
    sum = decimal_to_digit(carry) + sum; // adds the last digit if there is a carry
    if (lhs == "0" && rhs == "0") {
        return "0";
    } else { 
        sum = trim_leading_zeros(sum); // deletes all the leading zeros
        return sum;
    }
}

string multiply(string lhs, string rhs) {
    int i = 1; // iterates through the rhs number 
    int j = 1; // iterates through the lhs number
    int k; // going to multiply the number by 10 ^ i
    int rhs_len = rhs.length();
    int lhs_len = lhs.length();
    int carry = 0;
    string curr_sum = "";
    string tot_sum;
    string zero = "0";
    while (i <= rhs_len) {
        curr_sum = "";
        carry = 0;
        j = 1;
        while (j <= lhs_len) {
            curr_sum = decimal_to_digit(((lhs[lhs_len - j] - 48) * (rhs[rhs_len - i] - 48) + carry) % 10) + curr_sum;
            carry = ((lhs[lhs_len - j] - 48) * (rhs[rhs_len - i] - 48) + carry) / 10;
            j++;
        }
        curr_sum = decimal_to_digit(carry) + curr_sum;
        for (k = 1; k < i; k++) {
            curr_sum = curr_sum +  "0";   // this multiplies the parital sum by 10 ^ i  (ex. if 51 * 12, 51 * 1 (but multiply this by 10))
        }
        tot_sum = add(tot_sum, curr_sum); // updates the total sum 
        i++;
    }


    return tot_sum; // returns the total sum 
}
