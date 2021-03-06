//
// Created by tristan on 04/04/19.
//

#include "InferenceEngine.h"

InferenceEngine::InferenceEngine(FactsEngine &factsEngine,
                                 RulesEngine &rulesEngine)
    : factsEngine(factsEngine), rulesEngine(rulesEngine) {}

void InferenceEngine::process(Record &record) {
  factsEngine.fill(record);
  if (!record.is_filled()) {
    rulesEngine.fill(record);
    factsEngine.store(record);
  }
}
