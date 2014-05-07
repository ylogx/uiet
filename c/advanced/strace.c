#include <stdio.h>
int main (void ) {
    printf("Hello World");
    return 0;
}
/*
chaudhary@Jarvis:~/code/chome/advanced$ strace ./strace.out > strace.c
execve("./strace.out", ["./strace.out"], [/ * 44 vars * /]) = 0
brk(0)                                  = 0xc71000
access("/etc/ld.so.nohwcap", F_OK)      = -1 ENOENT (No such file or directory)
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f508ba9e000
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
open("/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=179847, ...}) = 0
mmap(NULL, 179847, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7f508ba72000
close(3)                                = 0
access("/etc/ld.so.nohwcap", F_OK)      = -1 ENOENT (No such file or directory)
open("/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\200\30\2\0\0\0\0\0"..., 832) = 832
fstat(3, {st_mode=S_IFREG|0755, st_size=1811128, ...}) = 0
mmap(NULL, 3925208, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7f508b4bf000
mprotect(0x7f508b674000, 2093056, PROT_NONE) = 0
mmap(0x7f508b873000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1b4000) = 0x7f508b873000
mmap(0x7f508b879000, 17624, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7f508b879000
close(3)                                = 0
mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f508ba71000
mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f508ba70000
mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f508ba6f000
arch_prctl(ARCH_SET_FS, 0x7f508ba70700) = 0
mprotect(0x7f508b873000, 16384, PROT_READ) = 0
mprotect(0x600000, 4096, PROT_READ)     = 0
mprotect(0x7f508baa0000, 4096, PROT_READ) = 0
munmap(0x7f508ba72000, 179847)          = 0
fstat(1, {st_mode=S_IFREG|0664, st_size=0, ...}) = 0
mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f508ba9d000
write(1, "Hello World", 11)             = 11
exit_group(0)                           = ?
*/
