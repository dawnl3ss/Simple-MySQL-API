#include <stdio.h>
#include <mysql.h>
#include <stdlib.h>
#include "src/sql/sql_api.c"

int main(int argc, char **argv){

    /* Connect to MySQL database */
    MYSQL *con = connect_sql();

    /* Make a query to your MySQL database */
    MYSQL_RES *result = query_sql(con, "YOUR STATEMENT");

    /* Print your query's results in the console */
    print_sql_data(result);

    /* Close the MySQL gateway connection */
    mysql_free_result(result);
    mysql_close(con);

    return 0;
}