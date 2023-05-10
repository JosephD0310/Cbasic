# How to use library
To run the program:
Step 1: translate `.c` files into `.o` files with the following command:
```sh
  gcc -c list.c
  gcc -c main.c
```
Step 2: Link the `.o` files to create a test file
```sh
  gcc -o test llist.o main.o
```
> Note: `test` is the file to run: `.\test`

# Link list
You can change data types in the struct:
```sh
typedef struct data_s{

    int data;
} data_t;
```
> Note: in `typedef struct data_s` you can add some fields, like: `char StudentofName[11]`

> You need edit `ShowData()` function for new data types

# Queue and Stack

Queue and Stack are installed by link list, you need link with llist.o
```sh
  gcc -o test queue.o llist.o main.o
```
or
```sh
  gcc -o test stack.o llist.o main.o
```

# BST

```sh
typedef int key_t; 

typedef struct data_s{
    
    int key;
} data_t;
```
- You use `key_t` (a data type) to create the tree
- If your key is a string, comparison operators `== > < >= <=` will be replaced by using `strcmp()` fuction and assignment operator will be replaced by using `strcpy()` fuction
- In `typedef struct data_s` you can add some fields, like: `char StudentofName[11]`

# Hash Table
- Use Separate Chaining Collision Handling Technique
- The size Hash Table is 13, you can change at the command `#define TABLE_SIZE (13)` in hash.h
- Change the element type in hash.h:
```sh
typedef struct node_t {
  char key[MAX_CHAR];
  /* other fields */
  char word[50];
  struct node_t* next;
} element_t;  
```

# Make file

If you need to link too many files `.o`, makefile will be very useful

Example, if I want translate `.c` files into `.o`:
```sh
test.o: test.c bst.h
	gcc -c test.c

bst.o: bst.c bst.h
	gcc -c bst.c
```

Then, we need link all of files `.o`
```sh
test: test.o bst.o
	gcc -o test test.o bst.o
```

So we have a `makefile.mak`
```sh
test: test.o bst.o
	gcc -o test test.o bst.o

test.o: test.c bst.h
	gcc -c test.c

bst.o: bst.c bst.h
	gcc -c bst.c
```
> NOTE: you have to use `tab` not `space` !

Now, you just use `make` in cmd, and use `.\test` to run program
