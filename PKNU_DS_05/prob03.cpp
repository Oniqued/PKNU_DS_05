#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include <stdio.h>
#define SIZE 19

void load();
void judge();
bool horizon();
bool vertical();
void winner(int stone);

int N;
int board[SIZE][SIZE];

int main() {
	load();
	//��� ���� üũ
	if (vertical() == false &&
		horizon() == false) {
		printf("Not Finished\n");
	}

	return 0;
}


//���� �б�
void load() {
	FILE* file = fopen("board.txt", "r");
	if (file == NULL) {
		printf("FAILED TO READ FILE\n");
		return;
	}
	fscanf(file, "%d ", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			fscanf(file, "%d", &board[i][j]);
		}
	}
	fclose(file);
}

//���� �Ǵ�
/*
*	1. ���� ���� �밢�� �������� �����ؼ� 5���� ���δ�
*	2. ���� ���� �������� �����ؼ� 5���� �����ȴ� 
*	3. ���� ���� �������� �����ؼ� 5���� �����ȴ�
*/

//���� ���� �밢������ �����Ǵ� ���
bool diagonal() {
	int count;
	for (int i = N-1; i >= 0; i--) {
		count = 1;
		for (int j = 0; j < N; j++) {
			
		}
	}
}

//���� ���� �������� �����Ǵ� ���
bool horizon() {
	int count;
	for (int i = 0; i < N; i++) {
		count = 1;
		for (int j = 0; j < N; j++) {
			if ((board[i][j] == board[i][j + 1]) && (board[i][j] != 0)) {
				count++;
				//�����ؼ� 5���� ���̸�
				if (count == 5) {
					winner(board[i][j]);
					return true;
				}
			}
		}
	}
	return false;
}

//���� ���� �������� �����Ǵ� ���
bool vertical() {
	int count;
	for (int i = 0; i < N; i++) {
		count = 1;
		for (int j = 0; j < N; j++) {
			if ((board[j][i] == board[j+1][i]) && (board[j][i] != 0)) {
				count++;
				//�����ؼ� 5���� ���̸�
				if (count == 5) {
					winner(board[j][i]);
					return true;
				}
			}
		}
	}
	return false;
}

//�ش� ���� ���� ������ üũ
void winner(int stone) {
	if (stone == 1) {
		printf("Black\n");
	}
	else if (stone == 2) {
		printf("White\n");
	}
}
