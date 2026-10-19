### A pipe in C is a unidirectional communication channel that allows one process to send data to another, typically used for inter-process communication (IPC).

### Overview

A `pipe` is a temporary, one-way communication channel between processes, implemented as a kernel-managed buffer. Data written to the `write end` of the pipe can be read from the `read end`, following `FIFO (First In, First Out)` order. Pipes are commonly used in Unix/Linux systems for communication between a parent process and its child processes created via `fork()`

Conceptually, a pipe is a connection between two processes, such that the 
standard output from one process becomes the standard input of the other process. 
In UNIX Operating System, Pipes are useful for communication between related 
processes(inter-process communication).

* Pipe is one-way communication only i.e we can use a pipe such that One process 
write to the pipe, and the other process reads from the pipe. It opens a pipe, 
which is an area of main memory that is treated as a "virtual file".

* The pipe can be used by the creating process, as well as all its child processes, 
for reading and writing. One process can write to this "virtual file" or pipe 
and another related process can read from it.

* If a process tries to read before something is written to the pipe, the process 
is suspended until something is written.

* The pipe system call finds the first two available positions in the process's open 
file table and allocates them for the read and write ends of the pipe.

<p align="center">
  <a href="https://www.geeksforgeeks.org/c/pipe-system-call/"><img src="https://media.geeksforgeeks.org/wp-content/uploads/Process.jpg" alt="pipe" ></a>
  pipe
  <br>
</p>

### Syntax

To create a pipe in C, you use the `pipe()` system call:
```c
#include <unistd.h>
int pipe(int fd [3]);
```

* `fd [0]` is the `read end` of the pipe.
* `fd [1]` is the `write end` of the pipe.
* Returns `0` on success, `-1` on error

### Basic Usage

1. Create a pipe:
```c
int fd [3];
if (pipe(fd) == -1) {
    perror("pipe failed");
    exit(1);
}
```

2. Write to the pipe:
```c
char msg[] = "Hello, child!";
write(fd [1], msg, sizeof(msg));
```

3. Read from the pipe:
```c
char buffer [100];
read(fd [0], buffer, sizeof(buffer));
printf("Received: %s\n", buffer);
```

### Using Pipes with `fork()`
When a process calls `fork()`, the child inherits the pipe file descriptors. This allows parent and child processes to communicate:
```c
pid_t pid = fork();
if (pid > 0) {
    // Parent process
    close(fd [0]); // Close read end
    write(fd [1], "Message from parent", 20);
} else if (pid == 0) {
    // Child process
    close(fd [1]); // Close write end
    char buffer [100];
    read(fd [0], buffer, sizeof(buffer));
    printf("Child received: %s\n", buffer);
}
```
For two-way communication, two pipes are needed: one for each direction

<p align="center">
  <a href="https://www.geeksforgeeks.org/c/pipe-system-call/"><img src="https://media.geeksforgeeks.org/wp-content/uploads/sharing-pipe.jpg" alt="pipe" ></a>
  Parent and child sharing a pipe
  <br>
</p>

### Key Points

* Pipes are `unidirectional`; data flows from write end to read end only.
* `Blocking behavior`: reading blocks if the pipe is empty; writing blocks if the pipe is full.
* Pipes are `limited in size`; the kernel defines `PIPE_BUF` as the maximum atomic write size.
* Pipes are `in-memory`, so they are faster than file-based communication but only work between related processes (parent-child or siblings),

### Advantages

* Simple and efficient for parent-child communication.
* FIFO ensures order of data is preserved.
* Supported natively in Unix/Linux systems.

Pipes are a fundamental tool in C for inter-process communication, enabling processes to exchange data efficiently without using temporary files or other complex mechanisms.