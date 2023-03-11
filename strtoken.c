#include<stdio.h>
#include<string.h>
struct student{
	int roll;
	char *name;
	char *mail;
};

void main()
{
	
int val;
char *t;
char line[60];
struct student s1;
char filename[25];
int counter=0;
//LOOK INTO THE ISSUE
FILE *fp;
for(int i=1;i<=3;i++)
	{
		sprintf(filename,"%s%d%s","course",i,".txt");
printf("filename : %s\n",filename);
printf("i :%d\n",i);

	//C:\\Users\\Maithri.R\\OneDrive - Indian Institute of Technology Guwahati\\Desktop\\GAYATHRI IITG STUFF\\comprehensive\\practice c\\c[i].txt"
fp=fopen(filename,"r");


if(fp!=NULL)//file opened successfully
{
	printf("hi opened");
if(fgets(line,60,fp)!=NULL)//READ FROM FILE
{
	puts(line);
t=strtok(line,",");
val=atoi(t);
s1.roll=val;
printf("%d\n",s1.roll);
t=strtok(0,",");
s1.name=t;
printf("%s\n",s1.name);
t=strtok(0,",");
s1.mail=t;
printf("%s\n",s1.mail);
	}
	else{
	printf("couldnt read file\n");
	}	
}
else
{
	
	perror("Error");
}
fclose(fp);
}
}