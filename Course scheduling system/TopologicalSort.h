#ifndef TOPOLOGICALSORT_H_INCLUDED
#define TOPOLOGICALSORT_H_INCLUDED
#include<string>
#include"Graph.h"

struct Queue
{
	int Top,Tail;
	VNode *a[20];
	VNode *Front();
	void Clear();
	void Pop();
	void Push(VNode *e);
	bool Empty();
};


void Queue::Push(VNode *e)
{
	a[Tail++]=e;
	return ;
}


void Queue::Clear()
{
	Top=Tail=0;
	return ;
}

void Queue::Pop()
{
	Top++;
	return ;

}

VNode *Queue::Front()
{
	return a[Top];
}

bool Queue::Empty()
{
	return Top==Tail;
}

bool Find(ALGraph G)
{
	int j=0;
	for(int i=0;i<G.vexnum;i++)
	{
		if(G.AdjList[i].data.marks==0)
			{j=1;
		    break;}
	}
	return j;
}

void CourseSort(ALGraph G)
{
	int i,m,n,k=0,s=0,a=0;
	int Term=1;
	FILE *fp1;
	float t=0;//ѧ��ʣ��ѧ��
	VNode *v;
	VNode Sort[50];
	ArcNode *p;
	int Maxweeks;
	float Maxpoints;
	printf("\t\t\t������ÿѧ�ڵ�������ѧ������\n");
	printf("\n\t\t\t��������:");
	scanf("%d",&Maxweeks);
	printf("\n\t\t\tѧ������:");
	scanf("%f",&Maxpoints);
	s=Maxweeks;
	t=Maxpoints;
	system("cls");
	Queue Q;
	Q.Clear();
	while(Find(G))
	{   a=0;
		m=0,n=0;
		for(i=0;i<G.vexnum;i++)
	    {
		  if(G.AdjList[i].data.Indegree==0&&G.AdjList[i].data.marks!=1)
		  {
		 	  Q.Push(&G.AdjList[i]);
		 	  a++;
		 	  m++;
		 	  G.AdjList[i].data.marks=1;
		  }
	    }//���Ϊ0�ĵ������
	    if(a==0)
		{
			printf("\n\n\\t\t\t\t......��⵽ͼ�д��ڻ�!�����´����γ�ͼ!\n\n");
			exit(0);
		}
		else
		{
	    while(!Q.Empty())
	    {
		   v=Q.Front();//ȡ����Ԫ��
		   n++;
		   Q.Pop(); //������
		   p=v->firstarc;
		   while(p)
		   {
				G.AdjList[p->adjvex].data.Indegree--;//��ȼ�һ
				p=p->nextarc;
		   }

		   if(v->data.Point<=t&&v->data.Weeks<=s)
		   {
				v->data.term=Term;
				Sort[k++]=*v;
		   }
		   else
		    {
				Term++;//ѧ������һ
				t=Maxpoints;
				v->data.term=Term;
				Sort[k++]=*v;
			}
			  if(n==m)
		   {
		   	for(int j=0;j<k;j++)
			{
				if(Sort[j].data.term==Term)
				{
					if(s>=(Maxweeks-Sort[j].data.Weeks))
					{
						s=Maxweeks-Sort[j].data.Weeks;
					}
				}
			}
			t=t-v->data.Point;
		   }
		   else
		   {
		   	s=Maxweeks;
		   	t=t-v->data.Point;
		   }
	    }
		}
	}

	printf("�����Ż���ʹѧ����̵�����°�����Щ�γ̵�����ѧ������: %d\n\t\t\t\t�γ̱�����\n",Term);
	for(int j=1;j<=Term;j++)
	{
		printf("\n\t\t\t\t��%dѧ�ڵĿγ�����\n\n",j);
		printf("\t\t\t�γ̱��  �γ�����     ѧ��   ����   ѧ����\n");
		for(int m=0;m<k;m++)
		{
			if(Sort[m].data.term==j)
				printf("\n\t\t\t%d\t%10s\t%.2f\t%d\t%d\t\n",Sort[m].data.Num,Sort[m].data.Name,Sort[m].data.Point,Sort[m].data.Weeks,Sort[m].data.term);
		}
	}
	fp1=fopen("beifen","w+");
	if((fp1=fopen("beifen.txt","w+"))==NULL)
	{
		printf("���ļ�ʧ��!");
		exit(0);
	}
	else
	    for(int d=0;d<k;d++)
		{
			fprintf(fp1,"%d\t%10s\t%.2f\t%d\t%d\t\n",Sort[d].data.Num,Sort[d].data.Name,Sort[d].data.Point,Sort[d].data.Weeks,Sort[d].data.term);
		}
		fclose(fp1);
}

void SearchCourse()
{
	VNode S[50];
	char s[20];
	int d=0,j=0,m=1,n,Term=0;
	FILE *fp2;
	fp2=fopen("beifen.txt","a+");
	if((fp2=fopen("beifen.txt","a+"))==NULL)
	{
		printf("���ļ�ʧ��!");
		exit(0);
	}
	else
		while(!feof(fp2))
	{
		fscanf(fp2,"%d%s%f%d%d",&S[d].data.Num,&S[d].data.Name,&S[d].data.Point,&S[d].data.Weeks,&S[d].data.term);
		d++;
	}
	fclose(fp2);
	for(int s=0;s<d-1;s++)
	{
		if(S[s].data.term>=Term)
		{
			Term=S[s].data.term;
		}
	}

	while(m)
	{
		system("cls");
		printf("\n\t\t\t\t1-���γ����ֲ�ѯ\n\n\t\t\t\t2-��ѧ����Ų�ѯ\n\n\t\t\t\t3-��ѯȫ���γ�\n\n\t\t\t\t����:");
	    scanf("%d",&n);
		switch(n)
		{
		case 1:
			system("cls");
			j=0;
	        printf("\n��������Ҫ��ѯ�Ŀγ����֣�");
	        scanf("%s",s);
	        system("cls");
	        for(int i=0;i<d;i++)
            {
	      	if(strcmp(S[i].data.Name,s)==0)
		    {
			 printf("\n\t\t\t\t������Ŀγ���ϢΪ��\n");
			 printf("\n\t\t\t�γ̱��  �γ�����     ѧ��   ����   ѧ����\n");
			 printf("\n\t\t\t%d\t%10s\t%.2f\t%d\t%d\t\n",S[i].data.Num,S[i].data.Name,S[i].data.Point,S[i].data.Weeks,S[i].data.term);
			  j=1;
			 break;
		    }
			}
         	if(j==0)
	        {
		        printf("\n\t\t\t.......δ���ҵ�����Ҫ���ҵĿγ���Ϣ!\n");
	        }
	        break;
		case 2:
			system("cls");
			int t;
			printf("\n��������Ҫ��ѯ��ѧ�ںţ�");
			scanf("%d",&t);
			system("cls");
			if(t<=Term)
			{
			printf("\n\t\t\t\t��%dѧ�ڵĿγ�����\n\n",t);
			printf("\t\t\t�γ̱��  �γ�����     ѧ��   ����   ѧ����\n\n");
			for(int i=0;i<d;i++)
			{
				if(S[i].data.term==t)
				{
				   printf("\n\t\t\t%d\t%10s\t%.2f\t%d\t%d\t\n",S[i].data.Num,S[i].data.Name,S[i].data.Point,S[i].data.Weeks,S[i].data.term);
				}
			 }
			}
			else
				printf("\n\t\t\t......����ѧ����Ź��󣬸�ѧ�ڲ�����!\n");
			break;
		case 3:
			system("cls");
			for(int i=1;i<=Term;i++)
	       {
	        	printf("\n\t\t\t\t  ��%dѧ�ڵĿγ�����\n\n",i);
	        	printf("\t\t\t�γ̱��  �γ�����     ѧ��   ����   ѧ����\n");
		        for(int k=0;k<d;k++)
		        {
		        	if(S[k].data.term==i)
			        	printf("\n\t\t\t%d\t%10s\t%.2f\t%d\t%d\t\n",S[k].data.Num,S[k].data.Name,S[k].data.Point,S[k].data.Weeks,S[k].data.term);
		        }
		   }
		   break;
		default:
			printf("\n\t\t\t\t......�������!\n");
		}

	printf("\n\n\t\t\t�Ƿ������ѯ��\t(��-����1����-����0)\n\n\t\t\t���룺");
	scanf("%d",&m);
	}
}


void Tongji()
{
    VNode S[50];
	int d=0,Term=0,p1=0;
    float p2=0;
	FILE *fp2;
	fp2=fopen("beifen.txt","a+");
	if((fp2=fopen("beifen.txt","a+"))==NULL)
	{
		printf("���ļ�ʧ��!");
		exit(0);
	}
	else
		while(!feof(fp2))
	{
		fscanf(fp2,"%d%s%f%d%d",&S[d].data.Num,&S[d].data.Name,&S[d].data.Point,&S[d].data.Weeks,&S[d].data.term);
		d++;
	}
	fclose(fp2);

	for(int i=0;i<d-1;i++)
	{
		if(S[i].data.term>=Term)
		{
			Term=S[i].data.term;
		}
	}
	for(int j=1;j<=Term;j++)
	{
		p1=0;
		p2=0;
		for(int k=0;k<d;k++)
		{
			if(S[k].data.term==j)
			{
				p1++;
				p2=p2+S[k].data.Point;
			}
		}
		printf("\n\t\t\t��%dѧ�ڹ���ѧϰ%d�ſγ̣��޵�%.2fѧ��!\n",j,p1,p2);
	}

}

void func1(ALGraph G)
{
	int i;
	printf("\n\t\t\t\t��ѡ�񴴽��γ�ͼ�ķ�ʽ��\n");
	printf("\n\t\t\t\t1-�˹�����\n");
	printf("\n\t\t\t\t2-�ļ�����\n\n\t\t\t\t���룺");
	scanf("%d",&i);
	switch(i)
	{
	case 1:
		system("cls");
		CreateALGraph(G);
		break;
	case 2:
		system("cls");
		FileCreate(G);
		break;
	default:
		printf("�������!");
		exit(0);
	}
	system("cls");
	GhArc(G);
	GhPrint(G);
	CourseSort(G);
	printf("\n\n\t\t\t����γ̼ƻ����ųɹ�!\n");
}

void Update()
{
    char n[20];
    VNode S[50];
    int i,s,d=0,j=0;
    FILE *fp3,*fp4;
	fp3=fopen("beifen.txt","a+");
	if((fp3=fopen("beifen.txt","a+"))==NULL)
	{
		printf("���ļ�ʧ��!");
		exit(0);
	}
	else
		while(!feof(fp3))
	{
		fscanf(fp3,"%d%s%f%d%d",&S[d].data.Num,&S[d].data.Name,&S[d].data.Point,&S[d].data.Weeks,&S[d].data.term);
		d++;
	}
	fclose(fp3);
	while(s)
	{
		system("cls");
	j=0;
    printf("������Ҫ���µĿγ̵����֣�");
    scanf("%s",n);
    for(i=0;i<d-1;i++)
	{
		if(strcmp(S[i].data.Name,n)==0)
		{
			printf("\n����Ҫ���µĿγ���ϢΪ��\n");
			 printf("\n�γ̱��  �γ�����     ѧ��   ����   ѧ����\n");
			 printf("\n%d\t%10s\t%.2f\t%d\t%d\t\n",S[i].data.Num,S[i].data.Name,S[i].data.Point,S[i].data.Weeks,S[i].data.term);
			 j++;
			 break;
		}
	}
	if(j==0)
		printf("\nδ������Ҫ���µĿγ�!\n");
	else
		{
	     printf("\n%s  ����Ϊ�� ",S[i].data.Name);
	     scanf("%s",S[i].data.Name);
	     system("cls");
		 printf("\n���º����ϢΪ��\n");
		 printf("\n�γ̱��  �γ�����     ѧ��   ����   ѧ����\n");
	     printf("\n%d\t%10s\t%.2f\t%d\t%d\t\n",S[i].data.Num,S[i].data.Name,S[i].data.Point,S[i].data.Weeks,S[i].data.term);
         fp4=fopen("beifen.txt","w+");
	     if((fp4=fopen("beifen.txt","w+"))==NULL)
	     {
	    	printf("���ļ�ʧ��!");
	    	exit(0);
	     }
	     else
	          for(int k=0;k<d-1;k++)
		      {
		      	fprintf(fp4,"%d\t%10s\t%.2f\t%d\t%d\t\n",S[k].data.Num,S[k].data.Name,S[k].data.Point,S[k].data.Weeks,S[k].data.term);
		      }
		 fclose(fp4);
		 printf("\n���³ɹ�!\n");
		}
		printf("\n�Ƿ�������£�\t(��-����1����-����0)\n\n���룺");
	    scanf("%d",&s);
	}
}

#endif // TOPOLOGICALSORT_H_INCLUDED
