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
	char Equip_Id[10];        //设备编号
	char Equip_Name[10];      //设备名称
	char Equip_Code[10];      //设备型号
	char Equip_Factory[10];   //生产厂家
	Date Equip_Buydate;       //购买日期
	double Equip_price;       //购买价格
	Equip_node *next;   //指向下一设备结点
	Equip_node *last;   //指向上一设备结点
}*Node;
Node Equip_head,Equip_now;     //Equip_head,设备信息链表头节点，Equip_now当前系统最后录入的设备信息节点
FILE *fp;
//将新录入的设备与先前录入的设备连接
void Equip_Merge(Equip_node *p)
{
	Equip_now->next=p;
	p->last=Equip_now;
	Equip_now=p;
	p->next=NULL;
}
//设备信息录入
void Equip_Input()
{
	start:Node p=(Node)malloc(Equip_Size);
	Equip_Merge(p);
	p->next=NULL;
	printf("        ****************************************************************\n");
	printf("        *         **             请输入设备编号             **         *\n");
	printf("        ****************************************************************\n");
	printf("        ");
	scanf("%s",p->Equip_Id);
	printf("        ****************************************************************\n");
	printf("        *         **             请输入设备名称             **         *\n");
	printf("        ****************************************************************\n");
	printf("        ");
	scanf("%s",p->Equip_Name);
	printf("        ****************************************************************\n");
	printf("        *         **             请输入设备型号             **         *\n");
	printf("        ****************************************************************\n");
	printf("        ");
	scanf("%s",p->Equip_Code);
	printf("        ****************************************************************\n");
	printf("        *         **             请输入生产厂家             **         *\n");
	printf("        ****************************************************************\n");
	printf("        ");
	scanf("%s",p->Equip_Factory);
	printf("        ****************************************************************\n");
	printf("        *         **       请输入购买日期（年 月 日）       **         *\n");
	printf("        *         **                以空格隔开              **         *\n");
	printf("        ****************************************************************\n");
	printf("        ");
	scanf("%d %d %d",&p->Equip_Buydate.year,&p->Equip_Buydate.month,&p->Equip_Buydate.day);
	printf("        ****************************************************************\n");
	printf("        *         **             请输入购买价格             **         *\n");
	printf("        ****************************************************************\n");
	printf("        ");
	scanf("%lf",&p->Equip_price);
	printf("        ****************************************************************\n");
	printf("        *         **      信息录入完成，是否进行下一条      **         *\n");
	printf("        *         **       是       1    否         0       **         *\n");
	printf("        ****************************************************************\n");
	printf("        ");
	int index;
	scanf("%d",&index);
	if(index==1)
		goto start;
}

//设备信息修改
void Equip_Change()
{
	start:Node p=(Node)malloc(Equip_Size);
	bool find=false;
	printf("        ****************************************************************\n");
	printf("        *         **        请输入要修改的设备编号          **         *\n");
	printf("        ****************************************************************\n");
	printf("        ");
	scanf("%s",p->Equip_Id);
	Node q=0;
	//在已录入设备信息链表中寻找要修改的设备。
	for(q=Equip_head->next;q;q=q->next)
	{
		if(!strcmp(p->Equip_Id,q->Equip_Id))
		{
			find=true;
			break;
		}
	}
	//如果找到，对信息进行修改。
	if(find)
	{
		int choice;
		B:printf("        ****************************************************************\n");
		printf("        *         **          请输入要修改的内容            **         *\n");
		printf("        ****************************************************************\n");
		printf("        *         **          请输入要修改的内容            **         *\n");
		printf("        *         **          1         设备名称            **         *\n");
		printf("        *         **          2         设备型号            **         *\n");
		printf("        *         **          3         购买日期            **         *\n");
		printf("        *         **          4         购买价格            **         *\n");
		printf("        ****************************************************************\n");
		printf("        *         **      请根据修改内容输入对应编号        **         *\n");
		printf("        ****************************************************************\n");
		printf("        ");
		A:cin>>choice;
		switch(choice)
		{
			case 1:
			{
				printf("        ****************************************************************\n");
				printf("        *         **             请输入新设备名称           **         *\n");
				printf("        ****************************************************************\n");
				printf("        ");
				scanf("%s",p->Equip_Name);
				strcpy(q->Equip_Name,p->Equip_Name);
			}break;
			case 2:
			{
				printf("        ****************************************************************\n");
				printf("        *         **             请输入新设备型号           **         *\n");
				printf("        ****************************************************************\n");
				printf("        ");
				scanf("%s",p->Equip_Code);
				strcpy(q->Equip_Code,p->Equip_Code);
			}break;
			case 3:
			{
				printf("        ****************************************************************\n");
				printf("        *         **             请输入新购买日期           **         *\n");
				printf("        ****************************************************************\n");
				printf("        ");
				scanf("%d %d %d",&p->Equip_Buydate.year,&p->Equip_Buydate.month,&p->Equip_Buydate.day);
				q->Equip_Buydate=p->Equip_Buydate;
			}break;
			case 4:
			{
				printf("        ****************************************************************\n");
				printf("        *         **             请输入新购买价格           **         *\n");
				printf("        ****************************************************************\n");
				printf("        ");
				scanf("%lf",&p->Equip_price);
				q->Equip_price=p->Equip_price;
			}break;
			default:
			{
				printf("        ****************************************************************\n");
				printf("        *         **        编号输入错误，请重新输入        **         *\n");
				printf("        ****************************************************************\n");
				printf("        ");
				goto A;
			}
		}
		int index;
		printf("        ****************************************************************\n");
		printf("        *         **               修改是否继续             **         *\n");
		printf("        *         **             是   1    否   0           **         *\n");
		printf("        ****************************************************************\n");
		printf("        ");
		cin>>index;
		if(index)
			goto B;
		else
			free(p);
	}
	//如果未找到，输出提示信息，并释放当前输入错误的结点。
	else
	{
		int choice=0;
		printf("        ****************************************************************\n");
		printf("        *         **             未找到匹配的设备           **         *\n");
		printf("        *         **           重新输入  1    返回  0       **         *\n");
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

//设备信息删除
void Equip_Delete()
{
	start:Node p=(Node)malloc(Equip_Size);
	bool find=false;
	A:printf("        ****************************************************************\n");
	printf("        *         **        请输入要删除的设备编号          **         *\n");
	printf("        ****************************************************************\n");
	printf("        ");
	scanf("%s",p->Equip_Id);
	Node q=0;
	//在已录入设备信息链表中寻找要删除的设备。
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
		q->last->next=q->next;    //将要删除设备结点的前一结点的后继结点指针指向要删除设备结点的下一结点
		int index;
		printf("        ****************************************************************\n");
		printf("        *         **               删除是否继续             **         *\n");
		printf("        *         **             是   1    否   0           **         *\n");
		printf("        ****************************************************************\n");
		printf("        ");
		cin>>index;
		if(index)
			goto A;
		else
			free(p);              //释放当前结点的地址

	}
	else
	{
		int choice=0;
		printf("        ****************************************************************\n");
		printf("        *         **             未找到匹配的设备           **         *\n");
		printf("        *         **           重新输入  1    返回  0       **         *\n");
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

//设备查找
void Equip_Search()
{
	start:Node p=(Node)malloc(Equip_Size);
	bool find=false;
	A:printf("        ****************************************************************\n");
	printf("        *         **        请输入要查找的设备编号          **         *\n");
	printf("        ****************************************************************\n");
	printf("        ");
	scanf("%s",p->Equip_Id);
	Node q=0;
	//在已录入设备信息链表中寻找要查找的设备。
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
		printf("        *         编号: %-16s*       名称: %-17s*\n",q->Equip_Id,q->Equip_Name);
		printf("        *         型号: %-16s*       厂家: %-17s*\n",q->Equip_Code,q->Equip_Factory);
		printf("        *         日期:  %4d年%2d月%2d日 *       价格: %-7.2lf          *\n",
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
					printf("        *         **      维修时间:%-19s      **         *\n",time);
					flage=true;
				}
			}
			free(t);
			printf("        ****************************************************************\n");
		}
		else
		{
			printf("        *         **          该设备没有维修记录            **         *\n");
			printf("        ****************************************************************\n");
		}
		int index;
		printf("        ****************************************************************\n");
		printf("        *         **               查找是否继续             **         *\n");
		printf("        *         **             是   1    否   0           **         *\n");
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
		printf("        *         **       未找到匹配设备，是否重新输入      **        *\n");
		printf("        *         **            是   1        否   0         **        *\n");
		printf("        ****************************************************************\n");
		printf("        ");
		cin>>choice;
		if(choice)
			goto A;
		else
			free(p);
	}
}

//维修记录
void Maintenance_records()
{
	start:Node p=(Node)malloc(Equip_Size);
	bool find=false;
	A:printf("        ****************************************************************\n");
	printf("        *         **        请输入要维修的设备编号          **         *\n");
	printf("        ****************************************************************\n");
	printf("        ");
	scanf("%s",p->Equip_Id);
	Node q=0;
	//在已录入设备信息链表中寻找要维修的设备。
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
			time (&t);//获取Unix时间戳。
			lt = localtime (&t);//转为时间结构。
			fprintf (fp,"%d/%d/%d-%d:%d:%d",lt->tm_year+1900,lt->tm_mon+1,lt->tm_mday,lt->tm_hour,lt->tm_min,lt->tm_sec);//输出结果
			fclose(fp);
		}
		int index;
		printf("        ****************************************************************\n");
		printf("        *         **    维修成功，，是否对其他设备进行维修   **        *\n");
		printf("        *         **            是   1        否   0         **        *\n");
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
		printf("        *         **       未找到匹配设备，是否重新输入      **        *\n");
		printf("        *         **            是   1        否   0         **        *\n");
		printf("        ****************************************************************\n");
		printf("        ");
		cin>>choice;
		if(choice)
			goto A;
		else
			free(p);
	}
}

//菜单
void menu()
{
	int choice,index;
	printf("\n");
	printf("\n");
	A:printf("        ****************************************************************\n");
	printf("        *                     欢迎使用实验设备管理系统                 *\n");
	printf("        ****************************************************************\n");
	printf("\n");
	printf("\n");
	printf("        ****************************************************************\n");
	printf("        *                       实验设备管理系统菜单                   *\n");
	printf("        ****************************************************************\n");
	printf("        *         **         1        设备信息录入          **         *\n");
	printf("        *         **         2        设备信息修改          **         *\n");
	printf("        *         **         3        设备信息删除          **         *\n");
	printf("        *         **         4          设备查找            **         *\n");
	printf("        *         **         5          维修记录            **         *\n");
	printf("        *         **         0            退出              **         *\n");
	printf("        ****************************************************************\n");
	printf("        *         **        请输入所选功能对应的编号        **         *\n");
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
				printf("        *         **            系统将在3秒后退出           **         *\n");
				printf("        ****************************************************************\n");
				printf("        ");
				Sleep(3000);
				exit(0);
			}break;
		default:
			{
				printf("        ****************************************************************\n");
				printf("        *         **        编号输入错误，请重新输入        **         *\n");
				printf("        ****************************************************************\n");
				printf("        ");
				goto start;
			}
	}
	printf("        ****************************************************************\n");
	printf("        *         **              当前操作成功              **         *\n");
	printf("        *         **            是否进行其他操作            **         *\n");
	printf("        *         **            是  1      否  0            **         *\n");
	printf("        ****************************************************************\n");
	printf("        ");
	scanf("%d",&index);
	if(index)
		goto A;
	else
	{
		printf("        ****************************************************************\n");
		printf("        *         **            系统将在3秒后退出           **         *\n");
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
