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
    while (std::getline(cin, s))
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '\"' && start)
            {
                buf[j++] = '`';
                buf[j++] = '`';
                start = !start;
            }
            else if (s[i] == '\"')
            {
                buf[j++] = '\'';    
                buf[j++] = '\'';    
                start = !start;
            }
            else
            {
                buf[j++] = s[i];
            }
        }
        buf[j++] = '\n';
    }
    printf("%s", buf);
    return 0;
}
