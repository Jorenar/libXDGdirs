libXDGdirs
==========

An implemetation of [XDG Base Directory Specification](https://specifications.freedesktop.org/basedir-spec/basedir-spec-latest.html) (_XDGBDS_)

_XDGBDS_ defines four categories of dotfiles and the corresponding directories in a users
home directory that should be used for those. The categories are cache,
configuration, data and runtime files.

All those locations have corresponding `XDG_*` environment variables.

All paths set in them must be absolute. If a relative path is encountered,
the path is consider invalid and `NULL` is assigned.

# Obtaining

## Download

Download the latest version from [release page](https://github.com/Jorengarenar/libXDGdirs/releases)
or clone Git repository for latest:
```sh
git clone https://github.com/Jorengarenar/libXDGdirs.git
cd libXDGdirs
```

## Build
```sh
cmake -B build/ -DCMAKE_BUILD_TYPE=Release
cmake --build build/
```

## Install
```sh
cmake --install build/
```

# Documentation

Generated with [Doxygen](https://www.doxygen.nl)

**WARNING!** [Documentation](https://joren.ga/libXDGdirs) available
online uses latest commit, not release!

# Usage

Refer to [modules](https://joren.ga/libXDGdirs/modules.html) and
[examples](https://joren.ga/libXDGdirs/examples.html) in [documentation](https://joren.ga/libXDGdirs)
# Read more

* [XDG Base Directory Specification](https://specifications.freedesktop.org/basedir-spec/basedir-spec-latest.html)
* [XDG Base Directory - ArchWiki](https://wiki.archlinux.org/index.php/XDG_Base_Directory)
* [XDGBaseDirectorySpecification - Debian Wiki](https://wiki.debian.org/XDGBaseDirectorySpecification)
* [r/XDG](https://www.reddit.com/r/XDG)
* [Jorengarenar's blog posts on topic](https://blog.joren.ga/tags/#xdg)
