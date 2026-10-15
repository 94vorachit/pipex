#### Unix shell input/output redirections

```c
touch/mkdir files.txt/csv
ls -l
ls > filename.txt
cat filename.txt
```

All of file's name that show is `ls -l` will collect in filename.txt 

```c
cat cats.txt dogs.txt > pets.txt
```

Combine these two files aed redirected the result to a file name pets.txt

```c
cat fish.txt >> pets.txt
```
Append fish.txt to the end of the pets.txt

```c
tr '[A-Z]' '[a-z]' < upper_cats.txt > lower_cats.txt
```

turn the uppercase in upper_cats.txt convert to lowercase and collect in lower_cats.txt