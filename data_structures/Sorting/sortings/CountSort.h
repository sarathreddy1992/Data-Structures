#pragma once
#include<iostream>
#include<algorithm>
#include"Isort.h"
#include<string>
#include"windowswatch.h"
#include<vector>

class CountSort : public Isort
{
public:
	void sort(std::vector<int> &vect)
	{

		WindowsStopwatch timer;
		timer.start();
		std::cout << "Count sort for elements \n" << vect.size() << std::endl;
		const long n=0;
		long i;
		long largest = vect[0];
		long *temp = new long[n];
		for (i = 1; i < n; i++)
		{
			if (largest < vect[i])
			{
				largest = vect[i];
			}
		}
		unsigned long *count = new unsigned long[largest + 1];
		for (i = 0; i <= largest; i++)
		{
			count[i] = 0;
		}
		for (i = 0; i < n; i++)
		{
			count[vect[i]]++;
		}
		for (i = 1; i <= largest; i++)
		{
			count[i] = count[i - 1] + count[i];
		}
		for (i = n - 1; i >= 0; i--)
		{
			temp[count[vect[i]] - 1] = vect[i];
			count[vect[i]]--;
		}
		for (i = 0; i < n; i++)
		{
			vect[i] = temp[i];
		}

		timer.stop();

		std::cout << "\n Time taken for count sort to sort elements :" << timer.gettime() << std::endl;
	}
	void printElements(std::vector<int>& vect)   // vector elements
	{
		int i = 0;
		for (int i = 0; i < vect.size(); i++)
			std::cout << " " << vect[i] << std::endl;
	}

};


