#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2018 // UTC year
#define YOTTA_BUILD_MONTH 3 // UTC month 1-12
#define YOTTA_BUILD_DAY 8 // UTC day 1-31
#define YOTTA_BUILD_HOUR 18 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 1 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 30 // UTC second 0-61
#define YOTTA_BUILD_UUID 7445171c-7d5f-449b-8931-688f1c920a46 // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID 0badb7405482e6702c67a5cb7c88214e65bc21e5 // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION 0badb74 // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
