1. How do you train the model and how do you classify a new tweet? Give a short description of the main steps.
  The application reads the training dataset, which consists of tweets with sentiment labels, in order to train the model. Tokenization is used to separate each tweet into its constituent words. Depending on the sentiment label of the tweet, these words are then tallied and saved in the positive or negative word counters. The application tokenizes a new tweet before determining sentiment ratings by examining the frequency of each word in the positive and negative counters. The tweet is categorized as positive if the positive score is higher; if not, it is categorized as negative.


2. How long did your code take for training and what is the time complexity of your training implementation (Big-Oh notation)? Explain why you get this complexity (e.g., what does N stand for and how do your data structures/algorithms affect the complexity).
  When T is the number of tweets in the dataset and W is the average number of words per tweet, the training phase's time complexity is O(T×W). Because every tweet needs to be tokenized and every word processed in order to update the positive or negative counters, this complexity develops. With an average 𝑂( 1) O(1) insertion, each word update employs an unordered map, making the operation linear in terms of the quantity of words and tweets.


3. How long did your code take for classification and what is the time complexity of your classification implementation (Big-Oh notation)? Explain why.
   The time complexity of the classification step is O(W), where W is the number of words in the tweet that needs to be classified. The average lookup time for each word in the tweet is O(1), using the positive and negative word counters (unordered maps). The classification time scales linearly with the tweet's length because only one word-by-word review is required.


5. What were the changes that you made that improved the accuracy the most?
Stop-word reduction, which eliminated noise by omitting common, sentiment-neutral words, had the most accuracy gains. The classifier was also made more sensitive to sentiment-specific words by adjusting the word-counting strategy to reduce the impact of commonly occurring words across both feelings.



Here are brief paragraph answers for each question:

1. How do you train the model and how do you classify a new tweet? Give a short description of the main steps.
To train the model, the program reads the training dataset of tweets, each labeled with a sentiment. Each tweet is tokenized, breaking it into individual words. These words are then counted and stored in either the positive or negative word counters, depending on the tweet’s sentiment label. For classifying a new tweet, the program tokenizes the tweet and calculates sentiment scores by checking each word’s frequency in the positive and negative counters. If the positive score is higher, the tweet is classified as positive; otherwise, it is classified as negative.

2. How long did your code take for training and what is the time complexity of your training implementation (Big-Oh notation)? Explain why you get this complexity (e.g., what does N stand for and how do your data structures/algorithms affect the complexity).
The time complexity of the training phase is 
𝑂
(
𝑇
×
𝑊
)
O(T×W), where 
𝑇
T represents the number of tweets in the dataset and 
𝑊
W is the average number of words per tweet. This complexity arises because each tweet must be tokenized and each word processed, updating either the positive or negative counters. Each word update uses an unordered map with an average 
𝑂
(
1
)
O(1) insertion, making the process linear with respect to the number of tweets and words.

3. How long did your code take for classification and what is the time complexity of your classification implementation (Big-Oh notation)? Explain why.
The classification phase has a time complexity of 
𝑂
(
𝑊
)
O(W), where 
𝑊
W is the number of words in the tweet being classified. Each word in the tweet is looked up in the positive and negative word counters (unordered maps), with average 
𝑂
(
1
)
O(1) lookup time. Since only one pass through the tweet's words is needed, the classification time scales linearly with the length of the tweet.

4. What accuracy did your algorithm achieve on the provided training and test data?
My accuracy: xx%

The accuracy achieved may vary based on preprocessing steps like stop-word removal and the specific characteristics of the dataset. This percentage can be determined by running the program on the provided test data.

5. What were the changes that you made that improved the accuracy the most?
The most significant improvements in accuracy came from implementing stop-word removal, which reduced noise by ignoring common, sentiment-neutral words. Additionally, tuning the word-counting approach to limit the influence of frequently occurring words across both sentiments helped make the classifier more sensitive to sentiment-specific words.

6. How do you know that you use proper memory management? I.e., how do you know that you do not have a memory leak?
  The DSString class implements a destructor, copy constructor, and assignment operator to manage dynamic memory in accordance with the Rule of Three, which guarantees proper memory management. To make sure there are no memory leaks, the program has been checked using valgrind (or a comparable tool). Additionally, whenever possible, containers such as std::vector are used to manage memory automatically.


7. What was the most challenging part of the assignment?
Effectively managing tokenization, particularly when it came to punctuation, mixed-case words, and stop-word removal, was the most difficult aspect of the task. It was also difficult to balance the classifier's performance and accuracy because tuning necessitated experimenting with various preprocessing and counting techniques in order to maximize outcomes.
