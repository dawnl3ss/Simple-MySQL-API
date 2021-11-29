#include <stdio.h>
#include <mysql.h>
#include <stdlib.h>
#include "sql_api.c"

int main(int argc, char **argv){

    MYSQL *con = connect_sql();

    MYSQL_RES *result = query_sql(con, "YOUR STATEMENT");

    print_sql_data(result);
    
    mysql_free_result(result);
    mysql_close(con);

    return 0;
}