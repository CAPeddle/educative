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
  RequestLogger(int newTimeLimit) : timeLimit(newTimeLimit) {}

  bool MessageRequestDecision(int timestamp, std::string request);
};

#endif  // RATELIMITER_H