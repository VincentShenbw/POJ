//
//  main.cpp
//  poj1363
//
//  Created by Vincent Shen on 14-3-4.
//  Copyright (c) 2014年 Vincent Shen. All rights reserved.
//

#include<iostream>
#include<stack>

using namespace std;

int main(int argc, const char * argv[])
{
    int coachesN;
    int coachesPermutation[1000];
    stack<int> station;
    while ((cin >> coachesN) && (coachesN != 0))
    {
        while ((cin >> coachesPermutation[0]) && (coachesPermutation[0] != 0))
        {
            int i;
            for (i = 1; i != coachesN; i++)
            {
                cin >> coachesPermutation[i];
            }
            
            int j = 0;
            for (i = 0; i != coachesN; i++)
            {
                station.push(i + 1);
                while (!station.empty() && station.top() == coachesPermutation[j])
                {
                    station.pop();
                    j = j + 1;
                }
            }
            
            if (station.empty())
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
            while (!station.empty())
            {
                station.pop();
            }
        }
        cout << endl;
    }
}


