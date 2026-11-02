#ifndef __TDynamicStack_H__
#define __TDynamicStack_H__

#include <iostream>

template<typename T>
class TDynamicStack {
	int top;
	size_t memSize;
	T* pMem;
public:
	TDynamicStack(size_t _memSize = 1) : top(-1), memSize(_memSize), pMem(new T[memSize]) {}
	TDynamicStack(const TDynamicStack&) = delete;
	const TDynamicStack& operator=(const TDynamicStack&) = delete;
	~TDynamicStack()		{ delete[] pMem; }

	size_t size() const		{ return top + 1; }
	bool IsEmpty() const	{ return top == -1; }
	bool IsFull() const		{ return top == memSize - 1; }

	T Top() const {
		if (IsEmpty())
			throw std::exception("Getting top of empty stack is disallowed");
		return pMem[top];
	}
	void Pop() {
		if (IsEmpty())
			throw std::exception("Popping from empty stack is disallowed");
		top--;
	}
	void Push(const T& val) {
		if (IsFull())
			throw std::exception("Pushing to full stack is disallowed");
		pMem[++top] = val;
	}
};

#endif