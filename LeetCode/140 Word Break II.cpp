//
//  140 Word Break II.cpp
//  LeetCode
//
//  Created by 赵超 on 07/12/2016.
//  Copyright © 2016 赵超. All rights reserved.
//
// Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.
// For example, given
// s = "catsanddog",
// dict = ["cat", "cats", "and", "sand", "dog"].
// A solution is ["cats and dog", "cat sand dog"].

#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class SolutionPureIter {
private:
    vector<int> getWordSizes(unordered_set<string>& wordDict) {
        unordered_set<int> sizes;
        for (auto it = wordDict.begin(); it != wordDict.end(); ++it) {
            sizes.insert(sizes.end(), static_cast<int>(it->length()));
        }
        printf("word dict size: %lu, sizes size: %lu\n", wordDict.size(), sizes.size());
        vector<int> sizeVec(sizes.begin(), sizes.end());
        sort(sizeVec.begin(), sizeVec.end());
        reverse(sizeVec.begin(), sizeVec.end());
        printf("sizes: ");
        for (int i : sizes) {
            printf("%d ", i);
        }
        printf("\n");
        return sizeVec;
    }
    
    vector<string> core(string s, unordered_set<string>& wordDict, vector<int>& wordSizes, bool& exist) {
        printf("s: %s\n", s.c_str());
        vector<string> res;
        exist = false;
        for (int wordSz : wordSizes) {
            if (wordSz > s.size())
                continue;
            string head = s.substr(0, wordSz);
            if (wordDict.find(head) == wordDict.end())
                continue;
            string left = s.substr(wordSz);
            if (left.length() == 0) {
                res.push_back(head);
                exist = true;
                continue;
            }
            bool childExist; // another independent bool variable for detect existence of child iteration is necessary
            vector<string> leftVec = core(left, wordDict, wordSizes, childExist);
            if (!childExist)
                continue;
            exist = true;
            for (string leftStr : leftVec) {
                res.push_back(head + " " + leftStr);
            }
        }
        return res;
    }
    
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<int> wordSizes = getWordSizes(wordDict);
        bool exist;
        return core(s, wordDict, wordSizes, exist);
    }
};

class SolutionDP { // runtime: 6ms, beat 94.04%
private:
    string s;
    unordered_set<string> wordDict;
    vector<int> wordSizes;
    
    vector<vector<string>*> storage;
    
    void getWordSizes() {
        unordered_set<int> sizes;
        for (auto it = wordDict.begin(); it != wordDict.end(); ++it) {
            sizes.insert(sizes.end(), static_cast<int>(it->length()));
        }
        printf("word dict size: %lu, sizes size: %lu\n", wordDict.size(), sizes.size());
        vector<int> sizeVec(sizes.begin(), sizes.end());
        sort(sizeVec.begin(), sizeVec.end());
        reverse(sizeVec.begin(), sizeVec.end());
        wordSizes = sizeVec;
    }
    
    void calc(int pos) {
        string s = this->s.substr(pos);
        printf("s: %s\n", s.c_str());
        vector<string>* res = new vector<string>;
        for (int wordSz : wordSizes) {
            if (wordSz > s.size())
                continue;
            string head = s.substr(0, wordSz);
            if (wordDict.find(head) == wordDict.end())
                continue;
            int nextPos = pos + wordSz;
            if (nextPos == this->s.length()) {
                res->push_back(head);
                continue;
            }
            vector<string>* leftVec = get(nextPos);
            for (string leftStr : *leftVec) {
                res->push_back(head + " " + leftStr);
            }
        }
        storage[pos] = res;
    }
    
    vector<string>* get(int pos) {
        if (!storage[pos])
            calc(pos);
        return storage[pos];
    }
    
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        this->s = s;
        this->wordDict = wordDict;
        getWordSizes();
        storage.resize(s.length() + 1);
        for (auto ptr : storage)
            ptr = NULL;
        return *get(0);
    }
};

