#include<stdio.h>
/*写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
例如：给定s1 = AABCD和s2 = BCDAA，返回1
给定s1 = abcd和s2 = ACBD，返回0.
AABCD左旋一个字符得到ABCDA
AABCD左旋两个字符得到BCDAA
AABCD右旋一个字符得到DAABC*/
int IsRotate(char*str, char*sub)
{
	assert(*str != NULL);
	assert(*sub != NULL);
	if (strlen(str) != strlen(sub)) 
		return 0;
	char*tmp = (char*)malloc(sizeof(char)*strlen(str) * 2 + 1);
	strcat(tmp, str);    
	char*res = strstr(tmp, sub);
	free(tmp);
	return 1;
}
int main()
{
	char*str = "HelloBity";
	char*sub = "Bityhello";
	int flag = IsRotate(str, sub);
	if (flag)
		printf("True");
	else
		printf("False");
	return 0;
}