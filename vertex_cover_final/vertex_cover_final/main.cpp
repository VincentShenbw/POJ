//
//  main.cpp
//  vertex_cover_final
//
//  Created by Vincent Shen on 14-5-7.
//  Copyright (c) 2014年 Vincent Shen. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

bool removable(vector<int> &neighbor, vector<int> &cover);
int max_removable(vector<vector<int> > &neighbors, vector<int> &cover);
void vertex_cover(vector<vector<int> > &neighbors, vector<int> &cover);
int vertex_cover_size(vector<int> &cover);

int main()
{
    int T, n, m, i, j, k, s, x, y;
    char graph[101][101];
    
    cin >> T;
    while (T--){
        cin >> n >> m >> k;
    
        for (i = 0; i < n+1; i++)
        {
            memset(graph[i], 0, n+1);
        }
    
        for (i = 0; i < m; i++)
        {
            cin >> x >> y;
            graph[x-1][y-1] = 1;
            graph[y-1][x-1] = 1;
        }
    
        vector<vector<int> > neighbors;
        for (i = 0; i < n; i++)
        {
            vector<int> neighbor;
            for (j = 0; j < n; j++)
            {
                if (graph[i][j] == 1)
                {
                    neighbor.push_back(j);
                }
            }
            neighbors.push_back(neighbor);
        }
        
        bool found = false;
        vector<int> allcover;
        allcover.assign(n, 1);
        for (i = 0; i < allcover.size(); i++)
        {
            if (found)
                break;
            vector<int> cover = allcover;
            cover[i]=0;
            vertex_cover(neighbors,cover);
            s = vertex_cover_size(cover);
            if (s <= k)
            {
                cout << s << endl;
                for (j = 0; j < cover.size(); j++)
                {
                    if (cover[j] == 1)
                    {
                        cout << j+1 << " ";
                    }
                }
                cout << endl;
                found = true;
                break;
            }
        }
        if (!found)
            cout << "-1" << endl;
    }
    return 0;
}

bool removable(vector<int> &neighbor, vector<int> &cover)
{
    bool check = true;
    for (int i = 0; i < neighbor.size(); i++)
        if (cover[neighbor[i]] == 0)
        {
            check = false;
            break;
        }
    return check;
}

int max_removable(vector<vector<int> > &neighbors, vector<int> &cover)
{
    int r = -1, max = -1;
    for (int i=0; i<cover.size(); i++)
    {
        if (cover[i]==1 && removable(neighbors[i],cover)==true)
        {
            vector<int> temp_cover = cover;
            temp_cover[i] = 0;
            int sum = 0;
            for (int j = 0; j < temp_cover.size(); j++)
                if (temp_cover[j]==1 && removable(neighbors[j], temp_cover)==true)
                    sum++;
            if (sum > max)
            {
                max = sum;
                r = i;
            }
        }
    }
    return r;
}

void vertex_cover(vector<vector<int> > &neighbors, vector<int> &cover)
{
    int r = 0;
    while (r != -1)
    {
        r = max_removable(neighbors,cover);
        if (r != -1)
            cover[r] = 0;
    }
}

int vertex_cover_size(vector<int> &cover)
{
    int count = 0;
    for( int i = 0; i < cover.size(); i++)
        if (cover[i] == 1)
            count++;
    return count;
    
}

