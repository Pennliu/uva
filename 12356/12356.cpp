/*
 * =====================================================================================
 *
 *       Filename:  12356.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年03月27日 21时18分49秒
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

int left1[100005], right2[100005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    int s, b;
    int l, r;
    while (scanf("%d %d", &s, &b) && (s || b))
    {
        for (int i = 1; i <= s; i++)
        {
            left1[i] = i - 1;
            right2[i] = i + 1;
        }
        left1[1] = -1;
        right2[s] = -1;
        while (b--)
        {
            scanf("%d %d", &l, &r);
            left1[right2[r]] = left1[l];
            right2[left1[l]] = right2[r];
            if (left1[l] != -1) printf("%d ", left1[l]);
            else printf("* ");
            if (right2[r] != -1) printf("%d\n", right2[r]);
            else printf("*\n");
        }
        printf("-\n");
    }
    return 0;
}
