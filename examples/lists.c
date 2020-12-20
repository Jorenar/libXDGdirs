/** @example lists.c
 *  @code{.unparsed}
 *  -- POSSIBLE OUTPUT --
 *
 *  /usr/local/share:/usr/share
 *  2
 *  /usr/local/share
 *  /usr/share
 *
 *  /etc/xdg
 *  1
 *  /etc/xdg
 *  @endcode
 */
/// @cond
#include <stdio.h>
#include <xdgdirs.h>

int main()
{
    // XDG_DATA_DIRS ---------------------------------------
    xdgDirsList foo = *xdgDataDirs();
    puts(foo.raw);
    printf("%zd\n", foo.size);
    for (int i = 0; foo.list[i] != NULL; ++i) {
        puts(foo.list[i]);
    }

    // XDG_CONFIG_DIRS -------------------------------------
    xdgDirsList* bar = xdgConfigDirs();
    printf("\n%s\n%zd\n", bar->raw, bar->size);
    for (int i = 0; bar->list[i] != NULL; ++i) {
        puts(bar->list[i]);
    }

    // free memory -----------------------------------------
    xdgDirs_clear();

    return 0;
}
/// @endcond
