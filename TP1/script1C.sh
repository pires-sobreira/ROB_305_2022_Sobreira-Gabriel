arm-linux-g++ -Wall -Wextra src/main_td1c.cpp src/TimeLib/TimeLib.cpp -o td1c -lrt -lpthread
scp td1c root@192.168.50.53:
rm td1c