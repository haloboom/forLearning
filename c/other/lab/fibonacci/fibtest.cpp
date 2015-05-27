#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
int a = 1, b = 1, n, num;
scanf("%d", &n);
if(n == 1 || n == 2)
{
printf("1\n");
return 0;
}
else
{
for(int i = 3; i <= n; i++)
{
num = (a + b) % 10007;
a = b;
b = num;
}
printf("%d\n", num);
}
return 0;
}
