#include <stdio.h>
#include <xdgdirs.h>

int main()
{
    puts(xdgDataHome());
    return 0;
}
