#include <iostream>
#include"reading.cpp"

int main()
{
    reading();
    std::cout << "------------------------------------------------\nThe fourth task:\n";
    std::cout<<owners.size()<<" "<<anims.size()<<"\n";
    int oldestAge = 0;
    int youngestAge = INT_MAX;
    std::vector<Animal *> youngestAnimal;
    std::vector<Animal *> oldestAnimal;
    for (int i = 0; i < owners.size(); ++i)
    {
        std::vector<Animal *> animals = owners[i].GetVectorAnimal();
        for (Animal *anim : animals)
        {
            if (Cat *c = dynamic_cast<Cat *>(anim))
            { // динамическое приведение типов (dynamic_cast) используется для динамического приведения типов указателей или ссылок на объекты.
                if (c->GetAnimalAge() == oldestAge)
                {
                    oldestAnimal.push_back(anim);
                }
                else if (c->GetAnimalAge() == youngestAge)
                {
                    youngestAnimal.push_back(anim);
                }
                else if (c->GetAnimalAge() < youngestAge)
                {
                    youngestAge = c->GetAnimalAge();
                    youngestAnimal.clear();
                    youngestAnimal.push_back(anim);
                }
                else if (c->GetAnimalAge() > oldestAge)
                {
                    oldestAge = c->GetAnimalAge();
                    oldestAnimal.clear();
                    oldestAnimal.push_back(anim);
                }
            }
            if (Dog *d = dynamic_cast<Dog *>(anim))
            {
                if (d->GetAnimalAge() == oldestAge)
                {
                    oldestAnimal.push_back(anim);
                }
                else if (d->GetAnimalAge() == youngestAge)
                {
                    youngestAnimal.push_back(anim);
                }
                else if (d->GetAnimalAge() < youngestAge)
                {
                    youngestAge = d->GetAnimalAge();
                    youngestAnimal.clear();
                    youngestAnimal.push_back(anim);
                }
                else if (d->GetAnimalAge() > oldestAge)
                {
                    oldestAge = d->GetAnimalAge();
                    oldestAnimal.clear();
                    oldestAnimal.push_back(anim);
                }
            }
            if (Fish *f = dynamic_cast<Fish *>(anim))
            {
                if (f->GetAnimalAge() == oldestAge)
                {
                    oldestAnimal.push_back(anim);
                }
                else if (f->GetAnimalAge() == youngestAge)
                {
                    youngestAnimal.push_back(anim);
                }
                else if (f->GetAnimalAge() < youngestAge)
                {
                    youngestAge = f->GetAnimalAge();
                    youngestAnimal.clear();
                    youngestAnimal.push_back(anim);
                }
                else if (f->GetAnimalAge() > oldestAge)
                {
                    oldestAge = f->GetAnimalAge();
                    oldestAnimal.clear();
                    oldestAnimal.push_back(anim);
                }
            }
        }
    }

    std::cout << "Oldest animal(s):\n";
    for (Animal *anm : oldestAnimal)
    {
        std::cout << *anm;
    }

    std::cout << "Youngest animal(s):\n";
    for (Animal *anm : youngestAnimal)
    {
        std::cout << *anm;
    }

    std::cout<<"---------------------------------------------\nExample of method Play():\n";
    owners[0].Play();
    owners[3].Play();
    owners[1].Play();
    owners[2].Play();


    for (Animal *anim : anims) // освобождение памяти
    {
        delete anim;
    }
}


