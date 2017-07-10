#include"class.h"
#include"functions.h"

//随机数
int myrand(int m)
{
	// randomf() 返回一个 0 到 1 之间的随机浮点数
	int i;
	i = ((int)(randomf() * (m - 2)) + 1) * 20;
	return i;
}

int myrand_num(int m)
{
	// randomf() 返回一个 0 到 1 之间的随机浮点数
	int i;
	i = (int)(randomf() * m);
	return i;
}

int getHistory()
{
	FILE *fp;
	char ch, buffer[5];
	int scores, i;
	//读取最高记录
	ch = NULL;
	fp = fopen("资源\\记录\\length_max.txt", "r");
	if (fp == NULL)
		scores = 3;
	else
	{
		i = 0;
		while (ch != EOF)
		{
			ch = fgetc(fp);
			buffer[i] = ch;
			i++;
		}
		buffer[i] = '\0';
		scores = atoi(buffer);
	}

	fclose(fp);
	return scores;
}

void saveHistory(const int scores)
{
	//存档
	FILE *fp;
	char ch;
	int i, j, num[4];
	i = j = 0;
	if (scores > 0 && scores < 9)
	{
		i = 1;
		num[1] = scores;
	}
	else if (scores >= 10 && scores < 100)
	{
		i = 2;
		num[1] = scores / 10;
		num[2] = scores % 10;
	}
	else if (scores >= 100 && scores < 1000)
	{
		i = 3;
		num[1] = scores / 100;
		num[2] = (scores % 100) / 10;
		num[3] = scores % 10;
	}

	fp = fopen("资源\\记录\\length_max.txt", "w");
	fp = fopen("资源\\记录\\length_max.txt", "a+");
	for (j = 1; j <= i; j++)
	{
		ch = num[j] + 48;
		fputc(ch, fp);
	}
	fclose(fp);
}