#include<stdio.h>

int main()
{
	char a,b,c;
	scanf("%c%c%c",&a,&b,&c);
	printf("\n");
	
	printf("%c %c %c\n",a,b,c);
	
	printf("%d %d %d\n",a,b,c);
	
	return 0;
 } 
 /*  
   ����ʱ �����ַ�����a b c��a��b��c֮����һ���ո� 
                 �Լ� abc ��a��b��c֮��û�пո�
    �ֱ����г���鿴���           
                 
    �����ַ����� ϵͳ���������ַ������ո��ַ���ת���ַ��е��ַ�����Ϊ��Ч�ַ�����  ԭ�ⲻ�����͸������ı����ĵ�ַ�д�������
	
	%d���Խ��ַ�������Ӧ��ASCII�����
	%c���Խ�ASCII���Ӧ���ַ�������� 
	
	�������ʼ�� char a,b,c ��Ϊ int a,b,c  ����������ͬ�� 
	 
*/				  