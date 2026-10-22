### env

`env` is the process’s environment variables.

In the `main` function:

```c
int	main(int ac, char **av, char **env)
```

`env` is an array of strings, for example:

```c
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin
HOME=/home/acer
USER=acer
PWD=/home/acer/42_code/myGit/pipex
```

The array ends with a NULL pointer:

```c
env[0] = "PATH=...";
env[1] = "HOME=...";
env[2] = "USER=...";
...
env[n] = NULL;
```

this program passes it to `execve`:

```c
execve(path, s_cmd, env);
```
This gives the executed command access to the same environment variables.

Your `get_path` function uses it to find `PATH`:
```c
my_getenv("PATH", env)
```
`PATH` contains directories where executable commands are located, such as:
```c
/usr/local/bin:/usr/bin:/bin
```

### ADDITIONAL

To print every environment variable:
```c
int	i;

i = 0;
while (env[i])
{
    ft_putendl_fd(env[i], 2);
    i++;
}
```

To print only `PATH`:
```c
ft_putstr_fd("PATH=", 2);
ft_putendl_fd(my_getenv("PATH", env), 2);
```