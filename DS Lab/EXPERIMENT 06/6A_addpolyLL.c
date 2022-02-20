/*Experiment 6.A
Polynomial Addition using Linked List
31/01/2022
VML20CS066*/

#include <stdlib.h>
#include <stdio.h>

struct poly
{
    int coeff;
    int expo;
    struct poly *next;
} * poly1, *poly2, *poly_add;

void insert(struct poly *head, int coeff, int expo)
{
    struct poly *temp, *p;
    p = head;
    while (p->next != NULL && p->next->expo >= expo)
    {
        p = p->next;
    }
    if (p->expo == expo)
    {
        p->coeff = p->coeff + coeff;
    }
    else
    {
        temp = malloc(sizeof(struct poly));
        temp->coeff = coeff;
        temp->expo = expo;
        temp->next = p->next;
        p->next = temp;
    }
}
void create_poly(struct poly *head)
{
    struct poly *ptr = head;
    int coeff;
    int expo;
    printf("Enter number of terms: ");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter coeff of term %d: ", i + 1);
        scanf("%d", &coeff);
        printf("Enter expo of term %d: ", i + 1);
        scanf("%d", &expo);
        insert(ptr, coeff, expo);
    }
}
void add_poly()
{
    struct poly *p1, *p2;
    p1 = poly1->next;
    p2 = poly2->next;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->expo > p2->expo)
        {
            insert(poly_add, p1->coeff, p1->expo);
            p1 = p1->next;
        }
        else if (p1->expo < p2->expo)
        {
            insert(poly_add, p2->coeff, p2->expo);
            p2 = p2->next;
        }
        else
        {
            insert(poly_add, p2->coeff + p1->coeff, p1->expo);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    if (p1 == NULL && p2 != NULL)
    {
        while (p2 != NULL)
        {
            insert(poly_add, p2->coeff, p2->expo);
            p2 = p2->next;
        }
    }
    if (p1 != NULL && p2 == NULL)
    {
        while (p1 != NULL)
        {
            insert(poly_add, p1->coeff, p1->expo);
            p1 = p1->next;
        }
    }
}

void display_poly(struct poly *head)
{
    struct poly *ptr = head->next;
    while (ptr != NULL)
    {
        if (ptr->expo != 0)
        {
            printf("%dx^%d", ptr->coeff, ptr->expo);
            if (ptr->next != NULL)
            {
                printf(" + ");
            }
        }
        ptr = ptr->next;
    }
}

void main()
{
    poly1 = malloc(sizeof(struct poly));
    poly2 = malloc(sizeof(struct poly));
    poly_add = malloc(sizeof(struct poly));

    printf("Polynomial 1\n");
    create_poly(poly1);
    printf("\nPolynomial 1: ");
    display_poly(poly1);
    printf("\n\nPolynomial 2\n");
    create_poly(poly2);
    printf("\nPolynomial 2: ");
    display_poly(poly2);

    printf("\n\nPolynomial sum: ");
    add_poly();
    display_poly(poly_add);
}

/*OUTPUT

Polynomial 1
Enter number of terms: 3
Enter coeff of term 1: 2
Enter expo of term 1: 1
Enter coeff of term 2: 3
Enter expo of term 2: 2
Enter coeff of term 3: 5
Enter expo of term 3: 3

Polynomial 1: 5x^3 + 3x^2 + 2x^1

Polynomial 2
Enter number of terms: 4
Enter coeff of term 1: 4
Enter expo of term 1: 1
Enter coeff of term 2: 2
Enter expo of term 2: 2
Enter coeff of term 3: 3
Enter expo of term 3: 3
Enter coeff of term 4: 7
Enter expo of term 4: 4

Polynomial 2: 7x^4 + 3x^3 + 2x^2 + 4x^1

Polynomial sum: 7x^4 + 8x^3 + 5x^2 + 6x^1

*/