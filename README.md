# bcrack

BCrack is a basic tool designed to crack Bcrypt hashed passwords using brute-force methods. Written in C, it highlights the importance of strong passwords and the effectiveness of Bcrypt for password hashing. Ideal for educational purposes and ethical security testing with permission.

## Files

### Makefile

The Makefile is used to compile the project. It contains instructions for compiling the source code (`main.c`, `file1.c`, `file2.c`) into an executable called `myprogram`.

#### Targets:
- `all`: Compiles the project.
- `clean`: Removes object files and the executable.

### bcrack.c

`bcrack.c` contains the source code for the bcrypt hash cracker. It reads a wordlist file and attempts to crack a given bcrypt hash.

#### Usage:
1. Compile the program using `make`.
2. Run the executable `myprogram`.
3. Enter the path to the wordlist file when prompted.
4. Enter the bcrypt hash to crack when prompted.

### main.c, file1.c, file2.c

These files are placeholders for your actual source code. Modify or replace them according to your project's requirements.

## Compilation Instructions

To compile the project, use the following commands:

```bash
make
