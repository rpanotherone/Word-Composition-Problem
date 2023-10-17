#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <string>

using namespace std;

// Defining a TrieNode for the Trie data structure
class TrieNode {
public:
    TrieNode* children[26]; // Array to store children nodes for each letter of the alphabet
    bool isEndOfWord; // Indicates if a word ends at this node

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEndOfWord = false;
    }
};

// Defining the Trie data structure
class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(const string& word) {
        TrieNode* current = root;
        for (char c : word) {
            int index = c - 'a'; // Calculate the index for the letter 'a' to 'z'
            if (!current->children[index]) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isEndOfWord = true;
    }

    // Search for a word in the Trie
    bool search(const string& word) {
        TrieNode* current = root;
        for (char c : word) {
            int index = c - 'a';
            if (!current->children[index]) {
                return false;
            }
            current = current->children[index];
        }
        return current->isEndOfWord;
    }

private:
    TrieNode* root;
};

// Function to recursively check if a word is a compounded word
bool isCompoundWord(const string& word, int index, Trie& trie) {
    int length = word.length();
    if (index == length) {
        return true;
    }

    for (int i = index; i < length; i++) {
        if (trie.search(word.substr(index, i - index + 1)) && isCompoundWord(word, i + 1, trie)) {
            return true;
        }
    }

    return false;
}

// Function to find the longest compounded word in a list of words
string findLongestCompoundWord(const vector<string>& words) {
    Trie trie;
    string longestCompoundWord = "";

    for (const string& word : words) {
        if (word.length() == 0) continue;

        if (isCompoundWord(word, 0, trie)) {
            if (word.length() > longestCompoundWord.length()) {
                longestCompoundWord = word;
            }
        }

        trie.insert(word);
    }

    return longestCompoundWord;
}

// Function to find the second longest compounded word in a list of words
string findSecondLongestCompoundWord(const vector<string>& words) {
    Trie trie;
    string longestCompoundWord = "";
    string secondLongestCompoundWord = "";

    for (const string& word : words) {
        if (word.length() == 0) continue;

        if (isCompoundWord(word, 0, trie)) {
            if (word.length() >= longestCompoundWord.length()) {
                secondLongestCompoundWord = longestCompoundWord;
                longestCompoundWord = word;
            } else if (word.length() > secondLongestCompoundWord.length()) {
                secondLongestCompoundWord = word;
            }
        }

        trie.insert(word);
    }

    return secondLongestCompoundWord;
}

int main() {
    vector<string> words1, words2;
    string word;

    // taking current time as a reference for catculation of time taken to procees input
    auto start_time = chrono::high_resolution_clock::now();

    // reading & storing the input file
    ifstream input_file1("Input_01.txt");
    while (input_file1 >> word) {
        words1.push_back(word);
    }

    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);

    string longestCompoundWord1 = findLongestCompoundWord(words1);
    string secondLongestCompoundWord1 = findSecondLongestCompoundWord(words1);

    // Output for 1st input
    cout << "\nInput 01:" << endl;
    cout << "1. Longest Compound Word: " << longestCompoundWord1 << endl;
    cout << "2. Second Longest Compound Word: " << secondLongestCompoundWord1 << endl;
    cout << "Time taken to process Input 01: " << duration.count() << " milliseconds" << endl;

    // Reseting the time for input_02
    start_time = chrono::high_resolution_clock::now();

    // Reading and storing the Input_02
    ifstream input_file2("Input_02.txt");
    while (input_file2 >> word) {
        words2.push_back(word);
    }

    end_time = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);

    string longestCompoundWord2 = findLongestCompoundWord(words2);
    string secondLongestCompoundWord2 = findSecondLongestCompoundWord(words2);
    
    // Output 2
    cout << "\nInput 02:" << endl;
    cout << "1. Longest Compound Word: " << longestCompoundWord2 << endl;
    cout << "2. Second Longest Compound Word: " << secondLongestCompoundWord2 << endl;
    cout << "Time taken to process Input 02: " << duration.count() << " milliseconds" << endl;

    return 0;
}
