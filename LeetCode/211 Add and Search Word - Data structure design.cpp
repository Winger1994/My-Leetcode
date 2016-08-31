//
//  211 Add and Search Word - Data structure design.cpp
//  LeetCode
//
//  Created by 赵超 on 8/31/16.
//  Copyright © 2016 赵超. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

#define ADD(x) wordDictionary.addWord(x)
#define SEARCH(x) cout<<x<<": "<<wordDictionary.search(x)<<endl

class WordDictionaryWord {
private:
    struct Node {
        string word = "";
        Node* children[26];
    };
    Node* root;
    inline int index(char c) {
        return c - 'a';
    }
    bool search(string word, Node* ptr) {
        if (ptr == NULL)
            return false;
        if (word == ""){
            if (ptr -> word == "")
                return false;
            return true;
        }
        string subword;
        if (word.length() > 1)
            subword = word.substr(1);
        if (word[0] == '.') {
            for(int i = 0; i < 26; ++i) {
                if (search(subword, ptr->children[i]))
                    return true;
            }
            return false;
        }
        return search(subword, ptr->children[index(word[0])]);
    }
public:
    WordDictionaryWord(){
        root = new Node();
        root -> word = "root";
    }
    // Adds a word into the data structure.
    void addWord(string word){
        Node* ptr = root;
        for(auto it = word.begin(); it != word.end(); it++) {
            if (ptr->children[index(*it)] == NULL)
                ptr->children[index(*it)] = new Node();
            ptr = ptr->children[index(*it)];
        }
        ptr->word = word;
    }
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word){
        return search(word, root);
    }
    static int test() {
        WordDictionaryWord wordDictionary;
        ADD("ran");
        ADD("rune");
        ADD("runner");
        ADD("runs");
        ADD("add");
        ADD("adds");
        ADD("adder");
        ADD("addee");
        SEARCH("r.n");
        SEARCH("ru.n.e");
        SEARCH("add");
        SEARCH("add.");
        SEARCH("adde.");
        SEARCH(".an.");
        SEARCH("...s");
        SEARCH("....e.");
        SEARCH(".......");
        SEARCH("...n.r");
        return 0;
    }
};


class WordDictionary {
private:
    struct Node {
        bool exists;
        Node* children[26];
    };
    Node* root;
    inline int index(char c) {
        return c - 'a';
    }
    bool search(string word, Node* ptr) {
        if (ptr == NULL)
            return false;
        if (word == ""){
            if (ptr -> exists)
                return true;
            return false;
        }
        string subword;
        if (word.length() > 1)
            subword = word.substr(1);
        if (word[0] == '.') {
            for(int i = 0; i < 26; ++i) {
                if (search(subword, ptr->children[i]))
                    return true;
            }
            return false;
        }
        return search(subword, ptr->children[index(word[0])]);
    }
public:
    WordDictionary(){
        root = new Node();
    }
    // Adds a word into the data structure.
    void addWord(string word){
        Node* ptr = root;
        for(auto it = word.begin(); it != word.end(); it++) {
            if (ptr->children[index(*it)] == NULL)
                ptr->children[index(*it)] = new Node();
            ptr = ptr->children[index(*it)];
        }
        ptr->exists = true;
    }
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word){
        return search(word, root);
    }
    static int test() {
        WordDictionary wordDictionary;
        ADD("ran");
        ADD("rune");
        ADD("runner");
        ADD("runs");
        ADD("add");
        ADD("adds");
        ADD("adder");
        ADD("addee");
        SEARCH("r.n");
        SEARCH("ru.n.e");
        SEARCH("add");
        SEARCH("add.");
        SEARCH("adde.");
        SEARCH(".an.");
        SEARCH("...s");
        SEARCH("....e.");
        SEARCH(".......");
        SEARCH("...n.r");
        return 0;
    }
};


