/* 
 * pack :
 * add a pile
 * del a pile
 * pile :
 * add a card
 * del a card 
 */
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;
class card
{
    public:
        char m_face;
        char m_suit;
    public:
        card(char face = 0, char suit = 0):m_face(face), m_suit(suit){};
        bool operator==(const card& a);
};
bool card::operator==(const card& a)
{
    return ((m_face == a.m_face) || (m_suit == a.m_suit));
}
class pack
{
    public:
        card c[52];
};
typedef vector<card> pile;
typedef vector<pile> piles;
static pack s_pack;
static piles s_piles;
void init()
{
    s_piles.clear();
}
void solve()
{
    for (int i = 0; i < 52; i++)
    {
        pile p;
        p.push_back(s_pack.c[i]);
        s_piles.push_back(p);
        int last_index = s_piles.size() - 1;
        int index = last_index;
        while (index <= last_index)
        {
            card c = s_piles[index].back();
            int tmp_index = index;
            while (true)
            {
                if (index >= 3 && (c == s_piles[index-3].back()))
                {
                    index = index - 3;
                    continue;
                }
                else if (index >= 1 && (c == s_piles[index-1].back()))
                {
                    index = index - 1;
                    continue;
                }
                break;
            }
            if (index != tmp_index)
            {
                s_piles[index].push_back(c);
                s_piles[tmp_index].pop_back();
                if (s_piles[tmp_index].empty())
                {
                    piles::iterator it = s_piles.begin() + tmp_index;
                    s_piles.erase(it);
                    last_index--;
                }
            }
            index++;
        }
    }
    int size = s_piles.size();
    printf("%d pile", size);
    if (size > 1)
    {
        printf("s");
    }
    printf(" remaining:");
    for (int i = 0; i < size; i++)
    {
        printf(" %lu", s_piles[i].size());
    }
    printf("\n");
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
/* 1. input
 * 2. solve
 * 3. output*/
    while (true)
    {
        init();
        char a, b;
        scanf("%c", &a); 
        if (a == '#') break;
        else scanf("%c", &b);
        s_pack.c[0].m_face = a;
        s_pack.c[0].m_suit = b;
        getchar();
        for (int i = 1; i < 52; i++)
        {
            scanf("%c%c", &s_pack.c[i].m_face, &s_pack.c[i].m_suit);
            getchar();
        }
        solve();
    }
    return 0;
}
