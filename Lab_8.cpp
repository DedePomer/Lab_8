//Chirkov v.24

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

bool isNum(char s[2])
{
	bool b = false;
	if ((int)s[0]-48 < 3)
		b = true;
	else if ((int)s[0]-48 == 3 && (int)s[1]-48 <= 1)
		b = true;
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

void main()
{
	char s[] = "adddsd11.sds30.12.21";
	char miniN[2] = { 0 };
	char miniM[2] = { 0 };
	int f = 0;
	for (int i = 0; s[i]!='\0'; i++)
	{
		if (isdigit(s[i]) && (sizeof(s)) - (i+1) >= 8)
		{
			if (isdigit(s[i]) && isdigit(s[i + 1]) && s[i + 2] == '.' && isdigit(s[i + 3]) && isdigit(s[i + 4]) 
				&& s[i + 5] == '.' && isdigit(s[i + 6]) && isdigit(s[i + 7]))//проверяет что есть дата
			{
				miniN[0] = s[i];
				miniN[1] = s[i + 1];
				miniM[0] = s[i + 3];
				miniM[1] = s[i + 4];
				if (isNum(miniN) && isMou(miniM))
				{
					printf_s("Yes");
					f++;
					break;
				}		
			}
		}
		
	}
	if (f ==0)
	{
		printf_s("No");
	}


}


