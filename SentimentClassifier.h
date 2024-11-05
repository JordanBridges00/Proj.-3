#include <unordered_map>
#include "DSString.h"

class SentimentClassifier {
private:
    std::unordered_map<DSString, int> positiveWords;
    std::unordered_map<DSString, int> negativeWords;

public:
    void train(const std::string& trainingFile);
    int predict(const DSString& tweet);
    double evaluate(const std::string& testingFile, const std::string& groundTruthFile);
};

