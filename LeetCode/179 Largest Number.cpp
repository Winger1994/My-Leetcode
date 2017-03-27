//
//  179 Largest Number.cpp
//  LeetCode https://leetcode.com/problems/largest-number/#/description
//
//  Created by 赵超 on 13/03/2017.
//  Copyright © 2017 赵超. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    string num2string(int num) {
        char s[10];
        sprintf(s, "%d", num);
        return string(s);
    }
    bool greater(const string& a, const string& b) {
        int i = 0;
        while (1) {
            if (a[i] == b[i]) {
                ++i;
                if (i == a.size()) {
                    if (i == b.size())
                        return false;
                    return greater(a, b.substr(i));
                }
                if (i == b.size()) {
                    return greater(a.substr(i), b);
                }
            } else {
                return a[i] > b[i];
            }
        }
    }
    void qsort(vector<string>& arr, int begin, int end) {
        if (begin >= end)
            return;
        string key = arr[begin];
        int l = begin, r = end;
        printf("begin=%d, end=%d, key=%s\n", begin, end, key.c_str());
        while (l < r) {
            while (greater(arr[l], key) && l < end)
                ++l;
            while (!greater(arr[r], key) && r > begin)
                --r;
            printf("l=%d, r=%d\n", l, r);
            if (l <= r) {
                string tmp = arr[l];
                arr[l++] = arr[r];
                arr[r--] = tmp;
            }
        }
        qsort(arr, begin, r);
        qsort(arr, l, end);
    }
public:
    // All zero situation!
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for (int i : nums) {
            arr.push_back(num2string(i));
        }
        qsort(arr, 0, arr.size() - 1);
        if (arr[0] == "0")
            return "0";
        string res;
        for (string s : arr) {
            res += s;
        }
        return res;
    }
    static void test() {
        Solution solution;
        vector<int> nums{2, 1, 3, 4, 5};
        printf("%d\n", solution.greater("3", "30"));
        printf("%s\n", solution.largestNumber(nums).c_str());
    }
};
