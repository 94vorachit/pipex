### exec family of functions in C

The exec family of functions is defined in the unistd.h header file. The exec functions are used to replace the current running process with a new process. It can be used to run a C program by using another C program.

### Exec functions in C

There are many members in the exec family, which are shown below with examples. 

### `execvp` : Using this command, the created child process does not have to run the same program as the parent process does. The exec type system calls allow a process to run any program files, which include a binary executable or a shell script. 

#### Syntax: 
```c
int execvp (const char *file, char *const argv[]);
```
* `file`: points to the file name associated with the file being executed. 
* `argv`:  is a null terminated array of character pointers.

Example: To show how to use execvp() function in C. We will have two .C files , EXEC.c and execDemo.c and we will replace the execDemo.c with EXEC.c by calling execvp() function in execDemo.c

```c
//EXEC.c 
#include<stdio.h>
#include<unistd.h>

int main()
{
    int i;
    
    printf("I am EXEC.c called by execvp() ");
    printf("\n");
    
    return 0;
}
```
Now,create an executable file of EXEC.c using command 
```c
gcc EXEC.c -o EXEC
```

```c
//execDemo.c

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
        //A null terminated array of character 
        //pointers
        char *args[]={"./EXEC",NULL};
        execvp(args[0],args);
    
        /*All statements are ignored after execvp() call as this whole 
        process(execDemo.c) is replaced by another process (EXEC.c)
        */
        printf("Ending-----");
    
    return 0;
}
```
Now, create an executable file of execDemo.c using command 
```c
gcc execDemo.c -o execDemo
```
After running the executable file of execDemo.cby using command ./excDemo, we get the following output: 
```
I AM EXEC.c called by execvp()
```
When the file execDemo.c is compiled, as soon as the statement execvp(args[0],args) is executed, this very program is replaced by the program EXEC.c. "Ending-----" is not printed because as soon as the execvp() function is called, this program is replaced by the program EXEC.c.