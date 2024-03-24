#include<string>
#include<vector>
#include "animal.h"

class Person{
private:
int age;
std::string name;
std::vector<Animal*> pets;

public:
Person(std::string name_,int age_ ,Animal* anim){
   pets.push_back(anim);
   name = name_;
   age = age_;
}

void PrintOwner(){
	std::cout<<name<<" "<<age;
}

std::string GetOwnerName() const{
   return name;
}


int GetOwnerAge() const{
   return age;
}

void SetAge(int a){
age = a;
}

void PrintAllAnim(){
	for(auto& anim: pets){
	anim->Print();
	}
}

void Push_Animal(Animal* anim){
	pets.push_back(anim);
}

};

std::ostream &operator<<(std::ostream &ostream, Person &p)
{
	std::string name_ = p.GetOwnerName();
	int age_ = p.GetOwnerAge();
	ostream << name_ << " " << age_;
	p.PrintAllAnim();
	ostream << "\n";
	return ostream;
}
