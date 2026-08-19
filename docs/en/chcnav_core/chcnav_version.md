# CHCNAV Version Information
The header file for PSDK version information is `chcnav_version`. This document describes the macro definitions in the `chcnav_version.h` file.
## Definition
- CHCNAV PSDK Major Version Number
  CHCNAV PSDK major version number. Incremented when there are incompatible API changes. Range: 0 to 99.
  ```
    #define CHCNAV_VERSION_MAJOR 0
  ```
- CHCNAV PSDK Minor Version Number
  CHCNAV PSDK minor version number. Changed when functionality is added in a backward-compatible way. Range: 0 to 99.
  ```
    #define CHCNAV_VERSION_MINOR 0
  ```
- CHCNAV PSDK Patch Version Number
  CHCNAV PSDK patch version number. Changed when there are backward-compatible bug fixes. Range: 0 to 99.
  ```
    #define CHCNAV_VERSION_PATCH 0
  ```
- CHCNAV PSDK Code Branch Name
  CHCNAV PSDK code branch name.
  ```
    #define CHCNAV_VERSION_BRANCH "branch name"
  ```
- CHCNAV PSDK Code COMMIT ID
  CHCNAV PSDK code COMMIT ID.
  ```
    #define CHCNAV_VERSION_COMMIT "ee6852e"
  ```
