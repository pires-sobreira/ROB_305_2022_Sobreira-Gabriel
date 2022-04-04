arm-linux-g++ -Wall -Wextra src/main_td1e.cpp src/TimeLib/TimeLib.cpp -o td1e -lrt -lpthread
scp td1e root@192.168.50.53:
rm td1e