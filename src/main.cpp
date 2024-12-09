#include <algorithm>
#include <cxxopts.hpp>
#include <iostream>
#include <string>

#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "score.h"

using json = nlohmann::json;

void printScores(const std::vector<ScoreItem>& scores) {
  for (auto& i : scores) {
    std::cout << "Time: " << i.ts << " | Score: " << i.score
              << " | Size: " << i.size << " | Name: " << i.name << std::endl;
  }
}

int main(int argc, char** argv) {
  cxxopts::Options options(argv[0],
                           "Snake Game Udacity Nanodegree Capstone Project");
  options.add_options()("h,help", "Print usage")(
      "v,version", "Display the version",
      cxxopts::value<bool>()->default_value("false"))(
      "n,name", "User name",
      cxxopts::value<std::string>()->default_value("Anonymous"))(
      "s,scorefile", "Score file",
      cxxopts::value<std::string>()->default_value("score.json"));

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
  Game game(kGridWidth, kGridHeight, result["name"].as<std::string>());
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Player name: " << game.GetPlayerName() << "\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";

  Score score(game, result["scorefile"].as<std::string>());
  std::cout << "BY SCORE:" << std::endl;
  printScores(score.GetEntriesByScore(5));
  std::cout << "BY SIZE:" << std::endl;
  printScores(score.GetEntriesBySize(5));
  score.Save();
  return 0;
}
