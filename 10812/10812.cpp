/*
 * =====================================================================================
 *
 *       Filename:  10812.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年03月26日 22时41分22秒
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
    freopen("in", "r", stdin);
#endif
    int n;
    cin >> n;
    while (n--)
    {
        int s, d;
        cin >> s >> d;
        int x, y;
        bool found = true;
        if ((s + d) % 2) found = false;
        else{x = (s + d) / 2; y = s - x;}
        if (found && y >= 0) cout << x << " " << y << endl;
        else cout << "impossible" << endl;
    }
}
