#include<stdio.h>
/*дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
���磺����s1 = AABCD��s2 = BCDAA������1
����s1 = abcd��s2 = ACBD������0.
AABCD����һ���ַ��õ�ABCDA
AABCD���������ַ��õ�BCDAA
AABCD����һ���ַ��õ�DAABC*/
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