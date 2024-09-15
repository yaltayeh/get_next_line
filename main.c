#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
    char *files[] = {
        "a.txt",
        "b.txt",
        "c.txt",
        "get_next_line_bonus.c",
        "get_next_line.c",
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
    int c = 1;
    while (c)
    {
        char *line;
        int t;
        c = 0;
        for (int i = 0; i < count; i++)
        {
            line = get_next_line(fds[i]);
            printf("%d: %s", i, line);
            if (line)
            {
                free(line);
                c = 1;
            }
            else printf("\n");
        }
        printf("\n");
    }
    
    
    for (int i = 0 ; i < count; i++)
        close(fds[i]);
    return (0);
}