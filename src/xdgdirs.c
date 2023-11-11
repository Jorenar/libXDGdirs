#include "xdgdirs.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// @addtogroup DEV ~dev
/// @brief Additional documentation for contibutors
/// @details Generated with debug version
/// @{

/// @name Helpers
/// @{

static const char* xdgDirs_strdup(const char* str)
{
    if (str == NULL) {
        return NULL;
    }
    size_t len = strlen(str) + 1;
    char* out = malloc(len * sizeof(*out));
    return (out ? memcpy(out, str, len) : NULL);
}

static void xdgDirs_getenv(const char** ptr, const char* var, const char* fmt, ...)
{
    const char* temp = getenv(var);
    if (temp != NULL && temp[0] == '/') {
        *ptr = xdgDirs_strdup(temp);
        return;
    }

    if (fmt == NULL || fmt[0] == '\0') {
        *ptr = NULL;
        return;
    }

    va_list ap;
    va_start(ap, fmt);

    char fallback[BUFSIZ];
    vsnprintf(fallback, BUFSIZ, fmt, ap);

    *ptr = (fallback[0] == '/' ? xdgDirs_strdup(fallback) : NULL);

    va_end(ap);
}

static void xdgDirs_free(const char** str, struct xdgDirsList_t* li)
{
    if (str && *str) {
        free((void*)(*str));
        *str = NULL;
    } else if (li) {
        xdgDirs_free(&li->raw, NULL);
        for (size_t i = 0; li->list[i]; ++i) {
            free((void*)li->list[i]);
        }
        free(li->list);
        li->list = NULL;
        li->size = 0;
    }
}

static void xdgDirs_genList(struct xdgDirsList_t* li)
{
    li->size = 1;
    char* raw = (char*)xdgDirs_strdup(li->raw);
    for (size_t i = 0; raw[i]; ++i) {
        if (raw[i] == ':' && raw[i+1] != ':' && raw[i+1] != '\0') {
            li->size += 1;
        }
    }

    li->list = malloc((li->size + 1) * sizeof(*(li->list)));

    char* v = strtok(raw, ":");
    for (size_t i = 0; i < li->size && v != NULL; ++i) {
        li->list[i] = xdgDirs_strdup(v);
        v = strtok(NULL, ":");
    }

    free(raw);

    li->list[li->size] = NULL;
}

/// @}

/// @name Data cache management
/// @{

#if DOXYGEN
# define DOXYGEN_UNNAMED xdgDirs_cache_t
#else
# define DOXYGEN_UNNAMED
#endif

/** @var xdgDirs_cache
 *  @brief Container for cached values from environment variables
 *  @details
 *    The results of @ref CACHE_MANAGEMENT functions.\n
 *    Check xdgDirs_cache_t
 */

static struct DOXYGEN_UNNAMED {
    short initialized;
    struct /* user */ {
        const char* data;    ///< @c $XDG_DATA_HOME
        const char* state;   ///< @c $XDG_STATE_HOME
        const char* config;  ///< @c $XDG_CONFIG_HOME
        const char* cache;   ///< @c $XDG_CACHE_HOME
        const char* runtime; ///< @c $XDG_RUNTIME_DIR
    } user; ///< User directories
    struct /* system */ {
        struct xdgDirsList_t data;   ///< @c $XDG_DATA_DIRS
        struct xdgDirsList_t config; ///< @c $XDG_CONFIG_DIRS
    } system; ///< System directories
} xdgDirs_cache = { .initialized = 0 };

#undef DOXYGEN_UNNAMED

void xdgDirs_clear(void)
{
    if (xdgDirs_cache.initialized == 0) {
        return;
    }

    xdgDirs_free(&xdgDirs_cache.user.config,  NULL);
    xdgDirs_free(&xdgDirs_cache.user.data,    NULL);
    xdgDirs_free(&xdgDirs_cache.user.state,   NULL);
    xdgDirs_free(&xdgDirs_cache.user.cache,   NULL);
    xdgDirs_free(&xdgDirs_cache.user.runtime, NULL);

    xdgDirs_free(NULL, &xdgDirs_cache.system.data);
    xdgDirs_free(NULL, &xdgDirs_cache.system.config);

    xdgDirs_cache.initialized = 0;
}

int xdgDirs_init(void)
{
    if (xdgDirs_cache.initialized == 1) {
        return 0;
    }

    xdgDirs_clear();

    const char* home = getenv("HOME");

    if (home == NULL) {
        return 1;
    }

    xdgDirs_getenv(&xdgDirs_cache.user.data,    "XDG_DATA_HOME",   "%s%s", home, "/.local/share");
    xdgDirs_getenv(&xdgDirs_cache.user.state,   "XDG_STATE_HOME",  "%s%s", home, "/.local/state");
    xdgDirs_getenv(&xdgDirs_cache.user.config,  "XDG_CONFIG_HOME", "%s%s", home, "/.config");
    xdgDirs_getenv(&xdgDirs_cache.user.cache,   "XDG_CACHE_HOME",  "%s%s", home, "/.cache");
    xdgDirs_getenv(&xdgDirs_cache.user.runtime, "XDG_RUNTIME_DIR", "");

    xdgDirs_getenv(&xdgDirs_cache.system.data.raw, "XDG_DATA_DIRS", "/usr/local/share:/usr/share");
    xdgDirs_genList(&xdgDirs_cache.system.data);

    xdgDirs_getenv(&xdgDirs_cache.system.config.raw, "XDG_CONFIG_DIRS", "/etc/xdg");
    xdgDirs_genList(&xdgDirs_cache.system.config);

    xdgDirs_cache.initialized = 1;

    return 0;
}

void xdgDirs_refresh(void)
{
    xdgDirs_cache.initialized = -1;
    xdgDirs_init();
}

/// @}

/// @name Reading environment variables
/// @{

#define XDGDIRS_RETURN(var)        \
    do {                           \
        if (xdgDirs_init() != 0) { \
            return NULL;           \
        }                          \
        return var;                \
    } while (0)

// User directories {{{1

const char* xdgDataHome(void)
{
    XDGDIRS_RETURN(xdgDirs_cache.user.data);
}

const char* xdgStateHome(void)
{
    XDGDIRS_RETURN(xdgDirs_cache.user.state);
}

const char* xdgConfigHome(void)
{
    XDGDIRS_RETURN(xdgDirs_cache.user.config);
}

const char* xdgCacheHome(void)
{
    XDGDIRS_RETURN(xdgDirs_cache.user.cache);
}

const char* xdgRuntimeDir(void)
{
    XDGDIRS_RETURN(xdgDirs_cache.user.runtime);
}

// System directories {{{1

xdgDirsList* xdgDataDirs(void)
{
    XDGDIRS_RETURN(&xdgDirs_cache.system.data);
}

xdgDirsList* xdgConfigDirs(void)
{
    XDGDIRS_RETURN(&xdgDirs_cache.system.config);
}

// }}}1

#undef XDGDIRS_RETURN

const char* xdgCustomVar(const char* custom)
{
    char var[1000];
    snprintf(var, 1000, "%s%s%s", "XDG_", custom, "_DIR");
    const char* x = getenv(var);
    return x == NULL ? "" : x;
}

/// @}

/// @}

// vim: fdl=1
