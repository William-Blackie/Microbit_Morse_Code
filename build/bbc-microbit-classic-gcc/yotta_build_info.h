#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2018 // UTC year
#define YOTTA_BUILD_MONTH 2 // UTC month 1-12
#define YOTTA_BUILD_DAY 27 // UTC day 1-31
#define YOTTA_BUILD_HOUR 16 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 33 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 52 // UTC second 0-61
#define YOTTA_BUILD_UUID 9ac191a2-d271-4212-b42d-476351ee8fd2 // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID ad68ab2a13867b8716685911ecac20cf5d8cb5fc // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION ad68ab2 // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
