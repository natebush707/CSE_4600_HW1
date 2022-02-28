# CSE_4600_HW1

## Instructions for running code

### Part 1

#### 1 - Create chain of 10 processes
    Compile: `g++ -o part1_1.exe hw1_part1_1.cpp`
    Run: `./part1_1.exe`

#### 2 - Use execl instead of execlp
    Compile: `g++ -o part1_2.exe hw1_part1_2.cpp`
    Run: `./part1_2.exe`

#### 3 - No coding requirements. Documentation in .pdf.

#### 4 - Modify program so child creates grandchild and waits
    Compile: `g++ -o part1_4.exe hw1_part1_4.cpp`
    Run: `./part1_4.cpp`

#### 5 - Signals - sigaction() to intercept SIGINT & SIGQUIT
    Compile: `g++ -o part1_5.exe hw1_part1_5.cpp`
    Run: `./part1_5.exe`

### Part 2

#### 1 - No coding requirements. Documentation in .pdf.

#### 2 - Modify pipe to accept command line parameters
    Compile: `g++ -o pipe1a pipe1a.cpp`
    Run: `./pipe1a ps -auxw`

#### 3 - No coding requirements. Documentation in .pdf

#### 4 - Modify pipe code to accept keyboard message and pipe to pipe5
    Compile: `g++ -o pipe4a.exe pipe4a.cpp`
            `g++ -o pipe5 pipe5.cpp`
    Run: `./pipe4a.exe`

### Part 3

#### 1 - Modify code to run 3 threads with different functions/outputs
    Compile: `g++ -o pthreads_mod.exe pthreads_mod.cpp -lpthread`
    Run: `./pthreads_mod.exe`

#### 2 - Implement mutex lock on shared resource
    Compile: `gcc -o shared_resource_mutex_mod.exe shared_resource_mutex_mod.c -lpthread`
    Run: `./shared_resource_mutex_mod.exe`