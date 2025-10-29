#include <iostream>

#include "Card.h"
#include "Creature.h"
#include "Land.h"

int main() {
  // Create Creature and Land instances
  Creature c1("Dragon", 5, Creature::CreatureType::WARRIOR, 10, 8);
  Creature c2("Wizard", 4, Creature::CreatureType::MAGE, 3, 5);
  Land l1("Forest of Life", 0, Land::LandType::FOREST);

  // Use printInfo (polymorphic call example)
  Card* ptr = &c1;
  ptr->printInfo();  // prints Dragon details (Card pointer to Creature)
  c2.printInfo();    // prints Wizard details
  l1.printInfo();    // prints land details

  // Check static counts
  std::cout << "Total Cards: " << Card::getTotalCards() << std::endl;
  std::cout << "Total Creatures: " << Creature::getTotalCreatures()
            << std::endl;
  std::cout << "Total Lands: " << Land::getTotalLands() << std::endl;
  
  return 0;
}