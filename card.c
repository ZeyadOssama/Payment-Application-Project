#include "card.h"
#include <stdio.h>

/** This function will ask for the cardholder's name and store it into card data.
Card holder name is 24 characters string max and 20 min.
If the cardholder name is NULL, less than 20 characters or more than 24 will return WRONG_NAME error, else return DONE.*/

EN_cardError_t getCardHolderName(ST_cardData_t* cardData) {

	// Asking The User To Enter The Card Holder Name 

	printf("Please Enter The Card Holder Name: \n ");

	// Stores The Name Entered In cardHolderName

	gets(cardData->cardHolderName);

	// Checking That The Card Holder Name Is MUST Be 24 Alphabetic Characters Max and 20 Min

	if (strlen(cardData->cardHolderName) < 24 && strlen(cardData->cardHolderName) > 20 && strlen(cardData->cardHolderName) != 0){
		printf("Correct Name Data Entry!!\n");
		return CARD_OK;
	}
	else {
		printf("Incorrect Name Data Entry !!\n");
		return  WRONG_NAME;
	}

}
/** This function will ask for the card expiry date and store it in card data.
Card expiry date is 5 characters string in the format "MM/YY", e.g "05/25".
If the card expiry date is NULL, less or more than 5 characters, or has the wrong format will return WRONG_EXP_DATE error, else return DONE.*/

EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData) {

	// Asking The User To Enter ThE EXPIRY DATE

	printf("Please Enter The Expiry Date Of The Card In The Form MM/YY: \n");

	// Stores The Date Entered In The "cardExpirationDate" 

	gets(cardData->cardExpirationDate);

	// Checking That The Expiration Date is MUST Be 5 characters In The Format "MM/YY"

	if (strlen(cardData->cardExpirationDate) > 5  && cardData->cardExpirationDate[2] != "/") {
		printf("The Date Format Is Incorrect!!\n");
		return WRONG_EXP_DATE;

	}
	else {
		printf("Correct Date Format Entered\n");
		return CARD_OK;
	}


}
/** This function will ask for the card's Primary Account Number and store it in card data.
PAN is 20 characters alphanumeric only string 19 character max, and 16 character min.
If the PAN is NULL, less than 16 or more than 19 characters, will return WRONG_PAN error, else return DONE.*/

EN_cardError_t getCardPAN(ST_cardData_t* cardData) {

	// Asking The User To Enter The Card's Primary Account Number

	printf("Please Enter The Card's Primary Account Number:  \n");

	// Stores The Number Entered In The primaryAccountNumber 

	gets(cardData->primaryAccountNumber);

	// Checking The Card's Primary Account Number is 20 numbers,19 character max,and 16 character min.

	if (strlen(cardData->primaryAccountNumber) > 19 || strlen(cardData->primaryAccountNumber) < 16) {
		printf("Incorect Format Of Primary Account Number Entered!!\n");
		return WRONG_PAN;
	}
	else {
		printf("Correct Format Of Primary Account Number Entered\n");
		return CARD_OK;
	}
}

