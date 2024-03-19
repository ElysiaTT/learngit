#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct node
   { ElemType data;
     struct node *next;
    } NODE,*LinkList;
void TriLinkList(LinkList A, LinkList B, LinkList C) {
    NODE *p1, *pre;

    p1 = A->next;

    while (p1 != NULL) {
        pre = p1;
        NODE *p2 = B->next;
        NODE *p3 = C->next;

        while (p2 != NULL && p3 != NULL) {
            if (p1->data == p2->data) {
                if (p2->data == p3->data) {
                    pre->next = p1->next;
                    free(p1);
                    p1 = pre->next;
                    p2 = B->next; // 重置p2为B表头
                    p3 = C->next; // 重置p3为C表头
                    continue;
                } else {
                    p3 = p3->next;
                }
            } else {
                p2 = p2->next;
                if (p1->data == p2->data) {
                    if (p2->data == p3->data) {
                        pre->next = p1->next;
                        free(p1);
                        p1 = pre->next;
                        p2 = B->next; // 重置p2为B表头
                        p3 = C->next; // 重置p3为C表头
                        continue;
                    } else {
                        p3 = p3->next;
                    }
                }
            }
        }

        p1 = p1->next; // p1需要一直向后移动
    }
}
int main()
{
    LinkList L[3],p;
    ElemType x;
    int i;
    for(i=0;i<3;i++)
    {
    	L[i]=p=(NODE *)malloc(sizeof(NODE));
    	scanf("%d",&x);
    	while (x)
    	{
				p->next=(NODE *)malloc(sizeof(NODE));
				p=p->next;
				p->data=x;
				scanf("%d",&x);
    	}
      p->next=NULL;
    }
    TriLinkList(L[0],L[1],L[2]);
    for(p=L[0]->next;p;p=p->next)
        printf(" %d",p->data);
	return 0;
}