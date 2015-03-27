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
#include <set>

using namespace std;

set<int> container;
set<int>::iterator it;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    int s, b;
    while (cin >> s >> b && (s || b))
    {
        container.clear();
        for (int i = 0; i <= s+1; i++)
        {
            container.insert(i);
        }
        while (b--)
        {
            int l, r;
            cin >> l >> r;
            it = container.find(l);
            it--;
            if (*it) cout << *it;
            else cout << "*";
            cout << " ";
            it = container.find(r);
            it++;
            if (*it != s+1) cout << *it;
            else cout << "*";
            cout << endl;
            for (int i = l; i <= r; i++)
            {
                if (container.find(i) != container.end()) container.erase(i);
            }
        }
        cout << "-" << endl;
    }
    return 0;
}
