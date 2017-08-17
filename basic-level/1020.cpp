#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1010;
struct cake{
	double q, price, unit;
}c[maxn];

int cmp(cake a, cake b)
{
	return a.unit > b.unit;
}
int main()
{
	int n, m;
	double sum = 0;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		scanf("%lf", &c[i].q);
	}
	for(int i = 0; i < n; i++)
	{
		scanf("%lf", &c[i].price);
		c[i].unit = c[i].price / c[i].q;
	}
	sort(c, c+n, cmp);
	for(int i = 0; i < n; i++)
	{
		if(m - c[i].q > 0)
		{
			sum += c[i].price;
			m -= c[i].q;
		}
		else
		{
			sum += m * c[i].unit;
			break;
		}
	}
	printf("%.2f\n", sum);
	return 0;
}
