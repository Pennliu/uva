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

bool char_invalied(char c)
{
    return ((c != 'M') && (c != 'E') && (c != '?'));
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    int n;
    cin >> n;
    typedef enum {
        idle = 0,
        question_mark_1,
        M_mark,
        question_mark_2,
        E_mark,
        question_mark_3,
        ok
    } state;
    while (n--)
    {
        state s = idle;
        string str;
        cin >> str;
        bool flag = true;
        int cnt_middle = 0;
        int cnt_right= 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (char_invalied(str[i])) 
            {
                flag = false;
                break;
            }
            switch(s)
            {
                case idle:
                {
                    if (str[i] == '?') s = question_mark_1;
                    else {
                        flag = false;
                    }
                    break;
                }
                case question_mark_1:
                {
                    if (str[i] == 'M') s = M_mark;
                    else if (str[i] == 'E')
                    {
                        flag = false;
                    }
                    break;
                }
                case M_mark:
                {
                    if (str[i] == '?') {s= question_mark_2;cnt_middle++;}
                    else
                    {
                        flag = false;
                    }
                    break;
                }
                case question_mark_2:
                {
                    if (str[i] == 'E') s = E_mark;
                    else if (str[i] == 'M') 
                    {
                        flag = false;
                    }
                    else {cnt_middle++;}
                    break;
                }
                case E_mark:
                {
                    if (str[i] == '?') {s = ok; cnt_right++;}
                    else
                    {
                        flag = false;
                    } 
                    break;
                }
                case ok:
                {
                    if (str[i] != '?')
                    {
                        flag = false;
                    }
                    else
                    {
                        cnt_right++;
                    }
                    break;
                }
                default:
                assert(0);
            }
            if (flag == false)
            {
                break;
            }
        }
        if (flag && ((cnt_right - cnt_middle) >= 1)) cout << "theorem" << endl;
        else cout << "no-theorem" << endl;
    }
}
