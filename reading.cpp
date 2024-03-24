#include <iostream>
#include <fstream>
#include "cat.h"
#include "dog.h"
#include "fish.h"
#include "factory.h"
#include <set>
#include <map>

std::vector<Animal *> anims;//объявляю глобальными, чтобы было видо во всех task
std::vector<Person> owners;

std::string ToLower(std::string &s)
{
    for (int i = 0; i < s.size(); ++i)
    {
        s[i] = tolower(s[i]);
    }
    return s;
}

void reading(){
    AnimalFactory* catFactory = new CatFactory();
    AnimalFactory* dogFactory = new DogFactory();
    AnimalFactory* fishFactory = new FishFactory();
    std::ifstream file("input.txt");
    if (!file.is_open())
    {
        std::cerr << "File is not open!";
        exit(1);
    }
    if (file.peek() == EOF)
    {
        std::cerr << "The file is empty!";
        exit(1);
    }

    std::string owner_name = "";
    std::string str_OwnerAge = "";
    std::string animal_type = "";
    int ownerAge;
    int animalAge;
    std::string check = "";

    while (!file.eof())
    {
        std::getline(file,check);
        std::istringstream istr(check);
        istr>>owner_name>>str_OwnerAge>>animal_type;

        ownerAge = stoi(str_OwnerAge);
        
        if (animal_type == "cat")
        {
            Animal* anim = catFactory->create(istr);
            anims.push_back(anim);
            Person pr(owner_name, ownerAge, anims[anims.size() - 1]);
            bool isFind = 0;
            for (auto &ps : owners)
            {
                if (ps.GetOwnerName() == owner_name && ps.GetOwnerAge() == ownerAge)
                {
                    ps.Push_Animal(anims[anims.size() - 1]);
                    isFind = 1;
                    break;
                }
            }
            if (!isFind)
            {
                owners.push_back(pr);
            }
        }
        
        if (animal_type == "dog")
        {
            Animal* anim = dogFactory->create(istr);
            anims.push_back(anim);
            Person pr(owner_name, ownerAge, anims[anims.size() - 1]);
            bool isFind = 0;
            for (auto &ps : owners)
            {
                if (ps.GetOwnerName() == owner_name && ps.GetOwnerAge() == ownerAge)
                {
                    ps.Push_Animal(anims[anims.size() - 1]);
                    isFind = 1;
                    break;
                }
            }
            if (!isFind)
            {
                owners.push_back(pr);
            }
        }
        if (animal_type == "fish")
        {
            Animal* anim = fishFactory->create(istr);
            anims.push_back(anim);
            Person pr(owner_name, ownerAge, anims[anims.size() - 1]);
            bool isFind = 0;
            for (auto &ps : owners)
            {
                if (ps.GetOwnerName() == owner_name && ps.GetOwnerAge() == ownerAge)
                {
                    ps.Push_Animal(anims[anims.size() - 1]);
                    isFind = 1;
                    break;
                }
            }
            if (!isFind)
            {
                owners.push_back(pr);
            }
        }

        std::string owner_name = "";
        std::string str_OwnerAge = "";
        std::string animal_type = "";
        int ownerAge = 0;
        int animalAge = 0;
    }
}