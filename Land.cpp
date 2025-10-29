
#include <iostream>

#include "Land.h"

int Land::totalLands = 0;

Land::Land(const std::string& name, int cost, LandType t) 
    : Card(name, cost), landType(t) {
  totalLands++;
}

Land::Land(const Land& other) 
    : Card(other.name, other.cost), landType(other.landType) {
  totalLands++;
}

Land::~Land() {
  totalLands--;
}

void Land::printInfo() const {
  std::string typeName;
  switch (landType) {
    case LandType::FOREST: typeName = "Forest"; break;
    case LandType::MOUNTAIN: typeName = "Mountain"; break;
    case LandType::SWAMP: typeName = "Swamp"; break;
  }
  
  std::cout << "Land - " << name << " (Cost " << cost << "): " 
            << typeName << " land." << std::endl;
}

Land::LandType Land::getLandType() const {
  return landType;
}

int Land::getTotalLands() {
  return totalLands;
}

Card* Land::clone() const override { 
  return new Land(*this); 
}

Card::Type Land::getType() const override { 
  return Type::LAND; 
}