#include "SentimentClassifier.h"
#include <fstream>
#include <sstream>
#include <string>

void SentimentClassifier::train(const std::string& trainingFile) {
    std::ifstream file(trainingFile);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open training file.");
    }

    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string sentiment, tweet;
        getline(ss, sentiment, ',');
        getline(ss, tweet);

        // Tokenize the tweet text and process each word
        std::stringstream tweetStream(tweet);
        std::string word;
        while (tweetStream >> word) {
            DSString dsWord(word.c_str());  // Convert to DSString if necessary

            if (sentiment == "positive") {
                positiveWords[dsWord]++;
            } else if (sentiment == "negative") {
                negativeWords[dsWord]++;
            }
        }
    }
    file.close();
}

