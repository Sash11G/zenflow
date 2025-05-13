typedef unsigned long size_t;

#define xoffsetof(s, m) ((size_t)&(((s*)0)->m))

struct Example {
    char a;
    char b;
    int c;
};

int printf(const char*, ...);

int main() 
{
    printf("%zu\n", xoffsetof(struct Example, c));
    return 0;
}
