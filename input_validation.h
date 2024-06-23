#ifndef INPUT_VALIDATION_H
#define INPUT_VALIDATION_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

void clear_input_buffer();
void int_validation(int &number);
void name_validation(const string &input);
// void char_array_validation(const char *input);
void char_validation(char &character);
void double_validation(double &number);
void validate_phone_number(string &phoneNumber);

#endif // INPUT_VALIDATION_H
