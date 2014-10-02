/*
 * =====================================================================================
 *
 *       Filename:  101.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年10月02日 16时21分34秒
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

const int max_n = 25;  //[1, 24]
static int block_index[max_n];
static int st[max_n][max_n];
static int top[max_n];

void top_stack_elm_to_a(int a)
{
    int stack_index = block_index[a];
    while (st[stack_index][top[stack_index]] != a)
    {
        int elm = st[stack_index][stack_index];
        st[elm][++top[elm]] = elm;
        block_index[elm] = elm;
    }
    return;
}
void stack_a_to_b(int a, int b)
{
    int index_a = block_index[a];
    int index_b = block_index[b];
    static int tmp_st[max_n];
    int tmp_top = 0;
    while (st[index_a][top[index_a]] != a)
    {
        tmp_st[++tmp_top] = st[index_a][top[index_a]--];
    }
    top[index_a]--;
    st[index_b][++top[index_b]] = a;
    block_index[a] = index_b;
    while (tmp_top)
    {
        st[index_b][++top[index_b]] = tmp_st[tmp_top];
        block_index[tmp_st[tmp_top]] = index_b;
        tmp_top--;
    }
    return;
}
int main()
{
#ifndef online_judge
    freopen("101.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        block_index[i] = i;
    for (int i = 0; i < n; i++) st[i][++top[i]] = i;

    char cmd[5];
    char action[5];
    int a, b;
    while (1)
    {
        scanf("%s", cmd);
        if (strcmp(cmd, "quit") == 0)
        {
            break;
        }
        scanf("%d %s %d", &a, action, &b);
        printf("%s %d %s %d\n", cmd, a, action, b);
        if (block_index[a] == block_index[b]) continue;
        if (a == b) continue;
        if (strcmp(cmd, "move") == 0)
        {
            top_stack_elm_to_a(a);
            if (strcmp(action, "onto") == 0)
            {
                top_stack_elm_to_a(b);
            }
            --top[block_index[a]];
            st[block_index[b]][++top[block_index[b]]] = a;
            block_index[a] = block_index[b];
        }
        else
        {
            if (strcmp(action, "onto") == 0)
            {
                top_stack_elm_to_a(b);
            }
            stack_a_to_b(a, b);
        }

    }
    for (int i = 0; i < n; i++)
    {
        printf("%d:", i);
        if (top[i] == 0)
        {
            printf("\n");
            continue;
        }
        for (int j = 1; j <= top[i]; j++)
        {
            printf(" %d", st[i][j]);
        }
        printf("\n");
    }
    return 0;
}
