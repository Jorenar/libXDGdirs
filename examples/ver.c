/** @example ver.c
 *  @code{.unparsed}
 *  -- POSSIBLE OUTPUT --
 *
 *  1.0.0
 *  0.7
 *  @endcode
 */
/// @cond
#include <stdio.h>
#include <xdgdirs.h>

int main()
{
    puts(XDGDIRS_VER);
    puts(XDGBDS_VER);
    return 0;
}
/// @endcond
