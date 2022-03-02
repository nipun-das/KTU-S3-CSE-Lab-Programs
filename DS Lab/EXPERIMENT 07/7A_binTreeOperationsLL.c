/*Experiment 7
Binary Tree Operations 
14/02/2022
VML20CS066*/

#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};
struct node *root = NULL;

struct node *search(struct node *ptrS, int key)
{
    struct node *ptr, *temp;
    ptr = ptrS;
    if (ptr->data == key)
    {
        return ptr;
    }
    if (ptr->lchild != NULL)
    {
        temp = search(ptr->lchild, key);
        if (temp != NULL)
        {
            return temp;
        }
    }
    if (ptr->rchild != NULL)
    {
        temp = search(ptr->rchild, key);
        if (temp != NULL)
        {
            return temp;
        }
    }
    else
    {
        return NULL;
    }
}

void insert()
{
    struct node *ptr, *ptr2;
    printf("Enter data to insert and parent: ");
    int d, key, choice;
    scanf("%d %d", &d, &key);
    ptr = search(root, key);
    if (ptr == NULL)
    {
        printf("\nParent not found.\n");
        return;
    }
    if (ptr->lchild == NULL || ptr->rchild == NULL)
    {
        printf("Left(1) - Right(2) ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            if (ptr->lchild == NULL)
            {
                ptr2 = malloc(sizeof(struct node));
                ptr2->data = d;
                ptr->lchild = ptr2;
                ptr2->lchild = NULL;
                ptr2->rchild = NULL;
            }
            else
            {
                printf("\nLeft child is not free.\n");
                return;
            }
        }
        if (choice == 2)
        {
            if (ptr->rchild == NULL)
            {
                ptr2 = malloc(sizeof(struct node));
                ptr2->data = d;
                ptr->rchild = ptr2;
                ptr2->lchild = NULL;
                ptr2->rchild = NULL;
            }
            else
            {
                printf("\nRight child is not free.\n");
                return;
            }
        }
    }
    else
    {
        printf("\nChild node is not free.\n");
    }
}
struct node *delete (struct node *ptr1, int item)
{
    if (ptr1 == NULL)
    {
        return (NULL);
    }
    ptr1->lchild = delete (ptr1->lchild, item);
    ptr1->rchild = delete (ptr1->rchild, item);
    if (ptr1->data == item && ptr1->lchild == NULL && ptr1->rchild == NULL)
    {
        return (NULL);
    }
    else
    {
        return (ptr1);
    }
}
void display(struct node *ptro, int level)
{
    int j;
    struct node *ptr;
    ptr = ptro;
    if (ptr->rchild != NULL)
    {
        display(ptr->rchild, level + 1);
    }
    printf("\n");
    for (j = 0; j < level; j++)
    {
        printf("\t");
    }
    printf(" %d", ptr->data);
    if (ptr->lchild != NULL)
    {
        display(ptr->lchild, level + 1);
    }
}

void preorder(struct node *root)
{
    struct node *ptr;
    ptr = root;
    if (ptr != NULL)
    {
        printf(" %d", ptr->data);
        preorder(ptr->lchild);
        preorder(ptr->rchild);
    }
}
void inorder(struct node *root)
{
    struct node *ptr;
    ptr = root;
    if (ptr != NULL)
    {
        inorder(ptr->lchild);
        printf(" %d", ptr->data);
        inorder(ptr->rchild);
    }
}
void postorder(struct node *root)
{
    struct node *ptr;
    ptr = root;
    if (ptr != NULL)
    {
        postorder(ptr->lchild);
        postorder(ptr->rchild);
        printf(" %d", ptr->data);
    }
}

void main()
{
    printf("\nEnter root node data : ");
    root = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &root->data);
    root->lchild = NULL;
    root->rchild = NULL;
    int choice;
    do
    {
        printf("\n1.Insert a node\n2.Inorder\n3.Preorder\n4.Postorder\n5.Delete a node\n6.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            display(root, 1);
            break;
        case 2:
            printf("\nInorder Traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 3:
            printf("\nPreorder Traversal: ");
            preorder(root);
            printf("\n");
            break;
        case 4:
            printf("\nPostorder Traversal: ");
            postorder(root);
            printf("\n");
            break;
        case 5:
            printf("\nEnter element to delete : ");
            int item;
            scanf("%d", &item);
            delete (root, item);
            display(root, 1);
            break;
        case 6:
            break;
        }
    } while (choice < 6);
}

/*OUTPUT

Enter root node data : 5

1.Insert a node
2.Inorder
3.Preorder
4.Postorder
5.Delete a node
6.Exit
Enter your choice: 1
Enter data to insert and parent: 7 5
Left(1) - Right(2) 1

         5
                 7
1.Insert a node
2.Inorder
3.Preorder
4.Postorder
5.Delete a node
6.Exit
Enter your choice: 1
Enter data to insert and parent: 9 5
Left(1) - Right(2) 2

                 9
         5
                 7
1.Insert a node
2.Inorder
3.Preorder
4.Postorder
5.Delete a node
6.Exit
Enter your choice: 1
Enter data to insert and parent: 3 7
Left(1) - Right(2) 1

                 9
         5
                 7
                         3
1.Insert a node
2.Inorder
3.Preorder
4.Postorder
5.Delete a node
6.Exit
Enter your choice: 1
Enter data to insert and parent: 1 3
Left(1) - Right(2) 1

                 9
         5
                 7
                         3
                                 1
1.Insert a node
2.Inorder
3.Preorder
4.Postorder
5.Delete a node
6.Exit
Enter your choice: 1
Enter data to insert and parent: 6 3
Left(1) - Right(2) 2

                 9
         5
                 7
                                 6
                         3
                                 1
1.Insert a node
2.Inorder
3.Preorder
4.Postorder
5.Delete a node
6.Exit
Enter your choice: 1
Enter data to insert and parent: 2 9
Left(1) - Right(2) 1

                 9
                         2
         5
                 7
                                 6
                         3
                                 1
1.Insert a node
2.Inorder
3.Preorder
4.Postorder
5.Delete a node
6.Exit
Enter your choice: 1
Enter data to insert and parent: 4 9
Left(1) - Right(2) 2

                         4
                 9
                         2
         5
                 7
                                 6
                         3
                                 1
1.Insert a node
2.Inorder
3.Preorder
4.Postorder
5.Delete a node
6.Exit
Enter your choice: 1
Enter data to insert and parent: 8 4
Left(1) - Right(2) 2

                                 8
                         4
                 9
                         2
         5
                 7
                                 6
                         3
                                 1
1.Insert a node
2.Inorder
3.Preorder
4.Postorder
5.Delete a node
6.Exit
Enter your choice: 2

Inorder Traversal:  1 3 6 7 5 2 9 4 8

1.Insert a node
2.Inorder
3.Preorder
4.Postorder
5.Delete a node
Enter your choice: 3

Preorder Traversal:  5 7 3 1 6 9 2 4 8

1.Insert a node
2.Inorder
3.Preorder
4.Postorder
5.Delete a node
6.Exit
Enter your choice: 4

Postorder Traversal:  1 6 3 7 2 8 4 9 5

1.Insert a node
2.Inorder
3.Preorder
4.Postorder
5.Delete a node
6.Exit
Enter your choice: 5

Enter element to delete : 8

                         4
                 9
                         2
         5
                 7
                                 6
                         3
                                 1
1.Insert a node
2.Inorder
3.Preorder
4.Postorder
5.Delete a node
6.Exit
Enter your choice: 6
*/