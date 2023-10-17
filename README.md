# Word Composition Problem Solver

## Problem Statement

You are tasked with writing a program to solve the Word Composition Problem. The problem involves reading two input files, `Input_01.txt` and `Input_02.txt`, each containing alphabetically sorted words. The program should identify and display the following data:

1. Longest compounded word
2. Second longest compounded word
3. Time taken to process the input file

A compounded word is one that can be constructed by concatenating shorter words found in the same file. Your program should handle both small and large word lists efficiently.

### Example

For `Input_01.txt`:
```
cat
cats
catsdogcats
catxdogcatsrat
dog
dogcatsdog
hippopotamuses
rat
ratcatdogcat
```

The output should be:
```
Input 01:
1. Longest Compound Word: ratcatdogcat
2. Second Longest Compound Word: catsdogcats
Time taken to process Input 01: [Time in milliseconds]

Input 02:
1. Longest Compound Word: [Longest word]
2. Second Longest Compound Word: [Second longest word]
Time taken to process Input 02: [Time in milliseconds]
```

## Flow of Execution

Here is the flow of execution for the provided C++ code:

1. The program defines a `TrieNode` class to create nodes for a Trie data structure. Each node has an array of children nodes representing the alphabet letters and a flag to indicate the end of a word.

2. The `Trie` class is defined to create and manage a Trie. It provides methods for inserting a word into the Trie and searching for a word.

3. The `isCompoundWord` function is a recursive function that checks if a word is compounded from smaller words in the Trie.

4. The `findLongestCompoundWord` function finds the longest compounded word in a list of words by iterating through the list and checking if each word is compounded.

5. The `findSecondLongestCompoundWord` function finds the second longest compounded word in a list of words while keeping track of the longest and second-longest words found.

6. In the `main` function, the program measures the time it takes to process each input file separately. It uses the `<chrono>` library to measure time accurately.

7. The program reads words from `Input_01.txt`, processes them to find the longest and second longest compounded words, and measures the time taken to process the file. It then repeats the same process for `Input_02.txt`.

8. Finally, the program prints the results to the console, displaying the longest and second longest compounded words for each input file along with the time taken for processing.

## How to Execute the Code

To execute the code, follow these steps:

1. Compile the C++ code using a C++ compiler (e.g., g++):
   ```
   g++ -o word_composition_solver word_composition_solver.cpp
   ```

2. Run the executable with the provided input files:
   ```
   ./word_composition_solver
   ```

3. The program will process the input files, and the results will be displayed in the console.

---
