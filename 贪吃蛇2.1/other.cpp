#include"class.h"
#include"functions.h"

//�����
int myrand(int m)
{
	// randomf() ����һ�� 0 �� 1 ֮������������
	int i;
	i = ((int)(randomf() * (m - 2)) + 1) * 20;
	return i;
}

int myrand_num(int m)
{
	// randomf() ����һ�� 0 �� 1 ֮������������
	int i;
	i = (int)(randomf() * m);
	return i;
}

int getHistory()
{
	FILE *fp;
	char ch, buffer[5];
	int scores, i;
	//��ȡ��߼�¼
	ch = NULL;
	fp = fopen("��Դ\\��¼\\length_max.txt", "r");
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
	//�浵
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

	fp = fopen("��Դ\\��¼\\length_max.txt", "w");
	fp = fopen("��Դ\\��¼\\length_max.txt", "a+");
	for (j = 1; j <= i; j++)
	{
		ch = num[j] + 48;
		fputc(ch, fp);
	}
	fclose(fp);
}