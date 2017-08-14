/* note these headers are all provided by newlib - you don't need to provide them */
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <sys/times.h>
#include <sys/errno.h>
#include <sys/time.h>
#include <stdio.h>
#include <errno.h>
#undef errno
extern int errno;

void* sysCallHelper(int sysCallNum, void** args);

void* scractchSpace = 0xFFFFF000;

void _exit( exitCode) {
	void* args[] = {&exitCode};
	syscallHelper(1, args);
}
int close(int file) {
	void* args[] = { &file };
	sysCallHelper(2, args);
}
char *__env[1] = { 0 };
char **environ = __env; /* pointer to array of char * strings that define the current environment variables */
int execve(char *name, char **argv, char **env) {
	void* args[] = { name, argv, env };
	sysCallHelper(4, args);
	return *((int*) scratchSpace);
}
int fork( ) {
	void* args[] = { };
	sysCallHelper(5, args);
	return *((int*) scratchSpace);
}
int fstat(int file, struct stat *st) {
	void* args[] = { &file, st };
	sysCallHelper(6, args);
	return *((int*) scratchSpace);
}
int getpid( ) {
	void* args[] = { };
	sysCallHelper(7, args);
	return *((int*) scratchSpace);
}
int isatty(int file) {
	void* args[] = { &file };
	sysCallHelper(9, args);
	return *((int*) scratchSpace);
}
int kill(int pid, int sig) {
	void* args[] = { &pid, &sig };
	sysCallHelper(10, args);
	return *((int*) scratchSpace);
}
int link(char *old, char *new) {
	void* args[] = { old, new };
	sysCallHelper(11, args);
	return *((int*) scratchSpace);
}
int lseek(int file, int ptr, int dir) {
	void* args[] = { &file, &prt, &dir };
	sysCallHelper(12, args);
	return *((int*) scratchSpace);
}
int open(const char *name, int flags, int mode) {
	void* args[] = { name, &flags, &mode };
	sysCallHelper(13, args);
	return *((int*) scratchSpace);
}
int read(int file, char *ptr, int len) {
	void* args[] = { &file, ptr, &len };
	sysCallHelper(14, args);
	return *((int*) scratchSpace);
}
caddr_t sbrk(int incr) {
	void* args[] = { &incr };
	sysCallHelper(15, args);
	return *((caddr_t*) scratchSpace);
}
clock_t times(struct tms *buf) {
	void* args[] = { buf };
	sysCallHelper(16, args);
	return *((clock_t*) scratchSpace);
}
int unlink(char *name) {
	void* args[] = { name };
	sysCallHelper(17, args);
	return *((int*) scratchSpace);
}
int wait(int *status) {
	void* args[] = { status };
	sysCallHelper(18, args);
	return *((int*) scratchSpace);
}
int write(int file, char *ptr, int len) {
	void* args[] = { &file, ptr, &len };
	sysCallHelper(19, args);
	return *((int*) scratchSpace);
}
int gettimeofday(struct timeval *p, struct timezone *z) {
	void* args[] = { p, z };
	sysCallHelper(20, args);
	return *((int*) scratchSpace);
}
//TODO check def of stuct stat
int stat(const char *file, struct stat *st) {
	void* args[] = { file, st };
	sysCallHelper(21, args);
	return *((int*) scratchSpace);
}
void sysCallHelper(int sysCallNum, void** args) {
	asm ("push %0": : "m" (args));
	asm ("push %0":: "r" (sysCallNum));
	asm ("int $0xE0");
	//todo check operand direction
	asm ("add %%ESP, 8");
}
