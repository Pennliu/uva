/*
 * =====================================================================================
 *
 *       Filename:  112.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年10月02日 21时52分48秒
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



enum token
{
    LEFT_BRACKET,RIGHT_BRACKET, NUM,
    MATCH, NOT_MATCH, EMPTY_TREE
};
static int num;
enum token get_token()
{
    int c = getchar();    
    while (c == ' ' || c== '\n') c = getchar();
    num = 0; 
    if (c == '(') return LEFT_BRACKET;
    else if (c == ')') return RIGHT_BRACKET;
    else if (isdigit(c) || c == '-')
    {
        int sign = 1;
        if (c == '-') 
        {
            sign = -1;
            c = getchar();
        }
        for (; isdigit(c); c = getchar())
        {
            num = num*10 + c - '0';
        }
        num = num * sign;
        ungetc(c, stdin);
        return NUM;
    }
    assert(0);
}

enum token check(int sum, int target)
{
    get_token();
    enum token t = get_token();
    if (t == RIGHT_BRACKET) return EMPTY_TREE;
    else
        sum += num;
    enum token lc = check(sum, target);
    enum token rc = check(sum, target);
    get_token();
    if (EMPTY_TREE == lc && EMPTY_TREE == rc) 
    {
        if (sum == target) return MATCH;
    }
    if (MATCH == lc || MATCH == rc) return MATCH;
    return NOT_MATCH;
}

int main()
{
#ifndef online_judge
    freopen("112.in", "r", stdin);
#endif
    int target;
    while (scanf("%d", &target) == 1)
    {
        if (check(0, target) == MATCH) printf("yes");
        else printf("no");
        printf("\n");
    }
    return 0;
}
