#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2018 // UTC year
#define YOTTA_BUILD_MONTH 3 // UTC month 1-12
#define YOTTA_BUILD_DAY 5 // UTC day 1-31
#define YOTTA_BUILD_HOUR 12 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 13 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 9 // UTC second 0-61
#define YOTTA_BUILD_UUID ac8527c6-9877-4238-9cd9-d5b5c2c61502 // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID 4757df808fcbbe089f79ded7347d78712aab9d38 // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION 4757df8 // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
