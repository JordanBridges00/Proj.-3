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

