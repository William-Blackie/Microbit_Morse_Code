#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2018 // UTC year
#define YOTTA_BUILD_MONTH 2 // UTC month 1-12
#define YOTTA_BUILD_DAY 26 // UTC day 1-31
#define YOTTA_BUILD_HOUR 13 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 54 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 57 // UTC second 0-61
#define YOTTA_BUILD_UUID ec35801a-c694-44b6-86d1-52be1f757368 // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID 9ecbd6440e0cce21a17e692b80cf8edc3c4bb833 // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION 9ecbd64 // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
