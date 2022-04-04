arm-linux-g++ -Wall -Wextra -Wno-psabi src/main_td3c.cpp src/TimeLib/TimeLib.cpp src/Timer/Timer.cpp src/PeriodicTimer/PeriodicTimer.cpp src2/Chrono/Chrono.cpp src/CpuLoop/CpuLoop.cpp src/Calibrator/Calibrator.cpp src/Looper/Looper.cpp -o td3c -lrt -lpthread

scp td3c root@192.168.50.53:

rm td3c