#include <stdio.h>
#include <stdlib.h>
int tree[100];
int largest = 0;
int search(int x, int item)
{
 int l = 0, parent;
 parent = x;
 if (item < tree[parent])
 {
 if (tree[parent * 2] == 0)
 {
 l = parent * 2;
 }
 else
 {
 l = search(parent * 2, item);
 }
 }
 else if (item > tree[parent])
 {
 if (tree[(parent * 2) + 1] == 0)
 {
 l = (parent * 2) + 1;
 }
 else
 {
 l = search((parent * 2) + 1, item);
 }
 }
 else
 {
 printf("\n>> !! Item already exists!");
 }
 return l;
}
void insert(int item)
{
 int l;
 if (tree[1] == 0)
 {
 tree[1] = item;
 largest = 1;
 printf("\n>> Root Added as %d", tree[1]);
 }
 else
 {
 l = search(1, item);
 if (l != 0)
 {
 tree[l] = item;
 if (l > largest)
 {
 largest = l;
 }
 }
 }
}
void delete (int item)
{
 int flag = 0;
 int i = 1;
 while (i <= largest && flag != 1)
 {
 if (tree[i] == item)
 {
 if (tree[i * 2] == 0 && tree[(i * 2) + 1] == 0)
 {
 tree[i] = 0;
 printf("\n>> Element was deleted from %d", i);
 }
 else
 {
 printf("\n>> !! Element you trying to delete is not a leaf node");
 }
 flag = 1;
 }
 i++;
 }
 if (flag == 0)
 {
 printf("\n>> !! Item not found in tree!");
 }
}
void inorder(int x)
{
 int parent = x;
 if (tree[1] == 0)
 {
 printf("\n>> !! The tree is empty!");
 }
 else if (tree[parent] != 0)
 {
 inorder(parent * 2);
 printf("%d\t", tree[parent]);
 inorder((parent * 2) + 1);
 }
}
void preorder(int x)
{
 int parent = x;
 if (tree[1] == 0)
 {
 printf("\n>> !! The tree is empty!");
 }
 else if (tree[parent] != 0)
 {
 printf("%d\t", tree[parent]);
 preorder(parent * 2);
 preorder((parent * 2) + 1);
 }
}
void postorder(int x)
{
 int parent = x;
 if (tree[1] == 0)
 {
 printf("\n>> !! The tree is empty!");
 }
 else if (tree[parent] != 0)
 {
 postorder(parent * 2);
 postorder((parent * 2) + 1);
 printf("%d\t", tree[parent]);
 }
}
int main()
{
 int num;
 int choice;
 do
 {
 printf("\n\n1.Insert a node\n2.Delete a node\n3.Inorder\n4.Pre-order\n5.Post-order\n6.Exit");
 printf("\n\nEnter your choice : ");
 scanf("%d", &choice);
 switch (choice)
 {
 case 1:
 printf("\nEnter the element to be inserted : ");
 scanf("%d", &num);
 insert(num);
 break;
 case 2:
 printf("\nEnter the item you want to delete : ");
 scanf("%d", &num);
 delete (num);
 break;
 case 3:
 inorder(1);
 break;
 case 4:
 preorder(1);
 break;
 case 5:
 postorder(1);
 break;
 case 6:
 break;
 default:
 printf("\nInvalid Choice!");
 break;
 }
 } while (choice < 6);
}
