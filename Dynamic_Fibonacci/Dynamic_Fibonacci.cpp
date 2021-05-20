#include <iostream>
using namespace std;

int fib(int i) {
    if (i <= 1)
        return i;
    return fib(i - 1) + fib(i - 2);
}

int memo_fib_utility(const int n, int lookupTable[]) {
    if (lookupTable[n] == -1) { // Check if already present
      // Adding entry to table when not present
        if (n <= 1)
            lookupTable[n] = n;
        else
            lookupTable[n] = memo_fib_utility(n - 1, lookupTable) + memo_fib_utility(n - 2, lookupTable);
    }
    return lookupTable[n];
}

int memo_fib(int n) {
    int* lookupTable = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
        lookupTable[i] = -1; // Initializing the look up table to have -1
    int result = memo_fib_utility(n, lookupTable);
    delete[] lookupTable;

    return result;
}

int tab_fib_utility(int const n, int lookupTable[]) {
    lookupTable[0] = 1; // Set zeroth and first values
    lookupTable[1] = 1;

    for (int i = 2; i <= n; i++)
        lookupTable[i] = lookupTable[i - 1] + lookupTable[i - 2]; // Fill up the table by summing up previous two values

    return lookupTable[n - 1]; // Return the nth Fibonacci number
}

int tab_fib(int const n) {

    int* lookupTable = new int[n + 1];

    int result = tab_fib_utility(n, lookupTable);

    delete[] lookupTable;

    return result;
}

int main() {
    const int n = 6; // Finding the nth Fibonacci number 
    cout << memo_fib(n) << endl;

    cout << tab_fib(n) << endl;
}