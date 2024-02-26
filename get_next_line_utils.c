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
    char* result ;
    if (!s1 && !s2)
        return NULL;
    if (!s1 && s2)
        return strdup(s2);
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
    s1 = NULL;
    return result;
}

int contains_nl(char* chi_7aja) {
    int i = 0;

    if(!chi_7aja)
        return -1;
    while (chi_7aja[i] && chi_7aja[i] != '\0') {
        if (chi_7aja[i] == '\n')
            return 1;
        i++;
    }
    return 0;
}

char* copy_until_nl(char* chi_7aja) {
    char *cunl;
    int i = 0;
    if(!chi_7aja[0])
        return NULL;
    while (chi_7aja[i] && chi_7aja[i] != '\n')
        i++;
    if(chi_7aja[i] && chi_7aja[i] == '\n')
        i += 1;
    cunl = malloc(i + 1);
    if(!cunl)
        return NULL;
    i = 0;
    while (chi_7aja[i] && chi_7aja[i] != '\n')
    {
        cunl[i] = chi_7aja[i];
        i++;
    }
    if(chi_7aja && chi_7aja[i] == '\n' )
        cunl[i++] = '\n';
    cunl[i] = '\0';
    return cunl;
}

char* copy_after_nl(char* in) {
    char *anl;
    int i = 0;
    int j = 0;

    if(!in)
        return NULL;
    while (in[i] && in[i] != '\n')
        i++;
    if(!in[i])
    {
        free(in);
        return NULL;
    }
    anl = malloc((strlen(in) - i) + 1);
    i++;
    if(!anl)
        return NULL;
    while (in[i] != '\0')
    {
        anl[j] = in[i];
        i++;
        j++;
    }
    anl[j] = '\0';
    free(in);
    return anl;
}