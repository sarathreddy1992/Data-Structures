#pragma once

#include<iostream>
#include<vector>

struct Isort
{
public:
	Isort() {}
	virtual ~Isort() {}
	virtual void sort(std::vector<int> &vector) = 0;

};
#pragma once
