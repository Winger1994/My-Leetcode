//
//  207 Course Schedule.cpp
//  LeetCode
//
//  Created by 赵超 on 9/19/16.
//  Copyright © 2016 赵超. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <list>
using namespace std;

class Solution {
private:
    void printReq(vector<list<int>> pre) {
        for (list<int> l : pre) {
            if (l.size() == 0)
                printf("NULL");
            for (int i : l) {
                printf("%d ", i);
            }
            printf("\n");
        }
    }
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<list<int>> pre(numCourses);
        vector<list<int>> isPreTo(numCourses);
        for (pair<int, int> req : prerequisites) {
            pre[req.second].push_back(req.first);
            isPreTo[req.first].push_back(req.second);
        }
        printReq(pre);
        printReq(isPreTo);
        vector<bool> finished(numCourses);
        for (auto it = finished.begin(); it != finished.end(); it++) {
            *it = false;
        }
        int finishedNum = 0;
        while (finishedNum < numCourses) {
            int i = 0;
            for (; i < numCourses; i++) {
                if (pre[i].size() == 0 && !finished[i]) {
                    printf("Learn course id = %d\n", i);
                    for (int j : isPreTo[i]) {
                        printf("Cancel %d isPreTo %d\n", i, j);
                        for (auto it = pre[j].begin(); it != pre[j].end(); it++) {
                            if (*it == i) {
                                pre[j].erase(it);
                                break;
                            }
                        }
                    }
                    printf("pre update to\n");
                    printReq(pre);
                    finished[i] = true;
                    finishedNum++;
                    break;
                }
            }
            if (i == numCourses)
                return false;
        }
        return true;
    }
};
