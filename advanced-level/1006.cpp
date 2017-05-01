#include <cstdio>

typedef struct student{
	char num[20];
	int in_h;
	int in_m;
	int in_s;
	int out_h;
	int out_m;
	int out_s;
}stu_t;


bool earlier(stu_t s1, stu_t s2)
{
	if(s1.in_h != s2.in_h)
	{
		return s1.in_h < s2.in_h;
	}
	else if(s1.in_m != s2.in_m)
	{
		return s1.in_m < s2.in_m;
	}
	else
	{
		return s1.in_s < s2.in_s;
	}
}

bool later(stu_t s1, stu_t s2)
{
	if(s1.out_h != s2.out_h)
	{
		return s1.out_h > s2.out_h;
	}
	else if(s1.out_m != s2.out_m)
	{
		return s1.out_m > s2.out_m;
	}
	else
	{
		return s1.out_s > s2.out_s;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int i;
	stu_t stu[n];
	for(i = 0; i < n; i++)
	{
		scanf("%s %d:%d:%d %d:%d:%d", stu[i].num, &stu[i].in_h, &stu[i].in_m, &stu[i].in_s,
			&stu[i].out_h, &stu[i].out_m, &stu[i].out_s);
	}
	
	stu_t early, late;
	early.in_h = 24;
	early.in_m = 0;
	early.in_s = 0;
	
	late.out_h = 0;
	late.out_m = 0;
	late.out_s = 0;
	
	for(i = 0; i < n; i++)
	{
		if(earlier(stu[i], early))
		{
			early = stu[i];
		}
		if(later(stu[i], late))
		{
			late = stu[i];
		}
	}

	printf("%s %s", early.num, late.num);
	return 0;
}
