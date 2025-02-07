// Greedy_NumPlatforms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>

int findPlatform(int arrival[], int departure[], int n) {

    // Insert all the times (arrival and departure) in the multimap. 
    std::multimap <int, char> myMultiMap;
    for (int i = 0; i < n; i++) {
        myMultiMap.insert(std::make_pair(arrival[i], 'a'));
        myMultiMap.insert(std::make_pair(departure[i], 'd'));
    }

    int result = 0;
    int platformNeeded = 0;

    std::multimap <int, char> ::iterator i = myMultiMap.begin();
    for (; i != myMultiMap.end(); i++) {

        // If its arrival then add 1 to platformNeeded else subtract 1 from platformNeeded. 
        if ((*i).second == 'a')
            platformNeeded++;
        else
            platformNeeded--;

        if (platformNeeded > result)
            result = platformNeeded;
    }
    return result;
}

int main()
{
    int arrival[] = { 900, 940, 950, 1100, 1500, 1800 };
    int departure[] = { 910, 1200, 1120, 1130, 1900, 2000 };
    int n = sizeof(arrival) / sizeof(arrival[0]);

    std::cout << "Minimum Number of Platforms Required for Plan1 = " <<
        findPlatform(arrival, departure, n);

    std::cout << std::endl << std::endl;

    // Example 2
    int arrival1[] = { 200, 210, 300, 320, 350, 500 };
    int departure1[] = { 230, 240, 320, 430, 400, 520 };
    int n1 = sizeof(arrival1) / sizeof(arrival1[0]);

    std::cout << "Minimum Number of Platforms Required for Plan2 = " <<
        findPlatform(arrival1, departure1, n1);

    return 0;
}
