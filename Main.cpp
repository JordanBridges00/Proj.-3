/*
This project aims to build a sentiment analysis tool in C++ that classifies tweets as either positive or negative 
by analyzing the frequency of words associated with each sentiment. The program is composed of two primary classes: 
DSString, a custom string class optimized for text processing and memory management, and SentimentClassifier, which 
implements the core logic for sentiment classification based on a training dataset. The DSString class handles common 
string operations and ensures efficient dynamic memory management to support large datasets. SentimentClassifier 
utilizes frequency-based methods to analyze the sentiment of individual words within each tweet. It first 'trains' 
on a labeled dataset of tweets, building word frequency tables for both positive and negative tweets. In the prediction 
phase, the classifier evaluates the sentiment of a new tweet by calculating the cumulative sentiment score based on word 
occurrences in each category, ultimately classifying the tweet as positive or negative. The project is designed with 
modularity in mind, allowing for testing, optimization, and eventual extension to larger datasets or more sophisticated 
text processing methods, like removing stop words or stemming. Through command-line arguments, the program accepts paths 
to the training and testing datasets, allowing for flexibility in file input and output. This project serves as both a 
practical application of data structures and algorithms and an introduction to text-based machine learning in a C++ environment.
*/

/*
#include <iostream>


int main(int argc, char** argv)
{  
    std::cout << "I will be a sentiment analyzer!" << std::endl;

    return 0;
}
*/

#include <iostream>
#include <fstream>
#include "SentimentClassifier.h"

int main(int argc, char* argv[]) {
    if (argc != 6) {
        std::cerr << "Usage: " << argv[0] 
                  << " <training dataset> <testing dataset> <ground truth file> <results file> <accuracy file>" 
                  << std::endl;
        return 1;
    }

    std::string trainingFile = argv[1];
    std::string testingFile = argv[2];
    std::string groundTruthFile = argv[3];
    std::string resultsFile = argv[4];
    std::string accuracyFile = argv[5];

    SentimentClassifier classifier;

    // Train the classifier
    classifier.train(trainingFile);

    // Open the results file for writing predictions
    std::ofstream resultsOutput(resultsFile);
    if (!resultsOutput.is_open()) {
        std::cerr << "Error: Could not open results file." << std::endl;
        return 1;
    }

    // Open the ground truth file for accuracy evaluation
    std::ofstream accuracyOutput(accuracyFile);
    if (!accuracyOutput.is_open()) {
        std::cerr << "Error: Could not open accuracy file." << std::endl;
        return 1;
    }

    // Evaluate accuracy and save predictions
    double accuracy = classifier.evaluate(testingFile, groundTruthFile);

    // Save accuracy to file
    accuracyOutput << "Accuracy: " << accuracy << std::endl;

    resultsOutput.close();
    accuracyOutput.close();

    std::cout << "Classification complete. Accuracy: " << accuracy << std::endl;

    return 0;
}

