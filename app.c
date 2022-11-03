#include "app.h"
#include <stdio.h>
#include "Card/card.h"
#include "Terminal/terminal.h"
#include "Server/server.h"
ST_cardData_t cardData;
ST_terminalData_t termData;
ST_transaction_t transData;

/** test function void getCardHolderNameTest(void); to test all possible scenarios, happy-case, and worst-case scenarios. */
void getCardHolderNameTest(void) {
	ST_cardData_t cardData = { 0,0,0 };
	int test1;
	printf("Tester Name: Zeyad Ossama\n");
	printf("Function Name: getCardHolderName\n");
	for (test1 = 1; test1 < 3; test1++) {
		printf("Test Case:%d\n", test1);
		printf("Input Data:");
		EN_cardError_t TESTgetCardHolderName = getCardHolderName(&cardData);
		if (TESTgetCardHolderName == CARD_OK) {
			printf("Expected Result: 0 \n");
			printf("Actual Result: %d\n", TESTgetCardHolderName);
		}
		else {
			printf("Expected Result: 1\n");
			printf("Actual Result: %d\n", TESTgetCardHolderName);
		}
	}
}

/** This function will ask for the card expiry date and store it in card data.
Card expiry date is 5 characters string in the format "MM/YY", e.g "05/25".
If the card expiry date is NULL, less or more than 5 characters, or has the wrong format will return the WRONG_EXP_DATE error, else return CARD_OK. */
void getCardExpiryDateTest(void) {
	ST_cardData_t cardData = {0,0,0};
	int test2;
	printf("Tester Name: Zeyad Ossama\n");
	printf("Function Name: getCardExpiryDate \n");
	for (test2 = 1; test2 < 3; test2++) {
		printf("Test Case:%d\n", test2);
		printf("Input Data:");
		EN_cardError_t TESTgetExpiryDate = getCardExpiryDate(&cardData);
		if (TESTgetExpiryDate == CARD_OK) {
			printf("Expected Result: 0\n");
			printf("Actual Result: %d\n", TESTgetExpiryDate);
		}
		else {
			printf("Expected Result: 2\n");
			printf("Actual Result: %d\n", TESTgetExpiryDate);
		}
	}
}

/** This function will ask for the card's Primary Account Number and store it in card data.
PAN is 20 numeric characters string, 19 character max, and 16 character min.
If the PAN is NULL, less than 16 or more than 19 characters, will return the WRONG_PAN error, else return CARD_OK.
*/
void getCardPANTest(void) {
	ST_cardData_t cardData = { 0,0,0 };
	int test3;
	printf("Tester Name: Zeyad Ossama\n");
	printf("Function Name: getCardPAN  \n");
	for (test3 = 1; test3 < 3; test3++) {
		printf("Test Case:%d\n", test3);
		printf("Input Data:");
		EN_cardError_t TESTgetPAN = getCardPAN(&cardData);
		if (TESTgetPAN == CARD_OK) {
			printf("Expected Result: 0\n");
			printf("Actual Result: %d\n", TESTgetPAN);
		}
		else {
			printf("Expected Result: 3\n");
			printf("Actual Result: %d\n", TESTgetPAN);
		}
	}
}

/** This function will ask for the transaction date and store it in terminal data.
Transaction date is 10 characters string in the format DD/MM/YYYY, e.g 25/06/2022.
If the transaction date is NULL or is less than 10 characters or wrong format will return the WRONG_DATE error, else return TERMINAL_OK.*/ 

void getTransactionDateTest(void) {
	ST_terminalData_t termData = { 0,0,0 };
	int test4;
	printf("Tester Name: Zeyad Ossama\n");
	printf("Function Name: getTransactionDate  \n");
	for (test4 = 1; test4 < 3; test4++) {
		printf("Test Case:%d\n", test4);
		printf("Input Data:");
		EN_terminalError_t TESTTransactionDate = getTransactionDate(&termData);
		if (TESTTransactionDate == WRONG_DATE) {
			printf("Expected Result: 1\n");
			printf("Actual Result: %d\n", TESTTransactionDate);
		}
		else {
			printf("Expected Result: 0\n");
			printf("Actual Result: %d\n", TESTTransactionDate);
		}
	}
}

/** This function compares the card expiry date with the transaction date.
If the card expiration date is before the transaction date will return EXPIRED_CARD, else return TERMINAL_OK.*/

void isCardExpriedTest(void) {
	ST_terminalData_t termData = { 0,0,0 };
	ST_cardData_t cardData = { 0,0,0 };
	int test5;
	printf("Tester Name: Zeyad Ossama\n");
	printf("Function Name: isCardExpried  \n");
	for (test5 = 1; test5 < 3; test5++) {
		printf("Test Case:%d\n", test5);
		printf("Input Data:");
		EN_terminalError_t TESTTRANSACTION = getTransactionDate(&cardData);
		EN_cardError_t TestExpiry = getCardExpiryDate(&cardData);
		EN_terminalError_t TESTExpired = isCardExpired(cardData,termData);
		if (TESTExpired == EXPIRED_CARD) {
			printf("Expected Result: 2\n");
			printf("Actual Result:%d\n", TESTExpired);
		}
		else {
			printf("Expected Result: 0\n");
			printf("Actual Result: %d\n", TESTExpired);
		}
	}
}

/** This function asks for the transaction amount and saves it into terminal data.
If the transaction amount is less than or equal to 0 will return INVALID_AMOUNT, else return TERMINAL_OK.*/

void getTransactionAmountTest(void) {
	ST_terminalData_t termData = { 0,0,0 };
	int test6;
	printf("Tester Name: Zeyad Ossama\n");
	printf("Function Name: getTransactionAmount  \n");
	for (test6 = 1; test6 < 3; test6++) {
		printf("Test Case:%d\n", test6);
		printf("Input Data:");
		EN_terminalError_t TESTTransactionAmount = getTransactionAmount(&termData);
		if (TESTTransactionAmount == INVALID_AMOUNT) {
			printf("Expected Result: 4\n");
			printf("Actual Result:%d\n", TESTTransactionAmount);
		}
		else {
			printf("Expected Result: 0\n");
			printf("Actual Result:%d\n", TESTTransactionAmount);
		}
	}
}

/** This function compares the transaction amount with the terminal max allowed amount.
If the transaction amount is larger than the terminal max allowed amount will return EXCEED_MAX_AMOUNT, else return TERMINAL_OK.*/

void isBelowMaxAmountTest(void) {
	ST_terminalData_t termData = { 0,0,0 };
	int test7;
	printf("Tester Name: Zeyad Ossama\n");
	printf("Function Name: getTransactionAmount  \n");
	for (test7 = 1; test7 < 3; test7++) {
		printf("Test Case:%d\n", test7);
		printf("Input Data:");
		EN_terminalError_t TESTTransactionAmount2 = getTransactionAmount(&termData);
		EN_terminalError_t TESTMax = setMaxAmount(&termData);
		EN_terminalError_t TESTBelowMax = isBelowMaxAmount(&termData);
		if (TESTBelowMax == EXCEED_MAX_AMOUNT) {
			printf("Expected Result:5\n");
			printf("Actual Result:%d\n", TESTBelowMax);
		}
		else {
			printf("Expected Result:0\n");
			printf("Actual Result:%d\n", TESTBelowMax);
		}
	}
}

/** This function takes the maximum allowed amount and stores it into terminal data.
Transaction max amount is a float number.
If transaction max amount less than or equal to 0 will return the INVALID_MAX_AMOUNT error, else return TERMINAL_OK.*/

void setMaxAmountTest(void) {
	ST_terminalData_t termData = { 0,0,0 };
	int test8;
	printf("Tester Name: Zeyad Ossama\n");
	printf("Function Name: getTransactionAmount  \n");
	for (test8 = 1; test8 < 3; test8++) {
		printf("Test Case:%d\n", test8);
		printf("Input Data:");
		EN_terminalError_t TESTMax2 = setMaxAmount(&termData);
		if (TESTMax2 == INVALID_MAX_AMOUNT) {
			printf("Expected Result: 6\n");
			printf("Actual Result:%d\n", TESTMax2);
		}
		else {
			printf("Expected Result: 0\n");
			printf("Actual Result:%d\n", TESTMax2);
		}
	}
}

/** This function will take all transaction data and validate its data, it contains all server logic.
It checks the account details and amount availability.
If the account does not exist return FRAUD_CARD, if the amount is not available will return DECLINED_INSUFFECIENT_FUND, if the account is blocked will return DECLINED_STOLEN_CARD, if a transaction can't be saved will return INTERNAL_SERVER_ERROR , else returns APPROVED.
It will update the database with the new balance.*/

void recieveTransactionDataTest(void) {
	ST_cardData_t cardData = { "Zeyad Ossama","307790134933005506","04/11"};
	ST_terminalData_t termData = {500,5000,"04/11/2010"};
	struct ST_transaction_t transData;
	transData.cardHolderData = cardData;
	transData.terminalData = termData;
	transData.transactionSequenceNumber = "10";
	transData.transState = BLOCKED;
	printf("Tester Name: Zeyad Ossama\n");
	printf("Function Name: recieveTransactionData \n");
	printf("Test Case:1\n");
	printf("Input Data:");
	EN_transState_t TESTrecieveTransaction = recieveTransactionData(&transData);
	printf("Expected Result:3\n");
	printf("Actual Result: %d\n",TESTrecieveTransaction);
	
	}

/** This function will take card data and validate if the account related to this card exists or not.
It checks if the PAN exists or not in the server's database (searches for the card PAN in the DB).
If the PAN doesn't exist will return ACCOUNT_NOT_FOUND and the account reference will be NULL, else will return SERVER_OK and return a reference to this account in the DB. */

void isValidAccountTest(void) {
	ST_cardData_t cardData = { "Zeyad Ossama","307790134933005506","04/11" };
	printf("Tester Name: Zeyad Ossama\n");
	printf("Function Name: isValidAccount  \n");
	
		printf("Test Case:1\n");
		printf("Input Data:");
		EN_serverError_t TESTValid = isValidAccount(&cardData);
		printf("Expected Result:0\n");
		printf("Actual Result:%d\n", TESTValid);

		ST_cardData_t cardData1 = { "Zeyad Ossama","307790131200000000","04/11" };
		printf("Tester Name: Zeyad Ossama\n");
		printf("Function Name: isValidAccount  \n");

		printf("Test Case:2\n");
		printf("Input Data:");
		EN_serverError_t TESTValid1 = isValidAccount(&cardData1);
		printf("Expected Result:3\n");
		printf("Actual Result:%d\n", TESTValid1);

}
			
/** This function takes a reference to the account into the database and verifies if it is blocked or not.
If the account is running it will return SERVER_OK, else if the account is blocked it will return BLOCKED_ACCOUNT.*/

void isBlockedAccountTest(void) {
	ST_accountsDB_t Accounts = { 9000.0  ,RUNNING,"302748634527182821" };
	printf("Tester Name: Zeyad Ossama\n");
	printf("Function Name: isBlockedAccount  \n");

	printf("Test Case:1\n");
	printf("Input Data:");
	EN_serverError_t TESTBlock = isBlockedAccount(&Accounts);
		printf("Expected Result:0\n");
		printf("Actual Result:%d\n", TESTBlock);

	ST_accountsDB_t Accounts1 = { 15000.5 ,BLOCKED,"350276993032537351" };
	printf("Tester Name: Zeyad Ossama\n");
	printf("Function Name: isBlockedAccount  \n");

	printf("Test Case:2\n");
	printf("Input Data:");
	EN_serverError_t TESTBlock1 = isBlockedAccount(&Accounts1);
	printf("Expected Result:5\n");
	printf("Actual Result:%d\n", TESTBlock1);
}

/** This function will take terminal data and a reference to the account in the database and check if the account has a sufficient amount to withdraw or not.
It checks if the transaction's amount is available or not.
If the transaction amount is greater than the balance in the database will return LOW_BALANCE, else will return SERVER_OK.*/

void isAmountAvailableTest(void) {
	ST_accountsDB_t Accounts = { 9000.0  ,RUNNING,"302748634527182821" };
	ST_terminalData_t transData = { 500.0, 50000,21 / 11 / 2022 };
	printf("Tester Name: Zeyad Ossama\n");
	printf("Function Name: isAmountAvailable  \n");
		printf("Test Case: 1\n");
		printf("Input Data:");
		EN_serverError_t TESTAmountAvailable = isAmountAvailable(&termData,&Accounts);
		if (TESTAmountAvailable == OK_SERVER) {
			printf("Expected Result: 0\n");
			printf("Actual Result: %d\n", TESTAmountAvailable);
		}
		else {
			printf("Expected Result: 4\n");
			printf("Actual Result: %d\n", TESTAmountAvailable);
		}
	ST_accountsDB_t Accounts1 = { 550.0  ,RUNNING,"302748634527182821" };
	ST_terminalData_t transData1 = { 30.0, 50000,21 / 11 / 2022 };
	printf("Tester Name: Zeyad Ossama\n");
	printf("Function Name: isAmountAvailable  \n");
	printf("Test Case: 2\n");
	printf("Input Data:");
	EN_serverError_t TESTAmountAvailable1 = isAmountAvailable(&termData,&Accounts);
	if (TESTAmountAvailable1 == OK_SERVER) {
		printf("Expected Result: 0\n");
		printf("Actual Result: %d\n", TESTAmountAvailable1);
	}
	else {
		printf("Expected Result: 4\n");
		printf("Actual Result: %d\n", TESTAmountAvailable1);
	}
	}

/** This function will store all transaction data in the transactions database.
It gives a sequence number to a transaction, this number is incremented once a transaction is processed into the server, you must check the last sequence number in the server to give the new transaction a new sequence number.
It saves any type of transaction, APPROVED, DECLINED_INSUFFECIENT_FUND, DECLINED_STOLEN_CARD, FRAUD_CARD, INTERNAL_SERVER_ERROR.
It will list all saved transactions using the listSavedTransactions function.
Assuming that the connection between the terminal and server is always connected, then it will return SERVER_OK.*/

void saveTransactionTest(void) {
	ST_cardData_t cardData = { "Zeyad Ossama","307790134933005506","04/11" };
	ST_terminalData_t termData = { 500,5000,"04/11/2010" };
	struct ST_transaction_t transData;
	transData.cardHolderData = cardData;
	transData.terminalData = termData;
	transData.transactionSequenceNumber = "10";
	transData.transState = RUNNING;
	printf("Tester Name: Zeyad Ossama\n");
	printf("Function Name: saveTransaction \n");
	printf("Test Case:1\n");
	printf("Input Data:");
	EN_transState_t TESsaveTransaction = saveTransaction(&transData);
	printf("Expected Result:0\n");
	printf("Actual Result: %d\n", TESsaveTransaction);

	ST_cardData_t cardData1 = { "Zeyad Ossama","307790134900005506","12/10" };
	ST_terminalData_t termData1 = { 800,3000,"25/10/2022" };
	struct ST_transaction_t transData1;
	transData.cardHolderData = cardData1;
	transData.terminalData = termData1;
	transData.transactionSequenceNumber = "300";
	transData.transState = RUNNING;
	printf("Tester Name: Zeyad Ossama\n");
	printf("Function Name: saveTransaction \n");
	printf("Test Case:2\n");
	printf("Input Data:");
	EN_transState_t TESsaveTransaction1 = saveTransaction(&transData1);
	printf("Expected Result:0\n");
	printf("Actual Result: %d\n", TESsaveTransaction1);

}

void appstart(void) {

	if (getCardHolderName(&transData.cardHolderData) == WRONG_NAME) {
		printf("PROGRAM WILL CLOSE !!!!!\n");
		exit(0);
	}
	else {

		getCardExpiryDate(&transData.cardHolderData);
		getCardPAN(&transData.cardHolderData);

		getTransactionDate(&transData.terminalData);

		if (isCardExpired(transData.cardHolderData, transData.terminalData) == EXPIRED_CARD) {
			printf("PROGRAM WILL CLOSE !!!!!\n");
			exit(0);
		}
		else {
			getTransactionAmount(&transData.terminalData);
			setMaxAmount(&transData.terminalData);
			recieveTransactionData(&transData);
			EN_serverError_t Available = isAmountAvailable(&transData.terminalData, &Accounts);
			if (Available == TRANSACTION_NOT_FOUND || Available == LOW_BALANCE ) {
				printf("Insuffient Funds");
				exit(0);
			}
			else {
				

				if (isBelowMaxAmount(&transData.terminalData) == EXCEED_MAX_AMOUNT) {
					printf("PROGRAM WILL CLOSE !!!!!\n");
					exit(0);
				}

				else {
					listSavedTransactions();
					
				}
			}
		}
	}
}
int main() {
	appstart();
}