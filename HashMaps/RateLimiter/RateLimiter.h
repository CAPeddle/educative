#ifndef RATELIMITER_H
#define RATELIMITER_H

#include <iostream>
#include <unordered_map>
#include <vector>

class RequestLogger {
    private:
        std::unordered_map<std::string, int> requests;
        int timeLimit;

    public:

    RequestLogger(int newTimeLimit){
        // Initialize your data structure here
    }
    
    bool MessageRequestDecision(int timestamp, std::string request) {
        // Replace the placeholder return statement with your code
        return false;
    }
};


#endif // RATELIMITER_H