#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2018 // UTC year
#define YOTTA_BUILD_MONTH 2 // UTC month 1-12
#define YOTTA_BUILD_DAY 26 // UTC day 1-31
#define YOTTA_BUILD_HOUR 12 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 49 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 9 // UTC second 0-61
#define YOTTA_BUILD_UUID 07479032-8a04-4a76-b9d0-0d0ed1212220 // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID 63c488fcc2b6291e42054d9756a08d0c8f29fc33 // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION 63c488f // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
