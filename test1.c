#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)

// 쳲���������(ǰ���������=���ڵ���) F(1) = 1, F(2) = 1, F(3) = 2
/* ÿһ����n ^ 2����
					  		 8
					7					6
				6		5			5		4
			 5	  4	 4	  3		  4   3	  3	  2
		   4
	     3
       2
	 1
	
*/
// �ǵݹ�ȵݹ��

// �ǵݹ� a+b�ŵ�c ����ָ�������� Ҳ���ǰ�c����b, ��b����a, ���µ���ֵ����c
// ���������ʱ, a+b����cִ��1��
// ����ĸ���ʱ, a+b����cִ��2��
// ��������ʱ, a+b����cѭ��3��
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
// ���ֵ����ݴ�ʱ, ���ܻ�������³���
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

// �ݹ�, �����
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
	printf("%d\n", ret); // n=8ʱ,ret=21 ��8��쳲�������=21
	printf("%d\n", cnt); // ����41��
	system("pause");
	return 0;
}

// �ݹ������
// ��������ѭ��(��ѭ�� >=ѭ��) ��ѭ���ǵ��� �ݹ鲻��ѭ��
/*1. ��n�Ľ׳�
n <= 1ʱ: ���Ϊ1
n > 1ʱ: ���Ϊn*Fac(n-1)
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