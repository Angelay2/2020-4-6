#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)

// �ݹ�
int main1(){
	printf("hehe\n");
	main();// ջ��� main����һֱ������ռ� û�й黹
	system("pause");
	return 0;
}

void Print(unsigned int n){// 1234
	// %10 �õ�ĩβ�� /10 ȥ��ĩβ��
	// ��Ϊ��λ���ϵ���ʱ, ���ȴ�ӡ�����һλ������ÿһλ
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
int mystrlen(char* str){// Ҫ���ܵ�ַ�Ļ�, ҲҪ��char*
	// ��Ҫ������
	int count = 0;
	// ��������'\0'�� ++count
	// str Ϊ��ַ, Ҫ�õ�Ԫ�� ��Ҫ������,*str = a;
	while(*str != '\0'){
		count++;
		str++;
	}
	return count;
}
// ��������ʱ����
int mystrlen2(char* str){
	// �����һ���ַ�����'\0' �Ǿ���+1, �ܵĳ��� = 1+ʣ��ĳ���
	if (*str == '\0')
		return 0;
	else
		return 1 + mystrlen2(str+1);
}
int main(){
	char arr[] = "abcdef";

	// int len = strlen(arr);
	//int len = mystrlen(arr);// arrΪ��Ԫ�صĵ�ַ ����Ϊchar*
	int len = mystrlen2(arr);
	printf("%d\n", len);

	system("pause");
	return 0;
}