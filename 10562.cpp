/*
 * =====================================================================================
 *
 *       Filename:  10562.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年10月04日 14时28分02秒
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

using namespace std;

const int max_n = 210;
char graph_array[max_n][max_n];

int cnt = 0;
void solve_init()
{
    cnt = 0;
    memset(graph_array, 0, sizeof(graph_array));
}

bool check_char(char c)
{
    return (isprint(c) && !isspace(c) && (c != '|') && (c != '#') && (c != '-'));
}
void dfs(int i, int j)
{
    printf("%c(", graph_array[i][j]);
    if ((i == cnt - 2) || graph_array[i+1][j] != '|')
    {
        printf(")");
        return;
    }
    int k = j;
    for (; k >= 0; k--)
    {
        if (graph_array[i+2][k]!= '-') break;
    }
    k++;
    while (graph_array[i+2][k] == '-')
    {
        if (check_char(graph_array[i+3][k]))
        {
            dfs(i+3, k);
        }
        k++;
    }
    printf(")");
}
void solve()
{
    printf("(");
    for (int j = 0; j < max_n; j++)
    {
        if (check_char(graph_array[0][j]))
        {
            dfs(0, j);
        }
    }
    printf(")");
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("10562.in", "r", stdin);
#endif
    int t;
    scanf("%d", &t);
    getchar();
    while (t--)
    {
        solve_init();
        int i = 0;
        while (1)
        {
            fgets(graph_array[i], max_n, stdin);
            cnt++;
            if (graph_array[i][0] == '#') break;
            i++;
        }
        solve();
        printf("\n");
    }
}
