//�׽�Ʈ ��� ������ ��� ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX 100

//���� �Լ�
bool isInclude(char arr[]);
void check(char words[]);
void getMaxLength();

//���� �������� 
char words[MAX];
char result[MAX];
int index[MAX];
int maxStart, maxLength; 

int main() {
	scanf("%s", words);
	check(words);
	getMaxLength();

	//������ġ ���� (������ġ + �ش� ������ ����)���� ���
	for (int i = maxStart; i < maxStart + maxLength; i++) {
		printf("%c", words[i]);
	}

	return 0;
}

//�ش� char�� �������� �������� Ȯ�� .. ���� true / ���� false
bool isInclude(char ch) {
	if (ch == 'a' ||
		ch == 'e' ||
		ch == 'i' ||
		ch == 'o' ||
		ch == 'u') {
		return true;
	}
	return false;
}

//���ڿ��� ��ĵ�ϸ鼭 ������ ������ �ش� ������ ���� �迭 ������ġ�� j�� �����ϰ�,
//index���� �ش� ������ ���ӵ� ���̸� ����
void check(char words[]) {
	for (int i = 0; i < strlen(words); i++) {
		int j = i; //���� index�� ���� ��ġ
		int length = 0;
		while (isInclude(words[i]) == false && (i < strlen(words))) {
			length++;
			i++;
		}
		index[j] = length; //������ ���� ��ġ, ������ ���̸� ����
	}
}

// index�� ��ȸ�ϸ� ���ӵ� ������ ���̰� ���� �� ������ ����������, �� ���̸� ��ȯ
void getMaxLength() {
	maxLength = 0; 
	for (int i = 0; i < strlen(words); i++) {
		if (index[i] > maxLength) {
			maxLength = index[i];
			maxStart = i;
		}
	}
}