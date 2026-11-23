#include <iostream>
#include "Vector.hpp"

int main() {
    Vector<int> v;
    for (int i = 1; i <= 5; i++) v.push_back(i * 10);

    v.insert(1, 99);
    v.remove(0);
    v.pop_back();

    Vector<int> copy(v);
    copy.push_back(-1);

    for (int i = 0; i < v.size_(); i++) std::cout << v[i] << " ";
    std::cout << "\n";
    for (int i = 0; i < copy.size_(); i++) std::cout << copy[i] << " ";
    std::cout << "\n";
}