#include <iostream>
#include <string>
#include <vector>
#include "RateLimiter.h"

int main()
{
    RequestLogger logger(5);
    std::cout << logger.MessageRequestDecision(1, "a") << std::endl;
    std::cout << logger.MessageRequestDecision(2, "a") << std::endl;
    std::cout << logger.MessageRequestDecision(3, "a") << std::endl;
    std::cout << logger.MessageRequestDecision(4, "a") << std::endl;

    return 0;
}


