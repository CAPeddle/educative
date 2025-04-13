#ifndef DECORATOR_HPP
#define DECORATOR_HPP

#include <string>
#include <memory>
#include <iostream>

// Abstract Beverage class
class Beverage {
public:
    virtual ~Beverage() {
        std::cout << "Destroying Beverage" << std::endl;
    }
    virtual std::string getDescription() const = 0;
    virtual double cost() const = 0;
};

// Concrete Beverage: Coffee
class Coffee : public Beverage {
public:
    ~Coffee() override {
        std::cout << "Destroying Coffee" << std::endl;
    }

    std::string getDescription() const override {
        return "Coffee";
    }

    double cost() const override {
        return 2.50;
    }
};

// Concrete Beverage: Tea
class Tea : public Beverage {
public:
    ~Tea() override {
        std::cout << "Destroying Tea" << std::endl;
    }

    std::string getDescription() const override {
        return "Tea";
    }

    double cost() const override {
        return 1.75;
    }
};

// Abstract Decorator class for condiments
class CondimentDecorator : public Beverage {
public:
    ~CondimentDecorator() override {
        std::cout << "Destroying CondimentDecorator" << std::endl;
    }
};

// Concrete Condiment: Milk
class Milk : public CondimentDecorator {
private:
    std::shared_ptr<Beverage> beverage;

public:
    explicit Milk(std::shared_ptr<Beverage> bev) : beverage(std::move(bev)) {}

    ~Milk() override {
        std::cout << "Destroying Milk" << std::endl;
    }

    std::string getDescription() const override {
        return beverage->getDescription() + ", Milk";
    }

    double cost() const override {
        return beverage->cost() + 0.50;
    }
};

// Concrete Condiment: Sugar
class Sugar : public CondimentDecorator {
private:
    std::shared_ptr<Beverage> beverage;

public:
    explicit Sugar(std::shared_ptr<Beverage> bev) : beverage(std::move(bev)) {}

    ~Sugar() override {
        std::cout << "Destroying Sugar" << std::endl;
    }

    std::string getDescription() const override {
        return beverage->getDescription() + ", Sugar";
    }

    double cost() const override {
        return beverage->cost() + 0.25;
    }
};

#endif // DECORATOR_HPP