#pragma once

#include <vector>

template <typename T>
class LStack {
private:
	std::vector<T> data;

public:
	LStack() = default;

	void push(const T& element) {
		data.push_back(element);
	}

	void pop() {
		data.pop_back();
	}

	const T& top() const {
		return data.back();
	}

	bool empty()const {
		return data.size() == 0;
	}

	void clear() {
		data.clear();
	}

	size_t size()const {
		return data.size();
	}
};