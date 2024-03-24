#include <iostream>
#include "reading.cpp"

std::string ToNormal(std::string &s)
{
    s[0]= toupper(s[0]);
    for (int i = 1; i < s.size(); ++i)
    {
        s[i] = tolower(s[i]);
    }
    return s;
}

int main()
{
    reading();
    std::cout << "------------------------------------------------\nThe third task:\nEnter animal name:";
    std::string name;
    std::cin >> name;
    name = ToNormal(name);
    std::cout << name << ":\n";
    std::set<std::string> set_animls;

    for (int i = 0; i < owners.size(); ++i)
    {
        std::vector<Animal *> animals = owners[i].GetVectorAnimal();
        for (Animal *anim : animals)
        {
            if (Cat *c = dynamic_cast<Cat*>(anim))
            { // динамическое приведение типов (dynamic_cast)
                if (anim->GetAnimalName() == name)
                {
                    set_animls.insert("cat");
                }
            }
            if (Dog *d = dynamic_cast<Dog*>(anim))
            {
                if (anim->GetAnimalName() == name)
                {
                    set_animls.insert("dog");
                }
            }
            if (Fish *f = dynamic_cast<Fish*>(anim))
            {
                if (anim->GetAnimalName() == name)
                {
                    set_animls.insert("fish");
                }
            }
        }
    }
    std::cout << set_animls.size() << " type of animals have a name - \"" << name << "\"\n";

    for (Animal *anim : anims) // освобождение памяти
    {
        delete anim;
    }
}