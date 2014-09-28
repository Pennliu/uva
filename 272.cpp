/*
 * =====================================================================================
 *
 *       Filename:  272.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月28日 21时55分23秒
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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("272.in", "r", stdin);
#endif
    int c;
    bool f(true);
    while ((c = getc(stdin)) != EOF)
    {
        if (c == '\"')
        {
            printf("%s", f ? "``" : "\'\'");
            f = !f;
        }
        else printf("%c", c);
    }
    return 0;
}
