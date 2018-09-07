#pragma once
#include<iostream>
#include<algorithm>
#include"Isort.h"
#include<string>
#include"windowswatch.h"
#include<vector>

class ShellSort : public Isort
{
public:
	void sort(std::vector<int> &vect)
	{

		WindowsStopwatch timer;
		std::cout << "shell sort for elements \n" << vect.size() << std::endl;
		timer.start();
		int i, j, increase, current;
		increase = vect.size() / 2;
		while (increase > 0)
		{
			for (i = 0; i < vect.size(); i++)
			{
				j = i;
				current = vect[i];
				while ((j >= increase) && (vect[j - increase] > current))
				{
					vect[j] = vect[j - increase];
					j = j - increase;
				}
				vect[j] = current;
			}
			if (increase / 2 != 0)
				increase = increase / 2;
			else if (increase == 1)
				increase = 0;
			else
				increase = 1;
		}

		timer.stop();
		std::cout << "\n Time taken for shell sort to sort elements :\t : \t " << timer.gettime() << std::endl;
	}
	void printElements(std::vector<int>& vect)   // vector elements
	{
		int i = 0;
		for (int i = 0; i < vect.size(); i++)
			std::cout << " " << vect[i] << std::endl;
	}
};