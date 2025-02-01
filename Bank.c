#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  //Declaring All the variables necessary for the program
int i;
int oppy;
int details[4];
int option;
int choice;
int depositamount;
int withdrawamount;
char sentence[100];

  //Creating a structure of a typical Bank Account 
struct BankAccount{
char firstname[50];
char lastname[50];
int age;
char maritalstatus[30];
char country[50];
char province[50];
char district[50];
char city[50];
char address[50];
int pin;
int transactionpin;
int balance;
int accountnumber;
};

//We use BankAccount1 to store the details of user while they're signing up
struct BankAccount BankAccount1;
strcpy(BankAccount1.firstname,"");
strcpy(BankAccount1.lastname,"");
BankAccount1.age;
strcpy(BankAccount1.maritalstatus,"");
strcpy(BankAccount1.country,"");
strcpy(BankAccount1.province,"");
strcpy(BankAccount1.district,"");
strcpy(BankAccount1.city,"");
strcpy(BankAccount1.address,"");
BankAccount1.pin;
BankAccount1.transactionpin;
BankAccount1.balance;
BankAccount1.accountnumber;

  //We use supposedBankAccount1 to store the details of the user while they're logging in
struct BankAccount supposedBankAccount1;
strcpy( supposedBankAccount1.firstname, "");
strcpy(supposedBankAccount1.lastname,"");
BankAccount1.age;
strcpy(supposedBankAccount1.maritalstatus,"");
strcpy(supposedBankAccount1.country,"");
strcpy(supposedBankAccount1.province,"");
strcpy(supposedBankAccount1.district,"");
strcpy(supposedBankAccount1.city,"");
strcpy(supposedBankAccount1.address,"");
supposedBankAccount1.pin;
supposedBankAccount1.transactionpin;
supposedBankAccount1.balance;
supposedBankAccount1.accountnumber;

printf("-------------------------------------\n");
printf("Welcome to the Bank \n");
printf("-------------------------------------\n");
  
    //We ask the user to whether choose to continue further using the program or exit it as a whole 
   printf("1.Continue\n2.Exit\n");
   printf("Choose an option:");
   scanf("%d",&oppy);
  
  while(oppy!=2){
    printf("-------------------------------------\n");
printf("Log In if you have an existing account registered in The Bank. Sign Up to create your own brand new bank account ");
printf("if you do not already have one.\n1.Log In \n2.Sign Up\n");
printf("Select an option:");
scanf("%d",&option);

switch(option){

  //Logging phase
case 1:
printf("Enter your Account Number(10 digits):");
scanf("%d",&supposedBankAccount1.accountnumber);

  //Looking for the user's account number in the database 
  FILE * fpointer1 = fopen("BankDatabase.txt", "r");

for(i=0;i<1000;i++){  
fscanf(fpointer1,"%s\t%d\t%d\t%d\t%d",BankAccount1.firstname,&BankAccount1.accountnumber,&BankAccount1.pin,&BankAccount1.transactionpin,&BankAccount1.balance);
  if(supposedBankAccount1.accountnumber == BankAccount1.accountnumber) { 
      i=1000;
  } 
}
  fclose(fpointer1);
  
if(supposedBankAccount1.accountnumber!= BankAccount1.accountnumber) {
  printf("Account Number does not exist\n");
} else{
  printf("Enter your PIN:");
  scanf("%d", &supposedBankAccount1.pin);
  
  if(supposedBankAccount1.pin != BankAccount1.pin){
    printf("Incorrect PIN");
  }else{
    //User has finally logged in
    printf("-------------------------------------\n");
    printf("Welcome %s\n",BankAccount1.firstname);
    printf("-------------------------------------\n");
    printf("1.Deposit Money\n");
    printf("2.Withdraw Money\n");
    printf("3.Check Balance\n");
    printf("4.Display Transaction History\n");
    printf("5.Exit\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
switch(choice){
  case 1:
        printf("Enter your Transaction PIN:");
    scanf("%d",&supposedBankAccount1.transactionpin);
    if(supposedBankAccount1.transactionpin != BankAccount1.transactionpin){
          printf("Incorrect Transaction PIN");
     }
      else{
          printf("Enter the amount you want to deposit:");
      scanf("%d",&depositamount);
      BankAccount1.balance = BankAccount1.balance + depositamount;
            printf("You successfully deposited %d\n",depositamount);
      FILE * fpointer2 = fopen("Transaction.txt", "a");
fprintf(fpointer2,"You successfully deposited %d\n",depositamount);
fclose(fpointer2);
      }
    FILE * fpointer4 = fopen("BankDatabase.txt", "w");
fprintf(fpointer4,"%s\t%d\t%d\t%d\t%d\n",BankAccount1.firstname,BankAccount1.accountnumber,BankAccount1.pin,BankAccount1.transactionpin,BankAccount1.balance);
fclose(fpointer4);
  break;
  case 2:
    printf("Enter your Transaction PIN:");
    scanf("%d",&supposedBankAccount1.transactionpin);
    if(supposedBankAccount1.transactionpin != BankAccount1.transactionpin){
          printf("Incorrect Transaction PIN");
     }
      else{
          printf("Enter the amount you want to withdraw:");
      scanf("%d",&withdrawamount);
        if(withdrawamount > BankAccount1.balance){
              printf("Insufficient Balance.\n");
        }
        else{
          BankAccount1.balance = BankAccount1.balance - withdrawamount;
            printf("You successfully withdrew %d\n",withdrawamount);
      FILE * fpointer2 = fopen("Transaction.txt", "a");
fprintf(fpointer2,"You successfully withdrew %d\n",withdrawamount);
fclose(fpointer2);
        }
        }
    FILE * fpointer5 = fopen("BankDatabase.txt", "w");
fprintf(fpointer5,"%s\t%d\t%d\t%d\t%d\n",BankAccount1.firstname,BankAccount1.accountnumber,BankAccount1.pin,BankAccount1.transactionpin,BankAccount1.balance);
fclose(fpointer5);
  break;
  case 3:
        printf("Your Balance is %d\n", BankAccount1.balance);
  break;
  case 4:
        printf("Transaction History\n");
    FILE * fpointer3 = fopen("Transaction.txt", "r");
    for(i=0;i<100;i++){
      fgets(sentence,100,fpointer3);
      printf("%s",sentence);
    }
fclose(fpointer3);
  break;
  case 5:
  break;
}
  }
}
printf("-------------------------------------\n");
   printf("1.Continue\n2.Exit\n");
   printf("Choose an option:");
   scanf("%d",&oppy);
break;

  //Signing up phase
case 2:
printf("Enter your first name:");
scanf("%s",BankAccount1.firstname);
printf("Enter your last name:");
scanf("%s",BankAccount1.lastname);
printf("Enter your age:");
scanf("%d",&BankAccount1.age);
printf("Enter your marital status:");
scanf("%s",BankAccount1.maritalstatus);
printf("Enter your country:");
scanf("%s",BankAccount1.country);
printf("Enter your province:");
scanf("%s",BankAccount1.province);
printf("Enter your district:");
scanf("%s",BankAccount1.district);
printf("Enter your city:");
scanf("%s",BankAccount1.city);
printf("Enter your address:");
scanf("%s",BankAccount1.address);
printf("Create your PIN(6 digits):");
scanf("%d",&BankAccount1.pin);
printf("Create your Transaction PIN(6 digits):");
scanf("%d",&BankAccount1.transactionpin);
printf("Enter your balance:");
scanf("%d",&BankAccount1.balance);

  //Generating a random account number for the user
int lower=1000000000, upper=9999999999;
srand(time(NULL));
BankAccount1.accountnumber = (rand() % (upper-lower + 1)) + lower;

printf("Your account number is %d \n Please remember your account number or write it down somewhere.", BankAccount1.accountnumber);

printf("-------------------------------------\n");

  //Storing the data of the user in the database 
FILE * fpointer = fopen("BankDatabase.txt", "a");
fprintf(fpointer,"%s\t%d\t%d\t%d\t%d\n",BankAccount1.firstname,BankAccount1.accountnumber,BankAccount1.pin,BankAccount1.transactionpin,BankAccount1.balance);
fclose(fpointer);

  printf("-------------------------------------\n");
   printf("1.Continue\n2.Exit\n");
   printf("-------------------------------------\n");
   printf("Choose an option:");
   scanf("%d",&oppy);
  break;
  
default:
printf("Invalid Option.Please Try Again.");
  printf("-------------------------------------\n");
   printf("1.Continue\n2.Exit\n");
   printf("Choose an option:");
   scanf("%d",&oppy);
  break;
}
} 
   return 0;
}
