#include "server.h"
#include "../Card/card.h"
#include "../Terminal/terminal.h"

ST_accountsDB_t Accounts[255] =
{
	// balances:   state:      PANs:

		{1000.0  ,RUNNING,"5078034948991109"},
		{1500.5  ,BLOCKED,"392533806672556039"},
		{9000.0  ,RUNNING,"302748634527182821"},
		{12000.0 ,RUNNING,"307790134933005506"},
		{15000.5 ,BLOCKED,"350276993032537351"},
		{1000.0  ,RUNNING,"2479189249803973"},
		{500.0   ,BLOCKED,"3800558864160504382"},
		{100000.0,BLOCKED,"5807007076043875"},
		{0.0  ,RUNNING,"8989374615436851"},
		{55500.0 ,BLOCKED,"4057247864289864108"}
};

struct ST_transaction_t transData[255];
int index;
int sequence = 0;

/** This function will take card data and validate these data.
It checks if the PAN exists or not in the server's database.
If the PAN doesn't exist will return DECLINED_STOLEN_CARD, else will return OK */

EN_serverError_t isValidAccount(ST_cardData_t* cardData) {
	for (int i = 0; i < 255; i++) {

		// Compare The PAN Entered With The PANs Saved In The Database Array

		if (strcmp((const char*)cardData->primaryAccountNumber, (const char*)Accounts[i].primaryAccountNumber_Saved)==0) {
			
			
			printf("The PANs Is Found\n");
			index = i;
			
			return OK_SERVER;
		}
		
	}

	printf("The PANs Is NOT Found\n");
	return ACCOUNT_NOT_FOUND;
}

/** This function will take terminal data and validate these data.
It checks if the transaction's amount is available or not.
If the transaction amount is greater than the balance in the database will return LOW_BALANCE, else will return OK */

EN_serverError_t isAmountAvailable(ST_terminalData_t* termData, ST_accountsDB_t* accountRefrence) {
	if (accountRefrence[index].balance == 0) {

		return TRANSACTION_NOT_FOUND;
	}
	else {
		
		if (termData->transAmount == INVALID_AMOUNT) {
			return TRANSACTION_NOT_FOUND;
		}
		else {
			
			// Compare Between The Balance Saved In The Database Array With The Transaction Amount Entered

			if (termData->transAmount > accountRefrence[index].balance) {
				printf("The Transaction Ammount Is Greater Than The Balance\n");
				return LOW_BALANCE;
			}
			else {
				printf("The Balance Is Greater Than The Transaction Ammount\n");
				return OK_SERVER;
			}
		}
	}
}

/** This function will take all transaction data into the transactions database.
It gives a sequence number to a transaction, this number is incremented once a transaction is processed into the server.
If saves any type of transaction, APPROVED or DECLINED, with the specific reason for declining/transaction state.
If transaction can't be saved will return SAVING_FAILED, else will return OK */

EN_serverError_t saveTransaction(ST_transaction_t* transData) {

	// Sequence Is Initiallized EQUAL To ZERO

	// Checks Is Sequence Is Lower Than 255 Then Stores The Data Entered In The Database

	if (sequence < 255) {
		transData[sequence].cardHolderData = transData->cardHolderData;
		transData[sequence].terminalData = transData->terminalData;
		transData[sequence].transState = transData->transState;
		transData[sequence].transactionSequenceNumber = transData->transactionSequenceNumber;
		sequence++;
		return OK_SERVER;
	}
	else {
		return SAVING_FAILED;
	}

}

/** This function takes a reference to the account into the database and verifies if it is blocked or not.
If the account is running it will return SERVER_OK, else if the account is blocked it will return BLOCKED_ACCOUNT*/

EN_serverError_t isBlockedAccount(ST_accountsDB_t* accountRefrence) {

	// Checks The State Of The Account ( RUNNING OR BLOCKED )
	
	if (Accounts[index].state == 0) {
		printf("The Account Is RUNNING\n");
		return OK_SERVER;
	}
	else {
		printf("The Account Is BLOCKED\n");
		return BLOCKED_ACCOUNT;
	}
}


/** This function will take all transaction data and validate its data.
It checks the account details and amount availability.
If the account does not exist return DECLINED_STOLEN_CARD, if the amount is not available will return DECLINED_INSUFFECIENT_FUND, if a transaction can't be saved will return INTERNAL_SERVER_ERROR and will not save the transaction, else returns APPROVED.
It will update the database with the new balance. */

	EN_transState_t recieveTransactionData(ST_transaction_t * transData){

		ST_cardData_t cardData = transData->cardHolderData;
		ST_terminalData_t termData = transData->terminalData;
		

		// Checks The Validation Of The Card

		if (isValidAccount(&cardData) == ACCOUNT_NOT_FOUND) {
			printf("Account Is Not Valid \n");
			return DECLINED_STOLEN_CARD;
		}
		

		// Checks If The Data Entered Is Saved Or NOT

		else if (saveTransaction(&termData) == SAVING_FAILED) {
			return INTERNAL_SERVER_ERROR;
		}

		// Checks The Account Is Blocked OR NOT

		else if (isBlockedAccount(&Accounts) == BLOCKED_ACCOUNT){
			return FRAUD_CARD;
		}
		else {

			Accounts[index].balance = Accounts[index].balance - termData.transAmount;
			if (Accounts[index].balance < 0) {
				return DECLINED_INSUFFECIENT_FUND;
			}
			else {

				printf("The Remainig Balance is: %f\n", Accounts[index].balance);
				return APPROVED;
			}
		}
	}

	// This function prints all transactions found in the transactions DB

	void listSavedTransactions(void) {
		for (int i = 0; i < sizeof(transData); i++) {

			printf("#########################\n");
			printf("Transaction Sequence Number:%d\n", transData[i].transactionSequenceNumber);
			printf("Transaction Date: %s\n", transData[i].terminalData.transactionDate);
			printf("Transaction Amount: %f\n", transData[i].terminalData.transAmount);
			printf("Transaction State: %d\n", transData[i].transState);
			printf("Terminal Max Amount: %f\n", transData[i].terminalData.maxTransAmount);
			printf("Cardholder Name: %s\n", transData[i].cardHolderData.cardHolderName);
			printf("PAN: %s\n", transData[i].cardHolderData.primaryAccountNumber);
			printf("Card Expiration Date: %s\n", transData[i].cardHolderData.cardExpirationDate);
			printf("#########################");
		}

	}