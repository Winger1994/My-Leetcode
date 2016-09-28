//
//  295 Find Median from Data Stream.cpp
//  LeetCode
//
//  Created by 赵超 on 28/09/2016.
//  Copyright © 2016 赵超. All rights reserved.
//

#include <stdio.h>
#include <list>
using namespace std;

template <class T>
class Heap {
private:
    int CAPACITY;
    int size;
    T* content;
    void doubleCap() {
        CAPACITY *= 2;
        T* newContent = new T[CAPACITY];
        for (int i = 0; i < size; ++i) {
            newContent[i] = content[i];
        }
        delete[] content;
        content = newContent;
    }
    void topDown(int n) {
        int child = n * 2 + 1;
        if (child >= size)
            return;
        if (child + 1 < size && content[child + 1] > content[child]) {
            ++child;
        }
        if (content[child] > content[n]) {
            swap(content[n], content[child]);
            topDown(child);
        }
    }
    void bottomUp(int n) {
        if (n == 0)
            return;
        int parent = (n - 1) / 2;
        if (content[n] > content[parent]) {
            swap(content[n], content[parent]);
            bottomUp(parent);
        }
    }
public:
    Heap(int c = 100): size(0), CAPACITY(c) {
        content = new T[CAPACITY];
    }
    void add(T ele) {
        if (size == CAPACITY)
            doubleCap();
        content[size++] = ele;
        bottomUp(size);
    }
    T pop() {
        T topEle = content[0];
        content[0] = content[--size];
        topDown(0);
        return topEle;
    }
    T top() {
        return content[0];
    }
};

class MedianFinder {
private:
    list<int> nums;
    bool even = true;
    list<int>::iterator result = nums.begin();
    void printList(list<int> l) {
        printf("Head");
        for (int i : l) {
            printf("->%d", i);
        }
        printf("\n");
    }
    void printIter(list<int>::iterator it) {
        if (it == nums.begin()) {
            printf("begin\n");
            return;
        }
        printf("%d\n", *it);
    }
public:
    // Adds a number into the data structure.
    void addNum(int num) {
        printf("before add %d:\n", num);
        printList(nums);
        printf("result: ");
        printIter(result);
        bool pass = false;
        auto it = nums.begin();
        while (it != nums.end() && *it < num) {
            if (it == result)
                pass = true;
            ++it;
        }
        nums.insert(it, num);
        if (pass) {
            if (even) {
                even = false;
                ++result;
            } else {
                even = true;
            }
        } else {
            if (even) {
                even = false;
            } else {
                even = true;
                --result;
            }
        }
    }
    // Returns the median of current data stream
    double findMedian() {
        if (even) {
            return (*(++result) + *(--result)) / 2.0;
        } else {
            return *result;
        }
    }
};

class Solution {
public:
    static void test() {
        MedianFinder mf;
        mf.addNum(0);
        mf.addNum(0);
        printf("%lf\n", mf.findMedian());
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
