//�׽�Ʈ ��� ������ ��� ����
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

//���� �Լ�
void load();
void show();
void colmax();
void colmin();
void rowmax();
void rowmin();
void slice();

//���� ���� ����
int N;
int arr[BUFFER_SIZE][BUFFER_SIZE];

int main() {
	char buffer[BUFFER_SIZE];
	load();
	while (1) {
		printf("$ ");
		scanf("%s", buffer);
		if (strcmp(buffer, "show") == 0) {
			show();
		}
		else if (strcmp(buffer, "colmax") == 0) {
			colmax();
		}
		else if (strcmp(buffer, "colmin") == 0) {
			colmin();
		}
		else if (strcmp(buffer, "rowmax") == 0) {
			rowmax();
		}
		else if (strcmp(buffer, "rowmin") == 0) {
			rowmin();
		}
		else if (strcmp(buffer, "slice") == 0) {
			slice();
		}
		//return 0; ���� �����Լ� ����
		else if (strcmp(buffer, "exit") == 0) {
			return 0;
		}
		//����ڰ� ��ȿ���� ���� ��ɾ �Է����� ��� 
		else { 
			printf("ERROR : invalid value");
		}
		printf("\n");
	}

	return 0;
}

//���� �б� 
void load() {
	FILE* file = fopen("data.mat", "r");
	if (file == NULL) {
		printf("���Ͽ��� ����\n");
		return;
	}
	fscanf(file, "%d ", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			fscanf(file, "%d", &arr[i][j]);
		}
	}
	fclose(file);
}

//��� ���
void show() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

//�� ���� �ִ� ���
void colmax(){
	int max;
	for (int i = 0; i < N; i++) {
		max = 0;
		for (int j = 0; j < N; j++) {
			if (arr[j][i] > max) {
				max = arr[j][i];
			}
		}
		printf("%d ", max);
	}
	printf("\n");
}

//�� ���� �ּڰ� ���
void colmin(){
	int min;
	for (int i = 0; i < N; i++) {
		min = 9999;
		for (int j = 0; j < N; j++) {
			if (arr[j][i] < min) {
				min = arr[j][i];
			}
		}
		printf("%d ", min);
	}
	printf("\n");
}

//�� ���� �ִ� ���
void rowmax(){
	int max;
	for (int i = 0; i < N; i++) {
		max = 0;
		for (int j = 0; j < N; j++) {
			if (arr[i][j] > max) {
				max = arr[i][j];
			}
		}
		printf("%d ", max);
	}
	printf("\n");
}

//�� ���� �ּڰ� ���
void rowmin(){
	int min;
	for (int i = 0; i < N; i++) {
		min = 9999;
		for (int j = 0; j < N; j++) {
			if (arr[i][j] < min) {
				min = arr[i][j];
			}
		}
		printf("%d ", min);
	}
	printf("\n");
}

//
void slice(){
	int x, p, y, q;
	scanf("%d %d %d %d", &x, &p, &y, &q);
	int tmp = y; //y���� �ݺ����� �ٽ� ���� y�� �״�� ������ �־���ϹǷ� �ӽ� ������ ���� ����
	for (x; x < N; x = x + p) {
		for (y = tmp; y < N; y = y + q) { //y�� �ٽ� �ʱ�ȭ �Ǿ���
			printf("%d ", arr[x][y]);
		}
		printf("\n");
	}
}

