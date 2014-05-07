/**
  *     Name:       Shubham Chaudhary
  *     Lab:        OOPS
  *     Date:       Mar 18, 2013
  *     Roll:       UE113090
  *     Program:    Perform operations on matrices
  **/
#include <iostream>
#include <string.h>

using namespace std;
const int ROW=3,COLUMN=3;

class matrix{
    private:
    public:
        //int a[ROW][COLUMN]={0};     //error because it's a declaration
        int a[ROW][COLUMN];
        //memset(a,0,sizeof(a));      //Memory is not assigned
        void get();
        void put();
        matrix(){ memset(a,0,sizeof(a)); }  //it's a constructor for objects
        matrix operator +(matrix);
        matrix operator -(matrix);
        matrix operator *(matrix);
};
void matrix::get(){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COLUMN; j++){
            //cout<<"Enter a[i][j]",i,j;
            cout<<"Enter a["<<i<<"]["<<j<<"] : ";
            cin>>a[i][j];
        }
        cout<<endl;
    }
}
void matrix::put(){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COLUMN; j++){
            cout<<a[i][j]<<'\t';
        }
        cout<<endl;
    }
}
matrix matrix::operator +(matrix in){
    matrix temp;// = *this;
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COLUMN;j++){
            //this->a[i][j]=in[i][j];
            temp.a[i][j]=this->a[i][j] + in.a[i][j];
        }
    }
    return temp;
}
matrix matrix::operator -(matrix in){
    matrix temp;// = *this;
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COLUMN;j++){
            //this->a[i][j]=in[i][j];
            temp.a[i][j]=this->a[i][j] - in.a[i][j];
        }
    }
    return temp;
}
matrix matrix::operator *(matrix in){
    matrix temp;// = *this;
    //memset(temp.a,0,sizeof(temp.a));
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COLUMN;j++){
            for(int k=0; k<COLUMN; k++){
                temp.a[i][j]+=this->a[i][j] * in.a[j][i];
            }
        }
    }
    return temp;
}

int main(){
    matrix obj1,obj2;
    cout<<"\nEnter Input for obj1: \n";
    obj1.get();
    cout<<"\nEnter Input for obj1: \n";
    obj2.get();
    cout<<"\n=========obj1+obj2===========\n";
    obj1.put();
    obj2.put();
    obj1=obj1 + obj2;
    cout<<"\n==========RESULT==========\n";
    obj1.put();
    cout<<"\n=========obj1-obj2===========\n";
    obj1.put();
    obj2.put();
    obj1=obj1 - obj2;
    cout<<"\n==========RESULT==========\n";
    obj1.put();
    cout<<"\n=========obj1*obj2===========\n";
    obj1.put();
    obj2.put();
    obj1=obj1 * obj2;
    cout<<"\n==========RESULT==========\n";
    obj1.put();
    return 0;
}
/*******************************************
chaudhary@Dell-XPS-L502XC:~/code/cpp$ c 7overMatrix.cpp t3
 - - - - - - G++: Compiling 7overMatrix .cpp file - - - - - -
g++ -g -O2 -Wall -Wextra -Isrc -rdynamic -O2 -fomit-frame-pointer -o 7overMatrix.out 7overMatrix.cpp
==6572== Memcheck, a memory error detector
==6572== Command: ./7overMatrix.out
==6572== 
--6572-- Valgrind options:
--6572--    --suppressions=/usr/lib/valgrind/debian-libc6-dbg.supp
--6572--    --leak-check=full
--6572--    --show-reachable=yes
--6572--    --track-origins=yes
--6572--    -v
Enter a[0][0] : Enter a[0][1] : Enter a[0][2] : 
Enter a[1][0] : Enter a[1][1] : Enter a[1][2] : 
Enter a[2][0] : Enter a[2][1] : Enter a[2][2] : 

Enter Input for obj1: 
Enter a[0][0] : Enter a[0][1] : Enter a[0][2] : 
Enter a[1][0] : Enter a[1][1] : Enter a[1][2] : 
Enter a[2][0] : Enter a[2][1] : Enter a[2][2] : 
=========obj1+obj2===========
1	2	3	
4	5	6	
7	8	9
+
9	8	7	
6	5	4	
3	2	1	
==========RESULT==========
10	10	10	
10	10	10	
10	10	10	

=========obj1-obj2===========
10	10	10	
10	10	10	
10	10	10	
-
9	8	7	
6	5	4	
3	2	1	
==========RESULT==========
1	2	3	
4	5	6	
7	8	9	

=========obj1*obj2===========
1	2	3	
4	5	6	
7	8	9
* 
9	8	7	
6	5	4	
3	2	1	
==========RESULT==========
27	36	27	
96	75	36	
147	96	27	
--6572-- REDIR: 0x51b5580 (free) redirected to 0x4c2a7c0 (free)
==6572== 
==6572== HEAP SUMMARY:
==6572==     in use at exit: 0 bytes in 0 blocks
==6572==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==6572== 
==6572== All heap blocks were freed -- no leaks are possible
==6572== 
==6572== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 2 from 2)
--6572-- 
--6572-- used_suppression:      2 dl-hack3-cond-1
==6572== 
==6572== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 2 from 2)

real	0m0.620s
user	0m0.548s
sys	    0m0.068s

------------------
(program exited with code: 0)
Press return to continue
*************************************/
