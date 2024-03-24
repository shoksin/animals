#pragma once
#include "animal.h"

class Dog : public Animal
{
protected:
	std::string breed;
	std::string type = "dog";

public:
	Dog() : Animal(), breed("None")
	{
	}

	Dog(std::string name_, int age_, std::string breed_) : Animal(name_, age_), breed(breed_)
	{
	}

	Dog(const Dog &d) : Animal(d), breed(d.breed)
	{
	}

	Dog(Dog &&d) : Animal(d), breed(std::move(d.breed))
	{
	}

	Dog(std::istringstream &str) : Animal(str)
	{
		std::string breed_;
		str >> breed_;
		if (breed_ == ",,")
		{
			breed = "NoneBreed";
		}
		else
		{
			breed = breed_;
		}
	}

	~Dog() {}

	double getFeedWeight()
	{
		return 1;
	}

	void Print() const override
	{
		std::cout << "(" << id << ")"
				  << " " << name << " " << age << " " << breed << " "<<type<<" Owner: ";
	}

	void Play()
	{
		std::cout << id << " " << name << " is playing ";
	}

	std::string woof()
	{
		std::string message = " says woof\n";
		return name + message;
	}

	std::string GetBreed() const
	{
		return breed;
	}

	std::string GetDogName() const
	{
		return name;
	}

	int GetDogAge() const
	{
		return age;
	}

	bool operator<(const Dog &rhs) const
	{
		if (name < rhs.name)
		{
			return true;
		}
		else if (name == rhs.name)
		{
			if (age < rhs.age)
			{
				return true;
			}
			else if (age == rhs.age)
			{
				return breed < rhs.breed;
			}
		}
		return false;
	}

	bool operator==(const Dog &other) const
	{
		return name == other.name && age == other.age && breed == other.breed;
	}

	Dog &operator=(const Dog &d)
	{
		if (this == &d)
		{
			return *this;
		}
		name = d.name;
		age = d.age;
		breed = d.breed;
		return *this;
	}

	Dog &operator=(Dog &&d) noexcept
	{
		if (this == &d)
		{
			return *this;
		}
		name = std::move(d.name);
		age = std::move(d.age);
		breed = std::move(d.breed);
		return *this;
	}
};

std::ostream &operator<<(std::ostream &ostream, Dog &a)
{
	std::string name_ = a.GetAnimalName();
	int age_ = a.GetAnimalAge();
	std::string breed = a.GetBreed();
	int id = a.getId();
	ostream << "id(" << id << ") " << name_ << " " << age_ << " " << breed;
	ostream << "\n";
	return ostream;
}
