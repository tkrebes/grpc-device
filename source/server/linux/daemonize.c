#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>
#include <unistd.h>

#include "../daemonize.h"
#include "redirect.h"

void daemonize()
{
  pid_t pid;

  // Fork off the parent process
  pid = fork();

  // An error occurred
  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  // Success: Let the parent terminate
  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  // On success: The child process becomes session leader
  if (setsid() < 0) {
    exit(EXIT_FAILURE);
  }

  // Catch, ignore and handle signals
  signal(SIGCHLD, SIG_IGN);
  signal(SIGHUP, SIG_IGN);

  // Fork off for the second time
  pid = fork();

  // An error occurred
  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  // Success: Let the parent terminate
  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  // Set new file permissions
  umask(0);

  // Change the working directory to the root directory or another appropriated directory
  chdir("/");

  // Close all open file descriptors
  int x;
  for (x = sysconf(_SC_OPEN_MAX); x >= 0; x--) {
    close (x);
  }

  // Redirect standard files to /dev/null
  if (freopen("/dev/null", "r", stdin) == NULL) {
    syslog(LOG_ERR, "Failed to redirect stdin to /dev/null, code=%d (%s)", errno, strerror(errno));
  }
  if (freopen("/dev/null", "w", stdout) == NULL) {
    syslog(LOG_ERR, "Failed to redirect stdout to /dev/null, code=%d (%s)", errno, strerror(errno));
  }
  if (freopen("/dev/null", "w", stderr) == NULL) {
    syslog(LOG_ERR, "Failed to redirect stderr to /dev/null, code=%d (%s)", errno, strerror(errno));
  }

  // Open the log file
  openlog("ni_grpc_device_server", LOG_PID, LOG_DAEMON);
  tolog(&stderr, LOG_ERR);
  tolog(&stdout, LOG_INFO);
  atexit(closelog);
}