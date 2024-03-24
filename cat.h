#pragma once
#include "animal.h"

class Cat : public Animal
{
protected:
	std::string breed;
	std::string type = "cat";

public:
	Cat() : Animal(), breed("None")
	{
	}

	Cat(const Cat &c) : Animal(c), breed(c.breed)
	{
	}

	Cat(std::string name_, int age_, std::string breed_) : Animal(name_, age_), breed(breed_)
	{
	}

	Cat(std::istringstream &str) : Animal(str)
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

	Cat(Cat &&c) : Animal(c), breed(std::move(c.breed))
	{
	}

	~Cat() {}

	double getFeedWeight()
	{
		return 0.4;
	}

	void Print() const override
	{
		std::cout << "(" << id << ")"
				  << " " << name << " " << age << " " << breed << " "<< type<<" Owner: ";
	}

	void Play()
	{
		std::cout << id << " " << name << " is playing ";
	}

	std::string Say()
	{
		std::string message = " meows\n";
		return name + message;
	}

	std::string GetBreed() const
	{
		return breed;
	}

	std::string GetCatName() const
	{
		return name;
	}

	int GetCatAge() const
	{
		return age;
	}

	bool operator<(const Cat &rhs) const
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

	bool operator==(const Cat &other) const
	{
		return name == other.name && age == other.age && breed == other.breed;
	}

	Cat &operator=(const Cat &a)
	{
		if (this == &a)
		{
			return *this;
		}
		name = a.name;
		age = a.age;
		breed = a.breed;
		return *this;
	}

	Cat &operator=(Cat &&c)
	{
		if (this == &c)
		{
			return *this;
		}
		name = std::move(c.name);
		age = std::move(c.age);
		breed = std::move(c.breed);
		return *this;
	}
};

std::ostream &operator<<(std::ostream &ostream, Cat &a)
{
	std::string name_ = a.GetAnimalName();
	int age_ = a.GetAnimalAge();
	std::string breed = a.GetBreed();
	int id = a.getId();
	ostream << "id(" << id << ") " << name_ << " " << age_ << " " << breed;
	ostream << "\n";
	return ostream;
}
