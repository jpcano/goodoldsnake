#ifndef FOOD_H
#define FOOD_H

#include <array>
#include <random>

#include "SDL.h"

enum FoodType { kSmall, kMedium, kBig };

struct FoodItem {
  int points;
  FoodType type;
};

constexpr std::array<FoodItem, 3> FOOD_OPTIONS = {
    {{1, FoodType::kSmall}, {2, FoodType::kMedium}, {3, FoodType::kBig}}};

class Food {
 public:
  Food(std::size_t grid_width, std::size_t grid_height);
  void generate();
  void generate(FoodType type);
  int getX() const;
  int getY() const;
  int getPoints() const;
  FoodType getType() const;

 private:
  SDL_Point coord;
  FoodType type;
  int points;
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_food;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;
};

#endif
