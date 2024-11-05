#ifndef SENTIMENTCLASSIFIER_H
#define SENTIMENTCLASSIFIER_H

#include <unordered_map>
#include <string>
#include "DSString.h"

class SentimentClassifier {
private:
    std::unordered_map<DSString, int> positiveWords;
    std::unordered_map<DSString, int> negativeWords;

public:
    // Trains the classifier using the provided training dataset file
    void train(const std::string& trainingFile);

    // Predicts the sentiment of a given tweet
    // Returns 1 for positive and 0 for negative
    int predict(const DSString& tweet);

    // Evaluates the classifier's accuracy against a testing dataset
    // Returns the accuracy as a double (percentage of correct predictions)
    double evaluate(const std::string& testingFile, const std::string& groundTruthFile);
};

#endif // SENTIMENTCLASSIFIER_H


