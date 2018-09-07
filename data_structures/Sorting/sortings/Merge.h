#pragma once

#include<iostream>
#include<algorithm>
#include"Isort.h"
#include<string>
#include"windowswatch.h"
#include<vector>

class MergeSort : public Isort
{
public:
	void sort(std::vector<int> &vect )
	{

		WindowsStopwatch timer;
		timer.start();

		std::cout << "Merge sort for elements \n" << vect.size() << std::endl;
		int start=0;
		int start2=0;
		int end=0;
		int x = start;
		int y = start2;
		int i = start;
		while (x < start2 && y <= end) {
			if (vect[x] < vect[y])
				vect[i++] = vect[x++];
			else
				vect[i++] = vect[y++];
		}
		while (x < start2) {
			vect[i++] = vect[x++];
		}
		while (y <= end) {
			vect[i++] = vect[y++];
		}
		for (i = start; i <= end; i++) {
			vect[i] = vect[i];
		}
		timer.stop();
		std::cout << "\n Time taken for merge sort to sort elements :\t  " << timer.gettime() << std::endl;

		
		}
	void printElements(std::vector<int>& vect)   // vector elements
	{
		int i = 0;
		for (int i = 0; i < vect.size(); i++)
			std::cout << " " << vect[i] << std::endl;
	}
};