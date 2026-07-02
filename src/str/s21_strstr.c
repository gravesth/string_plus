#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle)
{
    // создание префикс функции
    int i = 0, indpf = 0;
    int *pf = NULL;

    while (needle[i] != '\0')
    {
        int *temp = (int *)realloc(pf, (i + 1) * sizeof(int));
        if (temp == NULL)
        {
            free(pf);
            pf = NULL;
            break;
        }
        pf = temp;

        if (i != 0 && needle[indpf] == needle[i])
        {
            pf[i] = ++indpf;
        }
        else
        {
            indpf = 0;
            pf[i] = 0;
        }
        i++;
    }
}