//
//  main.cpp
//  poj1028
//
//  Created by Vincent Shen on 14-3-10.
//  Copyright (c) 2014年 Vincent Shen. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(int argc, const char * argv[])
{

    // insert code here...
    stack<string> forwardStack;
    stack<string> backwardStack;
    string command;
    string currentPage = "http://www.acm.org/";
    while ( (cin >> command) && (command != "QUIT")) {
        if (command == "VISIT")
        {
            backwardStack.push(currentPage);
            cin >> currentPage;
            cout << currentPage << endl;
            while (!forwardStack.empty())
            {
                forwardStack.pop();
            }
        }
        else if (command == "BACK")
        {
            if (backwardStack.empty()) {
                cout << "Ignored" << endl;
            }
            else
            {
                forwardStack.push(currentPage);
                currentPage = backwardStack.top();
                backwardStack.pop();
                cout << currentPage << endl;
            }
            
        }
        else if (command == "FORWARD")
        {
            if (forwardStack.empty()) {
                cout << "Ignored" << endl;
            }
            else
            {
                backwardStack.push(currentPage);
                currentPage = forwardStack.top();
                forwardStack.pop();
                cout << currentPage << endl;
            }
        }
        else
        {
            break;
        }
    }
    
    return 0;
}

