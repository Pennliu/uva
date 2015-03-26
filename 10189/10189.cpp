/*
 * =====================================================================================
 *
 *       Filename:  10189.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年03月26日 23时21分53秒
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

string a[103];
int b[103][103];
int dir[8][2] = {{-1, -1},{-1, 0}, {-1, 1},
                {0, -1}, {0, 1},
                {1, -1}, {1, 0}, {1, 1}};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    int cnt = 0;
    int n, m;
    while (cin >> n >> m && n && m)
    {
     	if (cnt) cout <<endl;   
        cnt++;
        for (int i = 0; i < n; i++) cin >> a[i];
        memset(b, 0, sizeof(b));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == '*')
                {
                    for (int k = 0; k < 8; k++)
                    {
                        int x, y;
                        x = dir[k][0]+i;
                        y = dir[k][1]+j;
                        if (x >= 0 && x < n && y >=0 && y < m) b[x][y]++;
                    }
                }
            }
        }
        cout << "Field #" << cnt << ":" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == '*') cout << '*';
                else cout << b[i][j];
            }
            cout << endl;
        }
        //cout << endl;
    }
    return 0;
}
