### 📌 Configuration :  
Fullfill functions in the <a href="https://github.com/4m4Sec/Simple-MySQL-API/blob/main/settings/ids.c">ids.c</a> file with your MySQL identifiers.  
```c
char* get_host(){
    return "";
}

char* get_username(){
    return "";
}

char* get_password(){
    return "";
}

char* get_database(){
    return "";
}
```  
  
### 📌 Usage :  
Firstly, you must install the default-libmysqlclient-dev package :  
```bash
sudo apt-get update

sudo apt install default-libmysqlclient-dev
```
  
You can see an example of the way you should use the API in the <a href="https://github.com/4m4Sec/Simple-MySQL-API/blob/main/main.c">main.c</a> file.  
You can also directly start the program or check how to debug it with the <a href="https://github.com/4m4Sec/Simple-MySQL-API/blob/main/start.sh">start.sh</a> file.  
  
```c
#include "src/sql/sql_api.c"

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
