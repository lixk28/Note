/* 字符数组的初始化 */
#include<stdio.h>

int main()
{
	char a[12]={'H','e','l','l','o',',',' ','w','o','r','l','d'};// 利用初始化列表 初始化数组 
	// 要保证数组长度大于初值个数，否则会报错 
	// 若初值个数小于数组长度，则只将这些字符赋给前面的元素，其余的元素系统自动分配为 空字符 \0 
	
	char b[]={'H','e','l','l','o',',',' ','w','o','r','l','d'}; 
	// 定义时也可以省略数组长度，系统会自动根据初值个数确定数组长度 
	
	char c[]={"Hello, world"}; // 利用字符串常量 初始化数组
	char d[]="Hello, world"; // 花括号可以被省略 
	
	char diamond[5][5]={{'','','*'},{'','*','','*'},
	                    {'*','','','','*'},{'','*','','*'},{'','','*'}}; //也可以定义多维字符数组 有多行字符 
		
	return 0;
} 
