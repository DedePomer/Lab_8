//Chirkov v.24

#include <iostream>
#include <stdio.h>
#include <math.h>


using namespace std;


int charTOint(char *s)
{
	int num = 0;
	while (*s != '\0')
	{
		num += (int)*s - 48;
		num *= 10;
		s++;
	} 
	num = num / 10;
	return num;
}
bool isNum(char s[2], int mun, bool leep)
{
	bool b = false;
	int d = charTOint(s);
	switch (mun)
	{
	case 1:case 3:case 5:case 7:case 8:case 10:case 12://для месяцев с 31 днём
		if (d <= 31)
			b = true;
		else
			b = false;
		break;
	case 4:case 6:case 9: case 11://для месяцев с 30 днём
		if (d <= 30)
			b = true;
		else
			b = false;
		break;
	case 2://февраль
		if (leep)
		{
			if (d<=29)
				b = true;
			else
				b = false;		
		}
		else
		{
			if (d <= 28)
				b = true;
			else
				b = false;
		}
		break;
	}
	return b;
}

bool isMou(char s[2])
{
	bool b = false;
	if ((int)s[0]-48 < 1)
		b = true;
	else if ((int)s[0]-48 == 1 && (int)s[1]-48 <= 2)
		b = true;
	return b;
}

bool isLeepYear(char s[4])
{
	bool b = false;
	int year = charTOint(s);
	
	if ((year % 4 == 0 and year % 100 != 0) or (year % 400 == 0))
	{
		b = true;
	}
	else 
		b = false;
	return b;
}

void main()
{
	char s[] = "29.12.1991adddsd11.sds";
	char miniN[3] = { 0 };
	char miniM[3] = { 0 };
	char miniY[5] = { 0 };
	int f = 0;
	for (int i = 0; s[i]!='\0'; i++)
	{
		if (isdigit(s[i]) && (sizeof(s)) - (i+1) >= 8)
		{
			if (isdigit(s[i]) && isdigit(s[i + 1]) && s[i + 2] == '.' && isdigit(s[i + 3]) && isdigit(s[i + 4]) 
				&& s[i + 5] == '.' && isdigit(s[i + 6]) && isdigit(s[i + 7]) && isdigit(s[i + 8]) && isdigit(s[i + 9]))//проверяет что есть дата
			{
				miniN[0] = s[i];
				miniN[1] = s[i + 1];
				miniN[2] = '\0';
				miniM[0] = s[i + 3];
				miniM[1] = s[i + 4];
				miniM[2] = '\0';
				miniY[0] = s[i + 6];
				miniY[1] = s[i + 7];
				miniY[2] = s[i + 8];
				miniY[3] = s[i + 9];
				miniY[4] = '\0';
				if (isMou(miniM))// проверяем месяц
				{
					if (isNum(miniN, charTOint(miniM),isLeepYear))
					{
						printf_s("Yes");
						f++;
						break;
					}
				}
	
			}
		}
		
	}
	if (f ==0)
	{
		printf_s("No");
	}


}


