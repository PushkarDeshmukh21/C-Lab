#include<stdio.h>
#include<stdlib.h>

typedef struct Time{
    int hour;
    int minute;
    int second;
}time;

time *T1,*T2;
time *read(time *tim){
    printf("Enter time in format HH:MM:SS : ");
    scanf("%d%d%d",&tim->hour,&tim->minute,&tim->second);
}


void display(time *tim){
    printf("Current time is - ");
    printf("%d:%d:%d",tim->hour,tim->minute,tim->second);
}

time *update(time *tim){
    if(tim->second==59){
        tim->minute+=1;
        tim->second=00;
        if(tim->minute==60){
            tim->hour+=1;
            tim->minute=00;
            if(tim->hour==24){
                tim->hour=00;

            }
        }
    }
    else{
    tim->second+=1;        
    }
    display(tim);
    return tim;
    
}

time *ADD(time *T1,time *T2){
    if(T1->second+T2->second>=60){
        T1->minute=T1->minute+(T1->second+T2->second)/60;
        T1->second=(T1->second+T2->second)%60;
        
    }
    else{
    T1->second=T1->second+T2->second;
    }
    if(T1->minute+T2->minute>=60){
        T1->hour=T1->hour+(T1->minute+T2->minute)/60;
        T1->minute=(T1->minute+T2->minute)%60;
        
    }
    else{
    T1->minute=T1->minute+T2->minute;
    }
    if (T1->hour+T2->hour>=24)
    {
        T1->hour=(T1->hour+T2->hour)%24;
    }
    else{
    T1->hour=T1->hour+T2->hour;
    }
    return T1;
    
}

void main(){
    int choice;
    T1=(time *)malloc(sizeof(time));
    T2=(time *)malloc(sizeof(time));

    
  
    while(1){
         printf("\n1.Read\n2.Display\n3.Update\n4.ADD time\n5.exit\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);

    switch (choice){
        case 1:read(T1);
                printf("\n");
                read(T2);
                break;

        case 2:display(T1);
                printf("\n");
                display(T2);
                break;
        case 3:printf("Updated time T1 is\n");
                update(T1);
                printf("\nUpdated time T2 is\n");
                update(T2);
                break;
        case 4:ADD(T1,T2);
                printf("Added time T1 and T2 is\n");
                display(T1);
                break;
        case 5:
        exit(0);
        default:printf("Invalid choice");
    }
    }

    }


