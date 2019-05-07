#define gx getchar
#define px putchar
#define blank putchar('\n')



 /* Read an integer */
void readint(int &n)
{
    int sign = 1;
    n = 0;
    char c = gx();
    while (c < '0' || c > '9')
    {
        if (c == '-') sign = -1;
        c = gx();
    }
    while (c >= '0' && c <= '9') n = (n << 3) + (n << 1) + c - '0', c = gx();  n = n * sign;
}

/* Read a long long int */
void readll(ll &n)
{
    int sign = 1;
    n = 0;
    char c = gx();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            sign = -1;
        c = gx();
    }
    while (c >= '0' && c <= '9') n = (n << 3) + (n << 1) + c - '0', c = gx();  n = n * (ll)(sign);
}
 
/* Read a complete line */
int readline(char a[])
{
    char c = gx();
    while (c == ' ' || c == '\n') c = gx();
    int i = 0;
    while (c != '\n')a[i++] = c, c = gx();
    a[i] = 0;
    return i;
}
 
/* Read a single word */
int readstr(char a[])
{
    char c = gx();
    while (c == ' ' || c == '\n') c = gx();
    int i = 0;
    while (c != EOF && c != '\n' && c != ' ')a[i++] = c, c = gx();
    a[i] = 0;
    return i;
}
 
/* print an integer */
void writeint(int n)
{
    if (n<0)
    {
        n = -n;
        px('-');
    }
    int i = 10;
    char o[10];
    do { o[--i] = (n % 10) + '0'; n /= 10; } while (n);
    do { px(o[i]); } while (++i<10);
}
 
/* print long long int */
void writell(ll n)
{
    if (n<0LL)
    {
        n = -n;
        px('-');
    }
    int i = 21;
    char o[21];
    do { o[--i] = (n % 10LL) + '0'; n /= 10LL; } while (n);
    do { px(o[i]); } while (++i<21);
}
 
/* print string and line */
void writestr(const char a[])
{
    const char *p = a;
    while (*p)px(*p++);
}