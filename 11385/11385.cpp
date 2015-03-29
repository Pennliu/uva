#include <iostream>
#include <cassert>
#include <map>
#include <cstdio>
#include <ctype.h>

using namespace std;
const int max_n = 1000;
int num[max_n];
char str[max_n];
char result[max_n];
long long fib_table[max_n];
int fib_table_cnt = 0;
int fib_num_index;
map<int, char> htab;

void htab_create(int cnt, int* num, char* str)
{
	htab.clear();
	for (int i = 0, j = 0; i < cnt; i++, j++)
	{
		while (!isupper(str[j])) j++;
		htab[num[i]] = str[j];
	}
	return;
}
int htab_find(int num)
{
	map<int, char>::iterator it = htab.find(num);
	if (it == htab.end()) return -1;
	else return it->first;
}
void fib_table_init()
{
	fib_table[0] = 1;
	fib_table[1] = 2;
	int i = 2;
	unsigned m = 1<<31;
	while ((fib_table[i-1] + fib_table[i-2]) < m)
	{
		fib_table[i] = fib_table[i-1] + fib_table[i-2];
		//printf(" %d %lu\n", i, fib_table[i]);
		i++;
	}
	fib_table_cnt = i;
	//printf("fib_table size is %d\n", i);
	return;
}

int fib_num_get(int n)
{
	for (int i = 0; i < fib_table_cnt; i++)
	{
		if (fib_table[i] == n) return i+1;
	}
	assert(0);
}
void calc(int len)
{
	for (int i = 0; i < len; i++)
	{
		int fib_num = htab_find(fib_table[i]);
		if (fib_num != -1)
		{
			result[i] = htab[fib_num];
		}
		else result[i] = ' ';
	}
	result[len] = 0;
	printf("%s\n", result);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	fib_table_init();
	int n;
	cin >> n;
	while (n--)
	{
		int test;
		cin >> test;
		int max_fib = 0;
		for (int i = 0; i < test; i++)
		{
			cin >> num[i];
			if (num[i] > max_fib) max_fib = num[i];
		}
		cin.getline(str, sizeof(str));
		cin.getline(str, sizeof(str));
		//printf("str: %s\n", str);
		htab_create(test, num, str);
		fib_num_index = fib_num_get(max_fib);
		calc(fib_num_index);
	}
	return 0;
}
