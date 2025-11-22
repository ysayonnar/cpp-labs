#ifndef INPUT_UTILS_H
#define INPUT_UTILS_H

#include "../../string/string.h"

int input_int(int min, int max);
float input_float(float min, float max);
// if min_len and max_len less or equal to 0, they will be ignored
String input_string_eng(int min_len, int max_len);

#endif // INPUT_UTILS_H
