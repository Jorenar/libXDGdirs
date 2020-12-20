/** @example custom.c
 *  @code{.unparsed}
 *  -- POSSIBLE OUTPUT --
 *
 *  XDG_MUSIC_DIR: /home/user/music
 *  @endcode
 */
/// @cond
#include <stdio.h>
#include <xdgdirs.h>

int main()
{
    printf("XDG_MUSIC_DIR: %s", xdgCustomVar("MUSIC") );
    return 0;
}
/// @endcond
