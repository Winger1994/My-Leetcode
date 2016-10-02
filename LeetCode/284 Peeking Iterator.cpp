//
//  284 Peeking Iterator.cpp
//  LeetCode
//
//  Created by 赵超 on 29/09/2016.
//  Copyright © 2016 赵超. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
private:
    bool stillNext = true;
    int cache;
    Iterator *baseThis;
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        baseThis = (Iterator*) this;
        cache = baseThis->next();
    }
    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        return cache;
    }
    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        if (!stillNext) {
            return baseThis->next();
        }
        int oldCache = cache;
        if (baseThis->hasNext()) {
            cache = baseThis->next();
        } else {
            stillNext = false;
        }
        return oldCache;
    }
    bool hasNext() const {
        return stillNext;
    }
};
