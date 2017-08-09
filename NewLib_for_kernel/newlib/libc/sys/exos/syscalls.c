/* note these headers are all provided by newlib - you don't need to provide them */
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <sys/times.h>
#include <sys/errno.h>
#include <sys/time.h>
#include <stdio.h>
#include <errno.h>
#include <stdarg.h>
#undef errno
extern int errno;

void* sysCallHelper(int sysCallNum, void** args);

void _exit( exitCode) {
	void* args[] = {&exitCode};
	syscallHelper(1, args);
}
int close(int file) {
	void* args[] = { &file };
	return sysCallHelper(2, args);
}
char *__env[1] = { 0 };
char **environ = __env; /* pointer to array of char * strings that define the current environment variables */
int execve(char *name, char **argv, char **env) {
	void* args[] = { name, argv, env };
	return sysCallHelper(4, args);
}
int fork( ) {
	void* args[] = { };
	return sysCallHelper(5, args);
}
int fstat(int file, struct stat *st) {
	void* args[] = { &file, st };
	return sysCallHelper(6, args);
}
int getpid( ) {
	void* args[] = { };
	return sysCallHelper(7, args);
}
int isatty(int file) {
	void* args[] = { &file };
	return sysCallHelper(9, args);
}
int kill(int pid, int sig) {
	void* args[] = { &pid, &sig };
	return sysCallHelper(10, args);
}
int link(char *old, char *new) {
	void* args[] = { old, new };
	return sysCallHelper(11, args);
}
int lseek(int file, int ptr, int dir) {
	void* args[] = { &file, &prt, &dir };
	return sysCallHelper(12, args);
}
int open(const char *name, int flags, int mode) {
	void* args[] = { name, &flags, &mode };
	return sysCallHelper(13, args);
}
int read(int file, char *ptr, int len) {
	void* args[] = { &file, ptr, &len };
	return sysCallHelper(14, args);
}
caddr_t sbrk(int incr) {
	void* args[] = { &incr };
	return sysCallHelper(15, args);
}
clock_t times(struct tms *buf) {
	void* args[] = { buf };
	return sysCallHelper(16, args);
}
int unlink(char *name) {
	void* args[] = { name };
	return sysCallHelper(17, args);
}
int wait(int *status) {
	void* args[] = { status };
	return sysCallHelper(18, args);
}
int write(int file, char *ptr, int len) {
	void* args[] = { &file, ptr, &len };
	return sysCallHelper(19, args);
}
int gettimeofday(struct timeval *p, struct timezone *z) {
	void* args[] = { p, z };
	return sysCallHelper(20, args);
}
//TODO check def of stuct stat
int stat(const char *file, struct stat *st) {
	void* args[] = { file, st };
	return sysCallHelper(21, args);
}
void* sysCallHelper(int sysCallNum, void** args) {
	void* ret;
	asm ("push %0": : "m" (args));
	asm ("push %0":: "r" (sysCallNum));
	asm ("int $0xE0");
	//todo i think this may be wrong...
	asm (pop %0, "m"(ret));
	return ret;
}
