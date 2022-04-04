arm-linux-g++ -Wall -Wextra -Wno-psabi src/main_td5.cpp src/Calibrator/Calibrator.cpp src/Chrono/Chrono.cpp src/CountDown/CountDown.cpp src/CpuLoop/CpuLoop.cpp src/CpuLoopMutex/CpuLoopMutex.cpp src/Looper/Looper.cpp src/Mutex/Mutex.cpp src/Mutex/Lock.cpp src/Mutex/Monitor.cpp src/Mutex/TryLock.cpp src/PeriodicTimer/PeriodicTimer.cpp src/PosixThread/PosixThread.cpp src/Thread/Thread.cpp src/TimeLib/TimeLib.cpp src/Timer/Timer.cpp -o td5 -lrt -lpthread

scp td5 root@192.168.50.53:

rm td5