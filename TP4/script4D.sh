arm-linux-g++ -Wall -Wextra -Wno-psabi src/main_td4d.cpp src/TimeLib/TimeLib.cpp src/Chrono/Chrono.cpp src/Thread/Thread.cpp src/PosixThread/PosixThread.cpp src/Mutex/Mutex.cpp  src/FifoConsumer/FifoConsumer.cpp src/FifoProducer/FifoProducer.cpp src/Fifo/Fifo.hpp -o td4d -lrt -lpthread
scp td4d root@192.168.50.53:
rm td4d