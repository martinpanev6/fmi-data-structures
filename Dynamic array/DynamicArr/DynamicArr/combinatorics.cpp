#pragma once

#include <iostream>
#include "Vector.hpp"

template <class T>
void print(const Vector<T>& cur) {
	for (int i = 0; i < cur.size_(); i++) {
		std::cout << cur[i] << " ";
	}
	std::cout << "\n";
}

//combinations without duplicates
template <class T>
void combinations(const Vector<T>& set, int k, int start, Vector<T>& cur) {
	if (cur.size_() == k) {
		print(cur);
		return;
	}
	for (int i = start; i < set.size_(); i++) {
		cur.push_back(set[i]);
		combinations(set, k, i + 1, cur);
		cur.pop_back();
	}
}

//combinations with duplicates
template <class T>
void combinationsRep(const Vector<T>& set, int k, int start, Vector<T>& cur) {
	if (cur.size_() == k) {
		print(cur);
		return;
	}
	for (int i = start; i < set.size_(); i++) {
		cur.push_back(set[i]);
		combinationsRep(set, k, i, cur);
		cur.pop_back();
	}
}

//variations without duplicates
template <class T>
void variations(const Vector<T>& set, int k, Vector<bool>& used, Vector<T>& cur) {
	if (cur.size_() == k) {
		print(cur);
		return;
	}
	for (int i = 0; i < set.size_(); i++) {
		if (used[i]) {
			continue;
		}
		used[i] = true;
		cur.push_back(set[i]);
		variations(set, k, used, cur);
		cur.pop_back();
		used[i] = false;
	}
}

//variations with duplicates
template <class T>
void variations(const Vector<T>& set, int k, Vector<T>& cur) {
	if (cur.size_() == k) {
		print(cur);
		return;
	}
	for (int i = 0; i < set.size_(); i++) {
		cur.push_back(set[i]);
		variations(set, k, cur);
		cur.pop_back();
	}
}

//subsets
template <class T>
void subsets(const Vector<T>& set, int idx, Vector<T>& cur) {
	if (idx == set.size_()) {
		print(cur);
		return;
	}
	subsets(set, idx + 1, cur);
	cur.push_back(ste[idx]);
	subsets(set, idx + 1, cur);
	cur.pop_back();
}