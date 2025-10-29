#ifndef DECK_H
#define DECK_H

#include <vector>

#include "Card.h"

class Deck {
 private:
  std::vector<Card*> cards;
  static int totalDecks;

 public:
  Deck();
  Deck(const Deck& other);
  ~Deck();

  void addCard(Card* card);
  int size() const;
  int countCreatures() const;
  void printDeck() const;

  static int getTotalDecks();
};
#endif