//
//  289 Game of Life.cpp
//  LeetCode
//
//  Created by 赵超 on 27/09/2016.
//  Copyright © 2016 赵超. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
private:
    int access(int y, int x, const vector<vector<int>>& board) {
        if (y < 0 || y >= board.size())
            return 0;
        if (x < 0 || x >= board[0].size())
            return 0;
        return board[y][x];
    }
    int alives(int y, int x, const vector<vector<int>>& board) {
        int res = 0;
        int yy = y - 1;
        for (int xx = x - 1; xx <= x + 1; ++xx) {
            res += access(yy, xx, board);
        }
        yy = y + 1;
        for (int xx = x - 1; xx <= x + 1; ++xx) {
            res += access(yy, xx, board);
        }
        res += access(y, x - 1, board);
        res += access(y, x + 1, board);
        return res;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> newBoard(board.size());
        for (int i = 0; i < board.size(); ++i) {
            newBoard[i].resize(board[i].size());
        }
        for (int y = 0; y < board.size(); ++y) {
            for (int x = 0; x < board[0].size(); ++x) {
                int live = alives(y, x, board);
                if (board[y][x] == 1) {
                    if (live == 2 || live == 3) {
                        newBoard[y][x] = 1;
                    } else {
                        newBoard[y][x] = 0;
                    }
                } else {
                    if (live == 3) {
                        newBoard[y][x] = 1;
                    } else {
                        newBoard[y][x] = 0;
                    }
                }
            }
        }
        for (int y = 0; y < board.size(); ++y) {
            for (int x = 0; x < board[0].size(); ++x) {
                board[y][x] = newBoard[y][x];
            }
        }
    }
    static void test() {
        Solution solution;
        vector<vector<int>> board(1);
        solution.gameOfLife(board);
    }
};
