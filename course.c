#include<stdio.h>
#include<stdlib.h> 
#include<string.h>

struct student
{
	int rollnumber;
	char *name;
	char *email;
};
struct course
{
	int courseno;
	int strength;
	struct student **stud;//dynamic array 
	//struct course *next;
};
//struct course *temp=NULL;
struct course c[20];

//struct course *head=NULL;
void allocatemem()
{
	//head=temp;
	
	for (int i=1;i<=20;i++)
	{
		int st;
		printf("enter the strength of course1  ");
		scanf("%d\n",st);
	   c[i].stud=malloc(sizeof(struct student*)*st);
	   for(int j=1;j<=st;j++)
	   {
	     c[i].stud[j]=malloc(sizeof(struct student));
	   }
		//temp=(struct course*)malloc(sizeof(struct course));
		//temp=temp->next;

  
	}
}
/*void deallocmem()
{
	for(int i=0;i<20;i++)
	{
	//temp=head;
	free(c[i]);
	//head=head->next;
	}

}*/
void readfromfile()
{
	FILE *fp;
	char *str;
	char line[60];
	char filename[25];
	for(int i=1;i<=20;i++)
	{
		sprintf(filename, "%s%d%s","course",i,".txt");
		printf("\n\n%s\n",filename);
		fp=fopen(filename,"r");

		if(fp!=NULL)
		{
		 // temp=head;
		  if(fgets(line,60,fp))// && temp!=NULL)
		  {
			  puts(line);
		  str=strtok(line,",");
		  c[i].courseno=atoi(str);
		  printf("%d \n",c[i].courseno);
		  str=strtok(0,",");
		  c[i].strength=atoi(str);
		  printf("%d\n",c[i].strength);
		  for(int j=1;j<=c[i].strength;j++)
		  {
		  str=strtok(0,",");
		  c[i].stud[j]->rollnumber=atoi(str);
		  printf("%d\n",c[i].stud[j]->rollnumber);
		  str=strtok(0,",");
		  c[i].stud[j]->name=str;
		  printf("%s\n",c[i].stud[j]->name);
		  str=strtok(0,",");
		  c[i].stud[j]->email=str;
		  printf("%s\n",c[i].stud[j]->email);
		 
		  }//end of for
		  printf(" END OF COURSE %d DETAILS",i);
		  //temp=temp->next;
		  }//end of if2
		  else{
		  printf("couldnt read line");
		  }

		}//end of if1
		else{
		perror("Error");
		}

	}


}
void main()
{
allocatemem();
readfromfile();
//deallocmem();

}