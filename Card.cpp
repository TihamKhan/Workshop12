#include "Card.h"

int Card::totalCards = 0;

Card::Card(const std::string& n, int c) : name(n), cost(c) {
  totalCards++;
}

Card::~Card() {
  totalCards--;
}

std::string Card::getName() const {
  return name;
}

int Card::getCost() const {
  return cost;
}

int Card::getTotalCards() {
  return totalCards;
}