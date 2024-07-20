

#include <cstdio>   //NULL
//不再允许包含任何系统头文件

/* ----- 不允许定义任何形式的全局变量/全部数组/只读全局变量/宏定义!!!!! ----- */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return只是一个示例，可改变 */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlen(const char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    const char* p = str;
    if (p != NULL)
        while (*p != '\0') {
            p++;
        }
    return p - str;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strcat(char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p = s1;
    const char* q = s2;
    if (p != NULL) {
        while (*p)  //p指向'\0'
            p++;

        if (q != NULL)
            while (*q)
                *p++ = *q++;

        *p = '\0';
    }
    
    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strncat(char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int len_2 = tj_strlen(s2);
    int my_len = len < len_2 ? len : len_2;

    char* p = s1;
    const char* q = s2;

    if (p != NULL) {
        while (*p)  //p指向'\0'
            p++;

        if (q != NULL) {
            while (*q != '\0' && q - s2 < my_len)
                *p++ = *q++;
        }

        *p = '\0';
    }

    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strcpy(char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p = s1;
    const char* q = s2;
    if (p) {
        if (q) {
            while (*q)
                *p++ = *q++;
        }

        *p = '\0';
    }

    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strncpy(char *s1, const char *s2, const int len)
{
    char* p = s1;
    const char* q = s2;

    int len_2 = tj_strlen(s2);
    int my_len = len < len_2 ? len : len_2;

    if (p != NULL) {
        if (q != NULL) {
            while (q - s2 < my_len)
                *p++ = *q++;
        }

        //*p = '\0';
    }

    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcmp(const char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    const char* p = s1;
    const char* q = s2;
    if (p && q) {
        while (*p == *q && *p && *q) {
            p++;
            q++;
        }

        return *p - *q;
    }
    else if (p && !q)
        return 1;
    else if (!p && q)
        return -1;
    else
        return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasecmp(const char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    const char* p = s1;
    const char* q = s2;

    if (p && q) {
        while (1) {
            while (*p == *q && *p && *q) {
                p++;
                q++;
            }

            if (*p == '\0' && *q == '\0')
                return 0;

            char ch_1 = *p < *q ? *p : *q;
            char ch_2 = *p < *q ? *q : *p;

            if (ch_1 <= 'Z' && ch_1 >= 'A' && ch_2 <= 'z' && ch_2 >= 'a'
                && ch_1 - 'A' == ch_2 - 'a') {
                p++;
                q++;
            }
            else {
                ch_1 = *p;
                ch_2 = *q;
                if (ch_1 <= 'Z' && ch_1 >= 'A')
                    ch_1 += 'a' - 'A';
                if (ch_2 <= 'Z' && ch_2 >= 'A')
                    ch_2 += 'a' - 'A';
                return ch_1 - ch_2;
            }
        }
    }
    else if (p && !q)
        return 1;
    else if (!p && q)
        return -1;
    else
        return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncmp(const char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    const char* p = s1;
    const char* q = s2;

    
    int num_1 = tj_strlen(s1) + 1;
    int num_2 = tj_strlen(s2) + 1;
    int num = num_1 < num_2 ? num_1 : num_2;
    int my_len = len < num ? len : num;

    if (p && q) {
        while (*p == *q && p - s1 < my_len && q - s2 < my_len) {
            p++;
            q++;
        }

        if (p - s1 == my_len || q - s2 == my_len)
            return 0;
        else
            return *p - *q;
    }
     else if (p && !q)
         return 1;
     else if (!p && q)
         return -1;
     else
         return 0;

    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasencmp(const char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    const char* p = s1;
    const char* q = s2;

    int num_1 = tj_strlen(s1) + 1;
    int num_2 = tj_strlen(s2) + 1;
    int num = num_1 < num_2 ? num_1 : num_2;
    int my_len = len < num ? len : num;

    if (p && q) {
        for (; p - s1 < my_len && q - s2 < my_len; p++, q++) {
            if (*p != *q) {
                char ch_1 = *p < *q ? *p : *q;
                char ch_2 = *p < *q ? *q : *p;

                if (ch_1 <= 'Z' && ch_1 >= 'A' && ch_2 <= 'z' && ch_2 >= 'a'
                    && ch_1 - 'A' == ch_2 - 'a') {
                    continue;
                }
                else {
                    ch_1 = *p;
                    ch_2 = *q;
                    if (ch_1 <= 'Z' && ch_1 >= 'A')
                        ch_1 += 'a' - 'A';
                    if (ch_2 <= 'Z' && ch_2 >= 'A')
                        ch_2 += 'a' - 'A';
                    return ch_1 - ch_2;
                }
            }
        }

        return 0;
    }
    else if (p && !q)
        return 1;
    else if (!p && q)
        return -1;
    else
        return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strupr(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p = str;
    if (p) {
        while (*p) {
            if (*p <= 'z' && *p >= 'a')
                *p -= 'a' - 'A';
            p++;
        }
    }

    return str;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strlwr(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p = str;
    if (p) {
        while (*p) {
            if (*p <= 'Z' && *p >= 'A')
                *p += 'a' - 'A';
            p++;
        }
    }

    return str;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strchr(const char *str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    const char* p = str;
    if (p) {
        while (*p && *p != ch) {
            p++;
        }
        if (*p == ch)
            return p - str + 1;
        else
            return 0;
    }
    else
        return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strstr(const char *str, const char *substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    const char* p = str;
    const char* q = substr;

    if (p && q) {
        while (*p && *q) {
            if (*p == *q) {
                p++;
                q++;
            }
            else {
                p = p - (q - substr) + 1;
                q = substr;
            }
        }
        if (*q == '\0')
            return p - str - tj_strlen(substr) + 1;
        else
            return 0;
    }
    else
        return 0;
    
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrchr(const char *str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    const char* p = str;
    if (p) {
        while (*p)
            p++;

        for (; p - str >= 0; p--) {
            if (*p == ch)
                break;
        }

        return p - str + 1;
    }
    else
        return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrstr(const char *str, const char *substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    const char* p = str;
    const char* q = substr;
    const int num_2 = tj_strlen(substr);

    if (p && q) {
        while (*p)
            p++;
        while (*q)
            q++;
        p--;
        q--;

        while (p - str >= 0 && q - substr >= 0) {
            if (*p == *q) {
                p--;
                q--;
            }
            else {
                p = p + num_2 - (q - substr) - 2;
                q = substr + num_2 - 1;
            }
        }

        if (q == substr - 1)
            return p - str + 2;
        else
            return 0;
    }
    else 
        return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strrev(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p = str;
    char* q = str;

    if (p) {
        while (*q)
            q++;
        q--;

        while (p <= q) {
            char temp = *p;
            *p = *q;
            *q = temp;
            p++;
            q--;
        }
    }

    return str;

}
