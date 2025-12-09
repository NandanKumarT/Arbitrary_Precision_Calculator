/* Name        : Nandan Kumar T
   Date        : 08/12/2025
   Description : Arbitrary precision calculator
*/

#include "main.h"

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR)
{
  //printf("multiplication\n"); // Debug: multiplication started
  int data=0,carry=0,count=0; // Variables for result digit, carry, and zero padding count
  Dlist *temp2 = *tail2; // Pointer to last node of list2

  while(temp2!=NULL) // Loop for each digit of second number
  {
    Dlist *temp1 = *tail1; // Pointer to last node of list1
    Dlist *headR1=NULL; // Temporary partial result head
    Dlist *tailR1=NULL; // Temporary partial result tail
    carry=0; // Reset carry for each multiplication row

    while(temp1!=NULL) // Multiply each digit of list1 with current digit of list2
    {
        data = temp1->data * temp2->data + carry; // Multiply and add carry
        if(data > 9) // Handle carry if digit > 9
        {
            carry=data/10; // Update carry
            data=data%10; // Store remainder as current digit
        }
        else
          carry = 0;
        dll_insert_at_first(&headR1,&tailR1,data); // Insert digit at the beginning
        temp1=temp1->prev; // Move to previous digit
    }

    if(carry) // Insert leftover carry if exists
        dll_insert_at_first(&headR1,&tailR1,carry);

    for(int i=0;i<count;i++) // Add zeros based on position (like long multiplication)
        add_zero_at_last(&headR1,&tailR1,0);

    // print_list(headR1);
        
    Dlist *headR2=NULL; // New result list head
    Dlist *tailR2=NULL; // New result list tail

    addition(&headR1,&tailR1,headR,tailR,&headR2,&tailR2); // Add partial result to final result

    *headR =headR2; // Update final head pointer
    *tailR =tailR2; // Update final tail pointer
    delete_list(&headR1,&tailR1); // Free temporary list
    temp2=temp2->prev; // Move to previous digit of second number
    count++; // Increase zero padding count
  }
  
} // End of multiplication
