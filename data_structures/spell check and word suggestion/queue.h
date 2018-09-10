#ifndef QUEUE_H
#define QUEUE_H

#include <string>

using namespace std;
//----------------------------------<Defining a node>----------------------------------------------

class Queue
{
private:
	Queue* head = nullptr;  //setting a pointer to head
	Queue* tail = nullptr;  // setting a pointer to tail 

public:
	std::string data;     //store data
	Queue* next;   //store address of next node
	void Enqueue(std::string);
	std::string Dequeue();
};




void Queue::Enqueue(std::string x )
{
	Queue* temp;          //creating a node
	temp = new Queue();//acllocating space in dynamic memory
	temp->data = x;

	//temp->next = nullptr;

	if (!head && !tail)   //Node is empty
	{
		head = tail = temp;  // set the pointer to temp
		return;
	}
	tail->next = temp;  //point the pointer to the current node		
		tail = temp;   //store the address of the newly created node
}




std::string Queue::Dequeue()
{
	std::string mystring;
	Queue* temp = head;   
	if (!head && !tail)
		return mystring;
	if (head == tail)
	{
		mystring = head->data;
		head = tail = nullptr;
	}
	else
	{
		mystring = head->data;
		head = head->next;
	}
	free(temp);
	return mystring;
}




#endif




