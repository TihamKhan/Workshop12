#include <iostream>

#include "Creature.h"

int Creature::totalCreatures = 0;

Creature::Creature(const std::string& name, int cost, CreatureType t, int atk,
                   int def)
    : Card(name, cost), type(t), attack(atk), defense(def) {
  totalCreatures++;
}

Creature::Creature(const Creature& other) 
    : Card(other.name, other.cost), type(other.type), attack(other.attack), defense(other.defense) {
  totalCreatures++;
}

Creature::~Creature() {
  totalCreatures--;
}

void Creature::printInfo() const {
  std::string typeName;
  switch (type) {
    case CreatureType::WARRIOR: typeName = "Warrior"; break;
    case CreatureType::MAGE: typeName = "Mage"; break;
    case CreatureType::ARCHER: typeName = "Archer"; break;
  }
  
  std::cout << "Creature - " << name << " (Cost " << cost << "): Creature Type=" 
            << typeName << ", Attack=" << attack << ", Defense=" << defense << std::endl;
}

int Creature::getAttack() const {
  return attack;
}

int Creature::getDefense() const {
  return defense;
}

Creature::CreatureType Creature::getCreatureType() const {
  return type;
}

int Creature::getTotalCreatures() {
  return totalCreatures;
}

Card* Creature::clone() const { 
  return new Creature(*this); 
}

Card::Type Creature::getType() const { 
  return Type::CREATURE; 
}