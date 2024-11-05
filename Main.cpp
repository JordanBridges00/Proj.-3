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


#include <iostream>


int main(int argc, char** argv)
{  
    std::cout << "I will be a sentiment analyzer!" << std::endl;

    return 0;
}
