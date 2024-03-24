#pragma once
#include "cat.h"
#include "dog.h"
#include "fish.h"
#include "FactMethod.cpp"

class CompositeAnimal : public Animal
{
public:
    double getFeedWeight()
    {
        double total = 0;
        for (int i = 0; i < animals.size(); ++i)
        {
            total += animals[i]->getFeedWeight();
        }
        return total;
    }

    void addAnimal(Animal *p)
    {
        animals.push_back(p);
    }

    ~CompositeAnimal()
    {
        for (int i = 0; i < animals.size(); ++i)
            delete animals[i];
    }

    void Print() const override{
        for(int i = 0;i<animals.size();i++)
            animals[i]->Print();
            std::cout<<"\n";
    }

private:
    std::vector<Animal *> animals;
};
