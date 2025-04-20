/*C program for student structure */

#include<stdio.h>
#include<stdlib.h>

struct student{
    char name[30];
    int regNo;
    int marks[3];
    int avgMarks;
};
struct student *std;
int n,i,j;

void read(int );
void display(int );
void bestOf2(int );

void read(int n)
{
    for(i=0;i<n;i++)
    {
        printf("Enter the name of Student %d\n",i+1);
        scanf("%s",(std+i)->name);
        printf("Enter the Registration number of student %d",i+1);
        scanf("%d",(std+i)->regNo);
        printf("Enter marks obtained by Student %d",i+1);
        for(j=0;j<n;j++)
        {
            printf("Enter marks obtained in Subject %d",i+1);
            scanf("%d",(std+j)->marks[j]);
        }
    }

}

void main()
{
    n=3;
    std=(struct student *)malloc(n*sizeof(struct student));

    read(n);
}