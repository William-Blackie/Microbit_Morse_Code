#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2018 // UTC year
#define YOTTA_BUILD_MONTH 2 // UTC month 1-12
#define YOTTA_BUILD_DAY 25 // UTC day 1-31
#define YOTTA_BUILD_HOUR 15 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 47 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 4 // UTC second 0-61
#define YOTTA_BUILD_UUID 2d935149-4f81-4a4b-838d-33f6ad9c84d4 // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID 9fb443c2c010d10bc2cf6054512dd19d29a6249a // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION 9fb443c // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
