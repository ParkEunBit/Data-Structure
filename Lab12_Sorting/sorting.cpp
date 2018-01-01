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
// Insertion sort, compareȽ�� ��ȯ

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
// Quick Sort, compareȽ�� ��ȯ

template <class LE>
int Sorting<LE>::quick_sort(int left, int right)
{
	quickPartition(list, 0, left, right);
	return num_compare;
}

//--------------------------------------------------------------------
// merge sort, compareȽ�� ��ȯ
// ���� �Լ�

template <class LE>
int Sorting<LE>::merge_sort(int left, int right)
{
	int mid;

	// ������ ���� �ʾ��� ��� if��
	if (left < right)
	{
		mid = (left + right) / 2;

		merge_sort(left, mid);				// ���� ���ȣ��
		merge_sort(mid + 1, right);			// ������ ���ȣ��

		merge(list, left, mid, right);		// ���� ���� ����
	}
	return num_compare;
}

//--------------------------------------------------------------------
// list�� ����, compare ������ �׻� 0���� �ʱ�ȭ

template <class LE>
void Sorting<LE>::copy_list(LE newList[], int n, int compare)
{
	for (int i = 0; i < MAX_SIZE; i++)
		list[i] = newList[i];

	num_compare = compare;
}

//--------------------------------------------------------------------
// list�� left���� right������ ���

template <class LE>
void Sorting<LE>::print_list(int left, int right)
{
	for (int i = left; i <= right; i++)
		cout << list[i] << '\t';

	cout << endl;
}

//--------------------------------------------------------------------
// merge
// ���� �Լ�

template <class LE>
void Sorting<LE>::merge(LE keyList[], int left, int mid, int right)
{
	int i, j, k, m;

	i = left;
	j = mid + 1;
	k = left;

	int tempArray[MAX_SIZE];

	// left���� mid����, mid+1���� right���� ��
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
// Quick Sort : ���Ұ� ���ÿ� ������ �����ϴ� �˰���

template <class LE>
void Sorting<LE>::quickPartition(LE keyList[], int numKeys, int left, int right)
{
	int pivot, less, more;				// ���� �� ����, ���غ��� ���� ���� ����, ū ���� ���������� �ű��
	pivot = list[left];
	less = left,						// ���� ���� �迭�� �ε��� ���� ����
	more = right;						// ���� ������ �迭�� �ε��� ���� ����

	while (left < right)		// right�� left���� Ŭ ���� �ݺ�
	{
		// right�� ����
		while (pivot <= list[right] && left < right)	// ���� �迭���� pivot���� ũ��
			right--;									// right �ϳ� ���ҽ�Ű�� �� �ݺ�
		if (left > right) break;						// pivot���� ���� ���� ã���� �ݺ� ����

		// left�� ����
		while (pivot >= list[left] && left < right)		// ���� �迭���� pivot���� ������
			left++;										// left �ϳ� ������Ű�� �� �ݺ�
		if (left > right) break;						// pivot���� ū �� ã���� �ݺ� ����

		swap(list[left], list[right]);					// left�ε��� ���� right�ε��� �� �ٲٱ�
	}
	num_compare++;

	swap(list[less], list[left]);				// left���� pivot�� �ٲٱ�

	if (less < left)
		quick_sort(less, left - 1);				// �� ���ʺ��� left-1���� quick_sort�ݺ�

	if (more > right)
		quick_sort(left + 1, more);				// left+1 ���� �� �����ʱ��� quick_sort�ݺ�
}
