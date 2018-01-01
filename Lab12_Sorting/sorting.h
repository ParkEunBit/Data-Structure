#ifndef __SORTING_H__
#define __SORTING_H__

#define MAX_SIZE 10
#define true 1
#define false 0

template <class LE>
class Sorting {
public:

	Sorting(LE *original); //Constructor
	~Sorting(); 

	int insertion_sort(int n); //Insertion sort, compareȽ�� ��ȯ
	int quick_sort(int left, int right); //quick sort, compareȽ�� ��ȯ
	int merge_sort(int left, int right); //merge sort, compareȽ�� ��ȯ

	void copy_list(LE newList[], int n, int compare); //list�� ����, compare ������ �׻� 0���� �ʱ�ȭ
	void print_list(int left, int right); //list�� left���� right������ ���

private:
	void merge(LE keyList[], int left, int mid, int right); //merge
	void quickPartition(LE keyList[], int numKeys, int left, int right); //quick sort partition

	LE *list; //������ ������ list
	int num_compare; //Ű �� ��ȸ�� ī��Ʈ�� ���� ����
};




#endif