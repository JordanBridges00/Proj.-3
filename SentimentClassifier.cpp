#include "SentimentClassifier.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

void SentimentClassifier::train(const std::string& trainingFile) {
    std::ifstream file(trainingFile);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open training file.");
    }

    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string sentiment, tweet;
        getline(ss, sentiment, ',');  // Read sentiment (assume first column)
        getline(ss, tweet);           // Read tweet text (assume rest of line)

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

int SentimentClassifier::predict(const DSString& tweet) {
    std::stringstream tweetStream(tweet.c_str());
    std::string word;
    int positiveScore = 0;
    int negativeScore = 0;

    while (tweetStream >> word) {
        DSString dsWord(word.c_str());

        if (positiveWords.find(dsWord) != positiveWords.end()) {
            positiveScore += positiveWords[dsWord];
        }

        if (negativeWords.find(dsWord) != negativeWords.end()) {
            negativeScore += negativeWords[dsWord];
        }
    }

    // Return 1 for positive sentiment, 0 for negative sentiment
    return (positiveScore > negativeScore) ? 1 : 0;
}

double SentimentClassifier::evaluate(const std::string& testingFile, const std::string& groundTruthFile) {
    std::ifstream testFile(testingFile);
    std::ifstream groundTruth(groundTruthFile);
    if (!testFile.is_open() || !groundTruth.is_open()) {
        throw std::runtime_error("Failed to open testing or ground truth file.");
    }

    std::string testTweet, trueSentiment;
    int correctPredictions = 0;
    int totalTweets = 0;

    while (getline(testFile, testTweet) && getline(groundTruth, trueSentiment)) {
        DSString dsTweet(testTweet.c_str());
        int predictedSentiment = predict(dsTweet);
        int actualSentiment = (trueSentiment == "positive") ? 1 : 0;

        if (predictedSentiment == actualSentiment) {
            correctPredictions++;
        }
        totalTweets++;
    }

    testFile.close();
    groundTruth.close();

    // Calculate accuracy
    return static_cast<double>(correctPredictions) / totalTweets;
}
