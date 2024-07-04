libXDGdirs
==========

[![Codacy Badge](https://app.codacy.com/project/badge/Grade/547fc2ec9e314ad593c14d84a7d4fab5)](https://www.codacy.com/gh/Jorengarenar/libXDGdirs/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=Jorengarenar/libXDGdirs&amp;utm_campaign=Badge_Grade)
[![CodeFactor](https://www.codefactor.io/repository/github/jorengarenar/libxdgdirs/badge)](https://www.codefactor.io/repository/github/jorengarenar/libxdgdirs)
[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=Jorengarenar_libXDGdirs&metric=alert_status)](https://sonarcloud.io/summary/new_code?id=Jorengarenar_libXDGdirs)
[![License](https://img.shields.io/github/license/Jorengarenar/libXDGdirs)](https://github.com/Jorengarenar/libXDGdirs/blob/master/LICENSE)
[![GitHub release (latest SemVer including pre-releases)](https://img.shields.io/github/v/release/Jorengarenar/libXDGdirs?include_prereleases&sort=semver)](https://github.com/Jorengarenar/libXDGdirs/releases)
[![AUR version](https://img.shields.io/aur/version/libxdgdirs)](https://aur.archlinux.org/packages/libxdgdirs)

An implementation of [XDG Base Directory Specification](https://specifications.freedesktop.org/basedir-spec/basedir-spec-latest.html)

_XDGBDS_ defines four categories of dotfiles and the corresponding directories
in user's home directory that should be used for those. The categories are
cache, configuration, data, state and runtime files.

All those locations have corresponding `XDG_*` environment variables.

All paths set in them must be absolute.  
If a relative path is encountered, the path is consider invalid and `NULL` is assigned.

## Build

### Download

Download the latest version from [release page](https://github.com/Jorengarenar/libXDGdirs/releases)
or clone Git repository for latest:
```sh
git clone https://github.com/Jorengarenar/libXDGdirs.git
cd libXDGdirs
```

### Build
```sh
cmake -B build/ -DCMAKE_BUILD_TYPE=Release
cmake --build build/ --config=Release
```

### Install
```sh
cmake --install build/
```

## Documentation

[Documentation](https://jorengarenar.github.io/libXDGdirs) generated from **latest commit** using [Doxygen](https://www.doxygen.nl)

## Usage

Refer to [topics](https://jorengarenar.github.io/libXDGdirs/topics.html)
and [examples](https://jorengarenar.github.io/libXDGdirs/examples.html)
in [documentation](https://jorengarenar.github.io/libXDGdirs)

## Read more

* [XDG Base Directory Specification](https://specifications.freedesktop.org/basedir-spec/basedir-spec-latest.html)
* [XDG Base Directory - ArchWiki](https://wiki.archlinux.org/index.php/XDG_Base_Directory)
* [XDGBaseDirectorySpecification - Debian Wiki](https://wiki.debian.org/XDGBaseDirectorySpecification)
