//
//  String to Integer (atoi).cpp
//  LeetCode
//
//  Created by 赵超 on 8/30/16.
//  Copyright © 2016 赵超. All rights reserved.
//

// The trickiest number will be -2147483648 which in hex is -0x 80 00 00 00

#include <string>
#define MIN_INT         (1 << 31)
#define MAX_INT         (~ MIN_INT)
#define MAX_TO_MUL10    (MAX_INT / 10)


using namespace std;

class Solution {
private:

    bool sign = true;

    inline bool checkChar(char a) {
        return int(a) >= int('0') && int(a) <= int('9');
    }

    inline int charToInt(char a) {
        return int(a) - int('0');
    }

    inline int normalOut(int num) {
        return sign ? num : -num;
    }

    inline int overflowOut() {
        return sign ? MAX_INT : MIN_INT;
    }

    int myAtoiPositive(string str, int offset) {
        int ret = 0;
        for (string::iterator it = str.begin() + offset; it != str.end(); it++) {
            if (!checkChar(*it))
                return normalOut(ret);
            if (ret > MAX_TO_MUL10)
                return overflowOut();
            ret *= 10;
            ret += charToInt(*it);
            if (ret < 0)
                return overflowOut();
        }
        return normalOut(ret);
    }

    int myAtoiWrapper(string str, int offset) {
        if (checkChar(str[offset]))
            return myAtoiPositive(str, offset);
        if (str[offset] == '+')
            return myAtoiPositive(str, offset + 1);
        if (str[offset] == '-') {
            sign = false;
            return myAtoiPositive(str, offset + 1);
        } else
            return 0;
    }

public:

    int myAtoi(string str) {
        int offset = 0;
        while (str[offset] == ' ' || str[offset] == '\t')
            offset++;
        return myAtoiWrapper(str, offset);
    }

};
