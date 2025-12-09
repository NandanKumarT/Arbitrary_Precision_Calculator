/* Name        : Nandan Kumar T
   Date        : 08/12/2025
   Description : Arbitrary precision calculator
*/

#include "main.h"

// Addition of two numbers stored in DLL
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *temp1 = *tail1; // Pointer to last node of list1
    Dlist *temp2 = *tail2; // Pointer to last node of list2
    int carry = 0, num;
    int sign =0;
    if((*head1)->data < 0 || (*head2)->data < 0)
    {
        (*head1)->data *= -1;
        substraction(head1, tail1, head2, tail2, headR, tailR);
        return 1;
        sign=1;
    }
    // Add digits while both lists have nodes
    while (temp1 != NULL && temp2 != NULL)
    {
        num = temp1->data + temp2->data + carry; // Add values

        if (num > 9) // If carry needed
        {
            carry = 1;
            num = num % 10;
        }
        else
        {
            carry = 0;
        }

        dll_insert_at_first(headR, tailR, num); // Insert result digit
        temp1 = temp1->prev;
        temp2 = temp2->prev;
    }

    // Remaining digits from first list
    while (temp1 != NULL)
    {
        num = temp1->data + carry;

        if (num > 9)
        {
            carry = 1;
            num = num % 10;
        }
        else 
            carry = 0;

        dll_insert_at_first(headR, tailR, num);
        temp1 = temp1->prev;
    }

    // Remaining digits from second list
    while (temp2 != NULL)
    {
        num = temp2->data + carry;

        if (num > 9)
        {
            carry = 1;
            num = num % 10;
        }
        else 
            carry = 0;

        dll_insert_at_first(headR, tailR, num);
        temp2 = temp2->prev;
    }

    // If carry remains after addition
    if (carry)
    {
        dll_insert_at_first(headR, tailR, carry);
    }
}
