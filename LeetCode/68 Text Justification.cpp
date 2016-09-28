//
//  68 Text Justification.cpp
//  LeetCode
//
//  Created by 赵超 on 27/09/2016.
//  Copyright © 2016 赵超. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    string xSpace(int x) {
        printf("construct space string length: %d\n", x);
        return string(x, ' ');
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int begin = 0, end = 0;
        while (begin < words.size()) {
            string line;
            int groupLen = -1;
            while (end < words.size()) {
                printf("end: %d  word: %s\n", end, words[end].c_str());
                if (groupLen + words[end].length() + 1 > maxWidth)
                    break;
                groupLen += words[end++].length() + 1;
            }
            printf("begin: %d  end: %d\n", begin, end);
            if (end == words.size()) {
                if (begin < end)
                    line += words[begin++];
                while (begin < end) {
                    line += ' ' + words[begin++];
                }
                line += xSpace(maxWidth - groupLen);
            } else {
                groupLen -= end - begin - 1;
                printf("groupLen: %d\n", groupLen);
                int spaceNum = maxWidth - groupLen;
                int wordsNum = end - begin;
                int emptyNum = wordsNum <= 2 ? 1 : wordsNum - 1;
                int averageSpace = spaceNum / emptyNum;
                int oneMoreNum = spaceNum - averageSpace * emptyNum;
                while (begin < end) {
                    line += words[begin++];
                    if (emptyNum > 0) {
                        --emptyNum;
                        int spaceLen = averageSpace;
                        if (oneMoreNum > 0) {
                            --oneMoreNum;
                            ++spaceLen;
                        }
                        line += xSpace(spaceLen);
                    }
                }
            }
            res.push_back(line);
        }
        return res;
    }
    static void test() {
        Solution solution;
        // vector<string> words({"This", "is", "an", "example", "of", "text", "justification."});
        // vector<string> lines = solution.fullJustify(words, 16);
        vector<string> words({""});
        vector<string> lines = solution.fullJustify(words, 0);
        for (string line : lines) {
            printf("%s\n", line.c_str());
        }
    }
};
