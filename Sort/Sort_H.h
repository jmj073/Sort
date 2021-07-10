#ifndef SORT_H
#define SORT_H

#include <string.h>
#include <malloc.h>

//스택을 위한 구조체
typedef struct Node {
	int Left;
	int Right;
	struct Node* Down;
} Node;

//버블 정렬
void BubbleSort(int DataSet[], int Length);
//삽입 정렬
void InsertionSort(int Dataset[], int Length);
//스왑
void Swap(int* A, int* B);
//파티다!!!
int Partition(int DataSet[], int Left, int Right);
//quick정렬
void QuickSort(int DataSet[], int Left, int Right);
//qsort를 위한 함수
int CompareScore(const void* _elem1, const void* _elem2);
//스택을 이용한 퀵정렬
void SQuickSort(int DataSet[], int Length);
//노드 만들기
Node* QCreateNode(int Left, int Right);
//푸쉬
void QPush(Node** Stack, Node* NewNode);
//팝
Node* QPop(Node** Stack);
//빗질정렬
void comb_sort(int* data, int n);
#endif //SORT_H