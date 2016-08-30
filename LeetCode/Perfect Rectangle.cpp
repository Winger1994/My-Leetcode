//
//  Perfect Rectagle.cpp
//  LeetCode
//
//  Created by 赵超 on 8/29/16.
//  Copyright © 2016 赵超. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>>::iterator left, bottom, right, up;
    
    int rectangleSize(vector<vector<int>>::iterator recit) {
        int width = (*recit)[2] - (*recit)[0];
        int height = (*recit)[3] - (*recit)[1];
        return width * height;
    }
    
    bool checkCorner(vector<vector<int>>& rectangles) {
        left = bottom = right = up = rectangles.begin();
        for(vector<vector<int>>::iterator it = rectangles.begin() + 1; it!=rectangles.end(); it++) {
            if ((*it)[0] < (*left)[0])
                left = it;
            else
                if ((*it)[0] == (*left)[0] && (*it)[1] < (*left)[1])
                    left = it;
            
            if ((*it)[1] < (*bottom)[1])
                bottom = it;
            else
                if ((*it)[1] == (*bottom)[1] && (*it)[0] < (*bottom)[0])
                    bottom = it;
            
            if ((*it)[2] > (*right)[2])
                right = it;
            else
                if ((*it)[2] == (*right)[2] && (*it)[3] > (*right)[3])
                    right = it;
            
            if ((*it)[3] > (*up)[3])
                up = it;
            else
                if ((*it)[3] == (*up)[3] && (*it)[2] > (*up)[2])
                    up = it;
        }
        return (left == bottom && right == up);
    }
    
    bool checkSize(vector<vector<int>>& rectangles) {
        int theorySize = ((*up)[2] - (*bottom)[0]) * ((*up)[3] - (*bottom)[1]);
        int recSizeSum = 0;
        for(vector<vector<int>>::iterator it = rectangles.begin()++; it!=rectangles.end(); it++) {
            recSizeSum += rectangleSize(it);
        }
        cout << "sum: " << recSizeSum << "\t theory: " << theorySize << endl;
        return recSizeSum == theorySize;
    }
    
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        if (!checkCorner(rectangles))
            return false;
        cout << "HI" << endl;
        return checkSize(rectangles);
    }
};
