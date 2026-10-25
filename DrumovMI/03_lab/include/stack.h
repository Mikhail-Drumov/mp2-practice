#ifndef __TVectorStack_H__
#define __TVectorStack_H__

#include <iostream>
#include <vector>

template<typename T>
class TVectorStack {
	std::vector<T> mem;
public:
	TVectorStack() = default;

	TVectorStack(const TVectorStack&) = delete;
	const TVectorStack& operator=(const TVectorStack&) = delete;
		
	size_t size() const { return mem.size(); }
	bool IsEmpty() const { return mem.empty(); }
	void Push(const T& val) { mem.push_back(val); }
	void Pop() {
		if (mem.empty())
			throw std::exception("Pop from empty stack prohibited");
		mem.pop_back();
	}
	T Top() const {
		if (mem.empty())
			throw std::exception("Getting top of empty stack prohibited");
		return mem.back();
	}
};

#endif