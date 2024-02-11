#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUFFER_SIZE 10

#pragma region common_utils

int ft_strlen(const char* s) {
    int ret = 0;
    for (ret; s[ret]; ret++);
    return ret;
}

void* ft_memset(unsigned char* dst, unsigned char c, int len) {
    unsigned char* dst_bytes = (unsigned char*)dst;
    for (int i = 0; i < len; i++) {
        dst_bytes[i] = c;
    }
    return dst;
}

char* ft_strdup(const char* s) {
    char* cpy = malloc(sizeof(char) * (ft_strlen(s) + 1));
    ft_memset(cpy, 0, sizeof(char) * (ft_strlen(s) + 1));
    for (int i = 0; s[i]; i++) {
        cpy[i] = s[i];
    }
    return cpy;

}

char *ft_strjoin(char *s1, char *s2)
{
    int i = 0;
    int j = 0;

    if(!s1 && !s2)
        return NULL;
    // if(!s1)
    //     return ft_strdup(s2);
    if(s1 == NULL)
        s1 = "";
    char *result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    while (s1[i] && s1[i] != '\0')
    {
        result[i] = s1[i];
        i++;
    }
    while (s2[j] && s2[j] != '\0'){
        result [i + j] = s2[j];
        j++;
    }
    result[i + j] = 0;
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
    anl = malloc((i - j) + 1);
    int a = 0;
    while (in[j + 1] != '\0')
    {
        anl[a] = in[j + 1];
        a++;
        j++;
    }
    anl[i + j] = '\0';
    return anl;
}

char* get_next_line(int fd) {
    char buffer[BUFFER_SIZE + 1];
    int bytes_read = 0;
    static char *chi_7aja;
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        // joini buffer m3a chi 7aja
        chi_7aja = ft_strjoin(chi_7aja, buffer);
        if (contains_nl(buffer)) {
            break;
        }
    }
    char *line = copy_until_nl(chi_7aja);
    chi_7aja = copy_after_nl(line);
    return line;

    return NULL;
}


int main(int argc, char const *argv[]) {

    int fd = open("test.txt", O_RDONLY);
    if(fd == -1)
        printf("error");
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    printf("%s", NULL);
    return 0;
}
