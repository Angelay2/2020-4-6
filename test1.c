#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)

// 斐波拉契数列(前两个数相加=现在的数) F(1) = 1, F(2) = 1, F(3) = 2
/* 每一行有n ^ 2的数
					  		 8
					7					6
				6		5			5		4
			 5	  4	 4	  3		  4   3	  3	  2
		   4
	     3
       2
	 1
	
*/
// 非递归比递归快

// 非递归 a+b放到c 三个指针往后移 也就是把c赋给b, 把b赋给a, 把新的数值赋给c
// 求第三个数时, a+b赋给c执行1次
// 求第四个数时, a+b赋给c执行2次
// 求第五个数时, a+b赋给c循环3次
int fib1(int n){
	int a = 1;
	int b = 1;
	int c = 0;
	if (n <= 2){
		return 1;
	}
	else{
		while (n > 2){
			c = a + b;
			a = b;
			b = c;
			n--;
		}
		return c;
	}
}
// 这种当数据大时, 可能会溢出导致出错
int fib2(int n){
	int a = 1;
	int b = 1;
	int c = 1;
	while (n > 2){
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;	
}

// 递归, 会很慢
int cnt = 0;
int fib(int n){
	cnt++;
	/*if (n == 0)
		return 1;
	else if (n == 1)
		return 2;*/
	if (n <= 2)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}
int main(){
	int n = 0;
	int ret = 0;
	scanf("%d", &n);
	ret = fib(n);
	printf("%d\n", ret); // n=8时,ret=21 第8个斐波拉契数=21
	printf("%d\n", cnt); // 调了41次
	system("pause");
	return 0;
}

// 递归与迭代
// 迭代不是循环(像循环 >=循环) 但循环是迭代 递归不是循环
/*1. 求n的阶乘
n <= 1时: 结果为1
n > 1时: 结果为n*Fac(n-1)
*/
int Fac(int n){
	if (n <= 1)
		return 1;
	else
		return n*Fac(n - 1);
}
int main4(){
	int n = 0;
	int ret = 0;
	scanf("%d", &n);
	ret = Fac(n);
	printf("%d\n", ret);
	system("pause");
	return 0;
}