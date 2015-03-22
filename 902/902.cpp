/*
 * =====================================================================================
 *
 *       Filename:  902.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年03月22日 21时39分40秒
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
#include <map>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    string str;
    int n;
    while (cin >> n >> str)
    {
        int len = str.length();
        string substr;
        map<string, int> container;
        for (int i = 0; i < len - n + 1; i++)
        {
            substr.assign(str, i, n);
            container[substr]++;
        }
        int max_cnt = 0;
        string s;
        for (map<string, int>::iterator it = container.begin(); it != container.end(); it++)
        {
            if (it->second > max_cnt)
            {
                max_cnt = it->second;
                s = it->first;
            }
        }
        cout << s << endl;
    }
    return 0;
}
