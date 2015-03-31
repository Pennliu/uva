#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

string check(int num)
{
	vector<int> v;
	v.push_back(1);
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			v.push_back(i);
		}
	}
	int sum = 0;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		sum += *it;
	}
	if (sum == num) return "PERFECT";
	else if (sum > num) return "ABUNDANT";
	else return "DEFICIENT";
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	int n;
	cout << "PERFECTION OUTPUT" << endl;
	while (cin >> n && n)
	{
		//cout << n << " " << check(n) << endl;;
		printf("%5d ", n);
		cout << check(n) << endl;
	}
	cout << "END OF OUTPUT" << endl;
	return 0;
}
