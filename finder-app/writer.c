#include <stdio.h>
#include <string.h>
#include <syslog.h>


int main(int argc, char **argv) {
	int writefile_length = strlen(argv[1]);
	int writestr_length = strlen(argv[2]);

	openlog("Log:", LOG_CONS, LOG_USER);
	
	if (writefile_length <= 0 || writestr_length <= 0) {
		syslog(LOG_ERR, "Arguments were not specified");	
		return 1;
	}

	FILE *fp = fopen(argv[1], "w");
	if (fp == NULL) {
		syslog(LOG_ERR, "File (%s) cannot be opened/created", argv[1]);
		fclose(fp);
		return 1;
	}

	if (fputs(argv[2], fp) != EOF) {
		syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);
	} else {
		syslog(LOG_ERR, "cannot write string (%s) to file (%s)", argv[2], argv[1]);
		fclose(fp);
		return 1;
	}

	fclose(fp);
	closelog();
}
