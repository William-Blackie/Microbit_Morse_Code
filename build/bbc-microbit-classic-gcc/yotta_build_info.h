#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2018 // UTC year
#define YOTTA_BUILD_MONTH 3 // UTC month 1-12
#define YOTTA_BUILD_DAY 6 // UTC day 1-31
#define YOTTA_BUILD_HOUR 13 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 12 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 32 // UTC second 0-61
#define YOTTA_BUILD_UUID f72d1f69-815a-4ac2-bed4-3d75d6f35f5c // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID a56367acf880d3a8456bdb7455659ee0a1ca852d // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION a56367a // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
