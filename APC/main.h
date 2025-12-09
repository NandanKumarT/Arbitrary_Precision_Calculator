/* Name        : Nandan Kumar T
   Date        : 08/12/2025
   Description : Arbitrary precision calculator
*/

#ifndef MAIN_H
#define MAIN_H

// Terminal color codes
#define RED     "\033[1;31m"
#define YELLOW  "\033[4;33m"
#define YELLOW1 "\033[1;33m"
#define GREEN   "\033[1;32m"
#define CYAN    "\033[1;36m"
#define MAGENTA "\033[1;35m"
#define RESET   "\033[0m"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Status return enum
typedef enum 
{
    SUCCESS,
    FAILURE
} Status;

// Doubly linked list node structure
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} Dlist;

// Function prototypes
int  convert_ascii_to_dll(Dlist **head, Dlist **tail, char digit[]);
int  addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int  multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int  substraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int  division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int  compare_list(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2);

void dll_insert_at_first(Dlist **head, Dlist **tail, int data);
void delete_list(Dlist **headR, Dlist **tailR);
void print_list(Dlist *head);
void remove_zero(Dlist **head, Dlist **tail);
void add_zero_at_last(Dlist **head, Dlist **tail, int data);

Status validate_operand(char digits[]);
Status validate_operator(char op[]);

#endif
