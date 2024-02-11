#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#define BUFFER_SIZE 2

#pragma region common_utils

int ft_strlen(const char* s) {
    int ret = 0;
    while (s[ret])
        ret++;
    return ret;
}

// void* ft_memset(unsigned char* dst, unsigned char c, int len) {
//     unsigned char* dst_bytes = (unsigned char*)dst;
//     int i = 0;
//     while ( i < len) {
//         dst_bytes[i] = c;
//         i++;
//     }
//     return dst;
// }

char* ft_strdup(const char* s) {
    char* cpy = malloc(sizeof(char) * (ft_strlen(s) + 1));
    int i = 0;
    while ( s[i]) {
        cpy[i] = s[i];
        i++;
    }
    cpy[i] = '\0';
    return cpy;
}

char *ft_strjoin(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    char* result;
    if (!s1 && !s2)
        return NULL;
    if (s1 == NULL)
        s1 = malloc(1);
    result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    while (s1[i] && s1[i] != '\0')
    {
        result[i] = s1[i];
        i++;
    }
    while (s2[j] && s2[j] != '\0')
    {
        result [i + j] = s2[j];
        j++;
    }
    result[i + j] = 0;
    free(s1);
    return result;
}

#pragma endregion

int contains_nl(const char* s) {
    int i = 0;
    while (s[i]) {
        if (s[i] == '\n')
            return 1;
        i++;
    }
    return 0;
}

char* copy_until_nl(char* in) {
    char *cunl;
    int i = 0;
    if(!in)
        return NULL;
    while (in[i] && in[i] != '\n')
    {
        i++;
    }
    cunl = malloc(i + 2);
    i = 0;
    while (in[i] && in[i] != '\n')
    {
        cunl[i] = in[i];
        i++;
    }
    cunl[i] = '\n';
    cunl[i + 1] = '\0';
    return cunl;
    
    
}

char* copy_after_nl(char* in) {
    char *anl;
    int i = 0;
    int j = 0;
    while (in[i])
        i++;
    while (in[j] && in[j] != '\n')
        j++;
    j++;
    anl = malloc((i - j) + 1);
    int a = 0;
    while (in[j] != '\0')
    {
        anl[a] = in[j];
        a++;
        j++;
    }
    anl[a] = '\0';
    free(in);
    return anl;
}

char* get_next_line(int fd) {
    char buffer[BUFFER_SIZE + 1];
    // buffer[BUFFER_SIZE] = '\0';
    int bytes_read = BUFFER_SIZE;
    static char *chi_7aja;
    if(fd == -1)
        return NULL;
    while (bytes_read == BUFFER_SIZE) {
        // free(chi_7aja);
    //    printf("br when enter in the loop == %d\n\n", bytes_read);
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        buffer[bytes_read] = '\0';
        if(bytes_read == -1){
    //    printf("br whene it faild == %d\n", bytes_read);
            return NULL;
        }
        // if(bytes_read == 1)
        //     return ft_strdup(buffer);
        chi_7aja = ft_strjoin(chi_7aja, buffer);
        if (contains_nl(chi_7aja))
            break;
    }
    if (!bytes_read)
        return NULL;
    char *line = copy_until_nl(chi_7aja);
    chi_7aja = copy_after_nl(chi_7aja);
    return line;
}


int main() {

    int fd = open("file.txt", O_RDONLY);
    char*   buffer;
    if(fd == -1)
        printf("error");
    // while (1)
    // {
    //     buffer = get_next_line(fd);
    //     if (!buffer)
    //         break;
    //     printf(" *%s* ", buffer);
    // }
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    return 0;
}
