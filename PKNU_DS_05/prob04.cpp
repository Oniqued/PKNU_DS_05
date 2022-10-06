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
	int i = 0; //���� ��ȣ ����
	while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
		//���� �����ִ� ���� ����
		for (int j = 0; j < BUFFER_SIZE; j++) {
			if (buffer[j] == '\n') {
				buffer[j] = NULL;
			}
		}
		//Tag�� ����
		filter(buffer);
		break;
		//Tag�� ������ �� ��
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
			//Tag�� ���κ��� ���ö� ���� i++
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
