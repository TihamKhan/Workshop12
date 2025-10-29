#ifndef LAND_H
#define LAND_H

#include <string>

#include "Card.h"

class Land : public Card {
 public:
  // Enumeration for land category
  enum class LandType {
    FOREST,
    MOUNTAIN,
    SWAMP
  };

 private:
  LandType landType;
  static int totalLands;

 public:
  Land(const std::string& name, int cost, LandType type);
  Land(const Land& other);
  ~Land();

  void printInfo() const override;
  LandType getLandType() const;
  static int getTotalLands();
  Card* clone() const override;
  Card::Type getType() const override;
};
#endif