#include <iostream>

#include "Creature.h"
#include "Deck.h"
#include "Land.h"

int Deck::totalDecks = 0;

Deck::Deck() {
  totalDecks++;
}

Deck::Deck(const Deck& other) {
  totalDecks++;
  // Deep copy cards from other
  for (Card* c : other.cards) {
    cards.push_back(c->clone());
  }
}

Deck::~Deck() {
  // Delete all cards in the deck
  for (Card* c : cards) {
    delete c;
  }
  totalDecks--;
}

void Deck::addCard(Card* card) {
  cards.push_back(card);
}

int Deck::size() const {
  return cards.size();
}

int Deck::countCreatures() const {
  int count = 0;
  for (Card* c : cards) {
    if (c->getType() == Card::Type::CREATURE) {
      count++;
    }
  }
  return count;
}

void Deck::printDeck() const {
  std::cout << "Deck contains " << cards.size() << " cards:" << std::endl;
  for (Card* c : cards) {
    c->printInfo();
  }
}

int Deck::getTotalDecks() { 
  return totalDecks; 
}