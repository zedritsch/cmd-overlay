#include "directory.h"
#include "commands.h"

#include <stdlib.h>
#include <stdio.h>

#define COMMAND_MAX 8191

void shell() {
	char current_working_directory[PATH_MAX];
	char command[COMMAND_MAX];

	getcwd(current_working_directory, sizeof(current_working_directory));
	updateCurrentWorkingDirectory(current_working_directory);

	do {
		printf("%s > ", current_working_directory);
		fgets(command, sizeof(command), stdin);
		command[strcspn(command, "\n")] = 0;

		if (isChangeDirectory(command)) {
			changeDirectory(command + 2);

			getcwd(current_working_directory, sizeof(current_working_directory));
			updateCurrentWorkingDirectory(current_working_directory);
		}
		else
			system(command);

		printf("\n");
	} while (!isExit(command));
}

int main(const int ARGC, const char** ARGV) {
	if (ARGC == 1) {
		shell();

		return 0;
	}

	char command[COMMAND_MAX] = "cmd";
	int len = 3, x;

	for (int y = 1; ARGV[y] && len != COMMAND_MAX; y++) {
		command[len++] = ' ';

		for (x = 0; ARGV[y][x] && len != COMMAND_MAX; x++)
			command[len++] = ARGV[y][x];
	}

	system(command);
	return 0;
}