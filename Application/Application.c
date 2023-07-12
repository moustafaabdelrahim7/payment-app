#include"Application.h"

void main()
{
    ST_cardData_t card_data;
    ST_terminalData_t terminal_data;
    ST_transaction_t  transaction_data;

    uint8_t status=WRONG_NAME;

 /***********************************************************/
    while(status==WRONG_NAME)
         {
        status=getCardHolderName(card_data.cardHolderName);
        printf("invalid name\n");
         }
    if(status==CARD_OK)
     {
    system("cls");
     }

  /***************************************************************/
    status=WRONG_EXP_DATE;
    while(status==WRONG_EXP_DATE)
         {
        status=getCardExpiryDate(card_data.cardExpirationDate);
         }
   if(status==CARD_OK)
     {
    system("cls");
     }

  /***************************************************************/
  status=WRONG_PAN;
   while(status==WRONG_PAN)
       {
       status=getCardPAN(card_data.primaryAccountNumber);
       }
    if(status==CARD_OK)
     {
    system("cls");
     }

    /*****************************************************************/
   status=WRONG_DATE;
   while(status==WRONG_DATE)
       {
       status=getTransactionDate(&terminal_data);
       }
    if(status==TERMINAL_OK)
     {
    system("cls");
     }
     /********************************************************************/
     status=isCardExpired(&card_data,&terminal_data);
     if(status==EXPIRED_CARD)
     {
         printf("Declined\n");
         printf("Expired Card");
         break;
     }
     else
     {
         system("cls");
     }
     /*********************************************************************/
     status=INVALID_AMOUNT;
     while(status==INVALID_AMOUNT)
     {
      status=getTransactionAmount(&terminal_data);
     }

     if(status==TERMINAL_OK)
     {
         status=isBelowMaxAmount(&terminal_data);
         if(status==EXCEED_MAX_AMOUNT)
         {
             printf("Declined Amount\n");
             printf("Exceeding Amount");
         }
         else
         {
             system("cls");
         }
     }
    /***********************************************************************/
    /*
    transaction_data  {
    card,ter
    }
    _isValidAccount = isValidAccount(&card_data,p_account);
    _isBlockedAccount=isBlockedAccount(p_account);
    _isAmountAvailable=isAmountAvailable(&terminal_data,p_account);


    status=recieveTransactionData(&transaction_data);
    if(status==FRAUD_CARD)
    {


    }

*/

}
