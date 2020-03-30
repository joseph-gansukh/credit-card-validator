# Credit Card Validator

![credit-card](../img/../credit-card/img/cc.jpeg)

Credit or debit cards are used all the time to pay for goods and services. On each card there is a long number which is stored in a database somewhere. When making a transaction, the creditor uses this number so they know whom to bill. 

In general, American Express uses 15-digit numbers which start with 34 or 37, MasterCard uses 16-digit numbers which start with 51, 52, 53, 54, or 55, and Visa uses 13 and 16-digit numbers which start with 4. Credit card numbers are unique in that they each have checksum built into them, a mathematical relationship between the numbers. This checksum enables computers and humans to detect whether the card is valid or not without having to query a database. Regardless, a database lookup is still necessary for more rigorous checks. 

In this program, I explore the checksum algorithm, the Luhn's algorithm on Visa, MasterCard, and American Express only. 

# Luhn's Algorithm

Most cards use an this algorithm invented by Hans Peter Luhn of IBM. Using Luhn's algorithm, you can determine if a credit card number is syntactically valid: 
  
  1. Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
  2. Add the sum to the sum of the digits that weren’t multiplied by 2.
  3. If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!

To demonstrate this algorithm, let's take a look at an example of 4003600000000014.

  >For the sake of discussion, let’s first bold every other digit, starting with the number’s second-to-last digit:
  >
  **4**0**0**3**6**0**0**0**0**0**0**0**0**0**1**4
  >
  > Okay, let’s multiply each of the underlined digits by 2:
  >
  > 1•2 + 0•2 + 0•2 + 0•2 + 0•2 + 6•2 + 0•2 + 4•2
  >
  > That gives us:
  >
  > 2 + 0 + 0 + 0 + 0 + 12 + 0 + 8
  >
  > Now let’s add those products’ digits (i.e., not the products themselves) together:
  >
  > 2 + 0 + 0 + 0 + 0 + 1 + 2 + 0 + 8 = 13
  >
  >Now let’s add that sum (13) to the sum of the digits that weren’t multiplied by 2 (starting from the end):
  >
  >13 + 4 + 0 + 0 + 0 + 0 + 0 + 3 + 0 = 20
  >
  > Since, the last digit in the sum (20) is a 0, this card is valid. 


Below is representation of how this program behaves when passed a valid credit card number. Note that card number should be void of hyphens. 

```
$ ./credit
Number: 4003600000000014
VISA
```

```
$ ./credit
Number: 5105105105105100
MASTERCARD
```

```
$ ./credit
Number: 371449635398431
AMEX
```

If a number for instance a phone number is entered, INVALID will show. 

```
$ ./credit
Number: 3123422929
INVALID
```

Here are a [few card numbers](https://developer.paypal.com/docs/payflow/payflow-pro/payflow-pro-testing/#credit-card-numbers-for-testing) that PayPal recommends for testing.

***

# How to run the programs?

1. Compile by running make credit or clang -o credit credit.c in terminal
2. Run the program by running ./credit


# Word of caution when compiling

You must install CS50 library for C in order to compile. Installation guide is [here](https://cs50.readthedocs.io/library/c/). 
