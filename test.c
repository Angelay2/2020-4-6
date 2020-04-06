#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)

// 递归
int main1(){
	printf("hehe\n");
	main();// 栈溢出 main函数一直在申请空间 没有归还
	system("pause");
	return 0;
}

void Print(unsigned int n){// 1234
	// %10 得到末尾数 /10 去掉末尾数
	// 当为两位以上的数时, 首先打印除最后一位其他的每一位
	if (n > 9){
		Print(n / 10);// 123
	}
	printf("%d ", n % 10);// 4
}
int main2(){
	unsigned int num = 0;
	scanf("%d", &num);// 1234
	Print(num);

	system("pause");
	return 0;
}

#include <string.h>
int mystrlen(char* str){// 要接受地址的话, 也要用char*
	// 需要来计数
	int count = 0;
	// 遇到不是'\0'就 ++count
	// str 为地址, 要拿到元素 就要解引用,*str = a;
	while(*str != '\0'){
		count++;
		str++;
	}
	return count;
}
// 不创建临时变量
int mystrlen2(char* str){
	// 如果第一个字符不是'\0' 那就是+1, 总的长度 = 1+剩余的长度
	if (*str == '\0')
		return 0;
	else
		return 1 + mystrlen2(str+1);
}
int main(){
	char arr[] = "abcdef";

	// int len = strlen(arr);
	//int len = mystrlen(arr);// arr为首元素的地址 类型为char*
	int len = mystrlen2(arr);
	printf("%d\n", len);

	system("pause");
	return 0;
}