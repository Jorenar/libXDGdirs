Changelog
=========

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

## [1.1.3] - 2024-11-08
### Changed

- Use Git hooks for updating version in header
- Update badges in README
- Update URLs to repo in README
- Update URLs in CHANGELOG

### Removed

- AUTHORS file
- CONTRIBUTING.md file

## [1.1.2] - 2024-07-06
### Added

- pkg-config file

### Changed

- Use Git tags for generating version header

## [1.1.1] - 2023-11-11
### Fixed

- Missing `void` params

## [1.1.0] - 2022-04-27
### Added

- `XDG_STATE_HOME`

### Changed

- Updated to XDG Base Directory Specification version 0.8

## [1.0.5] - 2022-02-18
### Fixed

- Define undefined `XDGDIRS_VER`
- Return value of `xdgDirs_init()`

## [1.0.4] - 2020-12-22
### Fixed

- `xdgDirsList` in C++

## [1.0.3] - 2020-12-22
### Changed

- Use `vsnprintf()` in `xdgDirs_getenv()`

### Fixed

- Return from `xdgDirs_getenv()` after assigning `NULL`
- Missing `extern C`

## [1.0.2] - 2020-12-21
### Added

- LGTM and CodeFactor project badges in README

### Changed

- Rename `LIB_NAME` to `XDGDIRS` in CMakeLists.txt
- Use `${PROJECT_VERSION}` instead of `${CMAKE_PROJECT_VERSION}`

### Fixed

- Assignment of value instead of comparison (src/xdgdirs.c:35)

## [1.0.1] - 2020-12-20
### Added

- LGTM configuration

### Changed

- Cosmetic change from `-pedantic` compiler flag to `-Wpedantic`

### Fixed

- Check if `fmt` in `xdgDirs_getenv()` is `NULL`

## [1.0.0] - 2020-12-20
### Added

- Source code of library
- Simple examples of usage
- Documentation
- README, CHANGELOG and AUTHORS

##
[unreleased]: https://github.com/Jorenar/libXDGdirs/compare/v1.1.3...HEAD
[1.1.3]: https://github.com/Jorenar/libXDGdirs/compare/v1.1.2...v1.1.3
[1.1.2]: https://github.com/Jorenar/libXDGdirs/compare/v1.1.1...v1.1.2
[1.1.1]: https://github.com/Jorenar/libXDGdirs/compare/v1.1.0...v1.1.1
[1.1.0]: https://github.com/Jorenar/libXDGdirs/compare/v1.0.5...v1.1.0
[1.0.5]: https://github.com/Jorenar/libXDGdirs/compare/v1.0.4...v1.0.5
[1.0.4]: https://github.com/Jorenar/libXDGdirs/compare/v1.0.3...v1.0.4
[1.0.3]: https://github.com/Jorenar/libXDGdirs/compare/v1.0.2...v1.0.3
[1.0.2]: https://github.com/Jorenar/libXDGdirs/compare/v1.0.1...v1.0.2
[1.0.1]: https://github.com/Jorenar/libXDGdirs/compare/v1.0.0...v1.0.1
[1.0.0]: https://github.com/Jorenar/libXDGdirs/releases/tag/v1.0.0
