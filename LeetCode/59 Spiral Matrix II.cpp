//
//  59 Spiral Matrix II.cpp
//  LeetCode
//
//  Created by 赵超 on 9/9/16.
//  Copyright © 2016 赵超. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
private:
    int num = 1;
    void fillMatrix(int y, int x, int n, vector<vector<int>>& matrix) {
        int i = 0, j = 0;
        for (; i < n; ++i) {
            matrix[j + y][i + x] = num++;
        }
        i--;
        j++;
        for (; j < n; ++j) {
            matrix[j + y][i + x] = num++;
        }
        j--;
        i--;
        for (; i >= 0; --i) {
            matrix[j + y][i + x] = num++;
        }
        i++;
        j--;
        for (; j > 0; --j) {
            matrix[j + y][i + x] = num++;
        }
    }
    void printMatrix(const vector<vector<int>>& matrix) {
        for (auto vec : matrix) {
            for (int i : vec) {
                printf("%d ", i);
            }
            printf("\n");
        }
    }
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret;
        for (int i = 0; i < n; i++) {
            ret.push_back(vector<int>(n));
        }
        int begin = 0;
        while (n > 0) {
            fillMatrix(begin, begin, n, ret);
            begin += 1;
            n -= 2;
        }
        return ret;
    }
    static int test() {
        Solution solution;
        auto matrix = solution.generateMatrix(10);
        solution.printMatrix(matrix);
        return 0;
    }
};