#ifndef INPUT_UTILS_H
#define INPUT_UTILS_H

#include "../../string/string.h"

int input_int(std::istream &input, int min, int max);
float input_float(std::istream &input, float min, float max);
// if min_len and max_len less or equal to 0, they will be ignored
String input_string_eng(std::istream &input);

#endif // INPUT_UTILS_H
