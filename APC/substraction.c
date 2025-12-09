/* Name        : Nandan Kumar T
   Date        : 08/12/2025
   Description : Arbitrary precision calculator
*/

#include "main.h"

int substraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    int ret = compare_list(head1, tail1, head2, tail2);     // Compare both numbers

    // If second number is bigger, swap for correct subtraction
    if (ret == 2)
    {
        Dlist *temp1 = *head1;
        *head1 = *head2;
        *head2 = temp1;

        temp1 = *tail1;
        *tail1 = *tail2;
        *tail2 = temp1;
    }

    Dlist *temp1 = *tail1, *temp2 = *tail2;
    int data = 0, borrow = 0;

    // Subtract while both lists have digits
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data < temp2->data)             // Borrow required
        {
            data = (temp1->data + 10) - temp2->data - borrow;
            borrow = 1;
        }
        else
        {
            data = temp1->data - temp2->data - borrow;
            borrow = 0;
        }

        dll_insert_at_first(headR, tailR, data);    // Insert result digit
        temp1 = temp1->prev;
        temp2 = temp2->prev;
    }

    // Remaining digits from first list if any
    while (temp1 != NULL)
    {
        if (temp1->data - borrow < 0)              // Borrow propagation
        {
            data = temp1->data + 10 - borrow;
            borrow = 1;
        }
        else
        {
            data = temp1->data - borrow;
            borrow = 0;
        }

        dll_insert_at_first(headR, tailR, data);   // Insert result digit
        temp1 = temp1->prev;
    }

    remove_zero(headR, tailR);                    // Remove leading zeros
    return ret;                                   // Return comparison result for sign handling
}
