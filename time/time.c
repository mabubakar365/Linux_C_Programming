#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int main() {
    struct timeval tv;
    struct tm* ptm;
    char time_string[40];
    long milliseconds;

    // Get the current time
    gettimeofday(&tv, NULL);

    // Format the date and time, down to a single second
    ptm = localtime(&tv.tv_sec);
    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", ptm);

    // Compute milliseconds from microseconds
    milliseconds = tv.tv_usec;

    // Print the formatted time, in seconds, milliseconds and time zone offset
    printf("%s.%06ld %c%02ld%02ld\n", time_string, milliseconds, 
        (ptm->tm_gmtoff < 0) ? '-' : '+',
        abs(ptm->tm_gmtoff) / 3600,
        (abs(ptm->tm_gmtoff) % 3600) / 60);

    return 0;
}
