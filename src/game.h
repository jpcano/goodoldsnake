#ifndef GAME_H
#define GAME_H

#include <array>
#include <random>

#include "SDL.h"
#include "controller.h"
#include "food.h"
#include "renderer.h"
#include "snake.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;

 private:
  Snake snake;
  Food food;
  int score{0};

  void PlaceFood();
  void Update();
};

#endif
