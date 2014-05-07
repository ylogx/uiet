/*
 *       Name:        Shubham Chaudhary
 *       Roll No:     UE113090
 *       Branch:      CSE Sec.2
 *       Lab:     Analysis and Design of Algorithm
 *       Problem:     Knapsack using greedy approach
 *       Greedy Method: Version - ordering paradigm
 */
#include<stdio.h>
#define max(a,b) (a>b ? a : b)
#define DEBUG3
enum sortType {ratio,load,price};
//***Prototype***
int knapsack(int nItem, int size, int weight[], int value[]);
void sortW();
void sortV();
void sortR();
void sort(int);
void swap(int i,int j);
void display();
void displayTaken();
void knap(int);

//***Global Parameter***
#ifdef DEBUG1
    int noItem=4;
    float knapSize = 7;
    float weight[4]={2,5,1,3};
    float value[4]={1,4,2,5};
float taken[4]={0};
#endif
#ifdef DEBUG2
    int noItem=4;
    float knapSize = 10;
    float weight[4]={5,4,6,3};
    float value[4]={10,40,30,50};
float taken[4]={0};
#endif
#ifdef DEBUG3
    int noItem=22;
    float knapSize = 400;
    float weight[22]={9,13,153,50,15,68,27,39,23,52,11,32,24,48,73,42,43,22,7,18,4,30};
    float value[22]={150,35,200,60,60,45,60,40,30,10,70,30,15,10,40,70,75,80,20,12,50,10};
float taken[22]={0};
#endif
#ifdef DEBUG4   //Sahani pg 199
    int noItem=3;
    float knapSize = 20;
    float weight[3]={18,15,10};
    float value[3]={25,24,15};
float taken[3]={0};
#endif

//****Main****
int main(){
    display();
    knap(ratio);    //enum promoted to int, XXX NOTE reverse(int to enum) not valid
    displayTaken();
    knap(load);
    displayTaken();
    knap(price);
    displayTaken();
    return 0;
}
void displayTaken(){
    int i;
    float totW=0,totV=0;
    printf("\n\t\t* * * Items Taken * * *\n\tWeight\t---\tValue---\tFraction");
    for(i=0;i<noItem;i++){
        if(taken[i]!=0){
            printf("\n\t%.2f\t---\t%.2f\t---\t%.2f",weight[i],value[i],taken[i]);
            totW+=weight[i]*taken[i];
            totV+=value[i]*taken[i];
        }
    }
    printf("\n= = =  Total\tWeight=%.2f\tValue=%.2f\t= = =",totW,totV);
}
void display(){
    //return;
    int i;
    printf("\n\n\tWeight\t---\tValue");
    for(i=0;i<noItem;i++){
        printf("\n\t%.3f\t---\t%.3f",weight[i],value[i]);
    }
}
void knap(int sortType){
    sort(sortType);
    int i;
    float currW=0;
    for(i=0;i<noItem;i++){
        if (currW>=knapSize){
            //return; //then old taken values used
            taken[i]=0;
        }
        else if(currW+weight[i]<knapSize){
            currW+=weight[i];
            taken[i]=1;
        }
        else{
            taken[i]=(float)(knapSize-currW)/weight[i];
            currW+=taken[i]*weight[i];
            //printf("\ntaken[%d]=%f\tcurrW=%f",i,taken[i],currW);
            //XXX NOTE all optimal solutions will fill the sack exactly
        }
    }
}
void sort(int sortType){
    int i,j;
    switch(sortType){
        case load:
            printf("\nSort by Weight:");
            //***bubble sort***
            for(i=0;i<noItem;i++){
                for(j=0;j<noItem-1;j++){
                    if(weight[j]>weight[j+1]){
                        swap(j,j+1);
                    }
                }
            }
            break;
        case price:
            printf("\nSort by Values:");
            //***bubble sort***
            for(i=0;i<noItem;i++){
                for(j=0;j<noItem-1;j++){
                    if(value[j]<value[j+1]){
                        swap(j,j+1);
                    }
                }
            }
            break;
        default:
            printf("\nSort by Ratio:");
            //***bubble sort***
            for(i=0;i<noItem;i++){
                for(j=0;j<noItem-1;j++){
                    if((float)(value[j])/weight[j] < (float)(value[j+1])/weight[j+1]){
                    //if((value[j])/weight[j] < (value[j+1])/weight[j+1]){
                        swap(j,j+1);
                    }
                }
            }
            break;
    }
}

void swap(int i,int j){
    float temp;
    //swap weights
    temp=weight[i];
    weight[i]=weight[j];
    weight[j]=temp;
    //swap corresponding values
    temp=value[i];
    value[i]=value[j];
    value[j]=temp;
}

/* * * * * * * * * * * * *

    Weight  --- Value
    18.000  --- 25.000
    15.000  --- 24.000
    10.000  --- 15.000
Sort by Ratio:
        * * * Items Taken * * *
    Weight  --- Value---    Fraction
    15.00   --- 24.00   --- 1.00
    10.00   --- 15.00   --- 0.50
= = =  Total    Weight=20.00    Value=31.50 = = =
Sort by Weight:
        * * * Items Taken * * *
    Weight  --- Value---    Fraction
    10.00   --- 15.00   --- 1.00
    15.00   --- 24.00   --- 0.67
= = =  Total    Weight=20.00    Value=31.00 = = =
Sort by Values:
        * * * Items Taken * * *
    Weight  --- Value---    Fraction
    18.00   --- 25.00   --- 1.00
    15.00   --- 24.00   --- 0.13
= = =  Total    Weight=20.00    Value=28.20 = = =

------------------
(program exited with code: 0)


 * * * * * * * * * * * */
