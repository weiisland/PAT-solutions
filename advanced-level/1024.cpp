#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct bign{
	int d[100];
	int len;
	bign()
	{
		memset(d, 0, sizeof(d));
		len = 0;
	}
};

bign change(char str[])
{
	bign a;
	a.len = strlen(str);
	for(int i = 0; i < a.len; i++)
	{
		a.d[i] = str[a.len - 1 - i] - '0';
	}
	return a;
}

bign add(bign a, bign b)
{
	bign c;
	int carry = 0;
	for(int i = 0; i < a.len || i < b.len; i++)
	{
		int temp = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = temp % 10;
		carry = temp /10;
	}
	if(carry != 0)
	{
		c.d[c.len++] = carry;
	}
	return c;
}

void showBign(bign a)
{
	int len = a.len;
	for(int i = len-1; i >= 0; i--)
	{
		printf("%d", a.d[i]);	
	}
	printf("\n");
}
int k;
bool check(bign a)
{
	for(int j = 0; j <= a.len/2; j++)
	{
		if(a.d[j] != a.d[a.len - 1 - j])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	char str[15];
	scanf("%s", str);
	
	scanf("%d", &k);
	int len = strlen(str);
	bign a = change(str);
	bool flag = false;
	
	if(check(a))
	{
		showBign(a);
		printf("0");
		return 0;
	}
	
	for(int i = 0; i < k; i++)
	{
		bign tmp = a;
		reverse(tmp.d, tmp.d+tmp.len);
		a = add(a, tmp);
		
		int mid = a.len / 2;
		
		for(int j = 0; j <= mid; j++)
		{
			if(a.d[j] != a.d[a.len - 1 - j])
			{
				flag = true;
			}
		}
		if(flag == false)
		{
			showBign(a);
			printf("%d", i+1);
			break;
		}
		flag = false;
	}
	
	if(!check(a))
	{
		showBign(a);
		printf("%d", k);
	}
	
	return 0;
}

