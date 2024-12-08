#include "food.h"

Food::Food(std::size_t grid_width, std::size_t grid_height)
    : engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)),
      random_food(0, FOOD_OPTIONS.size() - 1) {
  generate();
}

void Food::generate() {
  int i = random_food(engine);
  generate((FoodType)i);
}

void Food::generate(FoodType i) {
  int x = random_w(engine);
  int y = random_h(engine);

  auto food = FOOD_OPTIONS[i];
  coord.x = x;
  coord.y = y;
  type = food.type;
  points = food.points;
}

int Food::getX() const { return coord.x; }
int Food::getY() const { return coord.y; }
int Food::getPoints() const { return points; }
FoodType Food::getType() const { return type; }
