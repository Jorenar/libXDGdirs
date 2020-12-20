/** @example print.c
 *  @code{.unparsed}
 *  -- POSSIBLE OUTPUT --
 *
 * XDG_DATA_HOME        /home/user/.local/share
 * XDG_CONFIG_HOME      /home/user/.config
 * XDG_CACHE_HOME       /home/user/.cache
 * XDG_RUNTIME_DIR      /run/user/1000
 * XDG_DATA_DIRS        /usr/local/share:/usr/share
 * XDG_CONFIG_DIRS      /etc/xdg
 *  @endcode
 */
/// @cond
#include <stdio.h>
#include <xdgdirs.h>

int main()
{
    const char* fmt = "%-20s %s\n";
    printf(fmt, "XDG_DATA_HOME",   xdgDataHome());
    printf(fmt, "XDG_CONFIG_HOME", xdgConfigHome());
    printf(fmt, "XDG_CACHE_HOME",  xdgCacheHome());
    printf(fmt, "XDG_RUNTIME_DIR", xdgRuntimeDir());
    printf(fmt, "XDG_DATA_DIRS",   xdgDataDirs()->raw);
    printf(fmt, "XDG_CONFIG_DIRS", xdgConfigDirs()->raw);
    xdgDirs_clear();
    return 0;
}
/// @endcond
