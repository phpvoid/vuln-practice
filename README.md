# Vulnerable C Programs 

### The most useful examples:
The ones that taught me the most while experimenting

### use_after_free.c:
We are reading and writing buf after free(buf). Freeing memory doesn't remove the memory mapping, it just tells the allocater that it is available now. The old data sits there so if we call printf everything seems fine however if we write to it, two things can happen depending on if the chunk has been reused. If it has not been reused you might corrupt the heap by overwriting the heap metadeta (fd and bk freelist pointers) which is similar to the double-free bug. If it has been reused by another memory allocation somewhere in the program then the write corrupts this completely unrelated object.

### double_free.c:
We are calling free twice on the same pointer, buf. Freeing for the first time puts the chunk into a freelist bin while the fd and bk pointers are written to what used to be user data. If we free again, the same chunk is put into the same freelist bin (or different one), which breaks the list structure since the two entries point to overlapping memory. If we malloc a chunk of the same size before we detect the problem, allocater could give back the same chunk twice (two pointers to one buffer).

### race_thread.c:
This is a classic data race, multiple threads executing a non-atomic counter++. At machine level, we are loading counter into a register from a memory address, incrementing the value in the register, then writing it back to the memory address. If we want more than one thread to perform this operation on a non-atomic variable, one of them might lose an operation like an increment, causing undefined behavior and will give us back some smaller non-deterministic number.





