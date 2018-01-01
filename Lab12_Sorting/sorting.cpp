#include <iostream>
#include "sorting.h"

using namespace std;

//--------------------------------------------------------------------
// Constructor

template <class LE>
Sorting<LE>::Sorting(LE *original)
	:num_compare(0)
{
	list = new LE[MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++)
		list[i] = original[i];
}

//--------------------------------------------------------------------
// Destructor

template <class LE>
Sorting<LE>::~Sorting()
{
	delete[] list;
}

//--------------------------------------------------------------------
// Insertion sort, compare횟수 반환

template <class LE>
int Sorting<LE>::insertion_sort(int n)
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		int start = 0;
		int end = i;
		bool finished = false;
		int current = end;
		bool moreToSearch = (current != start);

		while (moreToSearch && !finished)
		{
			if (list[current] < list[current - 1])
			{
				swap(list[current], list[current - 1]);
				current--;
				moreToSearch = (current != start);

				num_compare++;
			}
			else
				finished = true;
		}
	}
	return num_compare;
}

//--------------------------------------------------------------------
// Quick Sort, compare횟수 반환

template <class LE>
int Sorting<LE>::quick_sort(int left, int right)
{
	quickPartition(list, 0, left, right);
	return num_compare;
}

//--------------------------------------------------------------------
// merge sort, compare횟수 반환
// 분할 함수

template <class LE>
int Sorting<LE>::merge_sort(int left, int right)
{
	int mid;

	// 분할이 되지 않았을 경우 if문
	if (left < right)
	{
		mid = (left + right) / 2;

		merge_sort(left, mid);				// 왼쪽 재귀호출
		merge_sort(mid + 1, right);			// 오른쪽 재귀호출

		merge(list, left, mid, right);		// 분할 병합 정렬
	}
	return num_compare;
}

//--------------------------------------------------------------------
// list를 복사, compare 변수는 항상 0으로 초기화

template <class LE>
void Sorting<LE>::copy_list(LE newList[], int n, int compare)
{
	for (int i = 0; i < MAX_SIZE; i++)
		list[i] = newList[i];

	num_compare = compare;
}

//--------------------------------------------------------------------
// list를 left에서 right까지만 출력

template <class LE>
void Sorting<LE>::print_list(int left, int right)
{
	for (int i = left; i <= right; i++)
		cout << list[i] << '\t';

	cout << endl;
}

//--------------------------------------------------------------------
// merge
// 병합 함수

template <class LE>
void Sorting<LE>::merge(LE keyList[], int left, int mid, int right)
{
	int i, j, k, m;

	i = left;
	j = mid + 1;
	k = left;

	int tempArray[MAX_SIZE];

	// left부터 mid까지, mid+1부터 right까지 비교
	while (i <= mid&&j <= right)
	{
		if (keyList[i] < keyList[j])
		{
			tempArray[k] = keyList[i];
			i++;
		}
		else
		{
			tempArray[k] = keyList[j];
			j++;
		}
		k++;

		num_compare++;
	}

	if (i > mid)
	{
		for (m = j; m <= right; m++)
		{
			tempArray[k] = keyList[m];
			k++;
		}
		num_compare++;
	}
	else
	{
		for (m = i; m <= mid; m++)
		{
			tempArray[k] = keyList[m];
			k++;
		}
		num_compare++;
	}

	for (m = left; m <= right; m++)
		keyList[m] = tempArray[m];
}

//--------------------------------------------------------------------
// quick sort partition
// Quick Sort : 분할과 동시에 정렬을 진행하는 알고리즘

template <class LE>
void Sorting<LE>::quickPartition(LE keyList[], int numKeys, int left, int right)
{
	int pivot, less, more;				// 기준 값 설정, 기준보다 작은 값은 왼쪽, 큰 값은 오른쪽으로 옮기기
	pivot = list[left];
	less = left,						// 가장 왼쪽 배열의 인덱스 저장 변수
	more = right;						// 가장 오른쪽 배열의 인덱스 저장 변수

	while (left < right)		// right가 left보다 클 때만 반복
	{
		// right비교 진행
		while (pivot <= list[right] && left < right)	// 비교한 배열값이 pivot보다 크면
			right--;									// right 하나 감소시키고 비교 반복
		if (left > right) break;						// pivot보다 작은 값을 찾으면 반복 멈춤

		// left비교 진행
		while (pivot >= list[left] && left < right)		// 비교한 배열값이 pivot보다 작으면
			left++;										// left 하나 증가시키고 비교 반복
		if (left > right) break;						// pivot보다 큰 값 찾으면 반복 멈춤

		swap(list[left], list[right]);					// left인덱스 값과 right인덱스 값 바꾸기
	}
	num_compare++;

	swap(list[less], list[left]);				// left값과 pivot값 바꾸기

	if (less < left)
		quick_sort(less, left - 1);				// 맨 왼쪽부터 left-1까지 quick_sort반복

	if (more > right)
		quick_sort(left + 1, more);				// left+1 부터 맨 오른쪽까지 quick_sort반복
}
