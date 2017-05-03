#include <cstdio>

int main()
{
	int Galleon = 17 * 29; // sickle
	int Sickle = 29; // knuts
	long long a1, a2, a3, b1, b2, b3;
	scanf("%lld.%lld.%lld %lld.%lld.%lld", &a1, &a2, &a3, &b1, &b2, &b3);
	
	long long a = a1 * Galleon + a2 * Sickle + a3;
	long long b = b1 * Galleon + b2 * Sickle + b3;
	long long c = a + b;
	printf("%lld.%lld.%lld", c/Galleon, (c%Galleon)/29, c%Galleon%29);
	
	return 0;
}
