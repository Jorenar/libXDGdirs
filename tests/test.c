#include <stdio.h>
#include <xdgdirs.h>

int main()
{
    const char* data_home = xdgDataHome();
    if (data_home) {
        puts(data_home);
    }
    return 0;
}
