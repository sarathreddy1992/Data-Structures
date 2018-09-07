#pragma once
#include<iostream>
#include<algorithm>
#include"Isort.h"
#include<string>
#include"windowswatch.h"
#include<vector>

using namespace std;

/*void _introsort(int a[], int n);
int _partition(int a[], int first, int last);
void _insertion(int a[], int n);
void _swap(int *a, int *b);
void _doheap(int a[], int begin, int end);
void _heapsort(int a[], int begin, int end);
bool _isSorted(int a[], int end);*/


class IntroSort : public Isort
{
public:
	void sort(std::vector<int> &vect)
	{

		WindowsStopwatch timer;
		
		std::cout << "Intro sort for elements \n" << vect.size() << std::endl;
		int size = vect.size();
		int least = 0;
		int temp = 0;
		int a[1000000];
		timer.start();
		for (int i = 0; i < size; i++)
		{
			a[i] = vect[i];
		}
		_introsort(a, vect.size());
		for (int i = 0; i < 10; i++)
		{
			std::cout << a[i];
		}
		timer.stop();
		std::cout << "\n Time taken for Intro sort to sort elements :\t : \t " << timer.gettime() << std::endl;
	}

	void introsort_r(int a[], int first, int last, int depth)

	{
		while (last - first > 0) {
			if (depth = 0)
				_heapsort(&a[first], first, last - first + 1);
			else {
				int pivot;
				if (_isSorted(a, last))
					break;
				pivot = _partition(a, first, last);
				introsort_r(a, pivot + 1, last, depth - 1);
				last = pivot - 1;
			}
		}
	}

	void _introsort(int a[], int n)
	{
		introsort_r(a, 0, n - 1, (int(2 * log(double(n)))));
		_insertion(a, n);
	}

	int _partition(int a[], int first, int last) {
		int pivot, mid = (first + last) / 2;

		pivot = a[first] > a[mid] ? first : mid;

		if (a[pivot] > a[last])
			pivot = last;

		_swap(&a[pivot], &a[first]);
		pivot = first;

		while (first < last) {
			if (a[first] <= a[last])
				_swap(&a[pivot++], &a[first]);
			++first;
		}

		_swap(&a[pivot], &a[last]);
		return pivot;
	}

	void _insertion(int a[], int n) {
		int i;
		for (i = 1; i < n; i++) {
			int j, save = a[i];
			for (j = i; j >= 1 && a[j - 1] > save; j--)
				a[j] = a[j - 1];
			a[j] = save;
		}
	}

	void _swap(int *a, int *b) {
		int save = *a;
		*a = *b;
		*b = save;
	}
	void _doheap(int a[], int begin, int end) {
		int save = a[begin];
		while (begin <= end / 2) {
			int k = 2 * begin;
			while (k < end && a[k] < a[k + 1])
				++k;
			if (save >= a[k])
				break;
			a[begin] = a[k];
			begin = k;
		}
		a[begin] = save;
	}

	void _heapsort(int a[], int begin, int end) {
		int i;
		for (int i = (end - 1) / 2; i >= begin; i--) {
			_doheap(a, i, end - 1);
		}
		for (i = end - 1; i > begin; i--) {
			_swap(&a[i], &a[begin]);
			_doheap(a, begin, i - 1);
		}
	}
	bool _isSorted(int a[], int end) {
		for (int i = 0; i < end; i++) {
			if (a[i] > a[i + 1]) {
				return false;
			}
			else {
				return true;
			}

			

		}
	}
	void printElements(std::vector<int>& vect)   // vector elements
	{
		int i = 0;
		for (int i = 0; i < vect.size(); i++)
			std::cout << " " << vect[i] << std::endl;
	}
};