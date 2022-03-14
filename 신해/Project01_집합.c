#define _CRT_SECURE_NO_WARNINGS
#define MAX_SET_SIZE 10
#define HAVE_ELEMENT 1
#define DO_NOT_HAVE_ELEMENT 0
#include <stdio.h>

// set에 element가 있으면 1, 없으면 0 반환 
int hasElement(int set[], int size, int element)
{
	int i;

	for (i = 0; i < size; i++)
		if (set[i] == element)
			return HAVE_ELEMENT;
	return DO_NOT_HAVE_ELEMENT;
}

void printSet(int set[], int size)
{
	int i = 0;

	printf("{ %d", set[i]);
	for (i = 1; i < size; i++)
		printf(", %d", set[i]);
	printf(" }\n");

}



// set1과 set2가 같으면 1, 다르면 0 반환 
int isSetEqual(int set1[], int size1, int set2[], int size2)
{
	int i, j;

	if (size1 != size2)
		return DO_NOT_HAVE_ELEMENT;

	for (i = 0; i < size1; i++) {
		for (j = 0; j < size2; j++) {
			if (set1[i] == set2[j])
				hasElement(set1, size1, set2);
		}
	}

}

// 원소가 집합에 존재하지 않으면 추가, 존재하면 redundant 출력하고 크기 반환
int addOneElement(int set[], int size, int element)
{
	int i;

	for (i = 0; i < size; i++) {
		if (set[i] == element) {
			printf("It is redundant. Please retry.\n");
			return size;
		}
	}
	set[i++] = element;
	return i;
}
int setUnion(int set1[], int size1, int set2[], int size2, int setResult[])
{
	int i = size1;
	int size3 = size1;
	for (i = 0; i < size1; i++)
	{
		setResult[i] = set1[i];
	}

	for (i = 0; i < size2; i++) {
		if (hasElement(setResult, size3, set2[i]) == DO_NOT_HAVE_ELEMENT) {
			setResult[size3] = set2[i];
			size3++;
		}
	}
	return size3;
}

int setIntersection(int set1[], int size1, int set2[], int size2, int setResult[])
{
	int i = 0;
	int j = 0;
	int size3 = 0;

	for (i = 0; i < size1; i++)
	{
		for (j = 0; j < size2; j++)
		{
			if (set1[i] == set2[j])
			{
				setResult[size3] = set1[i];
				size3++;
			}
		}
	}

	return size3;
}

int setComplements(int set1[], int size1, int set2[], int size2, int setResult[])
{
	int i = 0;
	int size3 = 0;
	for (i = 0; i < size1; i++) {
		if (hasElement(set2, size2, set1[i]) == DO_NOT_HAVE_ELEMENT) 
		{
			setResult[size3] = set1[i];
			size3++;
		}
	}

	return size3;
}

int main(void)
{
	int setA[MAX_SET_SIZE];
	int setB[MAX_SET_SIZE];
	int setC[MAX_SET_SIZE * 2];
	int sizeA, sizeB, sizeC;
	int i = 0;

	printf("Enter the size of Set A : ");
	scanf("%d", &sizeA);

	while (i < sizeA)
	{
		printf("Enter the number of Set A (%d/%d) : ", i + 1, sizeA);
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

	sizeC = setUnion(setA, sizeA, setB, sizeB, setC);
	printf("Union of setA and setB: ");
	printSet(setC, sizeC);

	sizeC = setIntersection(setA, sizeA, setB, sizeB, setC);
	printf("Intersection of setA and setB: ");
	printSet(setC, sizeC);

	sizeC = setComplements(setA, sizeA, setB, sizeB, setC);
	printf("Set-theoretic difference of setA and setB (setA - setB): ");
	printSet(setC, sizeC);
}