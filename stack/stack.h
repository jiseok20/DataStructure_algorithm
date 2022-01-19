#pragma once
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
template <class KeyType>
class Stack {

private:
	KeyType* stack;
	int MaxSize;
	int top;

public:

	Stack(int MaxStackSize = DefalutSize);
	~Stack() {
		delete[] stack;
	}
	bool IsFull();
	bool IsEmpty();
	void Push(const KeyType& item);
	KeyType* Pop(KeyType&);

};