#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2018 // UTC year
#define YOTTA_BUILD_MONTH 3 // UTC month 1-12
#define YOTTA_BUILD_DAY 6 // UTC day 1-31
#define YOTTA_BUILD_HOUR 11 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 56 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 40 // UTC second 0-61
#define YOTTA_BUILD_UUID e38bc738-04f7-439d-a881-a972e95fb44c // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID e5f277aa775a0f9f9b309705d3df17b1f0325c5f // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION e5f277a // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
