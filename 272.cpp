/*
 * =====================================================================================
 *
 *       Filename:  272.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月26日 22时48分20秒
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
    string s;
    bool start = true;
    char buf[2000];
    int j = 0;
    int c;
    while ((c = getc(stdin)) != EOF)
    {
        {
            if (c == '\"' && start)
            {
                buf[j++] = '`';
                buf[j++] = '`';
                start = !start;
            }
            else if (c == '\"')
            {
                buf[j++] = '\'';    
                buf[j++] = '\'';    
                start = !start;
            }
            else
            {
                buf[j++] = c;
            }
        }
    }
    buf[j] = 0;
    printf("%s", buf);
    return 0;
}
