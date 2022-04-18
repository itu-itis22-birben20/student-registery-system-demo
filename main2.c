#include <stdio.h>
#include <stdlib.h>

void print_menu();
struct Node *add_record();
int dis_by_id();
int dis_by_year();
int dis_by_fac();
int del_rec();
int sort();

struct Node
{
    // each node holds integer data
    // conversion needed while printing name_surname
    int data;
    struct Node *next;
};

// our record stack
struct Node *record_stack[200];
int stack_marker = -1; // index of the last record

int main()
{
    while (1)
    {
        // Getting option from the user
        int choice;
        print_menu();
        scanf("%1d", &choice);

        if (choice == 1)
        {
            stack_marker++;
            struct Node *record;
            record = add_record();
            record_stack[stack_marker] = record;
        }
        else if (choice == 2)
        {
            dis_by_id();
        }
        else if (choice == 3)
        {
            // dis_by_year();
        }
        else if (choice == 4)
        {
            // dis_by_fac();
        }
        else if (choice == 5)
        {
            // del_rec();
        }
        else if (choice == 6)
        {
            exit(0);
        }
        else
        {
            printf("Wrong option. Please pick a valid one.");
        }
    }
}

struct Node *add_record()
{
    /*Adds the pointer of records to the main stack.
    Records are in the form of a linked list:
    student_id->n->a->m->e */
    struct Node *head;
    struct Node *current_pt = NULL;
    struct Node *node = (struct Node *)malloc(sizeof(struct Node *));
    head = node;
    current_pt = node;

    printf("\nEnter school number: ");
    scanf("%9d\n", &(node->data));
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        struct Node *new_Node = (struct Node *)malloc(sizeof(struct Node *));
        current_pt->next = new_Node;
        current_pt = new_Node;
        current_pt->next = NULL;
        current_pt->data = c;
    }
    return head;
}

int dis_by_id()
{
    sort();

    struct Node *record_head;

    for (int i = 0; i <= stack_marker; i++) // for each record till stack_marker
    {
        printf("School ID: ");
        record_head = record_stack[i];
        printf("%d", record_head->data);
        record_head = record_head->next;

        printf("\nName - Surname: ");
        while (record_head->next != NULL)
        {
            printf("%c", record_head->data);
            record_head = record_head->next;
        }
        printf("%c\n\n", record_head->data); // last character has null ->next, so print explicitly
        printf("\n");
    }
}

int dis_by_year()
{
    sort();
}

int dis_by_fac()
{
    sort();
}

int del_rec()
{
    sort();
}

int sort()
{
    // does sorting given ...
}

void print_menu()
{
    // prints the main menu
    printf("1-Enter record with school number\n");
    printf("2-Display school numbers sorted by ID\n");
    printf("3-Display school numbers sorted by year\n");
    printf("4-Display school numbers sorted by the faculty codes\n");
    printf("5-Delete a record by school number\n");
    printf("6-Exit\n");
    printf("Enter choice: ");
}