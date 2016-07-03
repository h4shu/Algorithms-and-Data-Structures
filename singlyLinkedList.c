#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *newnd()
{
    struct node *new;
    new = (struct node *)malloc(sizeof(*new));

    return new;
}

void concat(struct node *p, struct node *q)
{
    struct node *nd = p;

    while (nd->next != NULL)
        nd = nd->next;
    nd->next = q;
}

int length(struct node *p) 
{
    int count = 0;
    struct node *nd = p;

    while (nd != NULL) {
	count++;
        nd = nd->next;
    }
    return count;
}

int main(void)
{
    struct node *nd1, *nd2, *head1, *head2;
    int i = 1, n;
    nd1 = (struct node *)malloc(sizeof(*nd1));
    nd2 = (struct node *)malloc(sizeof(*nd2));
    head1 = (struct node *)malloc(sizeof(*head1));
    head2 = (struct node *)malloc(sizeof(*head2));

    printf("n : ");
    scanf("%d", &n);
    head1 = nd1;  head2 = nd2;
    while (1) {
        nd1->data = i;
        nd2->data = i + 10;
        if (i == n) {
            nd1->next = NULL;
            nd2->next = NULL;
            break;
        }
        nd1->next = newnd();
        nd2->next = newnd();
        nd1 = nd1->next;
        nd2 = nd2->next;
        i++;
    }

    nd1 = head1;    nd2 = head2;
    printf("list1 : [ ");
    while (nd1 != NULL) {
        printf("%d ", nd1->data);
        nd1 = nd1->next;
    }
    printf("]\n"
           "list2 : [ ");
    while (nd2 != NULL) {
        printf("%d ", nd2->data);
        nd2 = nd2->next;
    }
    printf("]\n"
           "Length\n"
           "list1 : %d\n"
           "list2 : %d\n", length(head1), length(head2));    

    concat(head1, head2);
    nd1 = head1;
    printf("----[Concat]----\n"
           "list1 : [ ");
    while (nd1 != NULL) {
        printf("%d ", nd1->data);
        nd1 = nd1->next;
    }
    printf("]\n"
           "Length\n"
           "list1 : %d\n", length(head1));

    return 0;
}
