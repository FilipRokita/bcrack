# BCrack: Bcrypt Hash Cracker

This is a simple C program to crack a bcrypt hash using a provided wordlist.

## Requirements

- Clang compiler
- Linux environment (due to the use of `<unistd.h>` for `crypt`)

## How to Use

1. **Compile the Program:**

```
make bcrack
```

2. **Run the Program:**

```
./bcrack
```

3. **Follow the Prompts:**

- Enter the path to the wordlist file containing passwords to test.
- Enter the bcrypt hash that you want to crack.

4. **Outcome:**

- The program will read each password from the wordlist, generate its bcrypt hash, and compare it with the provided hash.
- If a matching password is found, it will be displayed.
