#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2018 // UTC year
#define YOTTA_BUILD_MONTH 2 // UTC month 1-12
#define YOTTA_BUILD_DAY 26 // UTC day 1-31
#define YOTTA_BUILD_HOUR 14 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 18 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 13 // UTC second 0-61
#define YOTTA_BUILD_UUID 74b22ac6-1980-4ac9-bfdd-e87923d65a7d // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID 2ddea794bf0d04f764bdc8c1b0c66c62faf8d4ee // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION 2ddea79 // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
