#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
 protected:
  std::string name;
  int cost;
  static int totalCards;

 public:
  enum class Type { CREATURE, LAND };

  // Constructor: initialize name and cost
  Card(const std::string& name, int cost);

  // Virtual destructor
  virtual ~Card();

  // Pure virtual function to print card details (implemented in derived
  // classes)
  virtual void printInfo() const = 0;
  // Pure virtual function to return the card type
  virtual Type getType() const = 0;
  // Pure virtual function to make a deep copy of the card
  virtual Card* clone() const = 0;

  // Getters
  std::string getName() const;
  int getCost() const;

  // Static function to get total number of Card instances
  static int getTotalCards();
};

#endif