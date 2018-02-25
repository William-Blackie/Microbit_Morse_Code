#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2018 // UTC year
#define YOTTA_BUILD_MONTH 2 // UTC month 1-12
#define YOTTA_BUILD_DAY 25 // UTC day 1-31
#define YOTTA_BUILD_HOUR 12 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 39 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 8 // UTC second 0-61
#define YOTTA_BUILD_UUID 508861cf-c642-4ed7-9b41-03ddeb6312a8 // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID b07670a3802d4ef688e0fbc4e637ad3affe2ce47 // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION b07670a // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
