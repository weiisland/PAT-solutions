#include <cstdio>
#include <cstring>

int main()
{
	int n;
	scanf("%d", &n);
	getchar();
	char str[n][30];
	int i, j, count = 0;
	int save[n];
	bool flag = false;
	for(i = 0; i < n; i++)
	{
		save[i] = 0;
		gets(str[i]);
		
		int len = strlen(str[i]);
		for(j = 0; j < len; j++)
		{
			if(str[i][j] == ' ')
			{
				break;
			}
		}
		j++;
		//printf("j = %d\n", j);
		for(; j < len; j++)
		{
			switch(str[i][j])
			{
				case '1':
					str[i][j] = '@';
					flag = true;
					save[i] = 1;
					//printf("@\n");
					break;
				case 'l':
					str[i][j] = 'L';
					flag = true;
					save[i] = 1;
					//printf("L\n");
					break;
				case '0':
					str[i][j] = '%';
					flag = true;
					save[i] = 1;
					//printf("%\n");
					break;
				case 'O':
					str[i][j] = 'o';
					flag = true;
					save[i] = 1;
					//printf("o\n");
					break;
				default:
					break;
			}
		}
		
		if(flag)
		{
			count++;
			//printf("count = %d\n", count);
		}
		flag = false; //重置 
	}
	
	if(count == 0)
	{
		if(n == 1)
		{
			printf("There is 1 account and no account is modified");
		}
		else
		{
			printf("There are %d accounts and no account is modified", n);
		}
	}
	else
	{
		printf("%d\n", count);
		for(i = 0; i < n; i++)
		{
			if(save[i] == 1)
			{
				printf("%s\n", str[i]);
			}
		}
	}
	
	return 0;
}
