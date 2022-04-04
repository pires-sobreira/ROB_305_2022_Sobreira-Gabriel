arm-linux-g++ -Wall -Wextra src/main_td1a.cpp src/TimeLib/TimeLib.cpp src/tests/test.cpp -o td1a -lrt -lpthread
scp td1a root@192.168.50.53:

rm td1a