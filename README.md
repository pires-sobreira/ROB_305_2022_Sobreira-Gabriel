# Instructions to compile and send the code to the Raspberry

From the terminal in your notebook access the folder of which TP you would like to run and send the following commands:

    chmod +x script[TP_number][Letter_of_the_exercice_in_capital_letter].sh
    ./script[TP_number][Letter_of_the_exercice_in_capital_letter].sh

For example, if you want to compile and send the TP 1 exercice a to the Raspberry it would be:

    chmod +x script1A.sh
    ./script1A.sh

this script will automaticaly compile the code and send the executable file to the Raspberry

*DISCLAIMER*: In order to the script send the executable to the raspberry, it is necessary to be connected to the ENSTA RPi2 development PC


# Run the executable in the raspberry

For the majority of the exercices it just run the executable with the following command:

    ./td[TP_number][Letter_of_the_exercice_in_small_letter]

    Example:

    ./td1a

However for some exercices it is necessary to pass some arguments in command line, and these are:

### 1. TD 1 exercice C:

        ./td1c [nLoops]

### 2. TD 2 exercice A:

        ./td2a [nLoops] [nTasks]

### 3. TD 2 exercice B:

        ./td2b [nLoops] [nTasks] [schedPolicy]

The arguments for schedPolicy can be: SCHED_RR, SCHED_FIFO or SCHED_OTHER

### 4. TD 2 exercice C:

        ./td2c [nLoops] [nTasks] protected

        or 

        ./td2c [nLoops] [nTasks] 


If the protected argument is passed it will be used the mutex.

### 5. TD 3 exercice B:

        ./td3b [nLoops]

### 6. TD 4 exercice A:

        ./td4a [nLoops] [nTasks] 

### 7. TD 4 exercice B:

        ./td4b [nLoops] [nTasks] 

### 8. TD 4 exercice C:

        ./td4c [nProd] [nCons] [nItems]

### 9. TD 4 exercice D:
     
        ./td4d [nProd] [nCons] [nItems]