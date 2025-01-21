// Helper function that calculates the sum of squared digits.
#include <cmath>
#include <iostream>
#include <vector>

int SumOfSquaredDigits(int number) {
  int totalSum = 0;
  while (number > 0) {
    int digit = number % 10;
    number = number / 10;
    totalSum += digit * digit;
  }
  return totalSum;
}

// potential for optimization in keeping the set of values of the slow pointer
// check if the fast pointer is in the set of values of the slow pointer.
// downside is that the space complexity increases to O(n)
bool IsHappyNumber(int n) {
  int slowPointer = n;
  int fastPointer = SumOfSquaredDigits(n);

  while (fastPointer != 1 && slowPointer != fastPointer) {
    slowPointer = SumOfSquaredDigits(slowPointer);
    fastPointer = SumOfSquaredDigits(SumOfSquaredDigits(fastPointer));
  }

  if (fastPointer == 1) {
    return true;
  } else {
    return false;
  }
}

// Driver code
int main() {
  std::vector<int> inputs = {2, 1, 5, 19, 25, 7};
  for (int i = 0; i < inputs.size(); i++) {
    std::cout << i + 1 << ".\tInput Number: " << inputs[i] << "\n";
    bool result = IsHappyNumber(inputs[i]);
    std::cout << "\n\tIs it a happy number? ";
    if (result)
      std::cout << "True\n";
    else
      std::cout << "False\n";
    std::cout << std::string(100, '-') << "\n";
  }
}