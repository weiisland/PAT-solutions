#include <cstdio>
#include <cstring>

typedef struct student{
	char name[20];
	char sex;
	char id[20];
	int grade;
}stu_t;

int main()
{
	int n;
	scanf("%d", &n);
	
	stu_t tmp, highf, lowe;
	lowe.grade = 101;
	highf.grade = 0;
	memset(highf.name, 0, sizeof(highf.name));
	memset(lowe.name , 0, sizeof(lowe.name));
	int i;
	for(i = 0; i < n; i++)
	{
		scanf("%s %c %s %d", tmp.name, &tmp.sex, tmp.id, &tmp.grade);
		if(tmp.sex == 'F')
		{
			if(tmp.grade > highf.grade)
			{
				highf = tmp;
			}
		}
		else
		{
			if(tmp.grade < lowe.grade)
			{
				lowe = tmp;
			}
		}
	}
	
	if(strlen(lowe.name) == 0)
	{
		printf("%s %s\n", highf.name, highf.id);
		printf("Absent\n");
		printf("NA");
	}
	else if(strlen(highf.name) == 0)
	{
		printf("Absent\n");
		printf("%s %s\n", lowe.name, lowe.id);	
		printf("NA");
	}
	else
	{
		printf("%s %s\n", highf.name, highf.id);
		printf("%s %s\n", lowe.name, lowe.id);
		printf("%d", highf.grade - lowe.grade);
	}
	
	
	return 0;
}
