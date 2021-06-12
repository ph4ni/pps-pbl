#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Function declarations*/
void CreateAcc(int a);
void transaction(int a);
void login();
void home();

/*User Structure*/
struct User {
   char  name[50];
   int   pin;
   float balance;
}user[50];    /*Array consisting of 50 user accounts*/

/*Global variables*/
int nos = 0;     /*Number of user accounts in use*/
int current;     /*Index of the currently logged in account*/

/*Main function*/
int main() {

	printf("|-----------------------------|\n");
	printf("|---Welcome to Virtual Bank---|\n");
	printf("|-----------------------------|\n\n");	
	printf("To start using, create an account first\n");
	CreateAcc(0); //first user has index 0 in array

	return 0;
}

void login(){
	int selected;

	printf("\nSelect account to login\n");
	for(int i =1; i<=nos;i++){
		printf("%d.\t%s\n",i,user[i-1].name);
	}

	printf("\nEnter account number: ");
	scanf("%d",&selected);
	if(selected<=nos && selected>0){
		printf("\nEnter Pin to proceed: ");
		
		int enteredpin;
		scanf("%d",&enteredpin);
		
		if(enteredpin != user[selected-1].pin){
	 		printf("\nWrong PIN. Please Try Again\n\n");
	 		int i;
	 		for(i =4;i>=1;i--){  //For loop for a maxiumum of four tries to re-enter PIN.
	 			printf("%d tries left :",i);
	 			scanf("%d",&enteredpin);
	 			if(enteredpin == user[selected-1].pin){
	 				current = selected-1;
	 				transaction(current);
	 				break;
	 			}
	 		} 
	 		if(i==0){ //All tries exhausted
	 			printf("\nFailed to login. Try Again\n");
	 			login();
	 		}
		}else{
			printf("\nSucessfully authenticated!\n");
			current = selected-1; //Change current account
			transaction(current); //Proceed to transactions page
		}
		
	}else{
		printf("\nInvalid account number. Try Again\n_______________________________________________\n");
		home(); //Redirect to main menu
	}
}

void CreateAcc(int a){ //a is the user index
	printf("\nEnter name: ");
	scanf("%s",user[a].name);
	printf("Set 4 digit PIN: ");
	scanf("%d",&user[a].pin);
	
	user[a].balance = 0; //Set initial balance to zero
	printf("\nAccount successfully created!\n");
	nos++; //increment number of accounts
	printf("___________________________________\n");
	home();
}

void home(){
	int sec; //selection variable
	printf("\nSelect action to proceed\n\n");
	printf("1. Create a new account\n");
	printf("2. Login to existing account\n");
	printf("3. Exit\n");
	printf("\nEnter your selection: ");
	scanf("%d",&sec);

	if(sec == 1){
		CreateAcc(nos); //To create new account
	}else if(sec == 2){
		login();        //login page
	}else if(sec ==3){
		printf("\nThank you for visiting us!\n");
		exit(0);        //exit out of program
	}
	else{
		printf("Invalid. Try again");
		home();         //go back to main menu
	}
}

void transaction(int a){
	printf("___________________________________\n");
	int check,anotherTransaction;
	printf("\nLogged in as %s\n",user[a].name);
	printf("\nSelect option to perform transactions\n\n");
	printf("1. Deposit\n"); 
	printf("2. Withdraw\n"); 
	printf("3. Check Balance\n");
	printf("4. Transfer Money\n5. Logout\n\nEnter option number: ");
	scanf("%d",&check);
	
	switch(check){
	
		case 1:
		// Depositing
		printf("Enter the amount to deposit in INR: ₹");
		float amount2deposit;
		scanf("%f",&amount2deposit);
		user[a].balance = user[a].balance + amount2deposit;
		printf("\nDeposit completed! Updated balance is ₹%.2f\n",user[a].balance);
		
		printf("\nDo you want to perform another transaction?\nPress 1 to proceed and 2 to exit to home screen\n\n"); 
      		scanf("%d", &anotherTransaction); 
      		if(anotherTransaction == 1){
        		transaction(current);
      		}else if(anotherTransaction == 2){
      			home();
      		}
		break;
		
    case 2:
    //Withdraw
    printf("Enter the amount to withdraw in INR: ₹");
		float amount2withdraw;
		scanf("%f",&amount2withdraw);
		
    if(amount2withdraw>user[current].balance){
				printf("\nInsufficient balance. Deposit required amount before withdrawing.\n");
			}else{
        user[a].balance = user[a].balance - amount2withdraw;
		    printf("\nWithdrawal completed! Updated balance is ₹%.2f\n",user[a].balance);
      } 

    printf("\nDo you want to perform another transaction?\nPress 1 to proceed and 2 to exit to home screen\n\n"); 
      		scanf("%d", &anotherTransaction); 
      		if(anotherTransaction == 1){
        		transaction(current);
      		}else if(anotherTransaction == 2){
      			home();
      		}
		break;

		case 3:
		//Check Balance
		printf("\nAvailable Balance: ₹%.2f\n",user[current].balance);
		printf("\nDo you want to perform another transaction?\nPress 1 to proceed and 2 to exit\n\n"); 
      		scanf("%d", &anotherTransaction); 
      		if(anotherTransaction == 1){
        		transaction(current);
      		}else if(anotherTransaction == 2){
      			home();
      		}
		break;
		
		case 4:
		//Transfers
		if(nos<2){
			printf("\nNo accounts available to transfer. Create new account first\n");
			
		}else{
			printf("\nSelect account to transfer to\n");
			int selected; float amnt;
			for(int i=1;i<=nos;i++){
				if(i-1!=current){
					printf("%d.\t%s\n",i,user[i-1].name);
				}
			}
			printf("\nEnter account number :");
			scanf("%d",&selected);
			while(selected <=0 || selected>nos || selected-1 == current){
				printf("Enter valid account number : ");
				scanf("%d",&selected);
			}
			printf("\nTransferring from %s to %s",user[current].name,user[selected-1].name);
			printf("\nEnter amount to transfer : ₹");
			scanf("%f",&amnt);
			if(amnt>user[current].balance){
				printf("\nInsufficient balance to transfer. Deposit required amount before transferring.");
			}else{
				user[current].balance = user[current].balance - amnt;
				user[selected-1].balance = user[selected-1].balance + amnt;
				printf("\nTransferred Successfully!\n");
				printf("Updated balances:\n");
				printf("Acc name\tBalance\n");
				printf("%s\t₹%.2f\n",user[current].name,user[current].balance);
				printf("%s\t₹%.2f",user[selected-1].name,user[selected-1].balance);
			}
			
      		}
		printf("\n\nDo you want to perform another transaction?\nPress 1 to proceed and 2 to exit\n\n"); 
      		scanf("%d", &anotherTransaction); 
      		if(anotherTransaction == 1){
        		transaction(current);
      		}else if(anotherTransaction == 2){
      			home();
      		}
		break;
		
		case 5:
		//logout
		printf("logging out...\n");
		printf("Logged out successfully!\n");
		printf("________________________________________________\n");
		home();
		break;
	}
}
