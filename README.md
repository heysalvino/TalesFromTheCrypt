# README.md for "Tales from the Crypt" Project


### Project Description
In this project, you will develop a dictionary-based password cracker using the C `crypt` utility. Your program will process a shadow password file containing usernames and password hashes and a dictionary of potential passwords. It aims to determine the true password for each user by matching the calculated hash of each dictionary entry against the hashes in the shadow file. Additionally, your cracker will include password mangling features to enhance its effectiveness.

### Shadow Password Files
- Review the structure of password files from our previous labs.
- Recall that Linux systems store hashed passwords, not raw passwords.
- The shadow password file format: `username:hash`
- Test shadow files have five entries each. Usernames are not used in this project.

### Tokenizing the Input String
- Use `strtok` to separate the hash string from the username.
- Example code is provided for reading and processing the shadow file lines.
- Ensure to strip the newline character when reading hashes and dictionary entries.

### Crypt Function
- Use the C `crypt` function for hashing.
- Requires two arguments: the string to hash and a "salt" string.
- Your salt string will always be `$1$`.

### Command-Line Options
Your program must support the following options:
- `-i`: Input shadow password file.
- `-o`: Output file for cracked passwords.
- `-d`: Dictionary file with candidate passwords.

#### Mangling Options
- `-n`: Append a single digit (0-9) to the end of the candidate.
- `-c`: Toggle the case of the first letter of the candidate.
- `-l`: Apply leet-style mangling to lowercase letters (a→@, e→3, i→!, l→1, o→0, s→5).

### Compiling, Running, and Grading
- Name your program `crack.c`.
- Include a Makefile for building the program.
- Submit your program to GitHub by the due date.
- Test your code using `test.py` (command: `python test.py`).
- Your grade will be based on the fraction of tests passed.

### Notes
- Focus on efficient dictionary searching and hash comparison.
- Be mindful of memory and resource management in your implementation.
- Good luck and happy coding!
