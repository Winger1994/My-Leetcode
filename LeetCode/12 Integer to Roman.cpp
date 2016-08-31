//
//  12 Integer to Roman.cpp
//  LeetCode
//
//  Created by 赵超 on 8/31/16.
//  Copyright © 2016 赵超. All rights reserved.
//

#include <stdio.h>
#include <string>
using namespace std;

class Solution {
private:
    string oneNumToRoman(int num, const char one, const char five, const char ten) {
        string ret;
        if (num >= 0 && num <= 3) {
            for (int i = 0; i < num; i++) {
                ret.push_back(one);
            }
            return ret;
        }
        if (num == 4)
            return string({one, five});
        if (num >= 5 && num <= 8) {
            ret.push_back(five);
            ret.append(oneNumToRoman(num - 5, one, five, ten));
            return ret;
        }
        if (num == 9)
            return string({one, ten});
        return "ERROR";
    }
public:
    string intToRoman(int num) {
        if (num > 3999)
            return "ERROR";
        string ret;
        ret.append(oneNumToRoman(num / 1000, 'M', 'E', 'E'));
        ret.append(oneNumToRoman((num % 1000) / 100, 'C', 'D', 'M'));
        ret.append(oneNumToRoman((num % 100) / 10, 'X', 'L', 'C'));
        ret.append(oneNumToRoman(num % 10, 'I', 'V', 'X'));
        return ret;
    }
};