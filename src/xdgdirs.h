#ifndef XDGDIRS_H_
#define XDGDIRS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

/** @def XDGDIRS_VER
 *  @brief Version of libXDGdirs
 *  @details
 *    Adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html)
 *
 *    Is set by build system
 */
#ifdef DOXYGEN
# define XDGDIRS_VER "MAJOR.MINOR.PATCH"
#endif

/// Version of XDG Base Directory specification implemented in this library
#define XDGBDS_VER "0.7"

/// @brief Container for environment variables which are colon separated lists
struct xdgDirsList_t {
    const char*  raw;  ///< Raw value of environment variable
    const char** list; ///< Null terminated array containing entries from environment variable
    size_t size;       ///< Number of entries in environment variable
};

typedef const struct xdgDirsList_t xdgDirsList;

/// @defgroup CACHE_MANAGEMENT Data cache management
/// @{

/** @brief Explicitly read variables before first use
 *  @details
 *    Will be used automatically with first call to any function from
 *    @ref VARIABLE_GETTERS
 *
 *    Call it if you want to have all data initialized before first use
 */
void xdgDirs_init();

/** @brief Clear cached data
 *  @details
 *    Deinitializes cached data and frees memory
 *
 *    Call when XDGBDS is no longer needed (presumably at the end of program)
 */
void xdgDirs_clear();

/** @brief Read environment variables again
 *  @details
 *    Clear cache with xdgDirs_clear() and initializes again with xdgDirs_init()
 */
void xdgDirs_refresh();

/// @}

/// @defgroup VARIABLE_GETTERS Reading environment variables
/// @{

/// @defgroup USER_DIRS User directories
/// @brief Base directories to which user-specific files should be written
/// @{

/** @brief Value of @c $XDG_DATA_HOME
 *  @details
 *    Base directory for user-specific data files (analogous to @c /usr/share)
 *  @return a path as described by the standards or NULL
 */
const char* xdgDataHome();

/** @brief Value of @c $XDG_CONFIG_HOME
 *  @details
 *    Base directory for user-specific configuration files (analogous to @c /etc)
 *  @return a path as described by the standards or NULL
 */
const char* xdgConfigHome();

/** @brief Value of @c $XDG_CACHE_HOME
 *  @details
 *    Base directory for user-specific non-essential data files (analogous to @c /var/cache)
 *  @return a path as described by the standards or NULL
 */
const char* xdgCacheHome();

/** @brief Value of @c $XDG_RUNTIME_DIR
 *  @details
 *    Base directory for user-specific non-essential runtime files (including file
 *    objects such as sockets and named pipes)
 *  @return a path as described by the standards or NULL
 */
const char* xdgRuntimeDir();

/// @}

/// @defgroup SYS_DIRS System directories
/// @brief Sets of preference ordered base directories relative to which files should be searched
/// @{

/** @brief Value of @c $XDG_DATA_DIRS
 *  @details
 *    Preference-ordered set of base directories to search for data files
 *    in addition to the @c $XDG_DATA_HOME base directory
 *
 *    See lists.c for example
 *  @return pointer to `const struct xdgDirsList_t`
 */
xdgDirsList* xdgDataDirs();

/** @brief Value of @c $XDG_CONFIG_DIRS
 *  @details
 *    Preference-ordered set of base directories to search for configuration
 *    files in addition to the @c $XDG_CONFIG_HOME base directory
 *  @return pointer to `const struct xdgDirsList_t`
 */
xdgDirsList* xdgConfigDirs();

/// @}

/** @brief User definied custom XDG variables
 *  @details
 *    Environment variables of pattern @c XDG_*_DIR
 *
 *    Those are not cached
 *  @returns a value of @c XDG_*_DIR variable or NULL
 */
const char* xdgCustomVar(const char* custom);

/// @}

#ifdef __cplusplus
} // extern "C"
#endif

#endif // XDGDIRS_H_
