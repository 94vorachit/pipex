## Getpath

`get_path` finds the full executable path for a command.

#### For example:
```c
get_path("ls -l", env);
```

#### returns:
```c
/usr/bin/ls
```

### How it works

1. Gets the `PATH` environment variable:
```c
my_getenv("PATH", env)
```

my_getenv :
```
PATH=/home/acer/.local/bin:/home/acer/.vscode-server/data/User/globalStorage/github.copilot-chat/debugCommand:/home/acer/.vscode-server/data/User/globalStorage/github.copilot-chat/copilotCli:/home/acer/.vscode-server/bin/07f806f999227108933c2e30515b26eecc1fda74/bin/remote-cli:/home/acer/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/usr/lib/wsl/lib:/mnt/c/Program Files/WindowsApps/MicrosoftCorporationII.WindowsSubsystemForLinux_2.6.3.0_x64__8wekyb3d8bbwe:/mnt/c/WINDOWS/system32:/mnt/c/WINDOWS:/mnt/c/WINDOWS/System32/Wbem:/mnt/c/WINDOWS/System32/WindowsPowerShell/v1.0/:/mnt/c/WINDOWS/System32/OpenSSH/:/mnt/c/Program Files/Git/cmd:/mnt/c/Users/acer/.local/bin:/mnt/c/Users/acer/AppData/Local/Microsoft/WindowsApps:/mnt/c/Users/acer/AppData/Local/Programs/Microsoft VS Code/bin
```

2. Splits `PATH` by `:` :

```c
/home/acer/.local/bin
/home/acer/.vscode-server/data/User/globalStorage/github.copilot-chat/debugCommand
/home/acer/.vscode-server/data/User/globalStorage/github.copilot-chat/copilotCli
/home/acer/.vscode-server/bin/07f806f999227108933c2e30515b26eecc1fda74/bin/remote-cli
/home/acer/.local/bin
/usr/local/sbin
/usr/local/bin
/usr/sbin
/usr/bin
/sbin
/bin
/usr/games
/usr/local/games
/usr/lib/wsl/lib
/mnt/c/Program Files/WindowsApps/MicrosoftCorporationII.WindowsSubsystemForLinux_2.6.3.0_x64__8wekyb3d8bbwe
/mnt/c/WINDOWS/system32
/mnt/c/WINDOWS
/mnt/c/WINDOWS/System32/Wbem
/mnt/c/WINDOWS/System32/WindowsPowerShell/v1.0/
/mnt/c/WINDOWS/System32/OpenSSH/
/mnt/c/Program Files/Git/cmd
/mnt/c/Users/acer/.local/bin
/mnt/c/Users/acer/AppData/Local/Microsoft/WindowsApps
/mnt/c/Users/acer/AppData/Local/Programs/Microsoft VS Code/bin
```

3. Splits the command to get its executable name:
```c
s_cmd = ft_split(cmd, ' ');
```

For `"ls -l"`:
```c
s_cmd[0] = "ls"
s_cmd[1] = "-l"
```

4. Combines each PATH directory with the command:
```c
/usr/local/bin/ls
/usr/bin/ls
/bin/ls
```

5. Checks whether the path exists and is executable:
```c
access(exec, F_OK | X_OK)
```

6. Returns the first valid path:
```c
/usr/bin/ls
```

### Why `pipex` needs it

`execve` does not search through PATH automatically:
```c
execve(path, s_cmd, env);
```

Therefore, get_path converts:
```c
ls
```
into:
```c
/usr/bin/ls
```
Then execve can run the command.

### In one sentence:

`get_path` searches the directories in `PATH` and returns the full path of the requested executable.
