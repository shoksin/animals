#pragma once
#include <iostream>
#include <fstream>
#include <assert.h>
#include "cat.h"
#include "dog.h"
#include "fish.h"

Animal* Animal::createAnimal(Animal_ID id,std::string animalName,int animalAge,std::string animalBreed)
{
 Animal * p;
 switch (id)
 {
 case Cat_ID:
 p = new Cat(animalName,animalAge,animalBreed);
 break;
 case Dog_ID:
 p = new Dog(animalName,animalAge,animalBreed);
 break;
 case Fish_ID:
 p = new Fish(animalName,animalAge,animalBreed);
 break;
 default:
 assert(false);
 }
 return p;
};