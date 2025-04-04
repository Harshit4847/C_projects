#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
    int roll_no;
    char name[50];
    int classs;
    int year;
    int totalno;
}s1;

int main()
{
    printf("Enter the students Roll no.:\n");
    scanf("%d", &s1.roll_no);
    printf("Enter the students Name:\n");
    scanf("%s", &s1.name);
    printf("Enter the students Class:\n");
    scanf("%d", &s1.classs);
    printf("Enter the students Year:\n");
    scanf("%d", &s1.year);
    printf("Enter the students Total Marks:\n");
    scanf("%d", &s1.totalno);

    printf("\n--- Student Details ---\n");
    printf("Roll No.: %d\n", s1.roll_no);
    printf("Name: %s\n", s1.name);
    printf("Class: %d\n", s1.classs);
    printf("Year: %d\n", s1.year);
    printf("Total Marks: %d\n", s1.totalno);
}
