#ifndef NEPTUNE_SQL_API_H
#define NEPTUNE_SQL_API_H

MYSQL* connect_sql();
MYSQL_RES* query_sql(MYSQL *con, char *statement);
void print_sql_data(MYSQL_RES *result);
void throw_sql_error(MYSQL *con);

#endif