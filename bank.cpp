#include<iostream>
using namespace std;
char accountName;
double balance=0.00,amount=0.00;
void checkBalance();
double depositAmount();
double withdrawAmount();
void enterBaseBalance();
void checkBalance()
{
if (balance<500.00+36.00)
{
cout <<"Insufficient balance. To check account balance, there should be a total of Ksh536.00 or more in the account. Current balance = Ksh" << balance;
cout <<endl;
depositAmount();
}
else
{
balance-=36.00;
cout <<"\n Current balance = Ksh"<< balance;
}
}
double depositAmount()
{
cout<<"Enter the amount you want to deposit :> Ksh";
cin>>amount;
cout<<"\n You have successfully deposited Ksh" <<amount;
balance+=amount;
cout<<"\nCurrent balance = Ksh" << balance;
amount=0.00;
}
double withdrawAmount()
{
int option,select=0;
do
{
cout<<"\n I want to:\n";
cout<<"1. Withdraw.\n2. Transfer.\n3. Cancel.\n9. Exit.\n\tOption :> ";
cin>>select;
if (select == 1)
{
cout<<"Enter the amount you want to withdraw :> Ksh";
cin>>amount;
if (balance < amount + 500.00 + (amount*0.01))
{
cout << "Insufficient balance in the account to complete the withdraw. Please deposit some money to continue enjoying our services."<< endl;
depositAmount();
}
else
{
cout<<"\nYou have successfully withdrawed Ksh"<<amount<<". Withdrawal cost is Ksh"<<amount*0.01;
balance=balance-(amount+(amount*0.01));
cout<<"\nCurrent balance = Ksh"<<balance;
}
}
else if (select == 2)
{
cout<<"Enter the amount you want to transfer :> Ksh";
cin>>amount;
if (balance<amount+500.00+(amount*0.01))
{
cout<<"Insufficient balance in the account to complete the transfer. Please deposit some money to continue enjoying our services.";
cout<<endl;
depositAmount();
}
else
{
cout<<"\nYou have successfully transfered Ksh"<<amount<<". Transfer cost is Ksh" <<amount*0.01;
balance=balance-(amount+(amount*0.01));
cout<<"\nCurrent balance = Ksh"<<balance;
}
}
else if(select == 3)
{
cout<<"You have successfully cancelled the transaction.";
}
else if(select == 9)
{
return 0;
}
else
{
cout<<"Invalid choice!";
}
amount=0.00;
}
while(select != 1 && select != 2 && select != 3);
}
void enterBaseBalance()
{
cout<<"Enter the base balance :> Ksh";
cin>>balance;
}
int main()
{
int option=0,select;
enterBaseBalance();
cout<<balance<<endl;
while(balance<500)
{
cout<<"The base balance should be Ksh500 or more\n";
enterBaseBalance();
}
cout<<"Current base balance = Ksh"<<balance;
do
{
cout<<"\n\nChoose what you want to do:\n";
cout<<"1. Deposit.\n2. Withdraw/Transfer.\n3. check balance.\n4. Exit.\n\tOption :> ";
cin>>select;
if(select == 1)
{
depositAmount();
}
else if(select == 2)
{
withdrawAmount();
}
else if(select == 3)
{
checkBalance();
}
else if(select == 4)
{
cout<<"Bye! Bye! Thank you for using our services. Welcome again another time.\n";
return 0;
option = 6;
}
else
{
cout<<"Invalid choice!";
}
}
while(option == 0);
return 0;
}