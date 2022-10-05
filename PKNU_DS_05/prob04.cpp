#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 256

void load();

char buffer[BUFFER_SIZE];

int main() {

	load();

	return 0;
}

void load() {
	FILE* file = fopen("sample.txt", "r");
	if (file == NULL) {
		printf("ERROR! FAILED TO OPEN FILE\n");
		return;
	}
	while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
		printf("%s", buffer);
	}
}