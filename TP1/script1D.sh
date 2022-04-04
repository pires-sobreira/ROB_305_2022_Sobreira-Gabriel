arm-linux-g++ -Wall -Wextra src/main_td1d.cpp src/TimeLib/TimeLib.cpp -o td1d -lrt -lpthread
scp td1d root@192.168.50.53:
rm td1d