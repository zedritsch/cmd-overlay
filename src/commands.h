#pragma once

#include "string.h"

#include <stdbool.h>
#include <ctype.h>

bool isChangeDirectory(const char* command) {
	return startsWith(command, "cd") && (
		command[2] == ' ' || command[2] == '.' || command[2] == '"'
	);
}

bool isExit(const char* command) {
	return startsWith(command, "exit");
}