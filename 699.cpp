/*
 * =====================================================================================
 *
 *       Filename:  699.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年10月03日 21时28分41秒
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
#include <cassert>
using namespace std;

struct node
{
    int v;
    struct node *l, *r;
};

node* node_new()
{
    node* n = (node* )malloc(sizeof(node));
    if (n)
    {
        n->l = n->r = NULL;
        n->v = 0;
    }
    return n;
}

void tree_free(node* tree)
{
    if (tree)
    {
        tree_free(tree->l);
        tree_free(tree->r);
        free(tree);
    }
    return;
}

node* tree_build()
{
    int v;
    scanf("%d", &v);
    if (v == -1) return NULL;
    node* t = node_new();
    assert(t);
    t->v = v;
    t->l = tree_build();
    t->r = tree_build();
    return t;
}

static int ans[200];
static int mid;
void dfs(node* t, int mid)
{
    if (t)
    {
        ans[mid] += t->v;
        dfs(t->l, mid - 1);
        dfs(t->r, mid + 1);
    }
    return ;
}


void solve_init()
{
    mid = 100;
    memset(ans, 0, sizeof(ans));
}

void solve_ans()
{
    bool first = true;
    for (int i = 0; i < 200; i++)
    {
        if (ans[i])
        {
            if (first)
            {
                first = false;
                printf("%d", ans[i]);
            }
            else
            {
                printf(" %d", ans[i]);
            }
        }
    }
    printf("\n\n");
    return;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("699.in", "r", stdin);
#endif
    int test_case = 0;
    while (1)
    {
#if 0
        int c = getchar();
        while (!isdigit(c)) c = getchar();
        if (c - '0' == -1) break;
        else ungetc(stdin);
#endif
        solve_init();
        node* tree = tree_build();
        if (!tree) break;
        dfs(tree, 100);
        test_case++;
        printf("Case %d:\n", test_case);
        solve_ans();
        tree_free(tree);
    }
    return 0;
}
