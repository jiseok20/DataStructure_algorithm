#include"Stack.h"

template <class KeyType>
Stack<KeyType>::Stack(int MaxStackSize) :MaxSize(MaxStackSize) {
	stack = new KeyType[MaxSize];
	top = -1;
}
template <class KeyType>
bool Stack<KeyType>::IsFull() { //full 인지 판별
	if (top == MaxSize - 1)
		return true;
	else
		return false;
}
template <class KeyType>
bool Stack<KeyType>::IsEmpty() { //empty 판별
	if (top == -1)
		return true;
	else
		return false;
}
template <class KeyType>
void Stack<KeyType>::Push(const KeyType& x) {
	if (IsFull())
		overflow_error;
	else
		stack[++top] = x;
}
template <class KeyType>
KeyType* Stack<KeyType>::Pop(KeyType& x) {
	if (IsEmpty()) {
		underflow_error;
		return 0;
	}
	x = stack[top--];
	return &x;
}