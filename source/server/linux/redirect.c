#define _GNU_SOURCE
#include <string.h>
#include <stdint.h>
#include <syslog.h>

#include "redirect.h"

static cookie_read_function_t read;
static cookie_write_function_t write;
static cookie_seek_function_t seek;
static cookie_close_function_t close;

static const cookie_io_functions_t redirect_functions = {read, write, seek, close};

static ssize_t read(void* cookie, char* buf, size_t nbytes)
{
  return 0;
}

static ssize_t write(void* cookie, const char* buf, size_t nbytes)
{
  int priority = (int)((uintptr_t)cookie);
  syslog(priority, buf);
  return nbytes;
}

static int seek(void* cookie, off64_t* pos, int w)
{
  return 0;
}

static int close (void* cookie)
{
  return 0;
}

void tolog(FILE **pfp, int priority)
{
  setvbuf(*pfp = fopencookie((void *)((uintptr_t)priority), "w", redirect_functions), NULL, _IOLBF, 0);
}
