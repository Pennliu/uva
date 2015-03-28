#include <iostream>
#include <ctype.h>
#include <cstdio>

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
  int cnt = 0;
  char str[50];
  while (gets(str))
  {
    int i = 0;
    int a, b ,c;
    a = b = c = 0;
    int flag = 1;
    while (isdigit(str[i]))
    {
      a = 10*a +(str[i] - '0');
      i++;
    }
    if (str[i] == '-') flag = -1;
	i++;
    while (isdigit(str[i]))
    {
      
      b = 10*b + (str[i] - '0');
      i++;
    }
    i++;
    while (isdigit(str[i]))
    {
      c = 10*c + (str[i] - '0');
      i++;
    }
	//printf("a[%d], b[%d], c[%d]", a, b, c);
    if (a + (b*flag) == c) cnt++;
  }
  printf("%d\n", cnt);
  return 0;
}
