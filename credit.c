#include <cs50.h>
// #include <math.h>
#include <stdio.h>

// American Express starts with: 34 or 37 and 15 digits long
// MasterCard starts with: 51, 52, 53, 54, 55 and 16 digits long
// Visa starts with: 4 and uses 13 and 16 digits long numbers

int get_credit_card_length(long credit_card_number);
int checksum(long credit_card_number, int credit_card_length);
string get_credit_card_type(long credit_card, int credit_card_length);

int main(void)
{
    // Prompt user for the credit card number
    long credit_card_number = get_long("Number: ");

    // Get the length of the credit card
    int credit_card_length = get_credit_card_length(credit_card_number);

    // Checks for checksum 
    int check_sum = checksum(credit_card_number, credit_card_length);

    // Checks for validity of the card
    if (check_sum % 10 == 0) 
    {
        // Get credit card type if valid card is supplied
        string type = get_credit_card_type(credit_card_number, credit_card_length);
        printf("%s", type);
    }
    else 
    {
        printf("INVALID\n");
    }
    
}

// Calculates the length of the credit card
int get_credit_card_length(long credit_card_number)
{
    int credit_card_length = 0;
    
    // Calculates the length of the card by diving by 10;
    do
    {
        credit_card_length++;
        credit_card_number = credit_card_number / 10;
    } 
    while (credit_card_number);

    // printf("length: %f\n", floor(log10(credit_card_number)) + 1);
    return credit_card_length;
}

// Calculates Luhn's Algorithm for checking if credit card is valid
int checksum(long credit_card, int credit_card_length)
{
    long cc_number = credit_card;
    int doubled = 0;
    int added = 0;
    for (int i = 0; i < credit_card_length; i++) 
    {
        int last_digit = cc_number % 10;

        if (i % 2 == 0)
        {
            added += last_digit;
        }
        else 
        {
            if (last_digit * 2 > 9)
            {
                int product = last_digit * 2;
                doubled = doubled + product % 10 + 1;
            }
            else 
            {
                doubled += last_digit * 2;
            }
        }
        cc_number = ((cc_number - last_digit) / 10);
    }


    return added + doubled;
}

// Identifies the credit card type
string get_credit_card_type(long credit_card, int credit_card_length)
{   
    int number = 0;
    if (credit_card_length == 13) 
    {
        for (int i = 0; i < credit_card_length; i++)
        {
            credit_card = credit_card / 10;
            if (i == 11)
            {
                number = credit_card;
            }
        }
    }

    if (credit_card_length == 15)
    {
        for (int i = 0; i < credit_card_length; i++)
        {
            credit_card = credit_card / 10;
            if (i == 12)
            {
                number = credit_card;
            }
        }
    }

    if (credit_card_length == 16)
    {
        for (int i = 0; i < credit_card_length; i++)
        {
            credit_card = credit_card / 10;
            if (i == 13)
            {
                number = credit_card;
                if (number < 50 && number >= 40) 
                {
                    number = 4;
                }
            }
        }
    }

    // Depending on the number retrieved, gives the correct credit card type.
    switch (number)
    {
        case 4:
            return "VISA\n";
            break;
        case 34:
            return "AMEX\n";
            break;
        case 37:
            return  "AMEX\n";
            break;
        case 51:
            return "MASTERCARD\n";
            break;
        case 52:
            return "MASTERCARD\n";
            break;
        case 53:
            return "MASTERCARD\n";
            break;
        case 54:
            return "MASTERCARD\n";
            break;
        case 55:
            return "MASTERCARD\n";
            break;  
        default:
            return "INVALID\n";
            break;          
    }
}