#pragma once

#include<iostream>
#include<algorithm>
#include"Isort.h"
#include<string>
#include"windowswatch.h"
#include<vector>


class Insertion : public Isort
{
public:
	void sort(std::vector<int> &vect)
	{

		WindowsStopwatch timer;
          timer.start();
		  unsigned size = vect.size();
		  unsigned temp = 0;

std::cout << "Insertion sort for elements \n" << vect.size() << std::endl;
		unsigned i, j, tmp;
		for (unsigned i = 1; i < vect.size(); i++) {
			j = i;
			while (j > 0 && vect[j - 1] > vect[j]) {
				tmp = vect[j];
				vect[j] = vect[j - 1];
				vect[j - 1] = tmp;
				--j;
			}
		}
		timer.stop();
		std::cout << "\n Time taken for insertion sort to sort elements :\t : \t " << timer.gettime() << std::endl;
	}



	void printElements(std::vector<int>& vect)   // vector elements
	{
		unsigned i = 0;
		for (unsigned i = 0; i < vect.size(); i++)
			std::cout << " " << vect[i] << std::endl;
	}

};