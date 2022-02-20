/*Experiment 9
DFS BFS Traversals
18/02/2022
VML20CS066*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 50

char open[MAX], visit[MAX];
int top = -1, in = -1;
char OPEN[MAX], VISIT[MAX];
int front = -1, rear = -1, ind = -1;
void push(char);
char pop();
int search(char[], char);
void enqueue(char x);
char dequeue();
int findIn(int n, char data[], char u);
void dfs(int n, int array[n][n], char data[n]);
void bfs(int n, int array[n][n], char data[n]);

void main()
{
    int n, i, j, ch;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    int arr[n][n];
    char data[n];
    printf("Enter the node datas: ");
    for (i = 0; i < n; i++)
    {
        scanf(" %c", &data[i]);
    }
    printf("Enter the adjacency matrix representation of the graph: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    do
    {
        printf("\n\nChoose operation\n1.DFS traversal\n2.BFS traversal\n3.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            dfs(n, arr, data);
            break;
        case 2:
            bfs(n, arr, data);
            break;
        case 3:
            break;
        default:
            printf("Invalid Choice!");
        }
    } while (ch < 3);
}

int findIn(int n, char data[], char u)
{
    int a, i;
    for (i = 0; i < n; i++)
    {
        if (data[i] == u)
        {
            a = i;
        }
    }
    return a;
}
void dfs(int n, int array[n][n], char data[n])
{
    int i, j, a;
    char u, x;
    if (n == 0)
    {
        printf("Graph is empty!\n");
        return;
    }
    top = -1;
    in = -1;
    printf("Enter the starting element: ");
    scanf(" %c", &x);
    push(x);
    while (top != -1)
    {
        u = pop();
        if (search(visit, u) == 0)
        {
            visit[++in] = u;
            a = findIn(n, data, u);
            for (i = 0; i < n; i++)
            {
                if (array[a][i] == 1)
                {
                    push(data[i]);
                }
            }
        }
    }
    printf("VISIT: ");
    for (i = 0; i <= in; i++)
    {
        printf("%c  ", visit[i]);
    }
}
void push(char x)
{
    if (top != MAX - 1)
    {
        open[++top] = x;
    }
}
char pop()
{
    char x = open[top];
    top--;
    return x;
}
int search(char visit[], char x)
{
    int i, flag = 0;
    for (i = 0; i <= MAX; i++)
    {
        if (visit[i] == x)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}
void bfs(int n, int array[n][n], char data[n])
{
    if (n == 0)
    {
        printf("Graph is empty! \n");
        return;
    }
    char u, x;
    int i, a;
    front = -1;
    rear = -1;
    ind = -1;
    printf("Enter the starting element: ");
    scanf(" %c", &x);
    enqueue(x);
    while (!(front == -1 || front > rear))
    {
        u = dequeue();
        if (search(VISIT, u) == 0)
        {
            VISIT[++ind] = u;
            a = findIn(n, data, u);
            for (i = 0; i < n; i++)
            {
                if (array[a][i] == 1)
                {
                    enqueue(data[i]);
                }
            }
        }
    }
    printf("VISIT: ");
    for (i = 0; i <= ind; i++)
    {
        printf("%c  ", VISIT[i]);
    }
}
void enqueue(char x)
{
    if (front == -1)
    {
        front = 0;
    }
    rear++;
    OPEN[rear] = x;
}
char dequeue()
{
    char x = OPEN[front];
    front++;
    return x;
}

/*OUTPUT

Enter the number of nodes: 5
Enter the node datas: 1 2 3 4 5
Enter the adjacency matrix representation of the graph: 
0 1 0 1 0 1 0 1 1 0 0 1 0 1 1 1 1 1 0 1 0 0 1 1 0


Choose operation
1.DFS traversal
2.BFS traversal
3.Exit
1
Enter the starting element: 2
VISIT: 2  4  5  3  1  

Choose operation
1.DFS traversal
2.BFS traversal
3.Exit
2
Enter the starting element: 2
VISIT: 2  1  3  4  5  

Choose operation
1.DFS traversal
2.BFS traversal
3.Exit
3
*/