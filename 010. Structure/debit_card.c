#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define MAX_HOLDER_NAME_CHARS   128 
#define MAX_VENDOR_NAME_CHARS   64

struct Date {

    unsigned char day, month; 
    int year;
};

struct DebitCard {

    char holder_name[MAX_HOLDER_NAME_CHARS];    
    unsigned long long card_number; 
    unsigned short card_cvv; 
    struct Date card_valid_thru_date; 
    struct Date card_expiry_date; 
    char card_vendor[MAX_VENDOR_NAME_CHARS];
};

int main(void) {

    struct DebitCard my_debit_card; 
    unsigned long long name_length; 

    name_length = strlen("Abhijeet Rai");
    strncpy(my_debit_card.holder_name, "Abhijeet Rai", name_length);
    strncpy(my_debit_card.card_vendor, "MasterCard", strlen("MasterCard"));
    
    my_debit_card.card_valid_thru_date.day = 1; 
    my_debit_card.card_valid_thru_date.month = 1; 
    my_debit_card.card_valid_thru_date.year = 2020;

    my_debit_card.card_expiry_date.day = 1; 
    my_debit_card.card_expiry_date.month = 1; 
    my_debit_card.card_expiry_date.year = 2032;

    my_debit_card.card_number = 12344321;
    my_debit_card.card_cvv = 111;

    printf("Card Holder: %s\n", my_debit_card.holder_name);
    printf("Card Vendor: %s\n", my_debit_card.card_vendor);

    printf("Card Number: %llu\n", my_debit_card.card_number);
    printf("Card CVV: %hu\n", my_debit_card.card_cvv);

    printf("Valid through date: %hhu/%hhu/%d\n", my_debit_card.card_valid_thru_date.day, my_debit_card.card_valid_thru_date.month, my_debit_card.card_valid_thru_date.year);
    printf("Expiry date: %hhu/%hhu/%d\n", my_debit_card.card_expiry_date.day, my_debit_card.card_expiry_date.month, my_debit_card.card_expiry_date.year);

    return 0;
}