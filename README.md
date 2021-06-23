libXDGdirs
==========

[![Build Status](https://travis-ci.com/Jorengarenar/libXDGdirs.svg?branch=master)](https://travis-ci.com/Jorengarenar/libXDGdirs)
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/547fc2ec9e314ad593c14d84a7d4fab5)](https://www.codacy.com/gh/Jorengarenar/libXDGdirs/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=Jorengarenar/libXDGdirs&amp;utm_campaign=Badge_Grade)
[![CII Best Practices](https://bestpractices.coreinfrastructure.org/projects/4532/badge)](https://bestpractices.coreinfrastructure.org/projects/4532)
[![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/Jorengarenar/libXDGdirs.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/Jorengarenar/libXDGdirs/context:cpp)
[![CodeFactor](https://www.codefactor.io/repository/github/jorengarenar/libxdgdirs/badge)](https://www.codefactor.io/repository/github/jorengarenar/libxdgdirs)
[![License](https://img.shields.io/github/license/Jorengarenar/libXDGdirs)](https://github.com/Jorengarenar/libXDGdirs/blob/master/LICENSE)
[![GitHub release (latest SemVer including pre-releases)](https://img.shields.io/github/v/release/Jorengarenar/libXDGdirs?include_prereleases&sort=semver)](https://github.com/Jorengarenar/libXDGdirs/releases)
[![AUR version](https://img.shields.io/aur/version/libxdgdirs)](https://aur.archlinux.org/packages/libxdgdirs)

An implementation of [XDG Base Directory Specification](https://specifications.freedesktop.org/basedir-spec/basedir-spec-latest.html)

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

**WARNING!** [Documentation](https://jorengarenar.github.io/libXDGdirs) available
online uses latest commit, not release!

# Usage

Refer to [modules](https://jorengarenar.github.io/libXDGdirs/modules.html) and
[examples](https://jorengarenar.github.io/libXDGdirs/examples.html) in [documentation](https://joren.ga/libXDGdirs)
# Read more

* [XDG Base Directory Specification](https://specifications.freedesktop.org/basedir-spec/basedir-spec-latest.html)
* [XDG Base Directory - ArchWiki](https://wiki.archlinux.org/index.php/XDG_Base_Directory)
* [XDGBaseDirectorySpecification - Debian Wiki](https://wiki.debian.org/XDGBaseDirectorySpecification)
* [r/XDG](https://www.reddit.com/r/XDG)
* [Jorengarenar's blog posts on topic](https://jorengarenar.github.io/blog/tags/#xdg)
