#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <libc.h>

int main()
{
    char *files[] = {
        "a.txt",
        "b.txt",
        "c.txt"
    };
    const int count = sizeof(files)/sizeof(files[0]);
	int fds[count];
    for (int i = 0; i < count; i++)
    {
        if ((fds[i] = open(files[i], O_RDONLY)) == -1)
        {
            printf("Can't open '%s'\n", files[i]);
            for ( ; i >= 0; i--)
                close(fds[i]);
            return (1);
        }
    }

    while (1)
    {
        char *lines[count];
        for (int i = 0; i < count; i++)
            lines[i] = get_next_line(fds[i]);
        
    }
    
    
    for (int i = 0 ; i < count; i++)
        close(fds[i]);
    return (0);
}