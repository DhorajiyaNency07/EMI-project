// EMI - project
// HOME Loan Calculation
// (calculate EMI) calculate the monthly payment of the loan.
#include<iostream>
#include<math.h>
using namespace std;
class emi
{
    float emi, loan_amount, interest_rate, loan_period, Total_payment, payable_interest, balance, monthly_interest, z, h;  //p=loan amount, r=interest rate, n=loan period, i=payable interest,T=total payment
    public:
    void getdata();
    float calcdata();
    float calcdata1();
    float calcdata2();
    float cadata1(); 
};
void emi::getdata()
{
    cout<<"\n Enter loan amount : ";    
    cin>>loan_amount;                            
    cout<<"\n Enter rate of interest : ";  
    cin>>interest_rate;
    cout<<"\n Enter time period in month : ";   //n=loan period
    cin>>loan_period;
}
float emi::calcdata()
{
    interest_rate=interest_rate/(12*100);     //r=interest rate
   // loan_period=loan_period*12;         // if enter year, need it.
    emi=(loan_amount*interest_rate*pow(1+interest_rate,loan_period)/(pow(1+interest_rate,loan_period)-1));   // n=loan period, r=interest rate
    return emi;
}
float emi::calcdata1()
{
    
    payable_interest = emi * loan_period - loan_amount;     
    return payable_interest;
}
float emi::calcdata2()
{
    Total_payment = loan_amount + payable_interest;        
    return Total_payment;
}

float emi::cadata1()    
{
    cout<<"\n\n\n           month"<<"           interest"<<"           emi-interest"<<"            balance"<<"\n"; 
       //h=month, m=interest, z=emi-interest, a=balance

    for(int h=1;h<=loan_period;h++)    // h=month
    {
    monthly_interest = loan_amount * interest_rate;    
    z = emi - monthly_interest;          
    balance = loan_amount - (z);     // balance=loan_amount-(emi-monthly_interest);
    cout<<"\n\n           "<<h<<"               "<<monthly_interest<<"            "<<z<<"                 "<<balance;   
            //h=month, z=emi-interest 
    loan_amount = balance;              
    }                            

}

int main()
{
    emi a1;
    float emi,Total_payment,payable_interest;
    
    a1.getdata();

    emi = a1.calcdata();
    cout<<"\n\n Monthly EMI : "<<emi;

    payable_interest = a1.calcdata1();
    cout<<"\n\n Payable Interest : "<<payable_interest;

    Total_payment = a1.calcdata2();
    cout<<"\n\n Total Payment : "<<Total_payment;

    cout<<"\n";
    a1.cadata1();

    return 0;
}

/*
Enter loan amount : 100000

Enter rate of interest : 9.5

Enter time period in month : 12


Monthly EMI : 8768.32

Payable Interest : 5219.88

Total Payment : 105220


           month           interest           emi-interest            balance


           1               791.667            7976.66                 92023.3

           2               728.518            8039.81                 83983.5

           3               664.87            8103.45                 75880.1

           4               600.717            8167.61                 67712.5

           5               536.057            8232.27                 59480.2

           6               470.885            8297.44                 51182.8

           7               405.197            8363.13                 42819.6

           8               338.989            8429.33                 34390.3

           9               272.257            8496.07                 25894.2

           10               204.996            8563.33                 17330.9

           11               137.203            8631.12                 8699.8

           12               68.8734            8699.45                 0.347656

*/