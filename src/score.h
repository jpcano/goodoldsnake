#ifndef SCORE_H
#define SCORE_H

#include <nlohmann/json.hpp>
#include <string>
#include <vector>

#include "game.h"

using json = nlohmann::json;

struct ScoreItem {
  std::string ts;
  std::string name;
  int score;
  int size;
};

class Score {
 public:
  Score(const std::string &filename);
  void Save();
  void Push(const Game &game);
  std::vector<ScoreItem> GetEntriesByScore(size_t limit);
  std::vector<ScoreItem> GetEntriesByScore();
  std::vector<ScoreItem> GetEntriesBySize(size_t limit);
  std::vector<ScoreItem> GetEntriesBySize();

 private:
  json _score;
  std::string _filename;
  std::vector<ScoreItem> SortEntriesBy(const std::string &by);
  std::vector<ScoreItem> SliceLimit(const std::vector<ScoreItem> &scores,
                                    size_t limit);
};
#endif
