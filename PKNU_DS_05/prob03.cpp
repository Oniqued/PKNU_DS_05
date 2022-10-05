#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include <stdio.h>
#define SIZE 19

void load();
void judge();
bool horizon();
bool vertical();
bool diagonal();
void winner(int stone);

int N;
int board[SIZE][SIZE];

int main() {
	load();

	//우승 조건 체크
	if (vertical() == false &&
		horizon() == false &&
		diagonal() == false) {
		printf("Not Finished\n");
	}

	return 0;
}


//파일 읽기
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

//승패 판단
/*
*	1. 같은 수가 대각선 방향으로 연속해서 5개가 놓인다
*	2. 같은 수가 수평으로 연속해서 5개가 나열된다
*	3. 같은 수가 수직으로 연속해서 5개가 나열된다
*/

//같은 수가 대각선으로 나열되는 경우
bool diagonal() {
	int count;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			count = 1;
			if (board[i][j] == 0) continue;
			for (int k = 1; k < 5; k++) {
				if (board[i][j] == board[i + k][j - k]) {
					count++;
					if (count == 5) {
						winner(board[i][j]);
						return true;
					}
				}
			}
		}
	}
	return false;
}

//같은 수가 수평으로 나열되는 경우
bool horizon() {
	int count;
	for (int i = 0; i < N; i++) {
		count = 1;
		for (int j = 0; j < N; j++) {
			if ((board[i][j] == board[i][j + 1]) && (board[i][j] != 0)) {
				count++;
				//연속해서 5개가 놓이면
				if (count == 5) {
					winner(board[i][j]);
					return true;
				}
			}
		}
	}
	return false;
}

//같은 수가 수직으로 나열되는 경우
bool vertical() {
	int count;
	for (int i = 0; i < N; i++) {
		count = 1;
		for (int j = 0; j < N; j++) {
			if ((board[j][i] == board[j + 1][i]) && (board[j][i] != 0)) {
				count++;
				//연속해서 5개가 놓이면
				if (count == 5) {
					winner(board[j][i]);
					return true;
				}
			}
		}
	}
	return false;
}

//해당 돌이 무슨 돌인지 체크
void winner(int stone) {
	if (stone == 1) {
		printf("Black\n");
	}
	else if (stone == 2) {
		printf("White\n");
	}
}
