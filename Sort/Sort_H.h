#ifndef SORT_H
#define SORT_H

#include <string.h>
#include <malloc.h>

//������ ���� ����ü
typedef struct Node {
	int Left;
	int Right;
	struct Node* Down;
} Node;

//���� ����
void BubbleSort(int DataSet[], int Length);
//���� ����
void InsertionSort(int Dataset[], int Length);
//����
void Swap(int* A, int* B);
//��Ƽ��!!!
int Partition(int DataSet[], int Left, int Right);
//quick����
void QuickSort(int DataSet[], int Left, int Right);
//qsort�� ���� �Լ�
int CompareScore(const void* _elem1, const void* _elem2);
//������ �̿��� ������
void SQuickSort(int DataSet[], int Length);
//��� �����
Node* QCreateNode(int Left, int Right);
//Ǫ��
void QPush(Node** Stack, Node* NewNode);
//��
Node* QPop(Node** Stack);
//��������
void comb_sort(int* data, int n);
#endif //SORT_H