//
//  240 Search a 2D Matrix II.cpp
//  LeetCode https://leetcode.com/problems/search-a-2d-matrix-ii/#/description
//
//  Created by 赵超 on 14/03/2017.
//  Copyright © 2017 赵超. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
private:
    typedef pair<int, int> P;
    template<class T>
    T index(const vector<vector<T>>& matrix, P p) {
        return matrix[p.first][p.second];
    }
    bool binarySearch(const vector<vector<int>>& matrix, int target, P begin, P end) {
        // printf("begin: (%d, %d), end: (%d, %d)\n", begin.first, begin.second, end.first, end.second);
        if (begin.first > end.first || begin.second > end.second)
            return false;
        if (begin == end)
            return index(matrix, begin) == target;
        int mid_x = (begin.first + end.first) / 2;
        int mid_y = (begin.second + end.second) / 2;
        if (matrix[mid_x][mid_y] == target)
            return true;
        else {
            if (matrix[mid_x][mid_y] > target) {
                return binarySearch(matrix, target, begin, P{mid_x - 1, end.second}) ||
                binarySearch(matrix, target, P{mid_x, begin.second}, P{end.first, mid_y - 1});
            } else {
                return binarySearch(matrix, target, P{begin.first, mid_y + 1}, P{mid_x, end.second}) ||
                binarySearch(matrix, target, P{mid_x + 1, begin.second}, end);
            }
        }
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int length = matrix.size();
        if (length == 0)
            return false;
        int width = matrix[0].size();
        if (width == 0)
            return false;
        return binarySearch(matrix, target, P{0,0}, P{length - 1, width - 1});
    }
    static void test() {
        Solution solution;
        vector<vector<int>> matrix({{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}});
        printf("%d\n", solution.searchMatrix(matrix, 1));
    }
};
