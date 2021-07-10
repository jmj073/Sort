#include "Sort_H.h"

//버블 정렬
void BubbleSort(int DataSet[], int Length) {
	int i, j, temp, cnt;
	Length--;
	for (i = 0; i < Length; i++) {
		cnt = 0;
		for (j = 0; j < Length - i; j++) {
			if (DataSet[j] > DataSet[j + 1]) {
				temp = DataSet[j];
				DataSet[j] = DataSet[j + 1];
				DataSet[j + 1] = temp;
				cnt++;
			}
		}
		if (!cnt) break;
	}
}

//삽입 정렬
void InsertionSort(int Dataset[], int Length) {
	int i, j, value;
	for (i = 1; i < Length; i++) {
		if (Dataset[i - 1] <= Dataset[i])
			continue;
		value = Dataset[i];
		for (j = 0; j < i; j++) {
			if (Dataset[j] > value) {
				memmove(Dataset + j + 1, Dataset + j, sizeof(*Dataset) * (i - j));
				Dataset[j] = value;
				break;
			}
		}
	}
}

//스왑
void Swap(int* A, int* B) {
	int Temp = *A;
	*A = *B;
	*B = Temp;
}

//파티다!!!
int Partition(int DataSet[], int Left, int Right) {
	int First = Left;
	int Pivot = DataSet[First];
	++Left;

	while (Left <= Right) {
		while (DataSet[Left] <= Pivot && Left < Right)//Pivot과 같거나 작고 Right보다 작다
			++Left;
		while (DataSet[Right] > Pivot && Left <= Right)//Pivot보다 크고 Left와 같거나 크다
			--Right;
		if (Left < Right)
			Swap(DataSet + Left, DataSet + Right);
		else
			break;
	}

	Swap(DataSet + First, DataSet + Right);

	return Right;
}

//quick정렬
void QuickSort(int DataSet[], int Left, int Right) {
	if (Left < Right) {
		int Index = Partition(DataSet, Left, Right);
		QuickSort(DataSet, Left, Index - 1);
		QuickSort(DataSet, Index + 1, Right);
	}
}

//스택을 이용한 퀵정렬
void SQuickSort(int DataSet[], int Length) {
	int Left = 0, Right = Length - 1, Pivot;
	Node* Stack = NULL, * Node;
	QPush(&Stack, QCreateNode(Left,Right));

	while (Stack != NULL) {
		Node = QPop(&Stack);
		Left = Node->Left, Right = Node->Right;
		Pivot = Partition(DataSet, Left, Right);
		free(Node);

		if (Pivot - 1 > Left)
			QPush(&Stack, QCreateNode(Left, Pivot - 1));
		if (Pivot + 1 < Right)
			QPush(&Stack, QCreateNode(Pivot + 1, Right));
	}
}

//qsort를 위한 함수
int CompareScore(const void* _elem1, const void* _elem2) {
	return *(int*)_elem1 - *(int*)_elem2;
}

//노드 만들기
Node* QCreateNode(int Left, int Right) {
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Down = NULL;
	NewNode->Left = Left;
	NewNode->Right = Right;
}

//푸쉬
void QPush(Node** Stack, Node* NewNode) {
	NewNode->Down = *Stack;
	*Stack = NewNode;
}

//팝
Node* QPop(Node** Stack) {
	Node* Remove = *Stack;
	*Stack = Remove->Down;

	return Remove;
}

//빗질정렬
void comb_sort(int* data, int n)
{
	const double shrink = 1.3;
	int j, tmp, gap = n, swapped = 1;

	while (gap > 1 || swapped)
	{
		if ((gap /= shrink) < 1) gap = 1;
		for (j = swapped = 0; j < n - gap; j++)
		{
			//오름차순 정렬 (뒤에것이 더 크면 건너뜀
			if (data[j] <= data[j + gap]) continue;
			//한번이라도 스왑이 일어나면 다시 반복
			swapped = 1;
			tmp = data[j]; data[j] = data[j + gap]; data[j + gap] = tmp;
		}
	}
}