#include <stdio.h>
#include <stdlib.h>

struct TIME
{
    int hours, minute, second;
    struct TIME *next;
};

void display(struct TIME *t)
{
    printf("%d:%d:%d->%d:%d:%d", t->hours, t->minute, t->second, t->next->hours, t->next->minute, t->next->second);
}

int main()
{
    struct TIME *t1 = (struct TIME *)malloc(sizeof(struct TIME));
    struct TIME *t2 = (struct TIME *)malloc(sizeof(struct TIME));
    t1->hours = 10;
    t1->minute = 30;
    t1->second = 40;

    t2->hours = 11;
    t2->minute = 20;
    t2->second = 40;

    t1->next = t2;

    display(t1);
}