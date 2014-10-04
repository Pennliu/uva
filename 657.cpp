/*
 * =====================================================================================
 *
 *       Filename:  657.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年10月04日 21时39分00秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  loop (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm> //sort
using namespace std;

const int max_n = 60;
static char pic[max_n][max_n];
static bool visit[max_n][max_n];
int w, h;
int num[max_n*max_n];
int cnt;    //region counter
int numbers;
static void input()
{
    for (int i = 1; i <= h; i++)
    {
        fgets(pic[i] + 1, max_n-1, stdin);
    }
}
static void init()
{
    memset(visit, 0, sizeof(visit));
    //memset(pic, 0, sizeof(pic));
    cnt = 0;
}
struct InDex
{
    int x, y;
};
static InDex direct[4] = {
    {0, 1},{0, -1},{1, 0},{-1, 0}
};
static void bfs(int i, int j)
{
    queue<InDex> q;
    InDex node;
    node.x = i, node.y = j;
    pic[i][j] = '*';
    q.push(node);

    while (!q.empty())
    {
        InDex n = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int x = n.x + direct[k].x;
            int y = n.y + direct[k].y;
            if (pic[x][y] == 'X') 
            {
                InDex xx;
                xx.x = x;
                xx.y = y;
                pic[x][y] = '*';
            }
        }
    }
}
static void dfs(int i, int j)
{
    if (pic[i][j] == 'X') 
    {
        numbers++;
        bfs(i, j);
    }
    visit[i][j] = true;
    for (int k = 0; k < 4; k++)
    {
        int x = i + direct[k].x;
        int y = j + direct[k].y;
        if (!visit[x][y] && (pic[x][y] == 'X' || pic[x][y] == '*'))
        {
            dfs(x, y);
        }
    }
    return;
}
static void solve()
{
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <=w; j++)
        {
            if (!visit[i][j] && (pic[i][j] == '*' || pic[i][j] == 'X'))
            {
                numbers = 0;
                dfs(i, j);
                num[cnt++] = numbers;
            }
        }
    }
    sort(num, num + cnt);
}
static int print_cnt;
static void output()
{
    print_cnt++;
    printf("Throw %d\n", print_cnt);
    bool first(true);
    for (int i = 0; i < cnt; i++)
    {
        if (first)
        {
            first = false;
            printf("%d", num[i]);
        }
        else printf(" %d", num[i]);
    }
    printf("\n\n");
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("657.in", "r", stdin);
#endif
    while (scanf("%d%d", &w, &h))
    {
        if (!w && !h) break;
        getchar();
        init();
        input();
        solve();
        output();
    }
    return 0;
}
