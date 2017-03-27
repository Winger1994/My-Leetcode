//
//  76 Minimum Window Substring.cpp
//  LeetCode https://leetcode.com/problems/minimum-window-substring/#/description
//
//  Created by 赵超 on 19/03/2017.
//  Copyright © 2017 赵超. All rights reserved.
//

#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;


// didn't consider the duplicate chars in string t
class SolutionError {
private:
    template <class T>
    void printVec(vector<T> vec) {
        for (T i : vec) {
            cout << i << ' ';
        }
        printf("\n");
    }
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tmap;
        for (int i = 0; i < t.length(); ++i) {
            tmap[t[i]] = i;
        }
        vector<int> tflag(t.length(), -1);
        
        int tcount = 0;
        vector<int> indexes;
        for (int i = 0; i < s.length(); ++i) {
            if (tmap.count(s[i]) != 0) {
                indexes.push_back(i);
            }
        }
        printVec(indexes);
        
        vector<bool> ijump(indexes.size(), false);
        
        int minbegin = 0, minend = -1;
        int ibegin = 0;
        for (int ii = 0; ii < indexes.size(); ++ii) {
            printf("ii = %d\n", ii);
            printf("begin tflag: ");
            printVec(tflag);
            printf("begin count: %d\n", tcount);
            if (tflag[tmap[s[indexes[ii]]]] == -1) {
                tflag[tmap[s[indexes[ii]]]] = ii;
                ++tcount;
            } else {
                printf("new record: %c at ii=%d\n", s[indexes[ii]], indexes[ii]);
                if (s[indexes[ii]] == s[indexes[ibegin]]) {
                    printf("change head from %c at %d ", s[indexes[ibegin]], indexes[ibegin]);
                    while (ibegin < indexes.size() - 1 && ijump[++ibegin]);
                    printf("to %c at %d\n", s[indexes[ibegin]], indexes[ibegin]);
                } else {
                    ijump[tflag[tmap[s[indexes[ii]]]]] = true;
                }
                tflag[tmap[s[indexes[ii]]]] = ii;
                printf("ijump: ");
                printVec(ijump);
            }
            if (tcount == t.length()) {
                printf("Bingo! ibegin=%d, iend=%d\n", indexes[ibegin], indexes[ii]);
                if (minend == -1 || indexes[ii] - indexes[ibegin] < indexes[minend] - indexes[minbegin]) {
                    minbegin = ibegin;
                    minend = ii;
                }
                printf("remove head: %c\n", s[indexes[ibegin]]);
                tflag[tmap[s[indexes[ibegin]]]] = -1;
                while (ibegin < indexes.size() - 1 && ijump[++ibegin]);
                --tcount;
                printf("new ibegin=%d, new head=%c\n", indexes[ibegin], s[indexes[ibegin]]);
            }
            printf("end tflag: ");
            printVec(tflag);
            printf("end count: %d\n", tcount);
        }
        if (minend < 0)
            return "";
        return s.substr(indexes[minbegin], indexes[minend] - indexes[minbegin] + 1);
    }
};

class Solution {
private:
    struct Item {
        int total; //, queueSize;
        priority_queue<int, vector<int>, greater<int>> locations;
    };
    class Record: public unordered_map<char, Item> {
        int maxCount, counter;
    public:
        Record(): unordered_map<char, Item>(), counter(0), maxCount(0){};
        void add(char c) {
            if (count(c) == 0) {
                (*this)[c] = Item{1, priority_queue<int, vector<int>, greater<int>>()};
            } else {
                (*this)[c].total++;
            }
            maxCount++;
        }
        bool needNewChar(char c) {
            // printf("need? queue size: %lu,  total: %d\n", (*this)[c].locations.size(), (*this)[c].total);
            // return (*this)[c].locations.size() < (*this)[c].total;
            return (*this)[c].locations.size() < (*this)[c].total;
        }
        void addNewLocation(char c, int location) {
            counter++;
            // printf("counter plus: %d\n", counter);
            (*this)[c].locations.push(location);
        }
        void removeFirstLocation(char c) {
            counter--;
            // printf("remove %c at %d\n", c, (*this)[c].locations.top());
            // printf("counter minus: %d\n", counter);
            (*this)[c].locations.pop();
            // printf("queue size: %lu\n", (*this)[c].locations.size());
        }
        bool containsAll() {
            return counter == maxCount;
        }
    };
public:
    string minWindow(const string s, const string t) {
        Record record;
        for (char c : t) {
            record.add(c);
        }
        vector<int> indexes;
        for (int i = 0; i < s.length(); ++i) {
            if (record.count(s[i]) != 0) {
                indexes.push_back(i);
            }
        }
        vector<bool> ijump(indexes.size(), false);
        int minbegin = 0, minend = -1;
        int ibegin = 0;
        for (int ii = 0; ii < indexes.size(); ++ii) {
            // printf("index = %d, char: %c\n", indexes[ii], s[indexes[ii]]);
            if (record.needNewChar(s[indexes[ii]])) {
                record.addNewLocation(s[indexes[ii]], ii);
            } else {
                if (s[indexes[ii]] == s[indexes[ibegin]]) {
                    while (ijump[++ibegin]);
                } else {
                    ijump[record[s[indexes[ii]]].locations.top()] = true;
                }
                // record[s[indexes[ii]]].locations.pop();
                // record[s[indexes[ii]]].locations.push(ii);
                record.removeFirstLocation(s[indexes[ii]]);
                record.addNewLocation(s[indexes[ii]], ii);
            }
            if (record.containsAll()) {
                // printf("Bingo! ibegin: %d, iend: %d\n", indexes[ibegin], indexes[ii]);
                if (minend == -1 || indexes[ii] - indexes[ibegin] < indexes[minend] - indexes[minbegin]) {
                    minbegin = ibegin;
                    minend = ii;
                }
                record.removeFirstLocation(s[indexes[ibegin]]);
                while (ijump[++ibegin]);
                // printf("min begin: %d,  min end: %d, new ibegin: %d\n", indexes[minbegin], indexes[minend], indexes[ibegin]);
            }
        }
        if (minend < 0)
            return "";
        return s.substr(indexes[minbegin], indexes[minend] - indexes[minbegin] + 1);
    }
    static void priority_queue_test() {
        priority_queue<int, vector<int>, greater<int>> queue;
        for (int i : {6,5,4,3,2,1}) {
            queue.push(i);
        }
        while (queue.size()) {
            printf("size: %lu ", queue.size());
            printf("%d ", queue.top());
            queue.pop();
        }
        printf("\n");
    }
    static void test() {
        Solution solution;
        // printf("%s\n", solution.minWindow("A", "A").c_str());
        // printf("%s\n", solution.minWindow("CBADOBECODEBANC", "ABC").c_str());
        // printf("%s\n", solution.minWindow("aaflslflsldkalskaaa", "aaa").c_str());
        // printf("%s\n", solution.minWindow("bacbacaaabc", "baa").c_str());
        printf("%s\n", solution.minWindow("abccaaccaccabacb", "aaacacab").c_str());
        // priority_queue_test();
    }
};
