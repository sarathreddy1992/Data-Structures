#pragma once

#include<iostream>
#include<algorithm>
#include"Isort.h"
#include<string>
#include"windowswatch.h"
#include<vector>

class HeapSort : public Isort
{
public:
	void sort(std::vector<int> &vect) 
	{

		WindowsStopwatch timer;
		timer.start();
		std::cout << "Heap sort for elements \n" << vect.size() << std::endl;
		int begin = 0;
		int end = vect.size() - 1;
		make_heap(vect, begin, end);
		heap_sort(vect, begin, end);
		timer.stop();
		std::cout <<"\n time taken for sorting in heap sort  "<< timer.gettime() << std::endl;
		}
		
	void _swap(int *a, int *b) 
{
		int save = *a;
		*a = *b;
		*b = save;
	}

			void make_heap(std::vector<int>& vect, int begin, int end) {
				int save = vect[begin];
				while (begin <= end / 2) {
					int k = 2 * begin;
					while (k < end && vect[k] < vect[k + 1])
						++k;
					if (save >= vect[k])
						break;
					vect[begin] = vect[k];
					begin = k;
				}
				vect[begin] = save;
			}

			void heap_sort(std::vector<int>& vect, int begin, int end) {
				int i;
				for (int i = (end - 1) / 2; i >= begin; i--) {
					make_heap(vect, i, end - 1);
				}
				for (i = end - 1; i > begin; i--) {
					_swap(&vect[i], &vect[begin]);
					make_heap(vect, begin, i - 1);
				}
		
			}
	void printElements(std::vector<int>& vect)   // vector elements
	{
		int i = 0;
		for (int i = 0; i < vect.size(); i++)
			std::cout << " " << vect[i] << std::endl;
	}


};
