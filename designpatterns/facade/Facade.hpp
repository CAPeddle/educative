#ifndef FACADE_HPP
#define FACADE_HPP

#include <string>
#include <memory>

// Abstract Beverage class
class Beverage {
public:
    virtual ~Beverage() = default;
    virtual std::string getDescription() const = 0;
    virtual double cost() const = 0;
};

// Concrete Beverage: Coffee
class Coffee : public Beverage {
public:
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
    virtual ~CondimentDecorator() = default;
};

// Concrete Condiment: Milk
class Milk : public CondimentDecorator {
private:
    std::shared_ptr<Beverage> beverage;

public:
    explicit Milk(std::shared_ptr<Beverage> bev) : beverage(std::move(bev)) {}

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

    std::string getDescription() const override {
        return beverage->getDescription() + ", Sugar";
    }

    double cost() const override {
        return beverage->cost() + 0.25;
    }
};

#endif // FACADE_HPP