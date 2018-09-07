#pragma once

#include<iostream>
#include<algorithm>
#include"Isort.h"
#include<string>
#include"windowswatch.h"
#include<vector>

class RadixSort : public Isort
{
public:
	void sort(std::vector<int> &vect )
	{

		WindowsStopwatch timer;
		timer.start();
		std::cout << "Radix sort for elements" << vect.size() << std::endl;
		int const MAX = 10;
		static std::vector<int> buckets[MAX];
		int pow = 1;
		int base = 0;

		for (int i = 0; i < MAX; ++i)
		{
			buckets[i].resize(vect.size());
			buckets[i][0] = 0;
		}

		for (int i = 0; i < base; ++i, pow *= 10)
		{
			for (int j = 0; j < MAX; ++j)
			{
				buckets[j][0] = 0;
			}

			for (int j = 0; j < vect.size(); ++j)
			{
				int index = (vect[j] / pow) % 10;
				buckets[index][++buckets[index][0]] = vect[j];
			}

			int cnt = 0;
			for (int j = 0; j < MAX; ++j)
			{
				for (int k = 0; k < buckets[j][0]; ++k)
				{
					vect[cnt++] = buckets[j][k + 1];
				}
			}
		}
		timer.stop();
		std::cout << "\n Time taken for Radix sort to sort elements :\t : \t " << timer.gettime() << std::endl;


	}
	void printElements(std::vector<int>& vect)   // vector elements
	{
		int i = 0;
		for (int i = 0; i < vect.size(); i++)
			std::cout << " " << vect[i] << std::endl;
	}
};