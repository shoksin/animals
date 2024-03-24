#include <iostream>
#include "reading.cpp"

int main()
{
    reading();
    
    std::cout << "------------------------------------------------\nThe first task:\n";
    std::set<std::string> set_animal;
    for (int i = 0; i < owners.size(); ++i)
    {
        std::vector<Animal *> animls = owners[i].GetVectorAnimal();
        for (Animal *anim : animls)
        {
            if (Cat *c = dynamic_cast<Cat *>(anim))
            { // динамическое приведение типов (dynamic_cast)
                set_animal.insert("cat");
            }
            if (Dog *d = dynamic_cast<Dog *>(anim))
            {
                set_animal.insert("fish");
            }
            if (Fish *c = dynamic_cast<Fish *>(anim))
            {
                set_animal.insert("dog");
            }
        }
        std::cout << "Owner " << owners[i].GetOwnerName() << "(" << owners[i].GetOwnerAge() << " years old) has " << set_animal.size() << " different animals\n";
        animls.clear();
        set_animal.clear();
    }

    for (Animal *anim : anims) // освобождение памяти
    {
        delete anim;
    }
}
