arm-linux-g++ src/main_td3b.cpp src/TimeLib/TimeLib.cpp src/Chrono/Chrono.cpp src/Timer/Timer.cpp src/PeriodicTimer/PeriodicTimer.cpp src/CountDown/CountDown.cpp -o td3b -lrt -lpthread
scp td3b root@192.168.50.53:
rm td3b