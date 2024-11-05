# Sentiment Analysis Classifier Project

This project implements a sentiment analysis classifier that categorizes tweets as either positive or negative. Using a frequency-based approach, the classifier is trained on a labeled dataset of tweets to learn word associations with positive and negative sentiments. The program reads input files, processes tweets, predicts sentiments, and evaluates its accuracy against a ground truth dataset.

---

## Author Information

- **Authors**: Colby Papadakis and Jordan Bridges
- **Course**: CS5393-002
- **Project**: Project 3 - Sentiment Analysis Classifier

---

## Implementation Summary

This project includes two primary classes:

1. **DSString Class**: This custom string class handles basic string operations and manages dynamic memory efficiently, with functions for concatenation, comparison, and string manipulation. It is designed to work with C-style strings in C++ and provides essential operators and methods needed by the classifier.

2. **SentimentClassifier Class**: This class is responsible for analyzing the sentiment of tweets. It trains on a labeled dataset of positive and negative tweets, using word frequencies to build a simple sentiment model. The class includes functions to:
   - `train`: Process the training dataset and build word frequency maps for positive and negative tweets.
   - `predict`: Classify a new tweet as positive or negative based on the frequency of words in each category.
   - `evaluate`: Compare predictions with actual sentiments from a test dataset and calculate accuracy.

**Workflow**:
The main program (`main.cpp`) accepts command-line arguments for dataset paths, trains the classifier, makes predictions, and evaluates the model’s performance. It outputs the predictions to a results file and the accuracy to a separate file.

---

## Complexity Analysis

### `train` Function

- **Purpose**: Processes each tweet in the training dataset, tokenizing each word and updating word frequencies for positive and negative sentiments.
- **Time Complexity**: \( O(T \times W) \), where \( T \) is the number of tweets and \( W \) is the average number of words per tweet.
- **Space Complexity**: \( O(V) \), where \( V \) is the vocabulary size (the number of unique words across all tweets).

### `predict` Function

- **Purpose**: Tokenizes a single tweet and calculates sentiment scores by checking word frequencies.
- **Time Complexity**: \( O(W) \), where \( W \) is the number of words in the tweet.
- **Space Complexity**: \( O(W) \), for storing tokens temporarily.

### `evaluate` Function

- **Purpose**: Iterates through test tweets, calling `predict` for each tweet and comparing predictions to the ground truth labels.
- **Time Complexity**: \( O(T \times W) \), where \( T \) is the number of test tweets.
- **Space Complexity**: \( O(W) \), for storing tokens temporarily.

### Optimizations
- **Stop-Word Removal**: Common stop words like "the," "is," and "and" are ignored during tokenization to reduce noise and improve accuracy.

---

## Limitations and Improvements

While this frequency-based approach performs well for simple sentiment analysis, it may struggle with nuanced sentiments or complex sentence structures. Potential improvements include:

1. **Stemming**: Implementing word stemming could help reduce word variations (e.g., "running" vs. "run") and improve frequency accuracy.
2. **Machine Learning Techniques**: Using more advanced methods, such as Naive Bayes or logistic regression, could increase accuracy and provide better generalization across different datasets.

---

## How to Run the Program

### Compilation

To compile the program, navigate to the `src/` folder of your project and use the following command:

```bash
g++ -o sentiment_analysis main.cpp DSString.cpp SentimentClassifier.cpp

Running the Program
To execute the program, you need to provide five command-line arguments:

1. Training Dataset: CSV file with labeled tweets for training (e.g., data/train_dataset_20k.csv).
2. Testing Dataset: CSV file with tweets for testing (e.g., data/test_dataset_10k.csv).
3. Ground Truth File: CSV file with the actual sentiment labels for the testing dataset (e.g., data/test_dataset_sentiment_10k.csv).
4. Results File: The output file where the program will save the predicted sentiments (e.g., results.txt).
5. Accuracy File: The output file where the program will save the calculated accuracy (e.g., accuracy.txt).
Use the following command format to run the program:
./sentiment_analysis <training dataset> <testing dataset> <ground truth file> <results file> <accuracy file>

