arm-linux-g++ src/main_td3a.cpp src/TimeLib/TimeLib.cpp src/Chrono/Chrono.cpp -o td3a -lrt -lpthread
scp td3a root@192.168.50.53:
rm td3a