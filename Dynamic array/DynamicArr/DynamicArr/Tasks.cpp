#include <algorithm>
#include "Vector.hpp"

class Solution {
public:
	int subsetXORSum(Vector<int>& nums) {
		return solve(nums, 0, 0);
	}

	int distributesCandies(int n, int limit) {
		int count = 0;
		for (int a = 0; a <= std::min(n, limit); a++) {
			int rem = n - a;
			if (rem > limit * 2) {
				continue;
			}
			count += std::min(rem, limit) - std::max(0, rem - limit) + 1;
		}
		return count;
	}

private:
	int solve(const Vector<int>& nums, int idx, int currentXor) {
		if (idx == nums.size_()) {
			return currentXor;
		}
		int without = solve(nums, idx + 1, currentXor);
		int with = solve(nums, idx + 1, currentXor ^ nums[idx]);
		return with + without;
	}
};