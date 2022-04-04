arm-linux-g++ -Wall -Wextra -Wno-psabi src/main_td4b.cpp src/TimeLib/TimeLib.cpp src/Thread/Thread.cpp src/PosixThread/PosixThread.cpp src/IncrementerMutex/IncrementerMutex.cpp src/Mutex/Mutex.cpp -o td4b -lrt -lpthread
scp td4b root@192.168.50.53:
rm td4b