#include <stdio.h>
#include <stdlib.h>
#define nl printf("\n")

typedef struct node node;
struct node
{
    int data;
    node *next;
};

node *getNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void traverse(node *start)
{
    node *loc = start;
    if (!loc)
    {
        printf("No element exist\n");
        return;
    }
    // traverse and print data;
    while (loc)
    {
        printf("%d ", loc->data);
        loc = loc->next;
    }
    nl;
}

void insertAtPosition(node *start, int position, const int data)
{
    node *loc = start;
    // get node at given position node
    while (--position)
    {
        loc = loc->next;
    }

    // save next node's address
    node *nextNodeWas = loc->next;

    // insert new node
    loc->next = getNode(data);
    loc = loc->next;

    // re-attach next node
    loc->next = nextNodeWas;
}

void insertAtEnd(node *start, int data)
{
    // get last node
    node *loc = start;
    while (loc->next)
        loc = loc->next;

    // insert new node
    loc->next = getNode(data);
}

node *deleteFirstNode(node *start)
{
    if (!start)
    {
        printf("No node exist");
        return start; // NULL 
    }
    node *loc = start;
    start = start->next;

    printf("deleted : %d", loc->data);
    nl;
    free(loc);
    return start ;
}

void deleteFromEnd(node *start)
{
    // check if list is empty
    if (!start)
    {
        printf("No node exist");
        return;
    }

    node *loc = start;
    node *prevNode = loc;

    // get last node
    while (loc->next)
    {
        prevNode = loc;
        loc = loc->next;
    }

    //   delete node
    prevNode->next = NULL;
    printf("deleted : %d", loc->data);
    nl;
    free(loc);
}

void deleteFromPosition(node *start, int position)
{
    if (!start)
    {
        printf("No node exist");
        return;
    }
    node *loc = start;
    node *prevNode = loc;
    // go to given position but also care about if we reached to end.
    while (loc->next)
    {
        if (!(--position))
        {
            break;
        }
        prevNode = loc;
        loc = loc->next;
    }
    if (position)
    {
        printf("invalid position\n");
    }
    else
    {
        prevNode->next = loc->next;
        printf("deleted : %d", loc->data);
        nl;
        free(loc);
    }
}

int getChoice()
{
    int choice;
    printf("\nEnter operation from the following:\n");
    printf("Insert:\n");
    printf("  1    - End\n");
    printf("  2    - Start\n");
    printf("  3    - Given position\n");
    printf("Delete:\n");
    printf("  4    - End\n");
    printf("  5    - Start\n");
    printf("  6    - Given position\n");
    printf("7 Display elements\n");
    printf("0 EXIT\n");
    printf("\nEnter choice : ");
    scanf("%d", &choice);
    return choice;
}

/**
 * WHAT TO BE FIXED
 * calling insert at last without inserting at first not working
 * calling insert at position 1st without inserting at first not working
 * insert at position last doesn't works 
*/
int main()
{
    node *start = NULL;

    int data;
    int pos;

    while (1)
    {
        switch (getChoice())
        {
        case 0:
            return 0;
        case 1:
            // printf("Insert at end selected.\n");

            printf("number of items to be inserted : ");
            int numberOfItems;
            scanf("%d", &numberOfItems);
            printf("enter all items\n");
            while (numberOfItems--)
            {
                scanf("%d", &data);
                insertAtEnd(start, data);
            }
            printf("Inserted.\n");

            break;

        case 2:
            // printf("Insert at start selected.\n");
            printf("enter item\n");
            scanf("%d", &data);
            // get new node
            node *loc = getNode(data);
            // if is not empty then point new node->next to older node.
            if (start)
                loc->next = start;
            start = loc;

            printf("Inserted.\n");
            break;

        case 3:
            printf("Insert at given position selected.\n");
            printf("enter position : ");
            scanf("%d", &pos);

            printf("enter data : ");
            scanf("%d", &data);

            insertAtPosition(start, pos, data);
            break;

        case 4:

            deleteFromEnd(start);
            printf("now items are : \n");
            traverse(start);
            break;

        case 5:
            printf("Delete from start selected.\n");
            start = deleteFirstNode(start);
            traverse(start);
            break;

        case 6:
            printf("Delete from given position selected.\n");

            printf("enter position : ");
            scanf("%d", &pos);

            deleteFromPosition(start, pos);
            traverse(start);
            break;

        case 7:
            printf("Displaying elements .\n");
            traverse(start);
            break;

        default:
            printf("Invalid choice. Please select a valid option.\n");
        }
    }
    return 0;
}
