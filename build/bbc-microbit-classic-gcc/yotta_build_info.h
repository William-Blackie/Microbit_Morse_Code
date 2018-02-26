#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2018 // UTC year
#define YOTTA_BUILD_MONTH 2 // UTC month 1-12
#define YOTTA_BUILD_DAY 26 // UTC day 1-31
#define YOTTA_BUILD_HOUR 13 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 23 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 56 // UTC second 0-61
#define YOTTA_BUILD_UUID 18a86328-41b8-4eaa-ba6d-d3f42567f25a // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID deda65b05ab3a3802163571b7d9d5a3883e95b23 // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION deda65b // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
