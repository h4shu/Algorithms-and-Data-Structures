#define BUFSIZE 256
#define SSIZE 1024
#define SNAME "stack"
#define NUMBER '9'
#include <stdio.h>
#include <ctype.h>
#include "stack.h"

int gettoken (int *v)
{
    static int nxtoken = 0;
    int t, n = 0;

    if (nxtoken) {
        t = nxtoken; nxtoken = 0;
    } else {
        while ((t=getchar()) != EOF && isspace(t));
        if (isdigit(t)) {
            do {
            n = 10*n + t - '0';
            } while ((t=getchar()) != EOF && isdigit(t));
            if (!isspace(t))
                nxtoken = t;
            t = NUMBER;
            *v = n;
        }
    }
    return t;
}

int main (void)
{
    struct stack *s;
    char buff[BUFSIZE];
    int t, v;

    s = newstack(SSIZE, SNAME);
    while ((t = gettoken(&v)) != EOF) {
        if (t != NUMBER) {
            v = pop(s);
            switch (t) {
                case '+': v = pop(s) + v; break;
                case '-': v = pop(s) - v; break;
                case '*': v = pop(s) * v; break;
                case '/':
                    if (v) {
                        v = pop(s) / v; break;
                    } else {
                        error_id("zero-divided\n", s->id);
                    }
                default:
                    error_id("illegal char.\n", s->id);
            }
        }
        push(v, s);
    }
    printf("result: %d\n", pop(s));
    if (!isempty(s))
        error_id("stack is not empty¥n", s->id);
}
