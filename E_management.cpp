#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include <time.h>
#include<Windows.h>
#define Equip_Size  sizeof(Equip_node)
using namespace std;
typedef struct Date
{
	int year;
	int month;
	int day;
}Date;
typedef struct Equip_node
{
	char Equip_Id[10];        //�豸���
	char Equip_Name[10];      //�豸����
	char Equip_Code[10];      //�豸�ͺ�
	char Equip_Factory[10];   //��������
	Date Equip_Buydate;       //��������
	double Equip_price;       //����۸�
	Equip_node *next;   //ָ����һ�豸���
	Equip_node *last;   //ָ����һ�豸���
}*Node;
Node Equip_head,Equip_now;     //Equip_head,�豸��Ϣ����ͷ�ڵ㣬Equip_now��ǰϵͳ���¼����豸��Ϣ�ڵ�
FILE *fp;
//����¼����豸����ǰ¼����豸����
void Equip_Merge(Equip_node *p)
{
	Equip_now->next=p;
	p->last=Equip_now;
	Equip_now=p;
	p->next=NULL;
}
//�豸��Ϣ¼��
void Equip_Input()
{
	start:Node p=(Node)malloc(Equip_Size);
	Equip_Merge(p);
	p->next=NULL;
	printf("        ****************************************************************\n");
	printf("        *         **             �������豸���             **         *\n");
	printf("        ****************************************************************\n");
	printf("        ");
	scanf("%s",p->Equip_Id);
	printf("        ****************************************************************\n");
	printf("        *         **             �������豸����             **         *\n");
	printf("        ****************************************************************\n");
	printf("        ");
	scanf("%s",p->Equip_Name);
	printf("        ****************************************************************\n");
	printf("        *         **             �������豸�ͺ�             **         *\n");
	printf("        ****************************************************************\n");
	printf("        ");
	scanf("%s",p->Equip_Code);
	printf("        ****************************************************************\n");
	printf("        *         **             ��������������             **         *\n");
	printf("        ****************************************************************\n");
	printf("        ");
	scanf("%s",p->Equip_Factory);
	printf("        ****************************************************************\n");
	printf("        *         **       �����빺�����ڣ��� �� �գ�       **         *\n");
	printf("        *         **                �Կո����              **         *\n");
	printf("        ****************************************************************\n");
	printf("        ");
	scanf("%d %d %d",&p->Equip_Buydate.year,&p->Equip_Buydate.month,&p->Equip_Buydate.day);
	printf("        ****************************************************************\n");
	printf("        *         **             �����빺��۸�             **         *\n");
	printf("        ****************************************************************\n");
	printf("        ");
	scanf("%lf",&p->Equip_price);
	printf("        ****************************************************************\n");
	printf("        *         **      ��Ϣ¼����ɣ��Ƿ������һ��      **         *\n");
	printf("        *         **       ��       1    ��         0       **         *\n");
	printf("        ****************************************************************\n");
	printf("        ");
	int index;
	scanf("%d",&index);
	if(index==1)
		goto start;
}

//�豸��Ϣ�޸�
void Equip_Change()
{
	start:Node p=(Node)malloc(Equip_Size);
	bool find=false;
	printf("        ****************************************************************\n");
	printf("        *         **        ������Ҫ�޸ĵ��豸���          **         *\n");
	printf("        ****************************************************************\n");
	printf("        ");
	scanf("%s",p->Equip_Id);
	Node q=0;
	//����¼���豸��Ϣ������Ѱ��Ҫ�޸ĵ��豸��
	for(q=Equip_head->next;q;q=q->next)
	{
		if(!strcmp(p->Equip_Id,q->Equip_Id))
		{
			find=true;
			break;
		}
	}
	//����ҵ�������Ϣ�����޸ġ�
	if(find)
	{
		int choice;
		B:printf("        ****************************************************************\n");
		printf("        *         **          ������Ҫ�޸ĵ�����            **         *\n");
		printf("        ****************************************************************\n");
		printf("        *         **          ������Ҫ�޸ĵ�����            **         *\n");
		printf("        *         **          1         �豸����            **         *\n");
		printf("        *         **          2         �豸�ͺ�            **         *\n");
		printf("        *         **          3         ��������            **         *\n");
		printf("        *         **          4         ����۸�            **         *\n");
		printf("        ****************************************************************\n");
		printf("        *         **      ������޸����������Ӧ���        **         *\n");
		printf("        ****************************************************************\n");
		printf("        ");
		A:cin>>choice;
		switch(choice)
		{
			case 1:
			{
				printf("        ****************************************************************\n");
				printf("        *         **             ���������豸����           **         *\n");
				printf("        ****************************************************************\n");
				printf("        ");
				scanf("%s",p->Equip_Name);
				strcpy(q->Equip_Name,p->Equip_Name);
			}break;
			case 2:
			{
				printf("        ****************************************************************\n");
				printf("        *         **             ���������豸�ͺ�           **         *\n");
				printf("        ****************************************************************\n");
				printf("        ");
				scanf("%s",p->Equip_Code);
				strcpy(q->Equip_Code,p->Equip_Code);
			}break;
			case 3:
			{
				printf("        ****************************************************************\n");
				printf("        *         **             �������¹�������           **         *\n");
				printf("        ****************************************************************\n");
				printf("        ");
				scanf("%d %d %d",&p->Equip_Buydate.year,&p->Equip_Buydate.month,&p->Equip_Buydate.day);
				q->Equip_Buydate=p->Equip_Buydate;
			}break;
			case 4:
			{
				printf("        ****************************************************************\n");
				printf("        *         **             �������¹���۸�           **         *\n");
				printf("        ****************************************************************\n");
				printf("        ");
				scanf("%lf",&p->Equip_price);
				q->Equip_price=p->Equip_price;
			}break;
			default:
			{
				printf("        ****************************************************************\n");
				printf("        *         **        ��������������������        **         *\n");
				printf("        ****************************************************************\n");
				printf("        ");
				goto A;
			}
		}
		int index;
		printf("        ****************************************************************\n");
		printf("        *         **               �޸��Ƿ����             **         *\n");
		printf("        *         **             ��   1    ��   0           **         *\n");
		printf("        ****************************************************************\n");
		printf("        ");
		cin>>index;
		if(index)
			goto B;
		else
			free(p);
	}
	//���δ�ҵ��������ʾ��Ϣ�����ͷŵ�ǰ�������Ľ�㡣
	else
	{
		int choice=0;
		printf("        ****************************************************************\n");
		printf("        *         **             δ�ҵ�ƥ����豸           **         *\n");
		printf("        *         **           ��������  1    ����  0       **         *\n");
		printf("        ****************************************************************\n");
		printf("        ");
		free(p);
		cin>>choice;
		if(choice==1)
			goto start;
		else
			free(p);
	}
}

//�豸��Ϣɾ��
void Equip_Delete()
{
	start:Node p=(Node)malloc(Equip_Size);
	bool find=false;
	A:printf("        ****************************************************************\n");
	printf("        *         **        ������Ҫɾ�����豸���          **         *\n");
	printf("        ****************************************************************\n");
	printf("        ");
	scanf("%s",p->Equip_Id);
	Node q=0;
	//����¼���豸��Ϣ������Ѱ��Ҫɾ�����豸��
	for(q=Equip_head->next;q;q=q->next)
	{
		if(!strcmp(p->Equip_Id,q->Equip_Id))
		{
			find=true;
			break;
		}
	}
	if(find)
	{
		q->last->next=q->next;    //��Ҫɾ���豸����ǰһ���ĺ�̽��ָ��ָ��Ҫɾ���豸������һ���
		int index;
		printf("        ****************************************************************\n");
		printf("        *         **               ɾ���Ƿ����             **         *\n");
		printf("        *         **             ��   1    ��   0           **         *\n");
		printf("        ****************************************************************\n");
		printf("        ");
		cin>>index;
		if(index)
			goto A;
		else
			free(p);              //�ͷŵ�ǰ���ĵ�ַ

	}
	else
	{
		int choice=0;
		printf("        ****************************************************************\n");
		printf("        *         **             δ�ҵ�ƥ����豸           **         *\n");
		printf("        *         **           ��������  1    ����  0       **         *\n");
		printf("        ****************************************************************\n");
		printf("        ");
		free(p);
		cin>>choice;
		if(choice==1)
			goto start;
		else
			free(p);
	}
}

//�豸����
void Equip_Search()
{
	start:Node p=(Node)malloc(Equip_Size);
	bool find=false;
	A:printf("        ****************************************************************\n");
	printf("        *         **        ������Ҫ���ҵ��豸���          **         *\n");
	printf("        ****************************************************************\n");
	printf("        ");
	scanf("%s",p->Equip_Id);
	Node q=0;
	//����¼���豸��Ϣ������Ѱ��Ҫ���ҵ��豸��
	for(q=Equip_head->next;q;q=q->next)
	{
		if(!strcmp(p->Equip_Id,q->Equip_Id))
		{
			find=true;
			break;
		}
	}
	if(find)
	{
		printf("        ****************************************************************\n");
		printf("        *         ���: %-16s*       ����: %-17s*\n",q->Equip_Id,q->Equip_Name);
		printf("        *         �ͺ�: %-16s*       ����: %-17s*\n",q->Equip_Code,q->Equip_Factory);
		printf("        *         ����:  %4d��%2d��%2d�� *       �۸�: %-7.2lf          *\n",
			q->Equip_Buydate.year,q->Equip_Buydate.month,q->Equip_Buydate.day,q->Equip_price);
		printf("        ****************************************************************\n");
		fp=fopen("myfile.txt","r");
		if(fp!=NULL)
		{
			Node t=(Node)malloc(Equip_Size);
			char time[20];
			bool flage=false;
			while(!feof(fp))
			{
				fscanf(fp,"%s",t->Equip_Id);
				fscanf(fp,"%s",t->Equip_Name);
				fscanf(fp,"%s",t->Equip_Code);
				fscanf(fp,"%s",t->Equip_Factory);
				fscanf(fp,"%d/%d/%d",&t->Equip_Buydate.year,&t->Equip_Buydate.month,&t->Equip_Buydate.day);
				fscanf(fp,"%s",time);
				if(!strcmp(q->Equip_Id,t->Equip_Id))
				{
					printf("        *         **      ά��ʱ��:%-19s      **         *\n",time);
					flage=true;
				}
			}
			free(t);
			printf("        ****************************************************************\n");
		}
		else
		{
			printf("        *         **          ���豸û��ά�޼�¼            **         *\n");
			printf("        ****************************************************************\n");
		}
		int index;
		printf("        ****************************************************************\n");
		printf("        *         **               �����Ƿ����             **         *\n");
		printf("        *         **             ��   1    ��   0           **         *\n");
		printf("        ****************************************************************\n");
		printf("        ");
		cin>>index;
		if(index)
			goto A;
		else
			free(p);
	}
	else
	{
		int choice;
		printf("        ****************************************************************\n");
		printf("        *         **       δ�ҵ�ƥ���豸���Ƿ���������      **        *\n");
		printf("        *         **            ��   1        ��   0         **        *\n");
		printf("        ****************************************************************\n");
		printf("        ");
		cin>>choice;
		if(choice)
			goto A;
		else
			free(p);
	}
}

//ά�޼�¼
void Maintenance_records()
{
	start:Node p=(Node)malloc(Equip_Size);
	bool find=false;
	A:printf("        ****************************************************************\n");
	printf("        *         **        ������Ҫά�޵��豸���          **         *\n");
	printf("        ****************************************************************\n");
	printf("        ");
	scanf("%s",p->Equip_Id);
	Node q=0;
	//����¼���豸��Ϣ������Ѱ��Ҫά�޵��豸��
	for(q=Equip_head->next;q;q=q->next)
	{
		if(!strcmp(p->Equip_Id,q->Equip_Id))
		{
			find=true;
			break;
		}
	}
	if(find)
	{
		int i=0;
		if((fp=fopen("myfile.txt","a"))==NULL)
			fp=fopen("myfile.txt","w");
		if(fp!=NULL)
		{
			fprintf(fp,"\n%s\n",q->Equip_Id);
			fprintf(fp,"%s\n",q->Equip_Name);
			fprintf(fp,"%s\n",q->Equip_Code);
			fprintf(fp,"%s\n",q->Equip_Factory);
			fprintf(fp,"%d/%d/%d\n",q->Equip_Buydate.year,q->Equip_Buydate.month,q->Equip_Buydate.day);
			time_t t;
			struct tm * lt;
			time (&t);//��ȡUnixʱ�����
			lt = localtime (&t);//תΪʱ��ṹ��
			fprintf (fp,"%d/%d/%d-%d:%d:%d",lt->tm_year+1900,lt->tm_mon+1,lt->tm_mday,lt->tm_hour,lt->tm_min,lt->tm_sec);//������
			fclose(fp);
		}
		int index;
		printf("        ****************************************************************\n");
		printf("        *         **    ά�޳ɹ������Ƿ�������豸����ά��   **        *\n");
		printf("        *         **            ��   1        ��   0         **        *\n");
		printf("        ****************************************************************\n");
		printf("        ");
		cin>>index;
		if(index)
			goto A;
		else
			free(p);
	}
	else
	{
		int choice;
		printf("        ****************************************************************\n");
		printf("        *         **       δ�ҵ�ƥ���豸���Ƿ���������      **        *\n");
		printf("        *         **            ��   1        ��   0         **        *\n");
		printf("        ****************************************************************\n");
		printf("        ");
		cin>>choice;
		if(choice)
			goto A;
		else
			free(p);
	}
}

//�˵�
void menu()
{
	int choice,index;
	printf("\n");
	printf("\n");
	A:printf("        ****************************************************************\n");
	printf("        *                     ��ӭʹ��ʵ���豸����ϵͳ                 *\n");
	printf("        ****************************************************************\n");
	printf("\n");
	printf("\n");
	printf("        ****************************************************************\n");
	printf("        *                       ʵ���豸����ϵͳ�˵�                   *\n");
	printf("        ****************************************************************\n");
	printf("        *         **         1        �豸��Ϣ¼��          **         *\n");
	printf("        *         **         2        �豸��Ϣ�޸�          **         *\n");
	printf("        *         **         3        �豸��Ϣɾ��          **         *\n");
	printf("        *         **         4          �豸����            **         *\n");
	printf("        *         **         5          ά�޼�¼            **         *\n");
	printf("        *         **         0            �˳�              **         *\n");
	printf("        ****************************************************************\n");
	printf("        *         **        ��������ѡ���ܶ�Ӧ�ı��        **         *\n");
	printf("        ****************************************************************\n");
	printf("        ");
	start:scanf("%d",&choice);
	switch(choice)
	{
		case 1:Equip_Input();break;
		case 2:Equip_Change();break;
		case 3:Equip_Delete();break;
		case 4:Equip_Search();break;
		case 5:Maintenance_records();break;
		case 0:
			{
				printf("        ****************************************************************\n");
				printf("        *         **            ϵͳ����3����˳�           **         *\n");
				printf("        ****************************************************************\n");
				printf("        ");
				Sleep(3000);
				exit(0);
			}break;
		default:
			{
				printf("        ****************************************************************\n");
				printf("        *         **        ��������������������        **         *\n");
				printf("        ****************************************************************\n");
				printf("        ");
				goto start;
			}
	}
	printf("        ****************************************************************\n");
	printf("        *         **              ��ǰ�����ɹ�              **         *\n");
	printf("        *         **            �Ƿ������������            **         *\n");
	printf("        *         **            ��  1      ��  0            **         *\n");
	printf("        ****************************************************************\n");
	printf("        ");
	scanf("%d",&index);
	if(index)
		goto A;
	else
	{
		printf("        ****************************************************************\n");
		printf("        *         **            ϵͳ����3����˳�           **         *\n");
		printf("        ****************************************************************\n");
		printf("        ");
		Sleep(3000);
		exit(0);
	}
}
int main()
{
	Equip_head=Equip_now=(Node)malloc(Equip_Size);
	Equip_head->next=Equip_head->last=NULL;
	menu();
	system("pause");
	return 0;
}
