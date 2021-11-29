c99 -o main main.c `mysql_config --cflags --libs`
./main
sleep 20
clear