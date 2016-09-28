//
//  62 Unique Paths.cpp
//  LeetCode
//
//  Created by 赵超 on 9/19/16.
//  Copyright © 2016 赵超. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> matrix(m);
        for (int i = 0; i < m; i++) {
            matrix[i] = vector<int>(n);
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (j == n - 1) {
                    matrix[i][j] = 1;
                    continue;
                }
                if (i == m - 1) {
                    matrix[i][j] = 1;
                    continue;
                }
                matrix[i][j] = matrix[i + 1][j] + matrix[i][j + 1];
            }
        }
        return matrix[0][0];
    }
};
