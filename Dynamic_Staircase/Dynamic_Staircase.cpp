// Dynamic_Staircase.cpp : This file contains the 'main' function. Program execution begins and ends there.
//https://www.educative.io/courses/algorithms-coding-interviews-cpp/7ABm4NQoZ2B
//

#include <iostream>
#include <chrono>
#include <vector>

unsigned long countWaysRecurring(long n) {
    if (n < 0)
        return 0;
    else if (n == 0)
        return 1;
    else
        return countWaysRecurring(n - 1) + countWaysRecurring(n - 2) + countWaysRecurring(n - 3);
}

long countWaysMemoUtility(long n, std::vector<unsigned long> lookupTable) {
    if (n < 0) // negative staircases i.e., invalid input
        return 0;
    else if (n == 0) // if 0 staircases
        return 1;
    else if (lookupTable[n] > -1) // if already present in the table
        return lookupTable[n];
    else
        lookupTable[n] = countWaysMemoUtility(n - 1, lookupTable) + countWaysMemoUtility(n - 2, lookupTable) + countWaysMemoUtility(n - 3, lookupTable);
    return lookupTable[n];
}

unsigned long countWaysMemoization(long n) {

    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 3;

    std::vector<unsigned long> lookupTable(n + 1, -1);
    return countWaysMemoUtility(n, lookupTable);
}


unsigned long countWaysTabul(long n) {
    unsigned long* lookupTable = new unsigned long[n + 1];
    lookupTable[0] = 1; // Setting the first three values
    lookupTable[1] = 1;
    lookupTable[2] = 2;

    for (long i = 3; i <= n; i++)
        lookupTable[i] = lookupTable[i - 1] + lookupTable[i - 2] + lookupTable[i - 3]; // Fill up the table by summing up previous two values

    return lookupTable[n]; // Return the nth Fibonacci number
}

long main()
{
    const constexpr long steps = 40;

    std::chrono::time_point<std::chrono::steady_clock> start_start = std::chrono::steady_clock::now();


    std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
    std::cout << "Recurring Start at: [" << std::chrono::duration_cast<std::chrono::seconds>(start - start_start).count() << " s] " << "\n";
    auto countRecurring = countWaysRecurring(steps);
    std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();
    std::cout << "Recurring: " << countRecurring << "[" << std::chrono::duration_cast<std::chrono::seconds>(end - start).count() << " s] " << "\n";

    start = std::chrono::steady_clock::now();
    auto countDynamicMemo = countWaysMemoization(steps);
    end = std::chrono::steady_clock::now();
    std::cout << "Dynamic Memo : " << countDynamicMemo << "[" << std::chrono::duration_cast<std::chrono::seconds>(end - start).count() << " s] " << "\n";

    start = std::chrono::steady_clock::now();
    auto countDynamicTab = countWaysMemoization(steps);
    end = std::chrono::steady_clock::now();
    std::cout << "Dynamic Tab: " << countDynamicTab << "[" << std::chrono::duration_cast<std::chrono::seconds>(end - start).count() << " s] " << "\n";
}

