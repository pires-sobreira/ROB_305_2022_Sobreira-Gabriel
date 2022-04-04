arm-linux-g++ -Wall -Wextra src/main_td2c.cpp src/TimeLib/TimeLib.cpp -o td2c -lrt -lpthread
scp td2c root@192.168.50.53:
rm td2c