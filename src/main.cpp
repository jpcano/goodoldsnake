#include <algorithm>
#include <cstdlib>
#include <cxxopts.hpp>
#include <iostream>

#include "controller.h"
#include "game.h"
#include "renderer.h"

int main(int argc, char** argv) {
  cxxopts::Options options(argv[0],
                           "Snake Game Udacity Nanodegree Capstone Project");
  options.add_options()("v,version", "Display the version",
                        cxxopts::value<bool>()->default_value("false"))(
      "h,help", "Print usage");

  auto result = options.parse(argc, argv);

  if (result.count("help")) {
    std::cout << options.help() << std::endl;
    exit(0);
  }

  if (result["version"].as<bool>()) {
    std::cout << "Snake Game v1.0" << std::endl;
    exit(0);
  }

  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}
