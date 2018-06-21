#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/xattr.h>
#include <sys/stat.h>
#include <inttypes.h>
#include <string.h>


int
main ()
{
        int fd = -1;

        char *f = "a.txt";
        struct stat pre = {0};
        struct stat post = {0};

        fd = open (f, O_RDWR|O_CREAT);
        if (stat (f, &pre))
                printf ("Error");
        sleep (5);
        fsetxattr (fd, "trusted.def", "def", 3, 0);
        if (stat (f, &post))
                printf ("Error");
        printf ("fSetxattr: pre: ctime: %"PRIu32", ctime_nsec: %"PRIu32" post: ctime: %"PRIu32", ctime_nsec: %"PRIu32"\n", pre.st_ctime, pre.st_ctim.tv_nsec, post.st_ctime, post.st_ctim.tv_nsec);

        memset (&pre, 0, sizeof pre);
        memset (&post, 0, sizeof post);
        if (stat (f, &pre))
                printf ("Error");
        sleep (5);
        setxattr (f, "trusted.abc", "abc", 3, 0);
        if (stat (f, &post))
                printf ("Error");
        printf (" Setxattr: pre: ctime: %"PRIu32", ctime_nsec: %"PRIu32" post: ctime: %"PRIu32", ctime_nsec: %"PRIu32"\n", pre.st_ctime, pre.st_ctim.tv_nsec, post.st_ctime, post.st_ctim.tv_nsec);

}
