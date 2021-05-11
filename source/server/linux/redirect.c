#define _GNU_SOURCE
#include <string.h>
#include <syslog.h>

#include "redirect.h"

static cookie_read_function_t read;
static cookie_write_function_t write;
static cookie_seek_function_t seek;
static cookie_close_function_t close;

static struct RedirectCookie
{
   cookie_io_functions_t functions;
   int priority;
} redirect_cookie[] = {
   [LOG_EMERG] = {{read, write, seek, close}, LOG_EMERG},
   [LOG_ALERT] = {{read, write, seek, close}, LOG_ALERT},
   [LOG_CRIT] = {{read, write, seek, close}, LOG_CRIT},
   [LOG_ERR] = {{read, write, seek, close}, LOG_ERR},
   [LOG_WARNING] = {{read, write, seek, close}, LOG_WARNING},
   [LOG_NOTICE] = {{read, write, seek, close}, LOG_NOTICE},
   [LOG_INFO] = {{read, write, seek, close}, LOG_INFO},
   [LOG_DEBUG] = {{read, write, seek, close}, LOG_DEBUG},
};


static ssize_t read(void* cookie, char* buf, size_t nbytes)
{
  return 0;
}

static ssize_t write(void* cookie, const char* buf, size_t nbytes)
{
  struct RedirectCookie* rcookie = (struct RedirectCookie*)cookie;
  syslog(rcookie->priority, buf);
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
  struct RedirectCookie* rcookie = &redirect_cookie[priority];
  setvbuf(*pfp = fopencookie(rcookie, "w", rcookie->functions), NULL, _IOLBF, 0);
}
