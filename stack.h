#include <stdlib.h>

struct stack {
    int*bd; /* stack body */
    int pt; /* stack pointer */
    int mx; /* stack body size */
    char *id; /* stack identifier */
};

void error_id (char *frm, char *id)
{
    fprintf(stderr, frm, id);
    exit(1);
}

struct stack *newstack (int maxsize, char *name)
{
    struct stack *s;
    
    if ((s = (struct stack *)malloc(sizeof(struct stack))) == NULL)
        error_id("malloc for %s\n", name);
    if ((s->bd = (int *)malloc(maxsize * sizeof(int))) == NULL)
        error_id("malloc for %s's body\n", name);
    s->pt = -1;
    s->mx = maxsize;
    s->id = name;
    return s;
}

struct stack *push (int v, struct stack *s)
{
    if (++(s->pt) >= s->mx)
        error_id("%s overflows\n", s->id);
    s->bd[s->pt] = v;
    return s;
}

int pop (struct stack *s)
{
    if (s->pt < 0)
        error_id("empty %s is popped\n", s->id);
    return s->bd[(s->pt)--];
}

int top (struct stack *s)
{
    if (s->pt < 0)
        error_id("empty %s is referred\n", s->id);
    return s->bd[s->pt];
}

int isempty (struct stack *s)
{
    return (s->pt < 0);
}
