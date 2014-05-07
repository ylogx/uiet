/**
  *     Name:       Shubham Chaudhary
  *     Lab:        OOPS
  *     Date:       Apr 1, 2013
  *     Roll:       UE113090
  *     Program:    Problem 8.1 Balagurusamy
  **/
#include <iostream>
using namespace std;
enum AccType{ current, saving, fixed };
typedef enum{ FAILURE, SUCCESS } stat;

class account{
    private:
        char name[20];
        int accNo;
        bool initialized;
    protected:
        AccType type;
        float balance;
    public:
        account(){ initialized=false; }
        void init(){
            if (!initialized){
                cout<<"\nEnter Name: ";
                cin>>name;
                cout<<"Enter Account #: ";
                cin>>accNo;
                cout<<"Enter Initial Balance: ";
                cin>>balance;
                initialized=true;
            }
        }
        //part (a) Accept Deposit from customer and update balance
        bool deposit(float amtDep){ balance+=amtDep; return SUCCESS; }
        //part (b) Display Balance
        void display(){
            cout<<"\n*****************\n";
            cout<<"\nName: "<<name
                <<"\nAccNo: "<<accNo
                //<<"\nAccount Type: "<<type?"Current":"Saving"
                <<"\nBalance: Rs. "<<balance<<"\n";
        }
        //part (d) Permit withdraw and update balance
        bool withdraw(float amtWtd){
            if(balance>=amtWtd){
                balance-=amtWtd;
                return SUCCESS;
            }
            return FAILURE;
        }
};

class currAcc : public account {
    private:
        int minBalance, penaltyRate, timeLow;
    public://protected:
        //part (e) check for min bal, impose penalty, update balance
        bool balPenalty(){
            if(balance<minBalance){
                float penalty = (minBalance-balance)*(penaltyRate*timeLow)/100 ;
                balance -= penalty;
                cout<<"\n# # # DEBIT: Rs. "<<penalty<<'\n';
                return SUCCESS;
            }
            return FAILURE;
        }

    public:
        currAcc(){ type=current; }
        void init(){
            account::init();
            cout<<"Enter Minimum Balance: ";
            cin>>minBalance;
            cout<<"Enter Penalty Rate: ";
            cin>>penaltyRate;
            cout<<"Enter time since balance low: ";
            cin>>timeLow;
        }
        void display(){
            account::display();
            cout<<"time since low: "<<timeLow<<"\n";

        }
};
class savAcc : public account {
    private:
        float rate;     //Interest Rate
        int timeInt;    //#ofdays account has been active
    public://protected:
        //part (c) Compute and deposit Interest
        float calcInterest(){ return ( (balance*rate*timeInt)/100 ); }
        bool depositInterest(){
            if(balance){
                float intrst=calcInterest();
                balance+=intrst;
                cout<<"\n# # # CREDIT: Rs. "<<intrst<<'\n';
                return SUCCESS;
            }
            return FAILURE;
        }
    public:
        savAcc(){ type=saving; }
        void init(){
            account::init();
            cout<<"Enter rate: ";
            cin>>rate;
            cout<<"Enter time since open: ";
            cin>>timeInt;
        }
        void display(){
            account::display();
            cout<<"Rate: "<<rate<<"\n";
            cout<<"Time Interval: "<<timeInt<<"\n";
        }
};

int main(){
    account aObj;
    savAcc sObj;
    currAcc cObj;
    sObj.init();
    //part (b)
    cout<<"\nInitial state of saving account\n";
    sObj.display();
    //part (a)
    sObj.deposit(1001);
    cout<<"\nAfter deposit of Rs. 1001\n";
    sObj.display();
    //part (c)
    cout<<"\nDepositing Interest";
    sObj.depositInterest();
    sObj.display();
    //part (d)
    sObj.withdraw(111);
    cout<<"\nAfter withdrawing Rs. 111\n";
    sObj.display();
    //TODO apply type conversion
    cObj.init();
    cout<<"\nInitial state of current account\n";
    cObj.display();
    //part (e)
    cObj.balPenalty();
    cout<<"After imposing penalty\n";
    cObj.display();

    return 0;
}

/******************************
==903== Command: ./8ch8-1.out
Enter Name: Shubham
Enter Account #: 121
Enter Initial Balance: 1000
Enter rate: 2
Enter time since open: 20

Initial state of saving account

*****************
Name: Shubham
AccNo: 121
Balance: Rs. 1000
Rate: 2
Time Interval: 20

After deposit of Rs. 1001

*****************
Name: Shubham
AccNo: 121
Balance: Rs. 2001
Rate: 2
Time Interval: 20

Depositing Interest
# # # CREDIT: Rs. 800

*****************
Name: Shubham
AccNo: 121
Balance: Rs. 2801.4
Rate: 2
Time Interval: 20

After withdrawing Rs. 111

*****************
Name: Shubham
AccNo: 121
Balance: Rs. 2690.4
Rate: 2
Time Interval: 20

Enter Name: Chaudhary
Enter Account #: 989
Enter Initial Balance: 100
Enter Minimum Balance: 200
Enter Penalty Rate: 2
Enter time since balance low: 10

Initial state of current account

*****************
Name: Chaudhary
AccNo: 989
Balance: Rs. 100
time since low: 10

# # # DEBIT: Rs. 20
After imposing penalty

*****************
Name: Chaudhary
AccNo: 989
Balance: Rs. 80
time since low: 10

==903== HEAP SUMMARY:
==903==     in use at exit: 0 bytes in 0 blocks
==903==   total heap usage: 3 allocs, 3 frees, 171 bytes allocated
==903==
==903== All heap blocks were freed -- no leaks are possible
==903==
==903== For counts of detected and suppressed errors, rerun with: -v
==903== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 2 from 2)

real    0m0.473s
user    0m0.448s
sys     0m0.020s

****************************/
