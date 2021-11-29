### 📌 Configuration :  
Fullfill functions in the <a href="https://github.com/Neptune-IT/Simple-MySQL-API/blob/main/ids.c">ids.c</a> file with your MySQL identifiers.  
  
### 📌 Usage :  
You can see an example of the way you should use the API in the <a href="https://github.com/Neptune-IT/Simple-MySQL-API/blob/main/main.c">main.c</a> file.  
  
```c
#include "sql_api.c"

int main(int argc, char **argv){

    /** Connect to MySQL database */
    MYSQL *con = connect_sql();

    /** Make a query to your MySQL database */
    MYSQL_RES *result = query_sql(con, "YOUR STATEMENT");

    /** Print your query's results in the console */
    print_sql_data(result);
    
    /** Close the MySQL gateway connection */
    mysql_free_result(result);
    mysql_close(con);

    return 0;
}
```
