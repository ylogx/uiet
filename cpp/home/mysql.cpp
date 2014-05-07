#include <iostream>
extern "C"
{
#include <mysql/mysql.h>
}

using namespace std;

MYSQL *connection, mysql;
MYSQL_RES *result;
MYSQL_ROW row;
int query_state;

int main() {
    mysql_init(&mysql);
    connection= mysql_real_connect(&mysql,"host","user","password","database",0,0,0);
    if(connection == NULL) {
        cout<<mysql_error(&mysql)<<endl;
    }else{
        cout<<"Connected!!!"<<endl;
    }
}
