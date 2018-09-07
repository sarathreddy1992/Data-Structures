#pragma once
#include"Isort.h"
#include<string>
#include"windowswatch.h"
#include<vector>


class QuickSort : public Isort
{
public:
	void sort(std::vector<int> &vect)
	{
		WindowsStopwatch timer;
		timer.start();
		std::cout << "Heap sort for elements \n" << vect.size() << std::endl;
		int low = 0;
		int high = vect.size() - 1;
		quickSort(vect, low, high);

		timer.stop();
		std::cout << "\n time taken for sorting in heap sort  " << timer.gettime() << std::endl;
	}
		void quickSort(std::vector<int> vect, int low, int high)
		{
			int i = low;
			int j = high;
			int pivot = vect[(i + j) / 2];
			int temp;

			while (i <= j)
			{
				while (vect[i] < pivot)
					i++;
				while (vect[j] > pivot)
					j--;
				if (i <= j)
				{
					temp = vect[i];
					vect[i] = vect[j];
					vect[j] = temp;
					i++;
					j--;
				}
			}
			if (j > low)
				quickSort(vect, low, j);
			if (i < high)
				quickSort(vect, i, high);
		}
	void printElements(std::vector<int>& vect)   // vector elements
	{
		int i = 0;
		for (int i = 0; i < vect.size(); i++)
			std::cout << " " << vect[i] << std::endl;
	}

};