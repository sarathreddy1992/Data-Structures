#pragma once
#include<iostream>
#include<algorithm>
#include"Isort.h"
#include<string>
#include"windowswatch.h"
#include<vector>

class Bubble : public Isort
{
public:
	void sort(std::vector<int> &vect)
	{
		WindowsStopwatch timer;

		int temp;
		timer.start();
		std::cout << "Bubble sort for elements \n" << vect.size() << std::endl;
		int n = vect.size();
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = n - 1; j > i; --j)
			{
				if (vect[j] < vect[j - 1])
				{
					temp = vect[j];
					vect[j] = vect[j - 1];
					vect[j - 1] = temp;
				}
			}
		}
		timer.stop();
		std::cout << "\n Time taken for bubble sort to sort elements" << timer.gettime() << std::endl;
	}
	void printElements(std::vector<int>& vect)   // vector elements
	{
		int i = 0;
		for (int i = 0; i < vect.size(); i++)
			std::cout << " " << vect[i] << std::endl;
	}

};