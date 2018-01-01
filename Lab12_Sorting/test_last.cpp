#include <iostream>
#include "sorting.cpp"
using namespace std;

void main() {

	int original[] = { 25, 5, 37, 1, 61, 11, 59, 15, 48, 19 };  //������ �׽�Ʈ ������
	Sorting<int> testSort(original);
	int compare = 0;

	/*Insertion sort*/
	cout << endl << " ----- insertion sort ----- " << endl;
	testSort.copy_list(original, MAX_SIZE, 0);
	testSort.print_list(0, MAX_SIZE - 1);
	compare = testSort.insertion_sort(MAX_SIZE);
	cout << endl;
	testSort.print_list(0, MAX_SIZE - 1);
	cout << endl << " Total number of comparision =  " << compare << endl;

	/*Quick sort*/
	cout << endl << " ---- quick sort ---- " << endl;
	testSort.copy_list(original, MAX_SIZE, 0);
	testSort.print_list(0, MAX_SIZE - 1);
	compare = testSort.quick_sort(0, MAX_SIZE - 1);
	cout << endl;
	testSort.print_list(0, MAX_SIZE - 1);
	cout << endl << " Total number of comparision =  " << compare << endl;

	/*Merge sort*/
	cout << endl << " ---- merge sort ---- " << endl;
	testSort.copy_list(original, MAX_SIZE, 0);
	testSort.print_list(0, MAX_SIZE - 1);
	compare = testSort.merge_sort(0, MAX_SIZE - 1);
	cout << endl;
	testSort.print_list(0, MAX_SIZE - 1);
	cout << endl << " Total number of comparision =  " << compare << endl;

}