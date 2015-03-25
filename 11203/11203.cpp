/*
 * =====================================================================================
 *
 *       Filename:  11203.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年03月23日 22时14分04秒
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

bool check(string s)
{
    int a, b, c, i;
    a = b = c = i = 0;
    while (s[i] == '?') a++, i++;
    if (s[i] != 'M') return false;
    i++;
    while (s[i] == '?') b++, i++;
    if (s[i] != 'E') return false;
    i++;
    while (s[i] == '?') c++, i++;
    if (s[i] != 0) return false;
    return (a && b && c && (a == (c - (b - 1) - 1)));
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    int n;
    cin >> n;

    while (n--)
    {
        string s;
        cin >> s;
        if (check(s)) cout << "theorem";
        else cout << "no-theorem";
        cout << endl;
    }
    return 0;
}
