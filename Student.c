#include<stdio.h>
#include<stdlib.h>

typedef struct student{
    char name[20];
    int marks[3];
    int regNo;
}Student;

Student *std;
int i,j;

void read(int n)
{
    std=(Student *)malloc(n*sizeof(Student));
    for(i=0;i<n;i++)
    {
        printf("Enter details of Student %d",(i+1));
        printf("\nName: ");
        scanf("%s",(std+i)->name);
        printf("RegNo: ");
        scanf("%d",&(std+i)->regNo);
        for(j=0;j<3;j++)
        {
            printf("\nEnter marks for subject %d: ",j+1);
            scanf("%d",&(std+i)->marks[j]);
        }
        printf("\n\n");
    }

}

void dispaly(int n)
{
    
    for(i=0;i<n;i++)
    {
        printf("Details of Student %d",(i+1));
        printf("\nName: ");
        printf("%s",(std+i)->name);
        printf("\nRegNo: ");
        printf("%d",(std+i)->regNo);
        for(j=0;j<3;j++)
        {
            printf("\nMarks for subject %d: ",j+1);
            printf("%d",(std+i)->marks[j]);
        }
        printf("\n\n");
    }

}

void average(int n)
{
    int sum,lowest;
    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=0;j<3;j++)
        {
            sum=sum+(std+i)->marks[j];
        }
        lowest=((std+i)->marks[0]<=(std+i)->marks[1])?((std+i)->marks[0]<=(std+i)->marks[2]?(std+i)->marks[0]:(std+i)->marks[2]):((std+i)->marks[1]<=(std+i)->marks[2]?(std+i)->marks[1]:(std+i)->marks[2]);

        sum=sum-lowest;
        printf("\nAvg Student %d: %.2f",i+1,(float)sum*0.5);
    }
}

void main()
{
    int ch,n;
    printf("Enter the total number of students: ");
    scanf("%d",&n);

    while(1)
    {
        printf("\n1.Read Data\n2.Display Data\n3.Average\n4.Exit\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:read(n);
                    break;

            case 2:dispaly(n);
                    break;

            case 3:average(n);
                    break;

            case 4:exit(0);

            default:printf("Invalid Choice!!");
            break;

        }
    }
}
