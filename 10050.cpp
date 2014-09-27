/*
 * =====================================================================================
 *
 *       Filename:  10050.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月27日 08时15分52秒
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

static int party[110];
static int party_cnt[110];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("10050.in", "r", stdin);
#endif
    int test_case;
    scanf("%d", &test_case);

    while (test_case--)
    {
        int days, parties;
        int cnt(0);
        memset(party, 0, sizeof(party));
        scanf("%d %d", &days, &parties);
        for (int i = 0; i < parties; i++)
        {
            scanf("%d", &party[i]);
        }
        memcpy(party_cnt, party, sizeof(party));
        for (int j = 0; j < days; j++)
        {
            bool flag(true);
            for (int i = 0; i < parties; i++)
            {
                party_cnt[i]--;
                if (party_cnt[i] == 0)
                {
                    if ((j % 7 != 5) && (j % 7 != 6) && flag) {cnt++; flag = false;} 
                    party_cnt[i] = party[i];
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
