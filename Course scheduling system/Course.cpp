/*ÿ����ѧ�ڡ�ÿѧ�ڵĽ�ѧ������ѧ�־������ޣ��ڽ�ѧ�ƻ�һ��������£�
����Ŀγ̱�����������ϵ��
���Ҫ��
�����ڽӱ�ջ�����ݽṹ
����������ļ����˹��������ݣ�
����γ̵����Ż��֣�����ʹѧ�����
����ͳ�����ݲ������Ҫ��Լ������
���Բ�ѯ��������
�������ƻ���չ����
*/


#include <iostream>
#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include<windows.h>
#include "Graph.h"
#include "TopologicalSort.h"
using namespace std;

void Menu()
{
	int n;
	ALGraph G;
	while(n)
	{
		system("cls");
	int i;
	printf("\t\t\t\t��ӭʹ�ÿγ����ϵͳ\n");
	printf("\n\t\t\t\t1-�½��γ̱�\n");
	printf("\n\t\t\t\t2-��ѯ���ſγ�\n");
	printf("\n\t\t\t\t3-���¿γ̱�\n");
	printf("\n\t\t\t\t4-ͳ����Ϣ\n\n\t\t\t\t���룺");

	scanf("%d",&i);

	switch(i)
	{
	case 1:
		system("cls");
		func1(G);
		break;
	case 2:
		system("cls");
		SearchCourse();
		system("cls");
		break;
	case 3:
		system("cls");
		Update();
		system("cls");
		break;
	case 4:
		system("cls");
		Tongji();
		break;
	default:
		printf("�������!");
		exit(0);system("cls");
	}
	printf("\n\n\t\t\t�Ƿ񷵻����˵���(1-�������˵���0-�˳�ϵͳ)\n\n\t\t\t���룺");
	scanf("%d",&n);
	}
	system("cls");
	printf("\n\n\t\t\t\tллʹ�ÿγ����ϵͳ!\n\n");
}
int main()
{
	Menu();
	return 0;
}
