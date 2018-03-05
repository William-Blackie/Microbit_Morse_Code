#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2018 // UTC year
#define YOTTA_BUILD_MONTH 3 // UTC month 1-12
#define YOTTA_BUILD_DAY 5 // UTC day 1-31
#define YOTTA_BUILD_HOUR 12 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 37 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 16 // UTC second 0-61
#define YOTTA_BUILD_UUID f3ab5337-2a80-46da-bd15-130982111a63 // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID 77165e460d22428b1cc4ae029df928d556edca25 // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION 77165e4 // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
