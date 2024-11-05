#include "SentimentClassifier.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>

// Helper function to read CSV files, returning pairs of sentiment and tweet text
std::vector<std::pair<std::string, DSString>> readCSV(const std::string& filename) {
    std::vector<std::pair<std::string, DSString>> data;
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + filename);
    }

    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string sentiment, tweet;
        getline(ss, sentiment, ',');  // Read sentiment
        getline(ss, tweet);           // Read tweet text

        data.emplace_back(sentiment, DSString(tweet.c_str()));
    }

    file.close();
    return data;
}

#include <vector>

// Tokenizes a string into words and returns them as a vector of DSString objects
std::vector<DSString> tokenize(const DSString& text) {
    std::vector<DSString> tokens;
    std::stringstream ss(text.c_str());
    std::string word;

    while (ss >> word) {
        tokens.emplace_back(word.c_str());  // Convert each word to DSString
    }

    return tokens;
}


void SentimentClassifier::train(const std::string& trainingFile) {
    auto data = readCSV(trainingFile);  // Use readCSV to get the training data

    for (const auto& entry : data) {
        const std::string& sentiment = entry.first;
        const DSString& tweet = entry.second;

        // Tokenize the tweet
        auto tokens = tokenize(tweet);

        // Update word frequencies based on sentiment
        for (const auto& word : tokens) {
            if (sentiment == "positive") {
                positiveWords[word]++;
            } else if (sentiment == "negative") {
                negativeWords[word]++;
            }
        }
    }
}


int SentimentClassifier::predict(const DSString& tweet) {
    auto tokens = tokenize(tweet);  // Tokenize the tweet

    int positiveScore = 0;
    int negativeScore = 0;

    for (const auto& word : tokens) {
        if (positiveWords.find(word) != positiveWords.end()) {
            positiveScore += positiveWords[word];
        }
        if (negativeWords.find(word) != negativeWords.end()) {
            negativeScore += negativeWords[word];
        }
    }

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
