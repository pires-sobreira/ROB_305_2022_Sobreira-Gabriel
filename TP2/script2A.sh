arm-linux-g++ -Wall -Wextra src/main_td2a.cpp src/TimeLib/TimeLib.cpp -o td2a -lrt -lpthread
scp td2a root@192.168.50.53:
rm td2a