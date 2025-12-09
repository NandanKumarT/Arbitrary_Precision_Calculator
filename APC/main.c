/* Name        : Nandan Kumar T
   Date        : 08/12/2025
   Description : Arbitrary precision calculator
*/

#include "main.h"

int main(int argc, char *argv[])
{
    // Check argument count
    if (argc != 4)
    {
        printf(RED"Invalid Arguments.\n"RESET CYAN"please pass as ./a.out operand1 operator operand2 (ex: ./a.out 12345 + 12345)\n"RESET);
        return 0;
    }

    // Validate operands and operator
    if ((validate_operand(argv[1]) == SUCCESS) && 
        (validate_operator(argv[2]) == SUCCESS) && 
        (validate_operand(argv[3]) == SUCCESS))
    {
        // Initialize all list heads and tails
        Dlist *head1 = NULL, *tail1 = NULL;
        Dlist *head2 = NULL, *tail2 = NULL;
        Dlist *headR = NULL, *tailR = NULL;

        // Convert operands into DLL
        convert_ascii_to_dll(&head1, &tail1, argv[1]);
        remove_zero(&head1, &tail1);
        print_list(head1);

        convert_ascii_to_dll(&head2, &tail2, argv[3]);
        remove_zero(&head2, &tail2);
        print_list(head2);

        // Extract operator
        char choice = argv[2][0];

        // Perform operation
        switch (choice)
        {
            case '+':
            {
                int resa = addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);

                if (resa == 1)
                    printf("Result = -");
                else
                    printf("Result = ");

                print_list(headR);
                break;
            }

            case '-':
            {
                int ret = substraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);

                if (ret == 2)
                    printf("Result = -");
                else
                    printf("Result = ");

                print_list(headR);
                break;
            }

            case 'x':  // Multiplication
                multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                printf("Result = ");
                print_list(headR);
                break;

            case '/':  // Division
            {
                int res = division(&head1, &tail1, &head2, &tail2, &headR, &tailR);

                if (res != 0)
                {
                    printf("Result = ");
                    print_list(headR);
                }
                break;
            }

            default:
                // No default case message needed
                break;
        }
    }
}
