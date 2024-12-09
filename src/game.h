#ifndef GAME_H
#define GAME_H

#include <array>
#include <random>
#include <string>

#include "SDL.h"
#include "controller.h"
#include "food.h"
#include "renderer.h"
#include "snake.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height,
       std::string player_name);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;
  std::string GetPlayerName() const;

 private:
  Snake snake;
  Food food;
  int score{0};
  std::string player_name;

  void PlaceFood();
  void Update();
};

#endif
