#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SET_SIZE 10
#define HAVE_ELEMENT 1
#define DO_NOT_HAVE_ELEMENT 0
int hasElement(int set[], int size, int element)
{
	int i = 0;
	for (i = 0; i < size; i++)
		if (set[i] == element)
			return HAVE_ELEMENT; // we found it!
	return DO_NOT_HAVE_ELEMENT;
}

int addOneElement(int set[], int size, int element)
{
	for (int i = 0; i < size; i++) {
		if (set[i] == element) {
			printf("It is redundant. Please retry.\n");
			return size;
		}
	}
	set[size] = element;
	return size + 1;
}

int isSetEqual(int set1[], int size1, int set2[], int size2)
{
	if (size1 == size2) {
		for (int i = 0; i < size1; i++) {
			if (hasElement(set1, size1, set2[i]) == DO_NOT_HAVE_ELEMENT)
				return 0;
		}
	}
	else
		return 0;
	return 1;
}

void printSet(int set[], int size)
{
	printf("< ");
	for (int i = 0; i < size; i++) {
		if (i == size - 1) {
			printf("%d ", set[i]);
			break;
		}
		printf("%d, ", set[i]);
	}
	printf(">\n");
	return;
}

int main(void)
{
	int setA[MAX_SET_SIZE] = { 1, 2, 3 };
	int setB[MAX_SET_SIZE] = { 3, 2, 1, 4 };
	int num;
	int sizeA = 3, sizeB = 4;
	printf("A:"); printSet(setA, sizeA);
	printf("B:"); printSet(setB, sizeB);
	if (isSetEqual(setA, sizeA, setB, sizeB))
		printf("���� A �� B �� ����\n");
	else
		printf("���� A �� B �� �ٸ���\n\n");
	printf("A �� 3 �� �߰��ϸ�\n");
	sizeA = addOneElement(setA, sizeA, 3); // 3 �� SetA �� �߰��Ѵ�
	printf("���� A:"); printSet(setA, sizeA);
	printf("A �� 4 �� �߰��ϸ�\n");
	sizeA = addOneElement(setA, sizeA, 4); // 4 �� SetA �� �߰��Ѵ�
	printf("���� A:"); printSet(setA, sizeA);
	if (isSetEqual(setA, sizeA, setB, sizeB))
		printf("���� A �� B �� ����\n");
	else
		printf("���� A �� B �� �ٸ���\n");

}