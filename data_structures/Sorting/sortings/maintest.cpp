#pragma once
#include<iostream>
#include<fstream>
#include"RadixSort.h"
#include"Heap.h"
#include"shell.h"
#include"CountSort.h"
#include"Selection.h"
#include"Bubble.h"
#include"insertion.h"
#include"CombSort.h"
#include"Intro.h"
#include"Merge.h"
#include"QuickSort.h"
#include<vector>
#include<string>
#include<sstream>

int main()
{
	
	std::cout << "descending order file" << std::endl;

	std::vector<int> dcurrent;
	std::ifstream infiledesc("..//..//decsending.txt");  //Addding descending order text file
	std::string dstr;
	std::vector<std::string> d_read;
	std::vector<int> d_elems;
	std::vector<std::string> record;
	std::vector<std::string> data;

	if (infiledesc)
	{

	}
	else
	{
		std::cout << "could not read the file";
	}

	//logic for stroing data into a vector by using delimiter
	while (infiledesc)
	{
		std::string s;
		if (!getline(infiledesc, s)) break;

		std::istringstream ss(s);

		while (ss)
		{
			std::string s;
			if (!getline(ss, s, '-')) break;
			record.push_back(s);
		}


	}

	std::vector<int> main;
	for (long i = 0; i < record.size(); i++)
	{
		//::string value = record[i];
		int num = atoi(record.at(i).c_str());
		main.push_back(num);
		

	}

	Selection select;
    Insertion insert;
	Bubble bubble;
	CombSort comb;
	CountSort count;
	HeapSort heap;
   IntroSort intro;
	ShellSort shell;
	RadixSort radix;
	MergeSort merge;
	QuickSort quick;

    for (int i = 1000; i < main.size(); i *= 2)
	{
		std::vector<int> vect;
		for (int j = 0; j < i; j++)
		{

			vect.push_back(main[j]);

		}
		std::vector<int> v_vect;
		v_vect = vect;
		select.sort(vect);
		vect = v_vect;
		bubble.sort(vect);
		vect = v_vect;
		insert.sort(vect);
		vect = v_vect;
		comb.sort(vect);
		vect = v_vect;
		count.sort(vect);
		vect = v_vect;
		heap.sort(vect);
		vect = v_vect;
	    intro.sort(vect);
		vect = v_vect;
		shell.sort(vect);
		vect = v_vect;
		radix.sort(vect);
		vect = v_vect;
		merge.sort(vect);
		//vect = v_vect;
    	//quick.sort(vect);
	}

	

	std::cout << "Random order file" << std::endl;

	std::vector<int> rcurrent;
	std::ifstream infileresc("..//..//random.txt");  //Addding descending order text file
	std::string rstr;
	std::vector<std::string> r_read;
	std::vector<int> r_elems;
	std::vector<std::string> r_record;
	std::vector<std::string> r_data;

	if (infileresc)
	{

	}
	else
	{
		std::cout << "could not read the file";
	}

	//logic for stroing data into a vector by using delimiter
	while (infileresc)
	{
		std::string rs;
		if (!getline(infileresc, rs)) break;

		std::istringstream ss(rs);

		while (ss)
		{
			std::string rs;
			if (!getline(ss, rs, '-')) break;
			r_record.push_back(rs);
		}


	}

	std::vector<int> r_main;
	for (long i = 0; i < r_record.size(); i++)
	{
		
		int r_num = atoi(r_record.at(i).c_str());
		r_main.push_back(r_num);
		

	}

	Selection r_select;
	Insertion r_insert;
	Bubble r_bubble;
	CombSort r_comb;
	CountSort r_count;
	HeapSort r_heap;
	IntroSort r_intro;
	ShellSort r_shell;
	RadixSort r_radix;
	MergeSort r_merge;
	QuickSort r_quick;

		for (int i = 1000; i < r_main.size();)
		{
			std::vector<int> r_vect;
			for (int j = 0; j < i; j++)
			{

				r_vect.push_back(r_main[j]);

			}
			std::vector<int> s_vect;
			s_vect = r_vect;
		    r_select.sort(r_vect);
		    r_vect = s_vect;
			r_bubble.sort(r_vect);
			r_vect = s_vect;
			r_insert.sort(r_vect);
			r_vect = s_vect;
			r_comb.sort(r_vect);
			r_vect = s_vect;
			r_count.sort(r_vect);
			r_vect = s_vect;
			r_heap.sort(r_vect);
			r_vect = s_vect;
            r_intro.sort(r_vect);
			r_vect = s_vect;
			r_shell.sort(r_vect);
			r_vect = s_vect;
			r_radix.sort(r_vect);
			r_vect = s_vect;
			r_merge.sort(r_vect);
		//	r_vect = s_vect;
		//	r_quick.sort(r_vect);
		
		}


	
	std::cout << "Ascending order file" << std::endl;

	std::vector<int> acurrent;
	std::ifstream infileaesc("..//..//ascending.txt");  //Addding descending order text file
	std::string astr;
	std::vector<std::string> a_read;
	std::vector<int> a_elems;
	std::vector<std::string> a_record;
	std::vector<std::string> a_data;

	if (infileaesc)
	{

	}
	else
	{
		std::cout << "could not read the file";
	}

	//logic for stroing data into a vector by using delimiter
	while (infileaesc)
	{
		std::string sa;
		if (!getline(infiledesc, sa)) break;

		std::istringstream ss(sa);

		while (ss)
		{
			std::string sa;
			if (!getline(ss, sa, '-')) break;
			record.push_back(sa);
		}


	}

	std::vector<int> a_main;
	for (long i = 0; i < a_record.size(); i++)
	{
		//::string value = record[i];
		int num = atoi(a_record.at(i).c_str());
		a_main.push_back(num);
		

	}

	Selection a_select;
	Insertion a_insert;
	Bubble a_bubble;
	CombSort a_comb;
	CountSort a_count;
	HeapSort a_heap;
	IntroSort a_intro;
	ShellSort a_shell;
	RadixSort a_radix;
	MergeSort a_merge;
	//QuickSort a_quick;

	for (int i = 1000; i <a_main.size(); i *= 2)
	{
		std::vector<int> a_vect;
		for (int j = 0; j < i; j++)
		{

			a_vect.push_back(a_main[j]);

		}
		std::vector<int> b_vect;
		b_vect = a_vect;
		a_select.sort(a_vect);
		a_vect = b_vect;
		a_bubble.sort(a_vect);
		a_vect = b_vect;
		a_insert.sort(a_vect);
		a_vect = b_vect;
		a_comb.sort(a_vect);
	    a_vect = b_vect;
		a_count.sort(a_vect);
		a_vect = b_vect;
		a_heap.sort(a_vect);
		a_vect = b_vect;
		a_intro.sort(a_vect);
		a_vect = b_vect;
		a_shell.sort(a_vect);
		a_vect = b_vect;
		a_radix.sort(a_vect);
		a_vect = b_vect;
		a_merge.sort(a_vect);
		//a_vect = b_vect;
		//a_quick.sort(a_vect);
	}


	std::cin.get();
	
	return 0;
}