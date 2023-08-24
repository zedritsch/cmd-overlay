#pragma once

#include "string.h"

#include <stdlib.h>
#include <unistd.h>

void updateCurrentWorkingDirectory(char* current_working_directory) {
	const char* USER_PROFILE = getenv("UserProfile");

	if (startsWith(current_working_directory, USER_PROFILE)) {
		current_working_directory[0] = '~';

		moveLeft(current_working_directory, 1, strlen(USER_PROFILE) - 1);
	}

	replaceAll(current_working_directory, '\\', '/');
}

void changeDirectory(char* path) {
	while (path[0] == ' ')
		path++;

	if (path[0] == '"') {
		path[strlen(path) - 1] = 0;

		path++;
	}

	chdir(path);
}