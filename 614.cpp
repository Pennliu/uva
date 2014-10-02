/*
 * =====================================================================================
 *
 *       Filename:  614.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年10月02日 20时20分52秒
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
    freopen("614.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    string tmp;
    getline(cin, tmp);
    while (n--)
    {
        char s[129];
        int top = -1;
        bool flag(true);
        string buf;
        std::getline(cin, buf);
        for (int i = 0; i < buf.size(); i++)
        {
            if (buf[i] == '(' || buf[i] == '[') s[++top] = buf[i];
            else if (buf[i] == ')')
            {
                if (top >= 0 && s[top] == '(') top--;
                else 
                {
                    flag = false;
                    break;
                }
            }
            else if (buf[i] == ']')
            {
                if (top >= 0 && s[top] == '[') top--;
                else
                {
                    flag = false;
                    break;
                }
            }
        }
        if (top >= 0) flag = false;
        if (flag) printf("Yes");
        else printf("No");
        printf("\n");
    }
    return 0;
}
