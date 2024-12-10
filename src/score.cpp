#include "score.h"

#include <ctime>
#include <fstream>

Score::Score(const std::string& filename) : _filename(filename) {
  try {
    std::ifstream in(_filename);
    in.exceptions(std::ifstream::failbit);
    in >> _score;
  } catch (const std::ios_base::failure& fail) {
    _score = {{"entries", json::array()}};
  }
}

void Score::Save() {
  std::ofstream out(_filename);
  out << _score.dump(2) << std::endl;
}

void Score::Push(const Game& game) {
  json entry;
  std::time_t ts = std::time(nullptr);
  char* ts_asc = std::asctime(std::gmtime(&ts));
  ts_asc[strlen(ts_asc) - 1] = '\0';  // remove \n at the end of the string
  entry["timestamp"] = ts_asc;
  entry["name"] = game.GetPlayerName();
  entry["score"] = game.GetScore();
  entry["size"] = game.GetSize();

  _score["entries"].push_back(entry);
}

std::vector<ScoreItem> Score::GetEntriesByScore() {
  return SortEntriesBy("score");
}

std::vector<ScoreItem> Score::GetEntriesByScore(size_t limit) {
  auto sorted = GetEntriesByScore();
  return SliceLimit(sorted, limit);
}

std::vector<ScoreItem> Score::GetEntriesBySize() {
  return SortEntriesBy("size");
}

std::vector<ScoreItem> Score::GetEntriesBySize(size_t limit) {
  auto sorted = GetEntriesBySize();
  return SliceLimit(sorted, limit);
}

std::vector<ScoreItem> Score::SortEntriesBy(const std::string& by) {
  json entries = _score["entries"];
  std::vector<ScoreItem> res;

  sort(entries.begin(), entries.end(),
       [by](json a, json b) { return a[by] > b[by]; });
  for (auto& it : entries) {
    res.push_back(
        ScoreItem{it["timestamp"], it["name"], it["score"], it["size"]});
  }

  return res;
}

std::vector<ScoreItem> Score::SliceLimit(const std::vector<ScoreItem>& scores,
                                         size_t limit) {
  if (scores.size() <= limit)
    return scores;
  else
    return std::vector<ScoreItem>(scores.begin(), scores.begin() + limit);
}
