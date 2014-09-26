/*
 * =====================================================================================
 *
 *       Filename:  424.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月26日 21时21分47秒
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

const int max_n = 110;
struct bign
{
    int len;
    int b[max_n];
    bign()
    {
        memset(b, 0, sizeof(b));
        len = 1;
    }
    bign operator=(const char* str)
    {
        len = strlen(str);
        for (int i = 0; i < len; i++)
        {
            b[i] = str[len - 1 - i] - '0';
        }
        return *this;
    }
    bign operator=(int n)
    {
        char buf[max_n];
        sprintf(buf, "%d", n);
        *this = buf;
        return *this;
    }
    bign(const char* str)
    {
        *this = str;
    }
    bign(int n)
    {
        *this = n;
    }
    bign operator+(const bign& a) const
    {
        bign c;
        c.len = 0;

        for (int i = 0, q = 0; i < max(len, a.len) || q; i++)
        {
            int t = b[i] + a.b[i] + q;
            c.b[c.len++] = t % 10;
            q = t / 10;
        }
        return c;
    }
    bign operator+=(const bign& a)
    {
        *this = *this + a;
        return *this;
    }
    string str() const
    {
        string res = "";
        for (int i = 0; i < len; i++)
        {
            res = char(b[i] + '0') + res; 
        }
        if (res == "") res = "0";
        return res;
    }
    bool operator==(const bign& a) const
    {
        if (len != a.len) return false;
        for (int i = 0; i < len; i++)
        {
            if (b[i] != a.b[i]) return false;
        }
        return true;
    }
};
istream& operator>>(istream& in, bign& c) 
{
    string str;
    in >> str;
    c = str.c_str();
    return in;
}
ostream& operator<<(ostream& out, const bign& c)
{
    out << c.str();
    return out;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("424.in", "r", stdin);
#endif
    bign sum;
    bign a;
    bign z;

    while (cin >> a)
    {
        if (a == z) break;
        sum += a;
    }
    cout << sum << endl;
    return 0;
}
