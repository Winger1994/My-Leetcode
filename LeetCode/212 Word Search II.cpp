//
//  212 Word Search II.cpp
//  LeetCode https://leetcode.com/problems/word-search-ii/#/description
//
//  Created by 赵超 on 14/03/2017.
//  Copyright © 2017 赵超. All rights reserved.
//

// Input:
// ["aaaa","aaaa","aaaa"]
// ["aaaaaaaaaaaa","aaaaaaaaaaaaa","aaaaaaaaaaab"]
// Output:
// ["aaaaaaaaaaaaa","aaaaaaaaaaaa"]
// Expected:
// ["aaaaaaaaaaaa"]

// TLE! need to use DP programming to preprocess the searched strings

#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
private:
    typedef pair<int, int> P;
    int length, width;
    bool wordExists(vector<vector<char>>& board, string word) {
        char first = word[0];
        for (int x = 0; x < length; ++x) {
            for (int y = 0; y < width; ++y) {
                if (board[x][y] == first) {
                    board[x][y] *= -1;
                    // if (leftWordExists(board, word.substr(1), P(x, y), 0))
                    if (leftWordExists(board, word.substr(1), P(x, y)))
                        return true;
                    board[x][y] *= -1;
                }
            }
        }
        return false;
    }
//    bool leftWordExists(vector<vector<char>>& board, string leftWord, P xy, int except) {
//        if (leftWord.size() == 0)
//            return true;
//        int x = xy.first, y = xy.second;
//        char first = leftWord[0];
//        if (x > 0 && except != 1 && board[x - 1][y] == first) {
//            if (leftWordExists(board, leftWord.substr(1), P(x - 1, y), 3))
//                return true;
//        }
//        if (y < width - 1 && except != 2 && board[x][y + 1] == first) {
//            if (leftWordExists(board, leftWord.substr(1), P(x, y + 1), 4))
//                return true;
//        }
//        if (x < length - 1 && except != 3 && board[x + 1][y] == first) {
//            if (leftWordExists(board, leftWord.substr(1), P(x + 1, y), 1))
//                return true;
//        }
//        if (y > 0 && except != 4 && board[x][y - 1] == first) {
//            if (leftWordExists(board, leftWord.substr(1), P(x, y - 1), 2))
//                return true;
//        }
//        return false;
//    }
    bool leftWordExists(vector<vector<char>>& board, string leftWord, P xy) {
        if (leftWord.size() == 0)
            return true;
        int x = xy.first, y = xy.second;
        char first = leftWord[0];
        if (x > 0  && board[x - 1][y] == first) {
            board[x - 1][y] *= -1;
            if (leftWordExists(board, leftWord.substr(1), P(x - 1, y)))
                return true;
            board[x - 1][y] *= -1;
        }
        if (y < width - 1 && board[x][y + 1] == first) {
            board[x][y + 1] *= -1;
            if (leftWordExists(board, leftWord.substr(1), P(x, y + 1)))
                return true;
            board[x][y + 1] *= -1;
        }
        if (x < length - 1 && board[x + 1][y] == first) {
            board[x + 1][y] *= -1;
            if (leftWordExists(board, leftWord.substr(1), P(x + 1, y)))
                return true;
            board[x + 1][y] *= -1;
        }
        if (y > 0 && board[x][y - 1] == first) {
            board[x][y - 1] *= -1;
            if (leftWordExists(board, leftWord.substr(1), P(x, y - 1)))
                return true;
            board[x][y - 1] *= -1;
        }
        return false;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        length = board.size(), width = board[0].size();
        unordered_set<string> set;
        for (string word : words) {
            vector<vector<char>> newBoard(board);
            if (wordExists(newBoard, word))
                set.insert(word);
        }
        vector<string> res(set.begin(), set.end());
        return res;
    }
    static void test() {
        Solution solution;
//        vector<vector<char>> board{{'a','a','a','a'}, {'a','a','a','a'}, {'a','a','a','a'}};
//        vector<string> words{"aaaaaaaaaaaa","aaaaaaaaaaaaa","aaaaaaaaaaab"};
        vector<string> boardString{"oaan","etae","ihkr","iflv"};
        vector<vector<char>> board;
        for (string s : boardString) {
            board.push_back(vector<char>(s.begin(), s.end()));
        }
        vector<string> words{"oath","pea","eat","rain"};
        vector<string> res = solution.findWords(board, words);
        for (string s : res) {
            printf("%s\n", s.c_str());
        }
    }
};
