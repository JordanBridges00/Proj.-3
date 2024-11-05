/*
 * This file should help you to create a minimal interface for your string class based on
 * a dynamically allocated char array. Note that c-strings use `\0` as a terminator symbol
 * but your class should store its length in a member variable. Do not use c-string functions
 * from <string.h> or <cstring> other than for conversion from a c-string.
 */

#include "DSString.h"
#include <cstring>  // For strlen, strcpy

// Default constructor
DSString::DSString() : data(nullptr), len(0) {}

// Constructor from c-string
DSString::DSString(const char* str) {
    if (str) {
        len = strlen(str);
        data = new char[len + 1];
        strcpy(data, str);
    } else {
        data = nullptr;
        len = 0;
    }
}

// Copy constructor
DSString::DSString(const DSString& other) {
    len = other.len;
    data = new char[len + 1];
    strcpy(data, other.data);
}

// Copy assignment operator
DSString& DSString::operator=(const DSString& other) {
    if (this != &other) {
        delete[] data;
        len = other.len;
        data = new char[len + 1];
        strcpy(data, other.data);
    }
    return *this;
}

// Destructor
DSString::~DSString() {
    delete[] data;
}

// Return the length of the string
size_t DSString::length() const {
    return len;
}

// Overload [] operator
char& DSString::operator[](size_t index) {
    return data[index];  // Add bounds checking in real scenario
}

// Concatenate two DSStrings
DSString DSString::operator+(const DSString& other) const {
    DSString result;
    result.len = len + other.len;
    result.data = new char[result.len + 1];
    strcpy(result.data, data);
    strcat(result.data, other.data);
    return result;
}

// Equality check
bool DSString::operator==(const DSString& other) const {
    return strcmp(data, other.data) == 0;
}

// Less than
bool DSString::operator<(const DSString& other) const {
    return strcmp(data, other.data) < 0;
}

// Get substring
DSString DSString::substring(size_t start, size_t numChars) const {
    DSString sub;
    if (start + numChars > len) numChars = len - start;
    sub.data = new char[numChars + 1];
    strncpy(sub.data, data + start, numChars);
    sub.data[numChars] = '\0';
    sub.len = numChars;
    return sub;
}

// Convert to lowercase
DSString DSString::toLower() const {
    DSString lower(*this);  // Copy current string
    for (size_t i = 0; i < len; ++i) {
        lower.data[i] = tolower(data[i]);  // Convert each character to lower case
    }
    return lower;
}

// c-string accessor
const char* DSString::c_str() const {
    return data;
}

// Stream insertion operator
std::ostream& operator<<(std::ostream& os, const DSString& str) {
    return os << str.data;
}

