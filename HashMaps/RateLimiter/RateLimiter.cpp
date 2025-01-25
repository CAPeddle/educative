#include "RateLimiter.h"

bool RequestLogger::MessageRequestDecision(int timestamp, std::string request) {
  auto newMessage = requests.insert({request, timestamp});
  if (newMessage.second) {
    return true;
  } else if (timestamp - newMessage.first->second >= timeLimit) {
    newMessage.first->second = timestamp;
    return true;
  }
  return false;
}
