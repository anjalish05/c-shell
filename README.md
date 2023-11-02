# C-Shell

All the file names correspond to the name of the shell commands, i.e., `pwd` `echo` and `cd`. All `.c` files have their corresponding `.h` files. 

To run the shell program, type in the following in your respective Linux terminal:- 

```
make 
./shell
```

`headers.h` - Includes all library inclusions at one place. <br>
`display.c` - Has all the functions to extract the username and the system name. 

<h3>Commands</h3>

- `pwd` - Does not take any arguments. Prints the Current Working Directory.
- `echo` - Takes `custom text` as the argument.
- `cd` - Performs all the functions of changing the working directories.
  - `cd ~` - To go to home directory.
  - `cd ..` - To go one level above.
  - `cd -` - Print the previous directory and go to the previous directory. 
- `exit` `quit` `q` - To exit from the custom terminal.
