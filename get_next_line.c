#include "get_next_line.h"
#include <string.h>

char* get_next_line(int fd) {
    char buffer[BUFFER_SIZE + 1];
    int bytes_read = BUFFER_SIZE;
    static char *chi_7aja;
    // char *temp;

    if(fd <= 0 || BUFFER_SIZE <= 0)
        return NULL;
    while (bytes_read > 0) {
        // free(chi_7aja);
    //    printf("br when enter in the loop == %d\n\n", bytes_read);
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        buffer[bytes_read] = '\0';
        // 
        chi_7aja = ft_strjoin(chi_7aja, buffer);
        if (contains_nl(chi_7aja))
            break;
    }
    if (*chi_7aja == '\0'){
        return NULL;
    }
    char *line = copy_until_nl(chi_7aja);
    chi_7aja = copy_after_nl(chi_7aja);
    // if (!line)
    //     free(line);
    return line;
}


// int main() {

//     int fd = open("file.txt", O_RDONLY);
//     if(fd == -1)
//         printf("error");
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     return 0;
// }