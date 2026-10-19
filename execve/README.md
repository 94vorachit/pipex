## execve

### `execve` replaces the current process with a new program, taking a path, command-line arguments, and environment variables.

### Overview

The `execve()` system call in C executes a program specified by its path, replacing the current process's memory space with the new program 
This means the original program stops running, and the new program starts execution in the same process ID. The function is defined in `<unistd.h>` and is part of the exec family of functions, which includes execv, execvp, execle, and others

### Syntax
```c
#include <unistd.h>
int execve(const char *path, char *const argv[], char *const envp[]);
```

* `path`: Path to the executable file (binary or script starting with #!interpreter).
* `argv`: Null-terminated array of strings representing command-line arguments. By convention, `argv [^^0^^]` is the program name.
* `envp`: Null-terminated array of strings representing environment variables in the form `KEY=VALUE` 

`execve` does `not return` on success; if it fails, it returns `-1` and sets `errno`.

### Example Usage

Here’s an example of running a Linux command (echo) using execve:

```c
#include <stdio.h>
#include <unistd.h>
int main() 
{
	char *binaryPath = "/bin/bash";
	char *args[] = {binaryPath, "-c", "echo visit $HOSTNAME:Fun with your browser", NULL};
	char *const env[] = {"HOSTNAME=www.delftstack.com", "PORT=8080", NULL};
	if (execve(binaryPath, args, env) == -1) {
		perror("execve failed");
	}
	return 1;
}
```

#### In this example:

* `/bin/bash` is the executable.
* `args` contains the command-line arguments, terminated by `NULL`.
* `env` specifies environment variables for the new process 

After `execve` is called, the original program is replaced, so any code after the call is `not executed` unless `execve` fails.

### Key Points
* All process attributes are preserved except signal dispositions, memory mappings, and certain shared resources 
* `execve` can run both standard Linux commands and custom executables.
* Unlike `execvp`, `execve` requires the full path to the executable and explicitly passed environment variables 
* Common errors occur if `argv` or `envp` are not properly null-terminated or if the path is incorrect 

### Practical Tips
* Use `execvp` if you want the system to search the `PATH` for the executable.
* Always check the return value of `execve` to handle errors.
* Remember that after a successful `execve`, the original program’s code and stack are replaced.

This makes `execve` a powerful tool for process control in Linux, allowing one program to seamlessly hand over execution to another.

First of all, see this program:
```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *args[]) 
{
	int i;
  	int count = atoi(args[1]);
  	for (i = 1; i <= count; i++) 
		printf("[%d]", i);
  	printf("\n");
  	return 0;
}
```
This program is taking command line arguments. The command line argument (passed as a string) is converted to an integer in the second line of the `main` function.

Next, we run a loop from one to `count` and print counting in square brackets. See the output of this code.
```c
$./test 4 

[1][2][3][4]
```

We have created the executable with the name `test`. We have executed the `test` file with parameter `4` from a command prompt.

We can see counting one to four in square brackets in the output.

Next, we have to run this program `test` as an external command from another program. For this, we have to specify the path of the executable `test` program.

Here, the complete path is `/home/acer/42_code/myGit/pipex/execve/test`. Therefore, we will specify this path in our next program to locate the executable file.

```c
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *ar[])
{
  	printf("This is the first line\n");
  	char *binaryPath = "/bin/bash";
  	char name[80] = "/home/acer/42_code/myGit/pipex/execve/test";
  	strcat(name, ar[1]);
  	char *args[] = {binaryPath, "-c", name, NULL};
  	char *env_args[] = {"/bin/bash", (char *)0};
  	execve(binaryPath, args, env_args);
  	printf("This is the last line\n");
  	return 1;
}
```
We have included another library to use the function to concatenate strings. In the third line of the `main` function, we have a complete path and file name because this is not a Linux command; instead, this is user defined executable program (already discussed in detail).

In the following line, we are concatenating the command line argument passed to our current program with the new program’s name. Again, in the fifth line, we have command line arguments having a path, `-c`.

The third parameter is the variable name having path + name of executable + argument passed to the current program.

#### Output:
```c
$ ./a.out 5
This is the first line
[1][2][3][4][5]
```

We are running our current program with the command line parameter `5`. The first line of output has the first `print` statement.

Next, you can see our test program is executed. The counting from `1` to `5` is written in square brackets.

Finally, the conclusion is we can run both Linux commands and our executable programs using `execve`. In the case of the Linux command, we can pass the path to locate the Linux program.

In the case of some other/external executable, we can give a complete path with the file name; in this case, the program will be automatically located at the given path. In this case, the command will ignore the path variable in the third line of the `main` function.