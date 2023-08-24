#pragma once

#include <stdbool.h>
#include <ctype.h>

bool startsWith(const char* string, const char* search) {
	for (int i = 0; search[i]; i++) {
		if (tolower(string[i]) != tolower(search[i]))
			return false;
	}

	return true;
}

void moveLeft(char* string, int index, const int offset) {
	while (string[index]) {
		string[index] = string[index + offset];

		index++;
	}
}

void replaceAll(char* string, const char search, const char replace) {
	for (int i = 0; string[i]; i++) {
		if (string[i] == search)
			string[i] = replace;
	}
}