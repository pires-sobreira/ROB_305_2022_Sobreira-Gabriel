arm-linux-g++ -Wall -Wextra src/main_td2b.cpp src/TimeLib/TimeLib.cpp -o td2b -lrt -lpthread
scp td2b root@192.168.50.53:
rm td2b