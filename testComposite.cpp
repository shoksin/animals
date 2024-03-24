#include"component.h"

int main(){
    CompositeAnimal* household1 = new CompositeAnimal();//домашнее хозяйство номер 1
    Animal* anim1 = Animal::createAnimal(Cat_ID,"Gosha",12,"eng");
    Animal* anim2 = Animal::createAnimal(Cat_ID,"Murzik",8,"brit");
    Animal* anim3 = Animal::createAnimal(Dog_ID,"Spike",3,"bulldog");
    Animal* anim4 = Animal::createAnimal(Fish_ID,"Dori",2,"blue");

    household1->addAnimal(anim1);
    household1->addAnimal(anim2);
    household1->addAnimal(anim3);
    household1->addAnimal(anim4);
    std::cout<<household1->getFeedWeight()<<"\n";//сколько корма нужно в день домашнему хазяйству номер 1

    household1->Print();

    CompositeAnimal* household2 = new CompositeAnimal();
    Animal* anim5 = Animal::createAnimal(Dog_ID,"Sharik",10,"doberman");
    Animal* anim6 = Animal::createAnimal(Cat_ID,"Murzik",8,"British");
    Animal* anim7 = Animal::createAnimal(Fish_ID,",,", 3,"red");
    household2->addAnimal(anim5);
    household2->addAnimal(anim6);
    household2->addAnimal(anim7);
    std::cout<<household2->getFeedWeight()<<"\n";

    CompositeAnimal* bigHousehold = new CompositeAnimal();
    bigHousehold->addAnimal(household1);
    bigHousehold->addAnimal(household2);
    std::cout<<bigHousehold->getFeedWeight()<<"\n";
    bigHousehold->Print();
}