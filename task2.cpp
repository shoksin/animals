#include <iostream>
#include "reading.cpp"

int main(){
    reading();    
    std::cout << "------------------------------------------------\nThe second task:\n";
    std::set<Animal*> animal_set;
    std::map<std::string, std::set<Animal*>> animal_map;
    std::cout << "Enter type of animal(cat,dog,fish):\n";
    std::string check = "";
    std::cin >> check;
    check = ToLower(check);
    bool it_check = 1;
    if (check != "cat" && check != "dog" && check != "fish")
    {
        it_check = 0;
    }
    if (it_check)
    {
        std::cout << check << ":\n";
        for (int i = 0; i < owners.size(); ++i)
        {
            std::vector<Animal *> animls = owners[i].GetVectorAnimal();
            for (Animal *anim : animls)
            {
                if (Cat *c = dynamic_cast<Cat *>(anim))
                {
                    if (check == "cat")
                    {
                        animal_set.insert(anim);
                        std::pair<std::string, std::set<Animal*>> anm(owners[i].GetOwnerName(), animal_set);
                        animal_map.insert(anm);
                        animal_set.clear();
                    }
                }
                if (Dog *d = dynamic_cast<Dog *>(anim))
                {
                    if (check == "dog")
                    {
                        animal_set.insert(anim);
                        std::pair<std::string, std::set<Animal*>> anm(owners[i].GetOwnerName(), animal_set);
                        animal_map.insert(anm);
                        animal_set.clear();
                    }
                }

                if (Fish *c = dynamic_cast<Fish *>(anim))
                {
                    if (check == "fish")
                    {
                        animal_set.insert(anim);
                        std::pair<std::string, std::set<Animal*>> anm(owners[i].GetOwnerName(), animal_set);
                        animal_map.insert(anm);
                        animal_set.clear();
                    }
                }
            }
            animls.clear();
        }
        for (auto &item : animal_map)
        {
            std::cout << item.first << " ";
            for (auto &it : item.second) 
            {
                std::cout << *it << " ";
            }
            std::cout << "\n";
        }
        animal_map.clear();
    }
    else
    {
        std::cout << "We don't know this animal(" << check << ")\n";
    }

    for (Animal *anim : anims) // освобождение памяти
    {
        delete anim;
    }
}
