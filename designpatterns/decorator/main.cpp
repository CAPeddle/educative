#include <iostream>
#include "Decorator.hpp"

int main() {

    // Create a Coffee object
    std::shared_ptr<Beverage> coffee = std::make_shared<Coffee>();
    std::cout << coffee->getDescription() << " costs: $" << coffee->cost() << std::endl;

    std::shared_ptr<Beverage> teaPlus = std::make_shared<Tea>();
    teaPlus = std::make_shared<Milk>(teaPlus);
    std::cout << teaPlus->getDescription() << " costs: $" << teaPlus->cost() << std::endl;

    return 0;
}