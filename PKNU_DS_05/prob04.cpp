//�׽�Ʈ ��� ������ ��� ����
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 256

//���� �Լ�
void load();
void save();
void filter(char buffer[]);

//���� ���� ���� 
char buffer[BUFFER_SIZE];
char* content[BUFFER_SIZE];

int main() {
	load();
	save();

	return 0;
}

//���� �а� ���͸� �� ������ content�� ����
void load() {
	FILE* file = fopen("sample.html", "r");
	if (file == NULL) {
		printf("ERROR! FAILED TO OPEN FILE\n");
		return;
	}
	else {
		printf("OPEN sample.html...\n");
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
		//Tag�� ������ �� ��
		content[i] = strdup(buffer);
		i++;
	}
	fclose(file);
}

//���� ����
void save() {
	FILE* file = fopen("sample.txt", "w");
	if (file == NULL) {
		printf("FAILED TO WRITE FILE\n");
		return;
	}
	else {
		printf("SUCCESSED TO SAVE FILE (with sample.txt)\n");
	}
	
	for (int i = 0; content[i] != NULL; i++) {
		fprintf(file, "%s\n", content[i]);
	}

	fclose(file);
}

//Tag �ڸ��� 
void filter(char buffer[]) {
	int i = 0;
	int j = 0;
	char tmp[BUFFER_SIZE];
	while (buffer[i] != '\0') {
		//Tag ���� �κ�
		if (buffer[i] == '<') { 
			//Tag�� ���κ��� ���ö� ���� i++
			while (buffer[i] != '>') {
				i++;
			}
			i++; //'>'�κ� �ǳʶٱ�
			//���� ���ڰ� Tag�����̸� �ٽ� �� ���� �ݺ�
			if (buffer[i] == '<') continue;
		}
		//Tag�� �ڸ� ���� ���� �ϳ��� tmp[0]���� ����
		tmp[j++] = buffer[i++];
	}
	tmp[j] = '\0'; //���� NULL CHAR �߰�
	strcpy(buffer, tmp); //buffer�� tmp �����
}
