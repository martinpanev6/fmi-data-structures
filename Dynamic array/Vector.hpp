#pragma once

#include <cassert>
#include <utility>
#include <stdexcept>

template  <class T>
class Vector {
private:
	T* data = nullptr;
	int size = 0;
	int capacity = 0;

	void swap(Vector& other) {
		std::swap(data, other.data);
		std::swap(capacity, other.capacity);
		std::swap(size, other.size);
	}

public:
	Vector() = default;

	~Vector() {
		delete[]data;
	}

	Vector& operator=(const Vector& other) {
		if (this != &other) {
			Vector copy(other);
			swap(copy);
		}
		return *this;
	}

	Vector(const Vector& other) {
		reserve(other.size);
		try {
			for (int i = 0; i < other.size; i++) {
				data[i] = other.data[i];
			}
		}
		catch (...) {
			delete[]data;
			throw;
		}
		size = other.size;
	}


	void reserve(int newCap) {
		if (capacity >= newCap) {
			return;
		}
		int cap = capacity == 0 ? 1 : capacity;
		while (cap < newCap) {
			cap *= 2;
		}

		T* newData = new T[cap];
		try {
			for (int i = 0; i < size; i++) {
				newData[i] = data[i];
			}
		}
		catch (...) {
			delete[]newData;
			throw;
		}
		delete[]data;
		data = newData;
		capacity = cap;
	}
	//In the STL operator[] does not check if we are out of boundaries
	T& operator[](int idx) {
		assert(idx >= 0 && idx < size);
		return data[idx];
	}

	const T& operator[](int idx)const {
		assert(idx >= 0 && idx < size);
		return data[idx];
	}

	void push_back(const T& el) {
		reserve(size + 1);
		data[size] = el;
		size++;
	}

	void pop_back() {
		size--;
	}

	int size_()const {
		return size;
	}

	int capacity_()const {
		return capacity;
	}

	bool empty()const {
		return size_() == 0;
	}

	void clear() {
		size = 0;
	}

	void remove(int idx) {
		for (int i = idx; i < size - 1; i++) {
			data[i] = data[i + 1];
		}
		size--;
	}

	void insert(int idx, const T& el) {
		reserve(size + 1);
		for (int i = size; i >= idx + 1; i--) {
			data[i] = data[i - 1];
		}
		data[idx] = el;
		size++;
	}

	//In STL the at method checks for boundaries
	T& at(int idx) {
		if (idx < 0 || idx >= size) {
			throw std::invalid_argument("The given index is not valid.");
		}
		return data[idx];
	}

	const T& at(int idx) const{
		if (idx < 0 || idx >= size) {
			throw std::invalid_argument("The given index is not valid.");
		}
		return data[idx];
	}

	T* data_() { return data; }
	const T* data_() const { return data; }
};

template <class T>
bool operator==(const Vector<T>& a, const Vector<T>& b){
	if (a.size_() != b.size_()) {
		return false;
	}
	for (int i = 0; i < a.size_(); i++) {
		if (!(a[i] == b[i])) {
			return false;
		}
	}
	return true;
}

template<class T>
bool operator!=(const Vector<T>& a, const Vector<T>& b) {
	return !(a == b);
}