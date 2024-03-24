#include"FactMethod.cpp"

int main(){
std::vector<Animal*> anims;
std::vector<Person> owners;

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
    std::string animal_breed = "";
    std::string animalAgeStr = "";
    std::string animal_name = "";
    int ownerAge;
    int animalAge;
    std::string check = "";

    while (!file.eof())
    {
        std::getline(file,check);
        std::istringstream istr(check);
        istr>>owner_name>>str_OwnerAge>>animal_type>>animal_name>>animalAgeStr>>animal_breed;

        ownerAge = stoi(str_OwnerAge);
        animalAge = stoi(animalAgeStr);
        
        if (animal_type == "cat")
        {
            anims.push_back(Animal::createAnimal(Cat_ID,animal_name,animalAge,animal_breed));
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
            anims.push_back(Animal::createAnimal(Dog_ID,animal_name,animalAge,animal_breed));
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
            anims.push_back(Animal::createAnimal(Fish_ID,animal_name,animalAge,animal_breed));
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
for(int i=0; i<owners.size(); i++){
        std::cout<<owners[i];
        }
}
