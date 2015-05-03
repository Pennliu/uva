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
const int maxn = 30;
class blocks
{
public:
    int m_s[maxn];
    int m_top;
public:
    blocks(int top = -1):m_top(top)
    {
        memset(m_s, 0, sizeof(m_s));
    }
    void push(int a)
    {
        assert(m_top < maxn);
        m_s[++m_top] = a;
    }
    void pop(void)
    {
        assert(m_top != -1);
        m_top--;
        return;
    }
    int top()
    {
        assert(m_top != -1);
        return m_s[m_top];
    }
    int size()
    {
        return m_top + 1;
    }
};

class blocks_world
{
private:
    blocks bs[maxn];
public:
    blocks_world()
    {
        for (int i = 0; i < maxn; i++)
        {
            bs[i].push(i);
        }
    }
    blocks& get_blocks(int location)
    {
        return bs[location];
    }
};
class blocks_tracer
{
private:
    int m_t[maxn];
public:
    blocks_tracer()
    {
        for (int i = 0; i < maxn; i++) m_t[i] = i;
    }
    int get_location(int a)
    {
        return m_t[a];
    }
    void set_location(int a, int n)
    {
        m_t[a] = n;
    }
};

//define blocks_elt and pile_stack
void blocks_elt_top_to_a(blocks_tracer& ta, blocks_world& w, int a)
{
    int location = ta.get_location(a);
    blocks& b = w.get_blocks(location);
    int t = b.top();
    while (t != a)
    {
        b.pop();
        w.get_blocks(t).push(t);
        ta.set_location(t, t);
        t = b.top();
    }
}
void blocks_stack_a_to_b(blocks_tracer& ta, blocks_world& w, int a, int b)
{
    int location_a = ta.get_location(a);
    int location_b = ta.get_location(b);
    blocks& b_a = w.get_blocks(location_a);
    blocks& b_b = w.get_blocks(location_b);
    stack<int> s;
    int t = b_a.top(); 
    while (t != a)
    {
        s.push(t);
        b_a.pop();
        t = b_a.top();
    }
    s.push(t);
    b_a.pop();
    while (!s.empty())
    {
        t = s.top();
        s.pop();
        b_b.push(t);
        ta.set_location(t, location_b);
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
        blocks_tracer bt;
        blocks_world bw;
        while (true)
        {
            string cmd1, cmd2;
            int a, b;
            cin >> cmd1;
            if (cmd1 == "quit") break;
            cin >> a >> cmd2 >> b;
            if (a == b) continue;
            if (bt.get_location(a) == bt.get_location(b)) continue;
            if (cmd1 == "move")
            {
                blocks_elt_top_to_a(bt, bw, a);
                if (cmd2 == "onto")
                {
                    blocks_elt_top_to_a(bt, bw, b);
                }
                blocks_stack_a_to_b(bt, bw, a, b);
            }
            else
            {
                if (cmd2 == "onto")
                {
                    blocks_elt_top_to_a(bt, bw, b);
                }
                blocks_stack_a_to_b(bt, bw, a, b);
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << i << ":";
            int elts = bw.get_blocks(i).size();
            for (int j = 0; j < elts; j++)
            {
                cout << " " << bw.get_blocks(i).m_s[j];
            }
            cout << endl;
        }
    }
    return 0;
}
