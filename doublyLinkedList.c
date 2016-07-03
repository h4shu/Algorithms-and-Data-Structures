#include <stdio.h>
#include <stdlib.h>

struct dnode
{
    int data;
    struct dnode *prev;
    struct dnode *next;
};

struct dnode *newlist_after(struct dnode *nd)
{
    struct dnode *hd, *tl;
    hd = (struct dnode *)malloc(sizeof(*hd));
    tl = (struct dnode *)malloc(sizeof(*tl));
    
    hd->prev = nd;  hd->next = tl;  hd->data = 0;
    tl->prev = hd;  tl->next = tl;  tl->data = 0;

    return hd;
}

void makeN_dnode(struct dnode *hd, int n) {
    struct dnode *nd = hd;
    int i = 1;

    while (1) {
        nd->next = newlist_after(nd);
        nd = nd->next;
        if (i > n) {
            nd->data = 0;
            nd->next = nd;
            break;
        }
        nd->data = i;
        i++;
    }
}

struct dnode *n_dnode(struct dnode *hd, int n)
{
    struct dnode *p = hd;
    int i;

    for (i = 0; i < n; i++)
        p = p->next;

    return p;
}

struct dnode *insertprev(struct dnode *nd)
{
    struct dnode *nd_new;
    nd_new = (struct dnode *)malloc(sizeof(*nd_new));

    nd_new->prev = nd->prev;
    nd_new->prev->next = nd_new;
    nd_new->next = nd;
    nd->prev = nd_new;

    return nd_new;
}

void delete(struct dnode *nd)
{
    nd->prev->next = nd->next;
    nd->next->prev = nd->prev;
    free(nd);
}

int length_d(struct dnode *nd)
{
    struct dnode *p = nd;
    int count = 0;

    while (1) {
        if (p->data != 0)
            count++;
        p = p->next;
        if (p == NULL || p->data == 0 || p == p->next)
            break;
    }

    return count;
}

void printlist(struct dnode *hd)
{
    struct dnode *p = hd;
    int i;

    for (i = 0; i < length_d(hd); i++) {
        p = p->next;
        printf("%d ", p->data);
    }
    printf("\n");
}

int main(void)
{
    struct dnode *head_d, *p_d;
    int i = 1, n, data;
    p_d = (struct dnode *)malloc(sizeof(*p_d));
    head_d = p_d;

    printf("How many nodes? : ");
    scanf("%d", &n);
    makeN_dnode(head_d, n);
    p_d = head_d->next;
    printf("list : ");
    printlist(head_d);
    printf("----InsertPrev----\n"
           "[rank data] : ");
    scanf("%d %d", &n, &data);
    insertprev(n_dnode(head_d, n))->data = data;
    printlist(head_d);
    printf("----Delete----\n"
           "rank : ");
    scanf("%d", &n);
    delete(n_dnode(head_d, n));
    printlist(head_d);

    return 0;
}
