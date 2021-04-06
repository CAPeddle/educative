#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

vector<string> groupAnagrams(string strArray[], int arrSize) {
    vector<string> vec;
    // Write your code here

    std::unordered_map <size_t, int> anagrams;

    for (int i = 0; i < arrSize; ++i) {
        std::string copyForHash = strArray[i];
        std::sort(copyForHash.begin(), copyForHash.end());
        std::size_t str_hash = std::hash<std::string>{}(copyForHash);
        auto inserter = anagrams.insert({ str_hash, i });

        if (inserter.second == false) {
                        
            vec.push_back(strArray[inserter.first->second]);
            vec.push_back(strArray[i]);
        }
    }
    
    return vec;
}


int main()
{
    string arr[] = {
    "tom marvolo riddle ",
    "abc",
    "def",
    "cab",
    "fed",
    "brag",
    "clint eastwood ",
    "i am lord voldemort",
    "elvis",
    "grab",
    "old west action",
    "lives"
    };

    groupAnagrams(arr, 12);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
