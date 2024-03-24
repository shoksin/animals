#pragma once
#include <iostream>

class Fish : public Animal
{
protected:
    std::string color;
    std::string type = "fish";

public:
    Fish() : Animal(), color("None")
    {
    }

    Fish(std::string name_, int age_, std::string color_) : Animal(name_, age_), color(color_)
    {
    }

    Fish(const Fish &f) : Animal(f), color(f.color)
    {
    }

    Fish(Fish &&f) : Animal(f), color(std::move(f.color))
    {
    }

    Fish(std::istringstream &str) : Animal(str)
    {
        std::string color_;
        str >> color_;
        if (color_ == ",,")
        {
            color = "NoneColor";
        }
        else
        {
            color = color_;
        }
    }

    ~Fish() {}

    double getFeedWeight()
    {
        return 0.05;
    }

    void Print() const override
    {
        std::cout << "(" << id << ")"
                  << " " << name << " " << age << " " << color << " " << type<<" Owner:";
    }

    void Play()
    {
        std::cout << id << " " << name << " is playing ";
    }

    std::string Swim()
    {
        std::string message = name + " is swinmming\n";
        return message;
    }

    std::string GetColor() const
    {
        return color;
    }

    std::string GetFishName() const
    {
        return name;
    }

    int GetFishAge() const
    {
        return age;
    }

    bool operator<(const Fish &rhs) const
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
                return color < rhs.color;
            }
        }
        return false;
    }

    bool operator==(const Fish &other) const
    {
        return name == other.name && age == other.age && color == other.color;
    }

    Fish &operator=(const Fish &f)
    {
        if (this == &f)
        {
            return *this;
        }
        name = f.name;
        age = f.age;
        color = f.color;
        return *this;
    }

    Fish &operator=(Fish &&f)
    {
        if (this == &f)
        {
            return *this;
        }
        name = std::move(f.name);
        age = std::move(f.age);
        color = std::move(f.color);
        return *this;
    }
};

/*std::ostream &operator<<(std::ostream &ostream, Fish &a)
{
    std::string name_ = a.GetAnimalName();
    int age_ = a.GetAnimalAge();
    std::string breed = a.GetColor();
    int id = a.getId();
    ostream <<"id("<<id<<") "<< name_ << " " << age_<<" "<<breed;
    ostream << "\n";
    return ostream;
}
*/