//
//  main.cpp
//  Delete_Number
//
//  Created by Vincent Shen on 14-6-26.
//  Copyright (c) 2014年 Vincent Shen. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, const char * argv[])
{
    int T, k, i, len, pre, cur, begin;
    string num;
    char digits[100002];
    cin >> T;
    while (T--) {
        cin >> num;
        cin >> k;
        begin = 0;
        pre = 0;
        cur = 1;
        len = num.length();
        memset(digits, 0, len);
        while (cur < len) {
            if (num.at(pre) < num.at(cur))
            {
                digits[pre] = 1;
                k--;
                if (begin < pre)
                {
                    pre = pre - 1;
                    while (digits[pre]) {
                        pre--;
                    }
                }
                else
                {
                    begin = cur;
                    pre = cur;
                    cur++;
                }
            }
            else {
                pre = cur;
                cur++;
            }
            if (k==0)
            {
                break;
            }
        }
        if (k>0)
        {
            for (i = len-1; i>=0 && k>0; i--) {
                if (!digits[i]) {
                    digits[i] = 1;
                    k--;
                }
            }
        }
        for (i = 0; i < len; i++) {
            if (!digits[i])
                cout << num[i];
        }
        cout << endl;
    }
    return 0;
}

