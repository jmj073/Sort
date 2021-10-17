#include <iostream>
#include <thread>
#include <ctime>
#include <utility>
#include <vector>
#include <random>


using namespace std;

struct guarded_thread :thread
{
	using thread::thread;
	~guarded_thread() { if (joinable()) join(), cout << "join\n"; }
};


template <typename iter>
iter Partition(iter left, iter right) {
	auto& pivot = *left;
	++left;

	while (left <= right) {
		while (*left <= pivot && left < right) ++left;
		while (*right > pivot && left <= right) --right;

		if (left < right) swap(*left, *right);
		else break;
	}
	swap(pivot, *right);

	return right;
}

template <typename iter>
void QuickSort(iter Left, iter Right) {
	if (Left < Right) {
		iter Index = Partition(Left, Right);
		if (Left != Index)
			QuickSort(Left, Index - 1);
		if (Right != Index)
			QuickSort(Index + 1, Right);
	}
}

// static mutex
template <typename iter>
void QuickSort(iter Left, iter Right, int n_thread) {
	if (Left < Right) {
		guarded_thread task;
		iter Index = Partition(Left, Right);
		if (n_thread > 0) {
			if (Left != Index) {
				--n_thread;
				thread tmp{ [=] { QuickSort(Left, Index - 1, n_thread); } };
				task.swap(tmp);
			}
			if (Right != Index)
				QuickSort(Index + 1, Right, --n_thread);
		}
		else {
			if (Left != Index)
				QuickSort(Left, Index - 1);
			if (Right != Index)
				QuickSort(Index + 1, Right);
		}
	}
}

//template <typename iter>
//// ramdom access iterator
//void qsort(iter begin, iter end/*, int n_thread*/)
//{
//	if (begin != end) --end;
//	vector<pair<iter, iter>> stack;
//	stack.push_back({ begin, end });
//
//	while (!stack.empty()) {
//		cout << stack.size() << endl;
//		pair<iter, iter> idx = stack.back();
//		stack.pop_back();
//		
//		if (idx.first >= idx.second)
//			continue;
//
//		iter pivot = Partition(idx.first, idx.second);
//
//		if (pivot != begin)
//			stack.push_back({ idx.first, pivot - 1 });
//		if (pivot != end)
//			stack.push_back({ pivot + 1, idx.second});
//	}
//}

template <typename iter>
inline void qsort(iter begin, iter end, int n_thread) {
	if (begin != end)
		QuickSort(begin, end - 1, n_thread);
}

template <typename iter>
inline void qsort(iter begin, iter end) {
	if (begin != end)
		QuickSort(begin, end - 1);
}

// 0 12590 12785
// 1 12630 8086 10576
// 2 8150 7768
// 3 9184 8572 8488

// 0 85 117 95 99
// 1 133 75 83 89
// 2 87 100 76 76
// 3 122 69 70 50

int main() {
	vector<int> a;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 10000);

	for (int i = 0; i < 1000000; i++)
		a.push_back(dis(gen));
	clock_t take = clock();
	qsort(a.begin(), a.end());
	cout << clock() - take;
	/*for (auto& i : a)
		cout << i << ' ';*/
}