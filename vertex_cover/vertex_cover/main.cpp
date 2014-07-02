//
//  main.cpp
//  vertex_cover
//
//  Created by Vincent Shen on 14-4-14.
//  Copyright (c) 2014年 Vincent Shen. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

void MinimalVertexes(int **map, int *vertex, int &n, int &k);
int Max(int *vertex, int &n);

int const cover = 0;

int main(int argc, const char * argv[])
{
    int T, n, m, k;
    int **map;
    map = new int* [101];
    for (int i = 0; i < 101; i++) {
        map[i] = new int[101];
    }
    int vertex[101];
    
    cin >> T;
    
    while (T-- > 0) {
        
        cin >> n >> m >> k;
        for (int i = 0; i < n+1; i++) {
            memset(map[i], 0, sizeof(int) * (n+1));
        }
        memset(vertex, 0, sizeof(int) * (n+1));
        
        int x, y;
        for (int i = m; i != 0; i--) {
            cin >> x >> y;
            map[x][y] = 1;
            map[y][x] = 1;
            vertex[x] += 1;
            vertex[y] += 1;
        }
        
        MinimalVertexes(map, vertex, n, k);
        
    }
    
    
    return 0;
}

void MinimalVertexes(int **map, int *vertex, int &n, int &k)
{
    int resultArray[20];
    memset(resultArray, 0, sizeof(int) * 20);
    int count = 0;
    int max;
    
    while ((max = Max(vertex, n)) != cover) {
        for (int i = n; i != 0; i--)
        {
            if (map[max][i] != 0)
            {
                map[max][i] = 0;
                map[i][max] = 0;
                vertex[i]--;
            }
        }
            
        vertex[max] = 0;
        resultArray[count] = max;
        count++;
        if (count > k)
        {
            count = -1;
            break;
        }
    }
    cout << count << endl;
    if (count != -1) {
        for (int i = 0; i != count; i++) {
            if(i != 0)
            {
                cout << " ";
            }
            cout << resultArray[i];
        }
        cout << endl;
    }
}

int Max(int *vertex, int &n)
{
    int max = 0;
    int result = cover;
    for (int i = n; i != 0; i--)
    {
        if (vertex[i] > max)
        {
            max = vertex[i];
            result = i;
        }
    }
    return result;
}

