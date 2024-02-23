#include "get_next_line.h"

int ft_strlen(const char* s) {
    int ret = 0;
    if(!s)
        return -1;
    while (s[ret])
        ret++;
    return ret;
}

char* ft_strdup(const char* s) {
    if(!s)
        return NULL;
    char* cpy = malloc(sizeof(char) * (ft_strlen(s) + 1));
    if(!cpy)
        return NULL;
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
    char* result = NULL;
    if (!s1 && !s2)
        return NULL;
    if (s1 == NULL)
        s1 = ft_strdup("");
    result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if(!result)
        return NULL;
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

int contains_nl(const char* s) {
    int i = 0;

    if(!s)
        return -1;
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
    if(!cunl)
        return NULL;
    i = 0;
    while (in[i] && in[i] != '\n')
    {
        cunl[i] = in[i];
        i++;
    }
    cunl[i] = '\n';
    cunl[i + 1] = '\0';
    // free(in);
    return cunl;
    
    
}

char* copy_after_nl(char* in) {
    char *anl;
    int i = 0;
    int j = 0;

    if(!in)
        return NULL;
    while (in[i])
        i++;
    while (in[j] && in[j] != '\n')
        j++;
    j++;
    anl = malloc((i - j) + 1);
    if(!anl)
        return NULL;
    int a = 0;
    while (in[j] != '\0')
    {
        anl[a] = in[j];
        a++;
        j++;
    }
    anl[a] = '\0';
    return anl;
}