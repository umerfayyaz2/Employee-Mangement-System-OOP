#ifndef INPUT_VALIDATION_H
#define INPUT_VALIDATION_H

#define PHONE_NUMBER_SIZE 12

#include <iostream>
using namespace std;

void clear_input_buffer();
// validation functions
void validate_input_int(int &number, const string &promptMessage, const string &errorMessage);
void validate_string(string &input, const string &promptMessage, const string &errorMessage);
void validate_input_char_array(char *input, int size, const string &promptMessage);
void validate_input_char_array_with_numbers(char *str, int size, const string &promptMessage);
void validate_input_char(char &character, int size, const string &promptMessage, const string &errorMessage);
void validate_input_double(double &number, const string &promptMessage, const string &errorMessage);
void validate_input_phone_number(char *phoneNumber, const string &promptMessage);

// utilties
bool isAlpha(char character);
bool isDigit(char digit);
void toUpper(char *str);

#include "input_validation.cpp"

#endif // INPUT_VALIDATION_H