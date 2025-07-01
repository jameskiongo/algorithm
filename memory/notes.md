- Pointers

In C (&) shows the address of the variable in the memory
In C [*] dereference- Have an address and go there.

```c
int c = 50;
int *p = &c; Show the address of c; p is a pointer to an integer
```

- Pointer Arithemtic

```c
int c = 50;
int *p = &c; // p is a pointer to c
p++; // p now points to the next integer in memory
```

```c

```

- Malloc
  Allocate memory dynamically

```c

```

- Heap Memory
  Memory allocated at runtime, not on the stack.
  Use `malloc` to allocate memory on the heap.
  Heap memory: calling malloc too many times can lead to overflow to other memory.

- Stack memory
  Memory allocated for function calls and local variables.
  Stack overflow: call so many functions that it overflows into other memory

potential bug: not specified the amount of memory to allocate to string

```c
char *string;
  printf("string: ");
  scanf("%s", string);

```
