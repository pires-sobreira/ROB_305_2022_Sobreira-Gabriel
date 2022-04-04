arm-linux-g++ -Wall -Wextra -Wno-psabi src/main_td4a.cpp src/TimeLib/TimeLib.cpp src/Thread/Thread.cpp src/PosixThread/PosixThread.cpp src/Incrementer/Incrementer.cpp -o td4a -lrt -lpthread
scp td4a root@192.168.50.53:
rm td4a