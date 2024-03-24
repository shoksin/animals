#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <sstream>
#include<assert.h>

enum Animal_ID
{
	Cat_ID = 0,
	Dog_ID,
	Fish_ID
};

class Animal
{
protected:
	static int nextId;
	const int id;
	std::string name;
	int age;

public:
	Animal() : id(nextId++), age(0), name("Noname")
	{
	}

	Animal(Animal &&a) : id(nextId++), name(std::move(a.name)), age(std::move(a.age))
	{ // конструктор перемещения
	}

	Animal(const Animal &a) : id(nextId++), name(a.name), age(a.age)
	{
	}

	Animal(std::string name_, int age_) : name(name_), age(age_), id(nextId++) {}

	Animal(std::istringstream &str) : id(nextId++)
	{
		std::string name_;
		str >> name_;
		if (name_ == ",,")
		{
			name = "NoName";
			str >> age;
		}
		else
		{
			name = name_;
			str >> age;
		}
	}

	virtual ~Animal() {}

	virtual double getFeedWeight() = 0;

	virtual void addAnimal(Animal *a)
	{
		assert(false);
	}

	virtual void Print() const = 0;

	virtual void Play()
	{
		std::cout << "Animal is playing" << std::endl;
	}

	static Animal *createAnimal(Animal_ID id,std::string animalName,int animalAge,std::string animalBreed);

	int getId() const
	{
		return id;
	}

	void SetAnimalName()
	{
		std::cin >> name;
	}

	std::string GetAnimalName() const
	{
		return name;
	}

	void SetAnimalAge()
	{
		std::cin >> age;
	}

	int GetAnimalAge() const
	{
		return age;
	}

	bool operator==(const Animal &other) const
	{
		return id == other.id && name == other.name && age == other.age;
	}

	Animal &operator=(const Animal &a)
	{
		if (this == &a)
		{
			return *this;
		}
		name = a.name;
		age = a.age;
		return *this;
	}

	Animal &operator=(Animal &&other)
	{ // оператор перемещения с присваиванием
		if (this == &other)
		{
			return *this;
		}
		name = std::move(other.name);
		age = std::move(other.age);
		return *this;
	}
};

class Person
{
private:
	int age;
	std::string name;
	std::vector<Animal *> pets;

public:
	Person(std::string name_, int age_, Animal *anim)
	{
		pets.push_back(anim);
		name = name_;
		age = age_;
	}

	void Play()
	{
		for (Animal *animal : pets)
		{
			animal->Play();
			std::cout << "with " << name << "\n";
		}
	}

	void PrintOwner()
	{
		std::cout << name << " " << age;
	}

	std::string GetOwnerName() const
	{
		return name;
	}

	int GetOwnerAge() const
	{
		return age;
	}

	void SetAge(int a)
	{
		age = a;
	}

	void PrintAllAnim()
	{
		for (auto &anim : pets)
		{
			anim->Print();
		}
	}

	void Push_Animal(Animal *anim)
	{
		pets.push_back(anim);
	}

	std::vector<Animal *> GetVectorAnimal()
	{
		return pets;
	}
};

int Animal::nextId = 10000;

std::ostream &operator<<(std::ostream &ostream, Animal &a)
{
	std::string name_ = a.GetAnimalName();
	int age_ = a.GetAnimalAge();
	int Id = a.getId();
	ostream << "id(" << Id << ")" << name_ << " " << age_;
	ostream << "\n";
	return ostream;
}
std::ostream &operator<<(std::ostream &ostream, Person &p)
{
	std::string name_ = p.GetOwnerName();
	int age_ = p.GetOwnerAge();
	p.PrintAllAnim();
	ostream << name_ << " " << age_ << " ";
	ostream << "\n";
	return ostream;
}