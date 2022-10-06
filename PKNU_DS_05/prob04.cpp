#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 256

void load();
void filter(char buffer[]);

char buffer[BUFFER_SIZE];
char* content[BUFFER_SIZE];

int main() {

	load();
	//for (int i = 0; content[i] != NULL; i++) {
	//	printf("%s\n", content[i]);
	//}

	return 0;
}

void load() {
	FILE* file = fopen("sample.txt", "r");
	if (file == NULL) {
		printf("ERROR! FAILED TO OPEN FILE\n");
		return;
	}
	int i = 0; //줄의 번호 저장
	while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
		//문장 끝에있는 개행 제거
		for (int j = 0; j < BUFFER_SIZE; j++) {
			if (buffer[j] == '\n') {
				buffer[j] = NULL;
			}
		}
		//Tag를 제거
		filter(buffer);
		break;
		//Tag를 제거한 한 줄
		content[i] = strdup(buffer);
		i++;
	}
}

void filter(char buffer[]) {
	int i = 0;
	int j = 0;
	char tmp[BUFFER_SIZE];
	while (buffer[i] != NULL) {
		if (buffer[i] == '<') {
			//Tag의 끝부분이 나올때 까지 i++
			while (buffer[i] != '>') {
				printf("%d ", i);
				i++;
			}
		}
		tmp[j] = buffer[i];
		j++;
	}
	tmp[j] = NULL;
	strcpy(buffer, tmp);
	printf("%s", buffer);
}
