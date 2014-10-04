/*
 * =====================================================================================
 *
 *       Filename:  839.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年10月04日 11时41分54秒
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

bool flag;
int tree_build()
{
    int w1, d1, w2, d2;
    scanf("%d%d%d%d", &w1, &d1, &w2, &d2);
    if (!w1) w1 = tree_build();
    if (!w2) w2 = tree_build();
    if (w1*d1 != w2*d2) flag = false;
    return w1 + w2;
}

int main()
{
#ifndef online_judge
    freopen("839.in", "r", stdin);
#endif
    int test_case;
    bool first(true);
    scanf("%d", &test_case);
    while (test_case--)
    {
        if (first){first = false;}
        else printf("\n");
        flag = true;
        tree_build();
        if (flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
