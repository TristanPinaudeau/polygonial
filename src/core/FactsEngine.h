//
// Created by tristan on 04/04/19.
//

#ifndef POLYGONIAL_FACTSENGINE_H
#define POLYGONIAL_FACTSENGINE_H

#include <memory>
#include <string>
#include <utility>
#include "Node.h"
#include "Record.hpp"
#include "UnfilledRecordException.hpp"

class FactsEngine {
 private:
  std::string file_path;
  std::unique_ptr<Node> root_node = nullptr;

 public:
  explicit FactsEngine(std::string file_path)
      : file_path(std::move(file_path)) {}

  /*
   * Store the record in the fact tree.
   */
  void store(Record &record);

  /*
   * Go trough the tree and fill the record if a matching record is found.
   */
  void fill(Record &record);

  /*
   * Display the tree in a text format
   */
  std::string to_string();
};

#endif  // POLYGONIAL_FACTSENGINE_H
