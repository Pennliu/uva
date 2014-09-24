/*
 * =====================================================================================
 *
 *       Filename:  424.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月24日 21时13分43秒
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

static char a[110];
struct bign
{
    int len;
    int s[110];
    bign()
    {
        memset(s, 0, sizeof(s)); 
        len = 1;
    }
    bign operator=(const char* num)
    {
        len = strlen(num);
        for (int i = 0; i < len; i++) s[i] = num[len - 1 - i] - '0';
        return *this;
    }
    bign operator=(int num)
    {
        char a[110];
        sprintf(a, "%d", num);
        *this = a;
        return *this;
    }
    bign(const char* num)
    {
        *this = num;
    }
    bign(int num)
    {
        *this = num;
    }
    bign operator+(const bign& b) const
    {
        bign c;
        c.len = 0;
        int l = max(len, b.len);
        for (int i = 0, q = 0; i < l || q; i++)
        {
            int t = s[i] + b.s[i] + q;
            c.s[c.len++] = t % 10;
            q = t / 10;
        }
        return c;
    }
    bign operator+=(const bign& a)
    {
        *this = *this + a;
        return *this;
    }
    bool operator==(const bign& a) const
    {
        if (len != a.len) return false;
        for (int i = 0; i < len; i++) 
        {
            if (s[i] != a.s[i]) return false;
        }
        return true;
    }

    string str() const
    {
        string str = "";
        for (int i = 0; i < len; i++) str = (char)(s[i] + '0') + str;
        if (str == "") str = "0";
        return str;
    }
};
ostream& operator<<(ostream& out, const bign& a)
{
    out << a.str();
    return out; 
}
istream& operator>>(istream& in, bign& a)
{
    string str;
    cin >> str;
    a = str.c_str();
    return in;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("424.in", "r", stdin);
    freopen("424.out", "w", stdout);
#endif
    bign sum;
    bign n;
    bign zero(0);
    while (cin >> n)
    {
        if (zero == n) break;
        sum += n;
    }
    cout << sum.str() << endl;

    return 0;
}
