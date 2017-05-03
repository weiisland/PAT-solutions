#include <cstdio>
#include <cstring>

char days[8][5] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int min(int s1, int s2)
{
	return s1 < s2 ? s1 :s2; 
}

int main()
{
	char str[4][100];
	int i, j;
	for(i = 0; i < 4; i++)
	{
		gets(str[i]);
	}
	
	int len1 = min(strlen(str[0]), strlen(str[1]));
	int len2 = min(strlen(str[2]), strlen(str[3]));
	
	for(i = 0; i < len1; i++)
	{
		if(str[0][i] >= 'A' && str[0][i] <= 'G' && str[0][i] == str[1][i]) //注意限定完整
		{
			printf("%s ", days[str[0][i] - 'A']);
			break;
		}
	}
	i++;
	for(; i < len1; i++)
	{
		if(str[0][i] >= 'A' && str[0][i] <= 'N' && str[0][i] == str[1][i])
		{
			{
				printf("%d:", str[0][i] - 'A' + 10);
				break;
			}
		}
		if(str[0][i] >= '0' && str[0][i] <= '9' && str[0][i] == str[1][i])
		{
			printf("%02d:", str[0][i] - '0');
			break;
		}
	}
	
	for(j = 0; j < len2; j++)
	{
		if(str[2][j] >= 'A' && str[2][j] <= 'z' && str[2][j] == str[3][j])
		{
			printf("%02d", j);
			break;
		}
	}
	
	return 0;
}
