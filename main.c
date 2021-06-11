#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//数据结构体
typedef struct Date
{
	float* date;
	float average;
	float SD;
	float RSD;
	int size;
}Date;

//扩容函数
void AddMemory(Date* DateNu)
{
	DateNu->date = (float*)malloc(sizeof(float)*DateNu->size);
}

//数据输入
void inputDate(Date* DateNu)
{
	int i = 0;
	for (i = 0; i < DateNu->size; i++)
	{
		scanf("%f", &DateNu->date[i]);
	}
}

//数据计算
void calcuAver(Date* DateNu)
{
	int i = 0;
	float sum = 0;
	for (i = 0; i < DateNu->size; i++)
	{
		sum += DateNu->date[i];
	}
	DateNu->average = sum / (DateNu->size);
}

//计算标准偏差
void calcuSD(Date* DateNu)
{
	float square = 0;
	int i = 0;
	for (i = 0; i < DateNu->size; i++)
	{
		square+=(DateNu->date[i] - DateNu->average)*(DateNu->date[i] - DateNu->average);
	}
	DateNu->SD = (float)sqrt(square / (float)(DateNu->size - 1));
}

//计算标准偏差
void calcuRSD(Date* DateNu)
{
	DateNu->RSD = ((DateNu->SD) / (DateNu->average)) * 100;
}

void menu()        //菜单
{
	printf("****************************\n");
	printf("****  相对平均偏差计算  ****\n");
	printf("****************************\n");
}

//初始化数据
void initDate(Date* DateNu)
{
	DateNu->average = 0;
	DateNu->SD = 0;
	DateNu->RSD = 0;
	DateNu->size = 0;
}

void test()
{
	Date DateNu;
	//初始化
	initDate(&DateNu);
	//菜单
	menu();
	printf("请输入数据的数量：");
	scanf("%d", &DateNu.size);
	printf("请输入数据，每输入一个以回车结束！\n");
	//扩容
	AddMemory(&DateNu);
	//判空
	if (DateNu.date == NULL)
	{
		return;
	}
	//输入数据
	inputDate( &DateNu);
	//计算平均值
	calcuAver(&DateNu);
	//计算标准偏差
	calcuSD(&DateNu);
	//计算标准偏差
	calcuRSD(&DateNu);
	printf("平均值=%f\n", DateNu.average);
	printf("SD=%f\n", DateNu.SD);
	printf("RSD=%f%%\n", DateNu.RSD);
}

int main()
{
	test();
	system("pause");
	return 0;
}
