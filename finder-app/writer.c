#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <string.h>
#include <errno.h>

//script that accepts full path to a file "writefile" and text to be written "writestr", and writes to writefile
//assumes directories already exist, creates new file if writefile does not exist, or overwrites its content

void usage(const char *prog_name) {
	fprintf(stderr, "Usage: %s <writefile> <writestr>\n", prog_name);
}

int main(int argc, char *argv[]) {
    // Open syslog
    openlog("writer", LOG_PID, LOG_USER);

    // Check for the correct number of arguments
    if (argc != 3) {
        syslog(LOG_ERR, "Invalid number of arguments: expected 2, got %d", argc - 1);
        usage(argv[0]);
        closelog();
        exit(EXIT_FAILURE);
    }

    const char *writefile = argv[1];
    const char *writestr = argv[2];

    // Open the file
    FILE *file = fopen(writefile, "w");
    if (file == NULL) {
        syslog(LOG_ERR, "Error opening file %s: %s", writefile, strerror(errno));
        perror("Error opening file");
        closelog();
        exit(EXIT_FAILURE);
    }

    // Write the string to the file
    if (fprintf(file, "%s", writestr) < 0) {
        syslog(LOG_ERR, "Error writing to file %s: %s", writefile, strerror(errno));
        perror("Error writing to file");
        fclose(file);
        closelog();
        exit(EXIT_FAILURE);
    }

    // Log success message
    syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);

    // Close the file
    fclose(file);

    // Close syslog
    closelog();

    return 0;
}
