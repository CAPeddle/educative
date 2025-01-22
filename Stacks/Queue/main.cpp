#include <iostream>
#include <string>
#include <vector>
#include "MyQueue.h"


int main()
{
std::vector<std::vector<std::vector<std::string>>> input_queues = {
        {{"9", "3", "1", "", "", ""}, {"push", "push", "push", "pop", "peek", "empty"}},
        {{"10", "6", "", "", "" }, {"push", "push", "pop", "empty", "peek"}},
        {{ "1", "2", "3", "", "", "", "", "" }, {"push", "push", "push", "peek", "pop", "pop", "pop", "empty"}},
        {{ "14", "", "66", "" }, {"push", "pop", "push", "pop"}},
        {{ "4", "" }, {"push", "peek"}}
    };

    for (int i = 0; i < input_queues.size(); i++) {
        std::cout << i + 1 << ".\t Starting operations:" << std::endl;

        // Initialize a queue
        MyQueue queue_obj;

        // Loop over all the commands
        for (int j = 0; j < input_queues[i][1].size(); j++) {
            if (input_queues[i][1][j] == "push") {
                std::string inputstr = input_queues[i][1][j] + "(" + input_queues[i][0][j] + ")";
                std::cout << "\t\t" << inputstr << std::endl;
                queue_obj.push(std::stoi(input_queues[i][0][j]));
            }
            else if (input_queues[i][1][j] == "pop") {
                std::string inputstr = input_queues[i][1][j] + "(" + input_queues[i][0][j] + ")";
                std::cout << "\t\t" << inputstr << "   returns " << queue_obj.pop() << std::endl;
            }
            else if (input_queues[i][1][j] == "empty") {
                std::string inputstr = input_queues[i][1][j] + "(" + input_queues[i][0][j] + ")";
                std::cout << "\t\t" << inputstr << " returns " << (queue_obj.empty() ? "true" : "false") << std::endl;
            }
            else if (input_queues[i][1][j] == "peek") {
                std::string inputstr = input_queues[i][1][j] + "(" + input_queues[i][0][j] + ")";
                std::cout << "\t\t" << inputstr << "  returns " << queue_obj.peek() << std::endl;
            }
        }

        std::cout << std::string(100, '-') << std::endl;
    }

    return 0;
}


