#pragma once

#include<iostream>
#include<algorithm>
#include"Isort.h"
#include<string>
#include"windowswatch.h"
#include<vector>

class Selection : public Isort
{
public:
	void sort(std::vector<int> &vect)
	{

		WindowsStopwatch timer;

		std::cout << "selection sort for elements \n" << vect.size() << std::endl;
		int size = vect.size();
		int least = 0;
		int temp = 0;

		timer.start();

		for (int i = 0; i < size; i++)            //iterate through the entire list
		{
			least = i;
			for (int j = i + 1; j < size; j++)    // select the minimum from the rest of the vector
			{
				if (vect[j] < vect[least])        // ascending order
				{
					least = j;                    // the position of minimum element

				}
			}
			if (least != i)
			{
				temp = vect[i];
				vect[i] = least;                  // swap
				vect[least] = temp;
			}
		}


		timer.stop();
		std::cout << "\n Time taken for selection sort to sort elements\t : \t " << timer.gettime() << std::endl;
	}



	void printElements(std::vector<int>& vect)   // vector elements
	{
		int i = 0;
		for (int i = 0; i < vect.size(); i++)
			std::cout << " " << vect[i] << std::endl;
	}

};
#pragma once
