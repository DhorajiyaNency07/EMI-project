// EMI - project
// HOME Loan Calculation
// (calculate EMI) calculate the monthly payment of the loan.
#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
class emi
{
    long double emi, loan_amount, interest_rate, loan_period, Total_payment, payable_interest, balance, monthly_interest, z, h; 
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
    cout<<"\n\n\n             month"<<"             principal"<<"                   interest"<<"                  balance"<<"\n"; 
       //h=month, m=interest, z=emi-interest, a=balance

    for(int h=1;h<=loan_period;h++)    // h=month
    {
        monthly_interest = loan_amount * interest_rate;    
        z = emi - monthly_interest;          
        balance = loan_amount - (z);     // balance=loan_amount-(emi-monthly_interest);  
        cout<<std::fixed<<"\n\n\n              "<<h<<"              "<<z<<"               "<<monthly_interest<<"               "<<balance;
        loan_amount = balance;              
    }                            

}

int main()
{
    emi a1;
    float emi,Total_payment,payable_interest;
    
    a1.getdata();

    emi = a1.calcdata();
    cout<<std::fixed<<"\n\n Monthly EMI : "<<emi;

    payable_interest = a1.calcdata1();
    cout<<std::fixed<<"\n\n Payable Interest : "<<payable_interest;

    Total_payment = a1.calcdata2();
    cout<<std::fixed<<"\n\n Total Payment : "<<Total_payment;

    cout<<"\n";
    a1.cadata1();

    return 0;
}

/*

Enter loan amount : 9900000

Enter rate of interest : 25.5

Enter time period in month : 20


Monthly EMI : 612779.500000

Payable Interest : 2355590.500000

Total Payment : 12255590.000000



             month             principal                   interest                  balance



              1              402404.522736               210375.000000               9497595.477264


              2              410955.618844               201823.903892               9086639.858420


              3              419688.425744               193091.096991               8666951.432676


              4              428606.804791               184172.717944               8238344.627885


              5              437714.699393               175064.823343               7800629.928491


              6              447016.136755               165763.385980               7353613.791736


              7              456515.229661               156264.293074               6897098.562075


              8              466216.178292               146563.344444               6430882.383783


              9              476123.272080               136656.250655               5954759.111702


              10              486240.891612               126538.631124               5468518.220090


              11              496573.510559               116206.012177               4971944.709531


              12              507125.697658               105653.825078               4464819.011873


              13              517902.118733               94877.404002               3946916.893140


              14              528907.538757               83871.983979               3418009.354383


              15              540146.823955               72632.698781               2877862.530428


              16              551624.943964               61154.578772               2326237.586464


              17              563346.974023               49432.548712               1762890.612440


              18              575318.097221               37461.425514               1187572.515219


              19              587543.606787               25235.915948               600028.908432


              20              600028.908432               12750.614304               0.000000
              
*/              
