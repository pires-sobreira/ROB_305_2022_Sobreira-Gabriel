arm-linux-g++ -Wall -Wextra -Wno-psabi src/main_td4c.cpp src/TimeLib/TimeLib.cpp src/Chrono/Chrono.cpp src/Thread/Thread.cpp src/PosixThread/PosixThread.cpp src/Mutex/Mutex.cpp  src/SemaConsumer/SemaConsumer.cpp src/SemaProducer/SemaProducer.cpp src/Semaphore/Semaphore.cpp -o td4c -lrt -lpthread
scp td4c root@192.168.50.53:
rm td4c