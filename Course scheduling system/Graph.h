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
#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

#define MAX_VERTEX_NUM 50


//��ڵ�
struct ArcNode
{
	int adjvex;
	struct ArcNode *nextarc;
};

//������Ϣ
struct VertexType
{
	int Num;
	char Name[20];
	float Point;
	int Weeks;
	bool marks;
	int term;
	int Indegree;
	int Outdegree;
};

//ͷ���
typedef struct VNode
{
	VertexType data;
	ArcNode *firstarc;
}VNode;

typedef struct ALGraph
{
    VNode AdjList[MAX_VERTEX_NUM];
	int vexnum;
	int arcnum;
}ALGraph;

int GLocateVex(ALGraph G,int x)
{
	int i,j=-1;
	for(i=0;i<G.vexnum;i++)
	{
		if(G.AdjList[i].data.Num==x)
        {
            j=i;
            break;
        }
	}
	return j;
}


void GhArc(ALGraph G)
{
	int i;
	ArcNode *q;
	printf("\t\t\t�������γ�ͼ�Ŀγ̹�ϵ����(��Ŵ���γ̱�ʾ)\n");
	for(i=0;i<G.vexnum;i++)
	{
		q=G.AdjList[i].firstarc;
		while(q)
		{
			printf("\t\t\t\t\t%d->%d\n",G.AdjList[i].data.Num,G.AdjList[q->adjvex].data.Num);
		    q=q->nextarc;
		}
	}
}

void GhPrint(ALGraph G)
{
	int i;
	printf("\t\t\t\t   �γ���Ϣ����:\n\n\t\t\t�γ̱�� �γ�����    ѧ��   ����\n");
	for(i=0;i<G.vexnum;i++)
	{
		printf("\n\t\t\t%d\t%10s\t%.1f\t%d\n\n",G.AdjList[i].data.Num,G.AdjList[i].data.Name,G.AdjList[i].data.Point,G.AdjList[i].data.Weeks);
	}
}


void FileCreate(ALGraph &G)
{
	FILE *fp;
	int i=0;
	int m,n,k,s1,s2;
	ArcNode *s;
	fp=fopen("entering.txt","a+");
	if((fp=fopen("entering.txt","a+"))==NULL)
	{
		printf(".......���ļ�ʧ��!");
		exit(0);
	}
	else
	{
	while(!feof(fp))
	{
		fscanf(fp,"%d%s%f%d",&G.AdjList[i].data.Num,&G.AdjList[i].data.Name,&G.AdjList[i].data.Point,&G.AdjList[i].data.Weeks);
		G.AdjList[i].firstarc=NULL;
		G.AdjList[i].data.marks=0;
		G.AdjList[i].data.term=0;
		G.AdjList[i].data.Outdegree=0;
		G.AdjList[i].data.Indegree=0;
		i++;
	}
	fclose(fp);
	G.vexnum=i;
	printf("\t\t\t\t��ȡ�γ���Ϣ�ɹ���\n\n");
	GhPrint(G);
	printf("\t\t\t������γ�ͼ�ı�����");
	scanf("%d",&G.arcnum);
	printf("\n\t\t\t�����붥���ϵ:(�γ̱��(��β) �γ̱��(��ͷ))\n");
	for(int j=1;j<=G.arcnum;j++)
	{
		printf("\t\t\t");
		scanf("%d",&s1);
		scanf("%d",&s2);
		if(s1==s2)
		{
			printf("\t\t\t.....���벻����! ���������룺\n");
			j--;
			continue;
		}
		else
		{
	    m=GLocateVex(G,s1);
	    n=GLocateVex(G,s2);
	    if(m==-1||n==-1)
		{
			printf("\t\t\t��ͼ��û���ҵ��ñ�ţ�����������:\n");
			j--;
			continue;
		}
		else
		{
		   s = (ArcNode*)malloc(sizeof(ArcNode));
	       if(!s)
		   {
		   	  printf("�������ʧ��!");
			  exit(0);
		   }
		    s->adjvex=n;
	        s->nextarc=G.AdjList[m].firstarc;
	        G.AdjList[m].firstarc=s;
			G.AdjList[m].data.Outdegree++;
	        G.AdjList[n].data.Indegree++;
        }
	   }
	}
	}
}

void CreateALGraph(ALGraph &G)
{
	int i,j,m,n,k,s1,s2;
    ArcNode *s;
	printf("�������������γ�ͼ�Ķ�������ͱ�����");
	scanf("%d %d",&i,&j);
	G.vexnum=i;
	G.arcnum=j;
	printf("\n�����붥�����Ϣ˳������:\n");
	printf("\n�γ̱�� �γ����� ѧ�� ����\n");
	for(i=0;i<G.vexnum;i++)
	{
		scanf("%d%s%f%d",&G.AdjList[i].data.Num,&G.AdjList[i].data.Name,&G.AdjList[i].data.Point,&G.AdjList[i].data.Weeks);
		G.AdjList[i].firstarc=NULL;
		G.AdjList[i].data.marks=0;
		G.AdjList[i].data.term=0;
		G.AdjList[i].data.Outdegree=0;
		G.AdjList[i].data.Indegree=0;
	}
	printf("\n�����붥���ϵ:(�γ̱��(��β) �γ̱��(��ͷ))\n");
	for(j=1;j<=G.arcnum;j++)
	{
		scanf("%d",&s1);
		scanf("%d",&s2);
		if(s1==s2)
		{
			printf("���벻�������������룺\n");
			j--;
			continue;
		}
		else
		{
	    m=GLocateVex(G,s1);
	    n=GLocateVex(G,s2);
	    if(m==-1||n==-1)
		{
			printf("��ͼ��û���ҵ��ñ�ţ�����������:\n");
			j--;
			continue;
		}
		else
		{
		   s = (ArcNode*)malloc(sizeof(ArcNode));
	       if(!s)
		   {
		   	  printf("�������ʧ��!");
			  exit(0);
		   }
		    s->adjvex=n;
	        s->nextarc=G.AdjList[m].firstarc;
	        G.AdjList[m].firstarc=s;
			G.AdjList[m].data.Outdegree++;
	        G.AdjList[n].data.Indegree++;
        }
		}
	}
//	printf("�����ɹ�!\n");
}

#endif // HEAD_H_INCLUDED
