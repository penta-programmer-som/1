#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SET_SIZE 10
#define HAVE_ELEMENT 1
#define DO_NOT_HAVE_ELEMENT 0
// If the set has the element, returns 1;
// else return 0;
int hasElement(int set[], int size, int element)
{
	int i = 0;
	for (i = 0; i < size; i++)
		if (set[i] == element)
			return HAVE_ELEMENT; // we found it!
	return DO_NOT_HAVE_ELEMENT;
}
// 원소를 집합에 추가. 이미 존재하면 추가하지 않고 redundant라고 출력한다. 현재의 집합 크기를 반환한다.
int addOneElement(int set[], int size, int element)
{
	for (int i = 0; i < size; i++) {
		if (set[i] == element) {
			printf("It is redundant. Please retry.\n");
			return size;
		}
	}
	return size + 1;
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
int setUnion(int set1[], int size1, int set2[], int size2, int setResult[])
{
	int i, k = 0;
	for (i = 0; i < size1; i++)
		setResult[k++] = set1[i];
	for (i = 0; i < size2; i++) {
		if (hasElement(setResult, k, set2[i]) == DO_NOT_HAVE_ELEMENT)
			setResult[k++] = set2[i];
	}
	return k;
}

int setIntersecton(int set1[], int size1, int set2[], int size2, int setResult[])
{
	int i, j = 0;
	for (i = 0; i < size1; i++) {
		if (hasElement(set2, size2, set1[i]) == HAVE_ELEMENT)
			setResult[j++] = set1[i];
	}
	return j;
}
int setComplements(int set1[], int size1, int set2[], int size2, int setResult[])
{
	int i, j = 0;
	for (i = 0; i < size1; i++) {
		if (hasElement(set2, size2, set1[i]) == DO_NOT_HAVE_ELEMENT)
			setResult[j++] = set1[i];
	}
	return j;
}

int main(int argc, char* argv[])
{
	int i;
	int setA[MAX_SET_SIZE];
	int setB[MAX_SET_SIZE];
	int setC[MAX_SET_SIZE * 2];
	int sizeA;
	int sizeB;
	int sizeC;
	printf("Enter the size of Set A:");
	scanf("%d", &sizeA);
	i = 0;
	while (i < sizeA)
	{
		printf("Enter the number for Set A (%d/%d):", i + 1, sizeA);
		scanf("%d", &setA[i]);
		i = addOneElement(setA, i, setA[i]);
	}
	printf("Enter the size of Set B:");
	scanf("%d", &sizeB);
	i = 0;
	while (i < sizeB)
	{
		printf("Enter the number for Set B (%d/%d):", i + 1, sizeB);
		scanf("%d", &setB[i]);
		i = addOneElement(setB, i, setB[i]);
	}
	printf("Set A: ");
	printSet(setA, sizeA);
	printf("Set B: ");
	printSet(setB, sizeB);
	sizeC = setUnion(setA, sizeA, setB, sizeB, setC); // Union, setC is the result set
	printf("Union of setA and setB: ");
	printSet(setC, sizeC);
	sizeC = setIntersecton(setA, sizeA, setB, sizeB, setC); //Intersection, setC is the result set
	printf("Intersection of setA and setB: ");
	printSet(setC, sizeC);
	sizeC = setComplements(setA, sizeA, setB, sizeB, setC); //Complements, setC is the result set
	printf("Set-theoretic difference of setA and setB (setA - setB): ");
	printSet(setC, sizeC);
	return 0;
}