arm-linux-g++ -Wall -Wextra src/main_td1b.cpp -o td1b -lrt -lpthread
scp td1b root@192.168.50.53:
rm td1b