#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 20

struct student
{
    int id;
    char name[50];
    float marks;
};

struct student stu[MAX];
int choice,count = 0;

int main(){


while(1)
{
    printf("Enter 1 to add \n");
    printf("Enter 2 to display \n");
    printf("Enter 3 to search \n");
    printf("Enter 4 to exit \n");

    printf("Enter your choice:");
    scanf("%d",&choice);

    if (choice==1)
    {
        printf("Enter student id:");
        scanf("%d",&stu[count].id);
        printf("Enter student name:");
        scanf("%s",stu[count].name);
        printf("Enter student marks:");
        scanf("%f",&stu[count].marks);
        count++;
        printf("Student added successfully!\n");
    }
    else if (choice==2)
    {
        printf("Student Details:\n");
        for(int i=0;i<count;i++)
        {
            printf("ID: %d, Name: %s, Marks: %.2f\n",stu[i].id,stu[i].name,stu[i].marks);
        }
    }
    else if (choice==3)
    {
        int search_id, found = 0;
        printf("Enter student id to search:");
        scanf("%d",&search_id);
        for(int i=0;i<count;i++)
        {
            if(stu[i].id == search_id)
            {
                printf("Student Found: ID: %d, Name: %s, Marks: %.2f\n",stu[i].id,stu[i].name,stu[i].marks);
                found = 1;
                break;
            }
        }
        if(!found)
        {
            printf("Student with ID %d not found.\n", search_id);
        }
    }
    else if (choice==4)
    {
        printf("Exiting...\n");
        break;
    }    
    else
    {
        printf("Invalid choice! Exiting...\n");
        break;
    }
    
}

};