#include "DSString.h"

// Default constructor
DSString::DSString() : data(nullptr), len(0) {}

// Parameterized constructor
DSString::DSString(const char* str) {
    if (str) {
        len = 0;
        while (str[len] != '\0') { // Find length manually
            len++;
        }
        data = new char[len + 1];
        for (int i = 0; i < len; i++) {
            data[i] = str[i];
        }
        data[len] = '\0';
    } else {
        data = nullptr;
        len = 0;
    }
}

// Copy constructor
DSString::DSString(const DSString& other) {
    len = other.len;
    data = new char[len + 1];
    for (int i = 0; i < len; i++) {
        data[i] = other.data[i];
    }
    data[len] = '\0';
}

// Move constructor
DSString::DSString(DSString&& other) noexcept : data(other.data), len(other.len) {
    other.data = nullptr;
    other.len = 0;
}

// Destructor
DSString::~DSString() {
    delete[] data;
}

// Copy assignment operator
DSString& DSString::operator=(const DSString& other) {
    if (this == &other) return *this;
    delete[] data;
    len = other.len;
    data = new char[len + 1];
    for (int i = 0; i < len; i++) {
        data[i] = other.data[i];
    }
    data[len] = '\0';
    return *this;
}

// Move assignment operator
DSString& DSString::operator=(DSString&& other) noexcept {
    if (this == &other) return *this;
    delete[] data;
    data = other.data;
    len = other.len;
    other.data = nullptr;
    other.len = 0;
    return *this;
}

// Overload == operator for equality comparison
bool DSString::operator==(const DSString& other) const {
    if (len != other.len) return false;
    for (int i = 0; i < len; i++) {
        if (data[i] != other.data[i]) return false;
    }
    return true;
}

// Overload + operator for string concatenation
DSString DSString::operator+(const DSString& other) const {
    char* concatenatedData = new char[len + other.len + 1];
    for (int i = 0; i < len; i++) {
        concatenatedData[i] = data[i];
    }
    for (int i = 0; i < other.len; i++) {
        concatenatedData[len + i] = other.data[i];
    }
    concatenatedData[len + other.len] = '\0';
    DSString result(concatenatedData);
    delete[] concatenatedData;
    return result;
}

// Overload [] operator for accessing characters
char& DSString::operator[](const int index) {
    return data[index];
}

const char& DSString::operator[](const int index) const {
    return data[index];
}

// Get the length of the string
int DSString::length() const {
    return len;
}

// Method to return a C-string representation
const char* DSString::c_str() const {
    return data;
}


/* 
 * Implement the functions defined in DSString.h. You may add more functions as needed
 * for the project. 
 *
 * Note that c-strings don's store an explicit length but use `\0` as the terminator symbol
 * but your class should store its length in a member variable. 
 * DDO NOT USE C-STRING FUNCTIONS <string.h> or <cstring>.
 */  
