#include "RemoveDuplicates.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::string StackRemoveDuplicates::RemoveDuplicates(std::string s) {
  std::vector<char> stack;
  for (char c : s) {
    if (!stack.empty() && stack.back() == c) {
      stack.pop_back();
    } else {
      stack.push_back(c);
    }
  }
  std::string result;
  for (char c : stack) {
    result += c;
  }
  return result;
}
