/*
 * =====================================================================================
 *
 *       Filename:  101.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月02日 09时29分18秒
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
#include <stack>
#include <cassert>

using namespace std;

typedef vector<int> blocks;
typedef vector<blocks> blocks_world;
typedef vector<int> blocks_tracer;

blocks_tracer s_location;
blocks_world s_blocks_world;
//define blocks_elt and pile_stack
void blocks_world_init(int n)
{
    s_blocks_world.clear();
    s_location.clear();
    for (int i = 0; i < n; i++)
    {
        blocks b;
        b.push_back(i);
        s_blocks_world.push_back(b);
        s_location.push_back(i);
    }
}
void blocks_elt_top_to_a(int a)
{
    int location = s_location[a];
    blocks& b = s_blocks_world[location];
    int t = b.back();
    while (t != a)
    {
        b.pop_back();
        s_blocks_world[t].push_back(t);
        s_location[t] = t;
    }
}
void blocks_stack_a_to_b(int a, int b)
{
    int location_a = s_location[a];
    int location_b = s_location[b];
    blocks& b_a = s_blocks_world[location_a];
    blocks& b_b = s_blocks_world[location_b];
    stack<int> s;
    int t = b_a.back(); 
    while (t != a)
    {
        s.push(t);
        b_a.pop_back();
        t = b_a.back();
    }
    s.push(t);
    b_a.pop_back();
    while (!s.empty())
    {
        t = s.top();
        s.pop();
        b_b.push_back(t);
        s_location[t] = location_b;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    int n;
    while (cin >> n)
    {
        blocks_world_init(n);
        while (true)
        {
            string cmd1, cmd2;
            int a, b;
            cin >> cmd1;
            if (cmd1 == "quit") break;
            cin >> a >> cmd2 >> b;
            if (a == b) continue;
            if (s_location[a] == s_location[b]) continue;
            if (cmd1 == "move")
            {
                blocks_elt_top_to_a(a);
                if (cmd2 == "onto")
                {
                    blocks_elt_top_to_a(b);
                }
                blocks_stack_a_to_b(a, b);
            }
            else
            {
                if (cmd2 == "onto")
                {
                    blocks_elt_top_to_a(b);
                }
                blocks_stack_a_to_b(a, b);
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << i << ":";
            int elts = s_blocks_world[i].size();
            for (int j = 0; j < elts; j++)
            {
                cout << " " << s_blocks_world[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
