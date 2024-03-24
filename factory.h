#include"cat.h"
#include"dog.h"
#include"fish.h"

class AnimalFactory{
public:
virtual Animal* create(std::istringstream& str) const = 0;
};

class CatFactory : public AnimalFactory{
    public:
    Animal* create(std::istringstream& str)const override{
        return new Cat(str);
    }
};

class DogFactory :public AnimalFactory{
    public:
    Animal* create(std::istringstream& str)const override{
        return new Dog(str);
    }
};

class FishFactory : public AnimalFactory{
    public:
    Fish* create(std::istringstream& str) const override{
        return new Fish(str);
    }
};
