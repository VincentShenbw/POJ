//
//  main.cpp
//  vertex_cover_tpp
//
//  Created by Vincent Shen on 14-5-3.
//  Copyright (c) 2014年 Vincent Shen. All rights reserved.
//

/*
 思路，先求二分图最大匹配，再按照出度从大到小取点，去掉之后删边，知道覆盖所有边
 */
#include <stdio.h>
#include <string.h>
#include <algorithm>
int n1,n2,m,k,ans;
int result[101]; //记录V2中的点匹配的点的编号
bool state [101]; //记录V2中的每个点是否被搜索过
bool data[101][101];//邻接矩阵 true代表有边相连
using namespace std;

typedef struct Point
{
	int id;
	int degree;
} Point;

Point vetex[101];

bool cmp(Point a, Point b)
{
	return a.degree > b.degree;
}

void init() {
    int n, t1, t2;
    for (int i = 0; i <= 100; i++)
	{
		result[i] = 0;
		state[i] = false;
		vetex[i].id = i + 1;
		vetex[i].degree = 0;
	}
	scanf("%d %d %d", &n, &m, &k);
	n1 = n2 = n;
    ans = 0;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d",&t1,&t2);
        data[t1][t2] = true;
		data[t2][t1] = true;
		vetex[t1].degree++;
		vetex[t2].degree++;
    }
    return;
}
bool find(int a) {
    for (int i = 1; i <= n2; i++) {
        if (data[a][i] == 1 && !state[i]) { //如果节点i与a相邻并且未被查找过
            state[i] = true; //标记i为已查找过
            if (result[i] == 0 //如果i未在前一个匹配M中
                || find(result[i])) { //i在匹配M中，但是从与i相邻的节点出发可以有增广路
                result[i] = a; //记录查找成功记录
                return true; //返回查找成功
            }
        }
    }
    return false;
}
int main() {
	int c;
	scanf("%d", &c);
	while (c--)
	{
		init();
		for (int i = 1; i <= n1; i++) {
			memset(state,0,sizeof(state)); //清空上次搜索时的标记
			if (find(i)) ans++; //从节点i尝试扩展
		}
        
		int flag[101], point[101], t;
		memset(flag, 0, sizeof(flag));
		t = 0;
		for (int i = 1; i <= ans; i++)
		{
			int max_degree = -1, max_point;
			for (int j = 1; j <= n2; j++)
			{
				if (result[j] > 0 && !flag[j])
				{
					if (vetex[j].degree > max_degree)
					{
						max_degree = vetex[j].degree;
						max_point = j;
					}
				}
			}
			if (max_degree == 0) break;
			point[t++] = max_point;
			flag[max_point] = 1;
			for (int j = 1; j <= n2; j++)
			{
				if (data[max_point][j])
				{
					vetex[j].degree--;
				}
			}
		}
        bool format = false;
		if (t <= k)
		{
			printf("%d\n", t);
			for (int i = 1; i <= n2; i++)
			{
				if (flag[i] != 0)
                {
                    if(!format){
                        printf("%d", i);
                        format = true;
                    }
                    else{
                        printf(" %d", i);
                    }
                }
			}
			printf("\n");
		}
		else
		{
			printf("-1\n");
		}
	}
    return 0;
    
}

