/*
 * =====================================================================================
 *
 *       Filename:  10252.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年03月22日 19时20分55秒
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
#include <algorithm>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    char a[1005], b[1005];
    while (gets(a) && gets(b))
    {
        sort(a, a+strlen(a));
        sort(b, b+strlen(b));
        for (int i = 0, j = 0; i < strlen(a) && j < strlen(b);)
        {
            if (a[i] == b[j])
            {
                printf("%c", a[i]);
                i++;
                j++;
            }
            else if (a[i] < b[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        printf("\n");
    }
    return 0;
}
