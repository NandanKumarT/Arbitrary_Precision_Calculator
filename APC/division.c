/* Name        : Nandan Kumar T
   Date        : 08/12/2025
   Description : Arbitrary precision calculator
*/

#include "main.h"

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    // printf("division\n");
     if((*head2)->data==0&&(*head1)->data==0)
     {
        dll_insert_at_first(headR,tailR, 0);
        return 1;
     }
     else if((*head2)->data==0)
     {
        printf("Division is not posible\n");
        return 0;
     }
    // Quotient counter
    Dlist *H_count = NULL, *T_count = NULL;
    dll_insert_at_first(&H_count, &T_count, 0);

    // Increment value = 1
    Dlist *Hinc = NULL, *Tinc = NULL;
    dll_insert_at_first(&Hinc, &Tinc, 1);

    while(compare_list(head1, tail1, head2, tail2) != 2)  // while num1 >= num2
    {
        Dlist *H_temp = NULL, *T_temp = NULL;

        // subtract divisor from dividend
        substraction(head1, tail1, head2, tail2, &H_temp, &T_temp);

        // update dividend
        delete_list(head1, tail1);
        *head1 = H_temp;
        *tail1 = T_temp;

        // update quotient count
        Dlist *H_new = NULL, *T_new = NULL;
        addition(&H_count, &T_count, &Hinc, &Tinc, &H_new, &T_new);

        delete_list(&H_count, &T_count);
        H_count = H_new;
        T_count = T_new;
    }

    // final result = quotient
    *headR = H_count;
    *tailR = T_count;
    printf("modulus =");
    print_list(*head1);
    
    return 1;  // or return 0
}
