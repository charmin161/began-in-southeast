
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

static int hex2dec (char c) {
    if ('0' <= c && c <= '9') return c - '0';
    else if ('a' <= c && c <= 'f') return c - 'a' + 10;
    else if ('A' <= c && c <= 'F') return c - 'A' + 10;
    return 0;
}
 
static char dec2hex (short int c) {
    if (0 <= c && c <= 9) return c + '0';
    else if (10 <= c && c <= 15) return c + 'A' - 10;
    return 0;
}
 
/** url解码 **/
char *_url_decode(const char *s) {
    int i = 0, len = 0;
    int i_new = 0, len_new = 0;
    char *result = NULL;
 
    if (!s || *s == 0)
        return NULL;
 
    len = strlen(s);
    len_new = (len + 2) * 2 + 10;
    result = (char *)malloc(len_new);
    if (!result)
        return NULL;
 
    memset(result, 0, len_new);
    for (i = 0; i < len; ++i) {
        char c = s[i];
        if (c != '%') {
            if (c == '+')
                result[i_new++] = ' ';
            else
                result[i_new++] = c;
        } else {
            char c1 = s[++i];
            char c0 = s[++i];
            result[i_new++] = hex2dec(c1) * 16 + hex2dec(c0);
        }
    }
    result[i_new] = '\0';
    return result;
}
 
/** url编码 **/
char *_url_encode(const char *s) {
    int i = 0, j = 0;
    int s_len = 0, d_len = 0;
    int m = 0, n = 0;
    char *d = NULL;
 
    if (!s)
        return NULL;
 
    s_len = strlen(s);
    d_len = (s_len + 2) * 3 + 10;
    d = (char *)malloc(d_len);
    if (!d)
        return NULL;
 
    memset(d, 0, sizeof(d_len));
    for (i = 0; i < s_len; i++) {
        if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            d[j++] = s[i];
        } else {
            short int b = (short int)s[i];
            if (b < 0) b += 256;
            m = b / 16;
            n = b - m * 16;
            d[j++] = '%';
            d[j++] = dec2hex(m);
            d[j++] = dec2hex(n);
        }
    }
    d[j] = '\0';
    return d;
}
int main(){

    char *url = "https://yikuaimen-第二章/";
    char *urlen = _url_encode(url);
    char *urlde = _url_decode(urlen);
    printf("%s \n",url);
    printf("%s \n",urlen);
    printf("%s \n",urlde);
    printf(_url_decode(urlde));

    return 0;
}