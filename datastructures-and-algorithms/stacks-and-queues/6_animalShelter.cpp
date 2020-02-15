#include <iostream>
#include <list>
using namespace std;

class Animal{
public:
    enum AnimalType {Dog, Cat, None};
    AnimalType _animalType;
    string _name;
    
    Animal(AnimalType animalType, string name){
        _animalType = animalType;
        _name = name;
    }
};

class AnimalShelter{
    list<Animal> _animalShelter;
public:
    static Animal noAnimal(){
        return Animal(Animal::None, "");
    }
    
    void enqueue(Animal animal){
        _animalShelter.push_back(animal);
    }
    
    Animal dequeueAny(){
        if(_animalShelter.empty())
            return noAnimal();
        Animal animal = _animalShelter.front();
        _animalShelter.pop_front();
        return animal;
    }
    
    Animal dequeueDog(){
        Animal animal = _animalShelter.front();
        
        list<Animal> tempAnimalBuffer;
        while(animal._animalType != Animal::Dog && !_animalShelter.empty()){
            tempAnimalBuffer.push_back(animal);
            animal = _animalShelter.front();
            _animalShelter.pop_front();
        }
        while(!tempAnimalBuffer.empty()){
            _animalShelter.push_front( tempAnimalBuffer.front() );
            tempAnimalBuffer.pop_front();
        }
        
        if(animal._animalType != Animal::Dog)
            return noAnimal();
        
        return animal;
    }
    
    Animal dequeueCat(){
        Animal animal = _animalShelter.front();
        
        list<Animal> tempAnimalBuffer;
        while(animal._animalType != Animal::Cat && !_animalShelter.empty()){
            tempAnimalBuffer.push_back(animal);
            animal = _animalShelter.front();
            _animalShelter.pop_front();
        }
        while(!tempAnimalBuffer.empty()){
            _animalShelter.push_front( tempAnimalBuffer.front() );
            tempAnimalBuffer.pop_front();
        }
        
        if(animal._animalType != Animal::Cat)
            return noAnimal();
        
        return animal;
    }
};

void checkAndPrint(Animal animal){
    if(animal._animalType == Animal::None)
        cout << "You didn't get any animal" << endl;
    else
        cout << (animal._animalType == Animal::Dog ? "Dog":"Cat") << " : " << animal._name << endl;
}

int main(){
    
    AnimalShelter animalShelter;
    
    animalShelter.enqueue(Animal(Animal::Cat, "Cat1"));
    animalShelter.enqueue(Animal(Animal::Dog, "Dog1"));
    animalShelter.enqueue(Animal(Animal::Dog, "Dog2"));
    animalShelter.enqueue(Animal(Animal::Dog, "Dog3"));
    animalShelter.enqueue(Animal(Animal::Cat, "Cat2"));
    animalShelter.enqueue(Animal(Animal::Cat, "Cat3"));
    
    checkAndPrint(animalShelter.dequeueAny());
    checkAndPrint(animalShelter.dequeueCat());
    checkAndPrint(animalShelter.dequeueDog());
    
    
    return 0;
}
