# Development of a Deadlock-Aware Dining Philosophers Simulation Using Multithreading

## Overview
This project simulates the classic Operating Systems problem known as the **Dining Philosophers Problem** using C and POSIX threads (`pthread`). The simulation demonstrates vital OS concepts including multithreading, synchronization, mutual exclusion, and a highly effective deadlock prevention mechanism.

## Features
* **Multithreading:** Each of the 5 philosophers is represented and executed as a separate thread.
* **Mutual Exclusion:** Each fork is represented as a distinct `pthread_mutex_t` lock to prevent multiple philosophers from picking up the same fork simultaneously.
* **Deadlock Prevention (Resource Ordering):** To avoid the classic state of circular wait (where every philosopher grabs one fork and waits indefinitely for the other), the system enforces a strict resource ordering policy. A philosopher must unconditionally pick up the lower-numbered fork before the higher-numbered fork.
* **Continuous Execution:** A continuous, infinite loop simulates the repetitive "Think → Pick up forks → Eat → Release forks" life cycle.
* **Randomized Delays:** `sleep()` events introduce variable thinking and eating times, replicating true asynchronous thread behavior.

## Separation of Concerns (Project Structure)
The project strictly follows modular programming principles, separating definitions from implementations:

* **`config.h`**: Defines central global constants such as number of philosophers (`NUM_PHILOSOPHERS = 5`).
* **`forks.h` / `forks.c`**: Manages the initialization and destruction routines for the 5 fork mutex locks.
* **`deadlock.h` / `deadlock.c`**: Contains the deadlock prevention logic (Resource Ordering). Contains functions to safely pick up and release the appropriate forks sequentially.
* **`philosopher.h` / `philosopher.c`**: Defines the philosopher thread's life cycle. Houses the `philosopher_lifecycle` routine driving the continuous state transitions.
* **`main.c`**: Orchestrates thread creation, seeds random execution timing, starts the simulation, and manages thread joining.

## Requirements
* C Compiler (e.g., GCC)
* POSIX Threads library (`pthread`)
* Environment: Linux, macOS, WSL, or MSYS2/MinGW on Windows.

## Compilation and Execution
To compile the source files into a single executable, open a terminal in the project directory and run:

```bash
gcc main.c philosopher.c forks.c deadlock.c -lpthread -o dining
```

To run the simulation:
* **Linux/WSL/macOS:**
  ```bash
  ./dining
  ```
* **Windows (Command Prompt / PowerShell):**
  ```cmd
  .\dining.exe
  ```

## Expected Console Output
You will see output interleaving as threads continuously change states asynchronously:
```text
Starting Deadlock-Aware Dining Philosophers Simulation...
Rule: Philosophers must pick up the lower-numbered fork first.

Philosopher 1 is thinking
Philosopher 2 is thinking
Philosopher 4 is thinking
Philosopher 5 is thinking
Philosopher 3 is thinking
Philosopher 1 picked up fork 1
Philosopher 1 picked up fork 2
Philosopher 1 is eating
...
Philosopher 1 released forks
Philosopher 1 is thinking
```
