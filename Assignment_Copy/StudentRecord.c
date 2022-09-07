/* Student Record */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 3

typedef struct StudentRecord
{
    char name[50];
    int roll;
    char addr[50];
    int marks[5];
    int total;
    float avg;
    char grade;
} std;

void maxmarks(std[], int); // done
void grade(std[], int);

void maxEachSub(std[], int);
void sortData();

void maxEachSub(std s[], int size)
{
}
void grade(std s[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (s[i].avg < 0 || s[i].avg > 100)
        {
            printf("Wrong Entry");
        }
        else if (s[i].avg < 40)
        {
            s[i].grade = 'F';
        }
        else if (s[i].avg >= 40 && s[i].avg <= 49)
        {
            s[i].grade = 'D';
        }
        else if (s[i].avg >= 50 && s[i].avg <= 59)
        {
            s[i].grade = 'C';
        }
        else if (s[i].avg >= 60 && s[i].avg <= 69)
        {
            s[i].grade = 'B';
        }
        else if (s[i].avg >= 70 && s[i].avg <= 79)
        {
            s[i].grade = 'A';
        }
        else if (s[i].avg >= 80 && s[i].avg <= 89)
        {
            s[i].grade = 'E';
        }
        else
        {
            s[i].grade = 'O';
        }
    }
}
void maxmarks(std st[], int size)
{
    int i, j, max, sn = 0;
    std s1[n];
    max = st[0].avg;

    for (i = 0; i < size; i++)
    {
        if (st[i].avg > max)
        {
            max = st[i].avg;
            sn = i;
        }
    }
    printf("\nMaximum Marks Holder is: \n"); // Q1. Max Marks holder & Full Details(OK)

    printf("Name: %s\n", st[sn].name);
    printf("Roll: %d\n", st[sn].roll);
    printf("Address: %s\n", st[sn].addr);
    printf("Total Marks: %d\n", st[sn].total);
    printf("Average Marks: %.2f\% \n", st[sn].avg);
    grade(st, size);
    printf("Grade: %c\n", st[sn].grade);
}

int main()
{
    std s[n];
    int i, j, tempsum = 0;

    printf("Enter the record of %d student: ", n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter details of Student %d\n", (i + 1));

        printf("Name: ");
        gets(s[i].name);

        printf("\nAddress: ");
        gets(s[i].addr);

        printf("\nRoll Number: ");
        scanf("%d", &s[i].roll);

        printf("Marks in 5 Subjects \n");
        for (j = 0; j < 5; j++)
        {
            if (j == 0)
            {
                printf("DSA: ");
                scanf("%d", &s[i].marks[j]);
            }
            else if (j == 1)
            {
                printf("Java: ");
                scanf("%d", &s[i].marks[j]);
            }
            else if (j == 2)
            {
                printf("OS: ");
                scanf("%d", &s[i].marks[j]);
            }
            else if (j == 3)
            {

                printf("Value & Ethics: ");
                scanf("%d", &s[i].marks[j]);
            }
            else if (j == 4)
            {
                printf("Maths: ");
                scanf("%d", &s[i].marks[j]);
            }
        }
        getchar(); // clearing the buffer
    }
    for (i = 0; i < n; i++) // Total Marks of Each students
    {
        tempsum = 0;
        for (j = 0; j < 5; j++)
        {
            tempsum = tempsum + s[i].marks[j];
        }
        s[i].total = tempsum;
        s[i].avg = (float)(s[i].total / 5);
    }

    maxmarks(s, n); // structure to function call
    maxEachSub(s, n);

    return 0;
}
