#include<stdio.h>
#include<string.h>
int max=0;
int findfather(char list[10],int index)//-1 error
{
	index/=2;
	if(list[index]==0)
		return -1;
	return 1;
}
int repeat(char list[10],char index)//-1 error
{
for(int i=0;i<=max;i++)
	if(list[i]==index)
		return -1;
	return 1;
}
void printfall (char list[10])
{
	for(int i=0;i<=max;i++)
	{
		if(list[i]!=0)
			printf("%d:%c\t",i,list[i]);
	}
	printf("\n");
}
int main ()
{
	int opt,index,det,temp;
	char list[100],find[1],newdata[1];
	for(int i=0;i<100;i++)
	list[i]=0;
	while(1)
	{
		det=0;
	printf("(1)insert(2)delete(3)find patert (4)find child(-1)exit");
	scanf("%d",&opt);
	if(opt==-1)
		break;
	if(opt==1)
	{
		printf("index:");
		scanf("%d",&index);
		if(index>max+1)
			printf("full!can't insert!\n");
		else
		{
		if(index>=2&&findfather( list,index)==-1)
			printf("no parent !can't insert!\n");
		else
		{
			printf("data:");
			scanf("%s",newdata);
			if(repeat(list,newdata[0])==-1)
				printf("­«´_!can't insert!\n");
			else
			{
				temp=max;
				if(list[index]!=0)
				{
					temp++;
					for(temp;temp>=index;temp--)
					{
						list[temp]=list[temp-1];
					}
				}
			list[index]=newdata[0];		
			}
		}//data
		}//father
		max=max+1;
		printfall (list);
	}//opt1
	if(opt==2)
	{
		printf("data:");
		scanf("%s",find);
		for(int y=1;y<=max;y++)
		{
			if(find[0]==list[y])
				det=y;
		}
		if (det==0)
			printf("no that data!!\n");
		else
		{
		for(det;det<=max;det++)
		{
			list[det]=list[det+1];
		}//²¾¦ì
		max--;
			printfall (list);
		}
	}//opt2
	if(opt==3)
	{
		printf("data:");
		scanf("%s",find);
		for(int y=1;y<=max;y++)
		{
			if(find[0]==list[y])
				det=y;
		}
		if(det==1)
			printf("this data is root!");
		else
		{
			det=det/2;
			printf("%c\n",list[det]);
		}
	}//opt3
	if(opt==4)
	{
		printf("data:");
		scanf("%s",find);
		for(int y=1;y<=max;y++)
		{
			if(find[0]==list[y])
				det=y;
		}
		if(list[det*2]==0&&list[det*2+1]==0)
			printf("this data don't have child\n");
		else
		{
			printf("left child:%c\tright child:%c\n",list[2*det],list[2*det+1]);
		}
	}
	}//while
		return 0;
}

//strcmp(,)==0 same