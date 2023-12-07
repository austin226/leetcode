#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <ranges>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

/// Given an array of integers nums and an integer target, return indices of the
/// two numbers such that they add up to target.

class Solution {
 public:
  // Total complexity: O(n log n)
  vector<int> twoSum(vector<int>& nums, int target) {
    // O(n) size for a map
    multimap<int, size_t> num_indexes;

    // O(n) loop
    for (int i = 0; i < nums.size(); i++) {
      num_indexes.insert({nums[i], i});
    }

    // O(n) loop
    for (int i = 0; i < nums.size(); i++) {
      // Find a + b = target
      int a = nums[i];
      int b = target - a;

      // O (log n)
      auto range = num_indexes.equal_range(b);
      vector<int> result;

      if (a == b) {
        // Check if b occurs twice
        for (auto i = range.first; i != range.second; i++) {
          result.push_back(i->second);
          if (result.size() == 2) {
            return result;
          }
        }
      } else {
        // Check if b occurs once
        result.push_back(i);
        for (auto i = range.first; i != range.second; i++) {
          result.push_back(i->second);
          if (result.size() == 2) {
            return result;
          }
        }
      }
    }

    return {};
  }
};

int main() {
  Solution sol;

  vector<pair<vector<int>, int>> cases = {
      {{2, 7, 11, 15}, 9}, {{3, 2, 4}, 6}, {{3, 3}, 6}};

  for (int i = 0; i < cases.size(); i++) {
    vector<int> nums = cases[i].first;
    int target = cases[i].second;
    vector<int> solution = sol.twoSum(nums, target);
    cout << "Solution: [ ";
    for (int n : solution) {
      cout << n << ' ';
    }
    cout << ']' << endl;
  }
}