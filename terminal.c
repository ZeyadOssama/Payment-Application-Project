#include "terminal.h"
#include <stdbool.h>

/** This function will ask for the transaction data and store it in terminal data.
Transaction date is 10 characters string in the format DD/MM/YYYY, e.g 25/06/2022.
If the transaction date is NULL, less than 10 characters or wrong format will return WRONG_DATE error, else return OK.*/

EN_terminalError_t getTransactionDate(ST_terminalData_t* termData) {

	// Asking The User To Enter ThE Transaction DATE

	printf("Please Enter The Transaction Date In The Format DD/MM/YYYY: \n");

	// Stores The Data Entered in transactionDate

	gets(termData->transactionDate);
	lenght_date = strlen(termData->transactionDate);

	// Cheking The Date Entered Is 10 characters string in the format DD/MM/YYYY

	if (lenght_date < 10 && ((termData->transactionDate[2] != "/") || (termData->transactionDate[5] != "/"))) {
		printf("Incorect Date Format Entered!!\n");
		return WRONG_DATE;

	}
	else {
		printf("Correct Date Format Entered\n");
		return DONE_terminal;
	}
}

/** This function compares the card expiry date with the transaction date.
If the card expiration date is before the transaction date will return EXPIRED_CARD, else return DONE.*/

EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData) {

	// Dividing The Expiry And The Transaction Dates Entered Into The Following Integers

	int m, mm, M, MM, y, yy, Y, YY;
	//  ^  ^   ^   ^  ^  ^   ^   ^
	//  |  |   |   |  |  |   |   |
	//  M  M   |   |  Y  Y   |   |    Of The Expiry Date
	//         M   M         Y   Y    Of The Transaction Date  

	bool mounthExpiry, yearExpiry;

	// ( -'0' ) --> TO CONVERT THE char into int

	m = cardData.cardExpirationDate[0] - '0';
	mm = cardData.cardExpirationDate[1] - '0';
	y = cardData.cardExpirationDate[3] - '0';
	yy = cardData.cardExpirationDate[4] - '0';

	M = termData.transactionDate[3] - '0';
	MM = termData.transactionDate[4] - '0';
	Y = termData.transactionDate[8] - '0';
	YY = termData.transactionDate[9] - '0';

	if (m > M) {
		mounthExpiry = true;
	}
	else {
		mounthExpiry = false;
	}
	if (m <= M && mm > MM) {
		mounthExpiry = true;
	}
	else {
		mounthExpiry = false;
	}
	if (y > Y) {
		yearExpiry = true;
	}
	else {
		yearExpiry = false;
	}
	if (y <= Y && yy > YY) {
		yearExpiry = true;
	}
	else {
		yearExpiry = false;
	}

	if (yearExpiry == true) {
		printf("The Card Is Expired!!\n");
		return EXPIRED_CARD;
	}
	else {
		if (mounthExpiry == false) {
			printf("The Card Is Not Expired!!\n");
			return DONE_terminal;
		}
		else {
			printf("The Card Is Expired!!\n");
			return EXPIRED_CARD;
		}
	}
}

/** This function asks for the transaction amount and saves it into terminal data.
If the transaction amount is less than or equal to 0 will return INVALID_AMOUNT, else return DONE.*/

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData) {

	// Asking The User To Enter The Transaction Amount

	printf("Please Enter The Transaction Amount: \n");

	// Stores The Data Entered in transAmount

	scanf_s("%f", &termData->transAmount);
	amount = termData->transAmount;

	// Checks The Amount Entered Is Not EQUAL To ZERO

	if (amount == 0) {
		printf("Invaild Amount Entered!!\n");
		return INVALID_AMOUNT;
	}
	else {
		printf("Correct Amount Entered!!\n");
		return DONE_terminal;
	}
}

/** This function sets the maximum allowed amount into terminal data.
Transaction max amount is a float number.
If transaction max amount less than or equal to 0 will return INVALID_MAX_AMOUNT error, else return DONE */

EN_terminalError_t setMaxAmount(ST_terminalData_t* termData) {

	// Asking The User To Enter The Max Amount

	printf("Please Enter The Max Amount: \n");

	// Stores The Data Entered in maxTransAmount

	scanf_s("%f", &termData->maxTransAmount);
	Maxamount = termData->maxTransAmount;

	// Checks The Amount Entered Is Not EQUAL To ZERO

	if (Maxamount == 0) {
		printf("Invaild MAX Amount Entered!!\n");
		return INVALID_MAX_AMOUNT;
	}
	else {
		printf("Correct Amount Entered!!\n");
		return DONE_terminal;
	}
}

/** This function compares the transaction amount with the terminal max amount.
If the transaction amount is larger than the terminal max amount will return EXCEED_MAX_AMOUNT, else return DONE.*/

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData) {
	amount = termData->transAmount;
	Maxamount = termData->maxTransAmount;

	// Compare Between The Amount Entered And The Max Amount Entered 

	if (amount > Maxamount) {
		printf("The Max Amount Exceeded!!\n");
		return EXCEED_MAX_AMOUNT;
	}
	else {
		printf("The Max Amount Is Not Exceeded!!\n");
		return DONE_terminal;
	}
}