//
//  85 Maximal Rectangle.cpp
//  LeetCode
//
//  Created by 赵超 on 9/1/16.
//  Copyright © 2016 赵超. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <stack>
#include <string>
using namespace std;

#define VEC(s)  stringToVector(s)

class Solution {
private:
    static inline vector<char> stringToVector(string s) {
        vector<char> ret(s.length());
        auto ret_it = ret.begin();
        for (auto it = s.begin(); it != s.end(); it++) {
            *ret_it++ = *it;
        }
        return ret;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        unsigned long size = matrix.size();
        if (size == 0)
            return 0;
        unsigned long length = matrix[0].size();
        int maxArea = 0;
        vector<int> previousLineHeight(length);
        stack<pair<int, int>> index;
        int previousHeight, thisHeight;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < length; j++) {
                previousHeight = i == 0 ? 0 : previousLineHeight[j];
                thisHeight = matrix[i][j] == '1' ? (previousHeight + 1) : 0;
                previousLineHeight[j] = thisHeight;
                int thisWidth = j;
                if (index.empty()) {
                    goto push;
                }
                while (!index.empty() && thisHeight < index.top().second) {
                    int h = index.top().second;
                    int w = index.top().first;
                    printf("[i: %d] pop from stack! h:%d  w: %d  j: %d\n", i, h, w, j);
                    maxArea = max(maxArea, (j - w) * h);
                    thisWidth = index.top().first;
                    index.pop();
                }
            push:
                if (thisHeight > 0)
                    index.push(pair<int, int>(thisWidth, thisHeight));
            }
            while (!index.empty()) {
                int h = index.top().second;
                int w = index.top().first;
                printf("[i: %d] pop from stack! h:%d  w: %d  length: %lu\n", i, h, w, length);
                maxArea = max(maxArea, (int)(length - w) * h);
                index.pop();
            }
            for (int j = 0; j < length; j++) {
                printf("%d ", previousLineHeight[j]);
            }
            printf("\n");
        }
        return maxArea;
    }
    static int test() {
        Solution solution;
        vector<vector<char>> matrix = {VEC("101001"), VEC("101111"), VEC("111111"), VEC("100100")};
        // vector<vector<char>> matrix = {VEC("1101"), VEC("1101"), VEC("1111")};
        printf("%d\n", solution.maximalRectangle(matrix));
        return 0;
    }
};