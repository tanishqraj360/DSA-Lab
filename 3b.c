#include <stdio.h>

struct Student
{
    char name[20];
    int usn;
    int marks[3];
    float average;
    float totalMarks;
};

void AverageAndTotal(struct Student *s)
{
    s->totalMarks = 0;
    for (int i = 0; i < 3; i++)
    {
        s->totalMarks += s->marks[i];
    }
    s->average = s->totalMarks / 3;
}

void display(struct Student s[], int n)
{
    printf("%-20s %-10s %-10s %-10s %-10s\n", "Name", "USN", "Subject 1", "Subject 2", "Subject 3");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (s[j].totalMarks < s[j + 1].totalMarks)
            {
                struct Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%-20s %-10d %-10d %-10d %-10d\n", s[i].name, s[i].usn, s[i].marks[0], s[i].marks[1], s[i].marks[2]);
    }
}

int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct Student s1[n];
    for (int i = 0; i < n; ++i)
    {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Enter name: ");
        scanf("%s", s1[i].name);
        printf("Enter USN: ");
        scanf("%d", &s1[i].usn);
        printf("Enter marks for Subject 1: ");
        scanf("%d", &s1[i].marks[0]);
        printf("Enter marks for Subject 2: ");
        scanf("%d", &s1[i].marks[1]);
        printf("Enter marks for Subject 3: ");
        scanf("%d", &s1[i].marks[2]);

        AverageAndTotal(&s1[i]);
    }
    display(s1, n);
    return 0;
}