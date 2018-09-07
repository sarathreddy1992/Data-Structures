#pragma once
#include<iostream>
#include<algorithm>
#include"Isort.h"
#include<string>
#include"windowswatch.h"
#include<vector>

class CombSort : public Isort
{
public:
	void sort(std::vector<int> &vect)
	{

		WindowsStopwatch timer;
		timer.start();

		std::cout << "Comb sort for elements \n" << vect.size() << std::endl;

		int temp;
		int i;
		int gap = 0;
		bool swapped = false;
		bool ascending=true;
		//Checking to see if the gap value has reached one and no swaps have occurred.
		//If so, then the set has been sorted.
		while ((gap > 1) || swapped)
		{
			//Calculation of the gap value.
			if (gap > 1)
			{
				gap = (int)((double)gap / 1.3);
			}
			swapped = false;

			for (i = 0; gap + i < vect.size(); ++i)
			{
				if (ascending)	//ascending ordering
				{
					if (vect[i] - vect[i + gap] > 0)
					{
						temp = vect[i];
						vect[i] = vect[i + gap];
						vect[i + gap] = temp;
						swapped = true;
					}
				}

			}
		}
		timer.stop();
		std::cout << "\n Time taken for comb sort to sort elements :\t : \t " << timer.gettime() << std::endl;
	}
	void printElements(std::vector<int>& vect)   // vector elements
	{
		int i = 0;
		for (int i = 0; i < vect.size(); i++)
			std::cout << " " << vect[i] << std::endl;
	}
};