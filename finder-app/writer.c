#include <stdio.h>
#include <string.h>
#include <syslog.h>

int main(int argc, char **argv) {
    openlog("writer", LOG_CONS, LOG_USER);

    if (argc < 3) {
        syslog(LOG_ERR, "Usage: writer <file> <string>");
        closelog();
        return 1;
    }

    FILE *fp = fopen(argv[1], "w");
    if (fp == NULL) {
        syslog(LOG_ERR, "File (%s) cannot be opened/created", argv[1]);
        closelog();
        return 1;
    }

    if (fputs(argv[2], fp) != EOF) {
        syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);
    } else {
        syslog(LOG_ERR, "Cannot write string (%s) to file (%s)", argv[2], argv[1]);
        fclose(fp);
        closelog();
        return 1;
    }

    fclose(fp);
    closelog();
    return 0;
}
