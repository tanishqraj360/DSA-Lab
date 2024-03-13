#include <stdio.h>
#include <ctype.h>
#define SIZE 50

char stack[SIZE];
int top = -1;

void push(char elem)
{
    stack[++top] = elem;
}

char pop()
{
    return stack[top--];
}

int pr(char elem)
{
    switch (elem)
    {
    case '(':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
    case '%':
        return 3;
    case '^':
        return 4;
    }
}

int main()
{
    char infix[SIZE], postfix[SIZE], ch, elem;
    printf("Enter infix expression: ");
    scanf("%s", infix);
    int i = 0, k = 0;
    push('(');
    while ((ch = infix[i++]) != '\0')
    {
        if (ch == '(')
        {
            push(ch);
        }
        else if (isalnum(ch))
        {
            postfix[k++] = ch;
        }
        else if (ch == ')')
        {
            while (stack[top] != '(')
            {
                postfix[k++] = pop();
            }
            pop();
        }
        else
        {
            while (pr(stack[top]) >= pr(ch))
            {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }
    while (stack[top] != '(')
    {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
    printf("Postfix Expression: %s", postfix);
}