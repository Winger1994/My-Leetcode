//
//  383 Ransom Note.cpp
//  LeetCode
//
//  Created by 赵超 on 9/5/16.
//  Copyright © 2016 赵超. All rights reserved.
//

#include <cstdio>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    inline int index(const char c) {
        return c - 'a';
    }
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> map(26, 0);
        for (auto it = magazine.begin(); it != magazine.end(); it++) {
            map[index(*it)]++;
        }
        for (auto it = ransomNote.begin(); it != ransomNote.end(); it++) {
            if (map[index(*it)] == 0)
                return false;
            map[index(*it)]--;
        }
        return true;
    }
};