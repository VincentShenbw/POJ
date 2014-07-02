//
//  main.cpp
//  vertex_cover_test
//
//  Created by Vincent Shen on 14-4-14.
//  Copyright (c) 2014年 Vincent Shen. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

int N, K;
char G[101][101], g_visit[101];
int g_match[101];
int g_vertex[101];

int ExtendPath(int u);
int MinimalVertexes();
void GetVertexes(int count);

int main() {
    int T, m, x, y, count;
    
    cin >> T;
    while (T--) {
        cin >> N >> m >> K;
        memset(g_match, 0, sizeof(int) * (N+1));
        memset(g_vertex, 0, sizeof(int) * (N+1));
        
        for (int i = 1; i < N+1; i++) {
            memset(G[i], 0, N+1);
        }
        
        for (int i = 0; i != m; i++) {
            cin >> x >> y;
            G[x][y] = 1;
            G[y][x] = 1;
            g_vertex[x] += 1;
            g_vertex[y] += 1;
        }
        count = MinimalVertexes()/2;
        cout << count << endl;
        if(count != -1)
            GetVertexes(count);
    }
    return 0;
}

int MinimalVertexes() {
    int count = 0;
    for (int i = 1; i <= N; ++i) {
        memset(g_visit, 0, N+1);
        count += ExtendPath(i);
        if (count > 2*K) {
            count = -2;
            break;
        }
    }
    return count;
}

int ExtendPath(int u) {
    for (int i = 1; i <= N; ++i) {
        if (!G[u][i] || g_visit[i]) continue;
        g_visit[i] = 1;
        if (!g_match[i] || ExtendPath(g_match[i])) {
            g_match[i] = u;
            return 1;
        }
    }
    return 0;
}

void GetVertexes(int count)
{
    int resultArray[N+1];
    memset(resultArray, 0, sizeof(int) * (N+1));
    for (int i = 1; i <= N; i++) {
        if(g_match[i])
        {
            if (g_vertex[g_match[i]] > g_vertex[i]) {
                if (resultArray[g_match[i]] != 1) {
                    count--;
                    resultArray[g_match[i]] = 1;
                }
            }
            else
            {
                if (resultArray[i] != 1) {
                    count--;
                    resultArray[i] = 1;
                }
            }
        }
        if(!count)
            break;
    }
    for(int i = 1; i <= N; i++)
    {
        if(resultArray[i] != 0)
        {
            if (!count) {
                cout << i;
                count++;
            }
            else
                cout << " " << i;
        }
    }
    cout << endl;
}

