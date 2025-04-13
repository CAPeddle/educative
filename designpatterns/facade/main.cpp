#include <iostream>
#include "Facade.hpp"

int main() {

    // Create a Coffee object
    std::shared_ptr<Beverage> coffee = std::make_shared<Coffee>();
    std::cout << coffee->getDescription() << " costs: $" << coffee->cost() << std::endl;
    return 0;
}