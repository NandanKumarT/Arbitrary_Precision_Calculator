/* Name        : Nandan Kumar T
   Date        : 08/12/2025
   Description : Arbitrary precision calculator
*/

#include "main.h"

// Valid operator list
char operator[] = { '+', '-', '/', 'x' };

// Validate operator input
Status validate_operator(char op[])
{
    for (int i = 0; i < 4; i++) // Loop through allowed operators
    {
        if (op[0] == operator[i]) // Match found
            return SUCCESS;
    }

    printf(RED"Invalid Operator choose ( + , - , x , / )\n"RESET);
    return FAILURE;
}

// Validate that operand contains only digits
Status validate_operand(char digits[])
{
    int i = 0;

    while (digits[i] != '\0') // Loop until end of string
    {
        if (digits[0] == '-' || digits[0] == '+') // Skip sign
        {
            i++;
            continue;
        }

        if (digits[i] < '0' || digits[i] > '9') // Non-digit check
        {
            printf(RED"Please enter only digits.\n"RESET);
            return FAILURE;
        }

        i++;
    }

    return SUCCESS;
}

// Convert ASCII numeric string to DLL
int convert_ascii_to_dll(Dlist **head, Dlist **tail, char digit[])
{
    int i = 0, sign = 1, data;

    while (digit[i]) // Read each character
    {
        if (digit[i] == '-') // Detect negative sign
        {
            sign = -1;
            i++;
        }

        if (digit[i] == '+') // Skip positive sign
            i++;

        data = digit[i] - '0'; // Convert ASCII to integer

        Dlist *new = malloc(sizeof(Dlist)); // Allocate node
        if (new == NULL)
        {
            printf("Memory allocation failed\n");
            return FAILURE;
        }

        new->next = NULL;
        new->prev = NULL;
        new->data = data;

        if (*head == NULL && *tail == NULL) // First node case
        {
            *head = new;
            *tail = new;
        }
        else
        {
            new->prev = *tail;
            (*tail)->next = new;
            *tail = new;
        }

        i++;
    }

    if (sign == -1) // Apply sign to first element
        (*head)->data *= -1;
}

int compare_list(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2)
{
    int count1 = 1, count2 = 1;
    Dlist *temp1 = *head1;
    Dlist *temp2 = *head2;

    while (temp1 != NULL)
    {
        count1++;
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        count2++;
        temp2 = temp2->next;
    }

    if (count1 > count2)
        return 1;
    else if (count1 < count2)
        return 2;
    else
    {
        temp1 = *head1;
        temp2 = *head2;

        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->data > temp2->data)
                return 1;
            else if (temp1->data < temp2->data)
                return 2;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return 0;
    }
}

void delete_list(Dlist **head, Dlist **tail)
{
    if (*head == NULL && *tail == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    while (*head != NULL)
    {
        Dlist *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void add_zero_at_last(Dlist **head, Dlist **tail, int data)
{
    if (*head == NULL && *tail == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    Dlist *new = malloc(sizeof(Dlist));
    new->next = NULL;
    new->prev = *tail;
    new->data = data;
    (*tail)->next = new;
    *tail = new;
}

// Insert a node at the beginning of DLL
void dll_insert_at_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));

    if (new == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    if (*head == NULL && *tail == NULL) // Empty list
    {
        *head = new;
        *tail = new;
    }
    else
    {
        new->next = *head;
        (*head)->prev = new;
        *head = new;
    }
}

void remove_zero(Dlist **head, Dlist **tail)
{
    while (*head && (*head)->data == 0 && (*head)->next != NULL)
    {
        Dlist *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }
}

// Print Doubly Linked List
void print_list(Dlist *head)
{
    if (head == NULL)
    {
        printf("INFO: List is empty\n");
    }
    else
    {
        while (head)
        {
            printf("%d", head->data);
            head = head->next;
        }
        printf("\n");
    }
}
