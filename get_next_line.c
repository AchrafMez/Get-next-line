#include "get_next_line.h"
#include <string.h>
// #define BUFFER_SIZE 10

char *ft_read(int fd, char *chi_7aja, char *buffer)
{
    int bytes_read = BUFFER_SIZE;
    while (bytes_read > 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        buffer[bytes_read] = '\0';
        if(bytes_read == -1)
        {
            free(chi_7aja);
            free(buffer);
            chi_7aja = NULL;
            return NULL;
        }
        buffer[bytes_read] = '\0';
        chi_7aja = ft_strjoin(chi_7aja, buffer);
        if(contains_nl(chi_7aja) == 1)
            break;
    }
    free(buffer);
    return chi_7aja;
}

char* get_next_line(int fd) {
    char *buffer;
    static char *chi_7aja = NULL;
    char *line = NULL;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    buffer = malloc(BUFFER_SIZE + 1);
    if(!buffer)
        return NULL;
    chi_7aja = ft_read(fd, chi_7aja, buffer);
    if(!chi_7aja)
        return NULL;
    line = copy_until_nl(chi_7aja);
    // free(chi_7aja);
    // chi_7aja = NULL;
    chi_7aja = copy_after_nl(chi_7aja);
    return line;
}


int main() {

    int fd = open("file.txt", O_RDONLY);
    // printf("%d\n", fd);This is line 1.
    if(fd == -1)
        printf("error");
    printf("1%s", get_next_line(fd));
    printf("2%s", get_next_line(fd));
    printf("3%s", get_next_line(fd));
    printf("4%s", get_next_line(fd));
    printf("5%s", get_next_line(fd));
    printf("6%s", get_next_line(fd));
    printf("7%s", get_next_line(fd));
    printf("8%s", get_next_line(fd));
    printf("9%s", get_next_line(fd));
    printf("10%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("16%s", get_next_line(fd));
    printf("%s", get_next_line(fd));

    return 0;
}