#include <mysql.h>
#include "headers/sql_api.h"
#include "ids.c"

MYSQL* connect_sql(){
    MYSQL *con = mysql_init(NULL);

    if (con == NULL){
        fprintf(stderr, "mysql_init() failed\n");
        exit(1);
    }

    if (mysql_real_connect(con, get_host(), get_username(), get_password(), get_database(), 0, NULL, 0) == NULL){
        throw_sql_error(con);
    }
    return con;
}

MYSQL_RES* query_sql(MYSQL *con, char *statement){
    if (mysql_query(con, statement)){
        throw_sql_error(con);
    }

    MYSQL_RES *result = mysql_store_result(con);

    if (result == NULL){
        throw_sql_error(con);
    }
    return result;
}

void print_sql_data(MYSQL_RES *result){
    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result))){
        for(int i = 0; i < num_fields; i++){
            //printf("%s ", row[i] ? row[i] : "NULL");
            printf("%s ", row[i]);
        }
        printf("\n");
    }
}

void throw_sql_error(MYSQL *con){
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}