## dup() and dup2() Linux system call

### dup()

The dup() system call creates a copy of a file descriptor.

* It uses the lowest-numbered unused descriptor for the new descriptor.
* If the copy is successfully created, then the original and copy file descriptors may be used interchangeably.
* They both refer to the same open file description and thus share file offset and file status flags.

#### Syntax:
```c
int dup(int oldfd);
oldfd: old file descriptor whose copy is to be created.
```

```c
// C program to illustrate dup() 
#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    // open() returns a file descriptor file_desc to a 
    // the file "dup.txt" here"
    int file_desc = open("dup.txt", O_WRONLY | O_APPEND);
    if(file_desc < 0)
        printf("Error opening the file\n");
    // dup() will create the copy of file_desc as the copy_desc
    // then both can be used interchangeably.

    int copy_desc = dup(file_desc);
    // write() will write the given string into the file
    // referred by the file descriptors
    write(copy_desc,"This will be output to the file named dup.txt\n", 46);
    write(file_desc,"This will also be output to the file named dup.txt\n", 51);
    return 0;
}
```
Note that this program will not run in the online compiler as it includes opening a file and writing on it.

#### Explanation:

The open() returns a file descriptor file_desc to the file named "dup.txt". file_desc can be used to do some file operation with file "dup.txt". After using the dup() system call, a copy of file_desc is created copy_desc. This copy can also be used to do some file operation with the same file "dup.txt". After two write operations one with file_desc and another with copy_desc, same file is edited i.e. "dup.txt". Before running the code, Let The file "dup.txt" before the write operation be as shown below:
<p align="center">
  <a href="https://www.geeksforgeeks.org/c/dup-dup2-linux-system-call/"><img src="https://media.geeksforgeeks.org/wp-content/uploads/before1.png" alt="dup" ></a>
</p>
After running the C program shown above, the file "dup.txt" is as shown below:
<p align="center">
  <a href="https://www.geeksforgeeks.org/c/dup-dup2-linux-system-call/"><img src="https://media.geeksforgeeks.org/wp-content/uploads/after1.png" alt="dup" ></a>
</p>

### dup2()

The `dup2` system call in C/C++ duplicates an existing file descriptor (`oldfd`) to a specified file descriptor (`newfd`). If `newfd` is already open, it is closed first, and then made to refer to the same open file description as `oldfd`. This is often used for `I/O redirection`.

The `dup2()` system call is similar to `dup()` but the basic difference between them is that instead of using the lowest-numbered unused file descriptor, it uses the descriptor number specified by the user.

#### Syntax:
```c
int dup2(int oldfd, int newfd);
```

* `oldfd`: old file descriptor
* `newfd`: new file descriptor which is used by `dup2()` to create a copy.

#### Important points:

* Include the header file unistd.h for using dup() and dup2() system call.
* If the descriptor newfd was previously open, it is silently closed before being reused.
* If oldfd is not a valid file descriptor, then the call fails, and newfd is not closed.
* If oldfd is a valid file descriptor, and newfd has the same value as oldfd, then dup2() does nothing, and returns newfd.

#### A tricky use of dup2() system call:

As in `dup2()`, in place of newfd any file descriptor can be put. Below is a C implementation in which the file descriptor of Standard output (`stdout`) is used. This will lead all the `printf()` statements to be written in the file referred by the old file descriptor.

```c
// C program to illustrate dup2() 
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main()
{
    int file_desc = open("tricky.txt",O_WRONLY | O_APPEND);
    
    // here the newfd is the file descriptor of stdout (i.e. 1)
    dup2(file_desc, 1) ; 
        
    // All the printf statements will be written in the file
    // "tricky.txt"
    printf("I will be printed in the file tricky.txt\n");
    
return 0;
}
```

This can be seen in the figure shown below: Let The file "tricky.txt" before the dup2() operation be as shown below:
<p align="center">
  <a href="https://www.geeksforgeeks.org/c/dup-dup2-linux-system-call/"><img src="https://media.geeksforgeeks.org/wp-content/uploads/Tricky_before.png" alt="dup" ></a>
</p>
After running the C program shown above, the file "tricky.txt" is as shown below:
<p align="center">
  <a href="https://www.geeksforgeeks.org/c/dup-dup2-linux-system-call/"><img src="https://media.geeksforgeeks.org/wp-content/uploads/Tricky_after.png" alt="dup" ></a>
</p>

Example – Redirecting `stdout` to a file:
```c
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
   // Open a file for writing
   int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
   if (fd < 0) {
       perror("open");
       return 1;
   }
   // Redirect stdout (fd = 1) to the file
   if (dup2(fd, STDOUT_FILENO) == -1) {
       perror("dup2");
       return 1;
   }
   // Now all stdout output goes to output.txt
   printf("This will be written into output.txt\n");
   close(fd); // Safe to close original fd
   return 0;
}
```

#### Key Points:

* `Header Files`: Include `<unistd.h>` for `dup2()` and `<fcntl.h>` for `open()`.

* `Behavior`: If newfd equals oldfd, nothing happens; returns newfd. If newfd was open, it is closed silently before reassignment. Both descriptors share the same file offset and status flags.

* `Return Value`: Returns the new file descriptor on success; `-1` on error with `errno` set (e.g., EBADF, EMFILE).

#### Common Use Cases:

* Redirecting `standard streams` (`stdin`, `stdout`, `stderr`) to files or sockets.

* Implementing shell-like piping and redirection in custom programs.

* Logging output without changing code that writes to standard output.
