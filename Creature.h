#ifndef CREATURE_H
#define CREATURE_H

#include <string>

#include "Card.h"

class Creature : public Card {
 public:
  // Enumeration for creature category
  enum class CreatureType {
    WARRIOR,
    MAGE,
    ARCHER
  };

 private:
  CreatureType type;
  int attack;
  int defense;
  static int totalCreatures;

 public:
  Creature(const std::string& name, int cost, CreatureType type,
           int attack, int defense);
  Creature(const Creature& other);  // copy constructor
  ~Creature();                      // destructor

  void printInfo() const override;
  // Getters
  int getAttack() const;
  int getDefense() const;
  CreatureType getCreatureType() const;
  static int getTotalCreatures();
  Card* clone() const override;
  Card::Type getType() const override;
};
#endif