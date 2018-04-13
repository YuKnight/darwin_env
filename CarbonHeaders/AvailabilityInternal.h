/*
    File:       AvailabilityInternal.h
 
    Copyright:  (c) 2007-2008 by Apple Inc., all rights reserved.

    Contains:   implementation details of __OSX_AVAILABLE_* macros from <Availability.h>
     

*/
#ifndef __AVAILABILITY_INTERNAL__
#define __AVAILABILITY_INTERNAL__


// if we want to support some compiler that does not support these
// attributes, we can test for the compiler version before defining these
#define __AVAILABILITY_INTERNAL_DEPRECATED         __attribute__((deprecated))
#define __AVAILABILITY_INTERNAL_UNAVAILABLE        __attribute__((unavailable))
#define __AVAILABILITY_INTERNAL_WEAK_IMPORT        __attribute__((weak_import))


#ifndef __IPHONE_OS_VERSION_MIN_REQUIRED
    #ifdef __ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__
        // compiler sets __ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__ when -miphoneos-version-min is used
        #define __IPHONE_OS_VERSION_MIN_REQUIRED __ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__
    #else
        // hack until compiler with -miphoneos-version-min is rolled out
        #if __arm__
            #define __IPHONE_OS_VERSION_MIN_REQUIRED 20000
        #endif
    #endif
#endif


#ifdef __IPHONE_OS_VERSION_MIN_REQUIRED
    // make sure a default max version is set
    #ifndef __IPHONE_OS_VERSION_MAX_ALLOWED
        #define __IPHONE_OS_VERSION_MAX_ALLOWED    __IPHONE_2_0
    #endif
    // make sure a valid min is set
    #if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_0
        #undef __IPHONE_OS_VERSION_MIN_REQUIRED
        #define __IPHONE_OS_VERSION_MIN_REQUIRED    __IPHONE_2_0 
    #endif

    // set up internal macros
    #if __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_2_0
        #define __AVAILABILITY_INTERNAL__IPHONE_2_0          __AVAILABILITY_INTERNAL_UNAVAILABLE
    #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_0
        #define __AVAILABILITY_INTERNAL__IPHONE_2_0          __AVAILABILITY_INTERNAL_WEAK_IMPORT
    #else
        #define __AVAILABILITY_INTERNAL__IPHONE_2_0
    #endif
    #define __AVAILABILITY_INTERNAL__IPHONE_NA                     __AVAILABILITY_INTERNAL_UNAVAILABLE 
    #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_NA     __AVAILABILITY_INTERNAL__IPHONE_2_0
    #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_2_0    __AVAILABILITY_INTERNAL_DEPRECATED
    #define __AVAILABILITY_INTERNAL__IPHONE_NA_DEP__IPHONE_NA      __AVAILABILITY_INTERNAL_UNAVAILABLE
    
#elif defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__)
    // compiler for Mac OS X sets __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__
    #define __MAC_OS_X_VERSION_MIN_REQUIRED __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__
    // make sure a default max version is set
    #ifndef __MAC_OS_X_VERSION_MAX_ALLOWED
        #define __MAC_OS_X_VERSION_MAX_ALLOWED __MAC_10_6
    #endif

    // set up internal macros
    #if __MAC_OS_X_VERSION_MAX_ALLOWED < __MAC_10_6
        #define __AVAILABILITY_INTERNAL__MAC_10_6        __AVAILABILITY_INTERNAL_UNAVAILABLE
    #elif __MAC_OS_X_VERSION_MIN_REQUIRED < __MAC_10_6
        #define __AVAILABILITY_INTERNAL__MAC_10_6        __AVAILABILITY_INTERNAL_WEAK_IMPORT
    #else    
        #define __AVAILABILITY_INTERNAL__MAC_10_6
    #endif
    #if __MAC_OS_X_VERSION_MAX_ALLOWED < __MAC_10_5
        #define __AVAILABILITY_INTERNAL__MAC_10_5        __AVAILABILITY_INTERNAL_UNAVAILABLE
    #elif __MAC_OS_X_VERSION_MIN_REQUIRED < __MAC_10_5
        #define __AVAILABILITY_INTERNAL__MAC_10_5        __AVAILABILITY_INTERNAL_WEAK_IMPORT
    #else
        #define __AVAILABILITY_INTERNAL__MAC_10_5
    #endif
    #if __MAC_OS_X_VERSION_MAX_ALLOWED < __MAC_10_4
        #define __AVAILABILITY_INTERNAL__MAC_10_4        __AVAILABILITY_INTERNAL_UNAVAILABLE
    #elif __MAC_OS_X_VERSION_MIN_REQUIRED < __MAC_10_4
        #define __AVAILABILITY_INTERNAL__MAC_10_4        __AVAILABILITY_INTERNAL_WEAK_IMPORT
    #else
        #define __AVAILABILITY_INTERNAL__MAC_10_4
    #endif
    #if __MAC_OS_X_VERSION_MAX_ALLOWED < __MAC_10_3
        #define __AVAILABILITY_INTERNAL__MAC_10_3        __AVAILABILITY_INTERNAL_UNAVAILABLE
    #elif __MAC_OS_X_VERSION_MIN_REQUIRED < __MAC_10_3
        #define __AVAILABILITY_INTERNAL__MAC_10_3        __AVAILABILITY_INTERNAL_WEAK_IMPORT
    #else
        #define __AVAILABILITY_INTERNAL__MAC_10_3
    #endif
    #if __MAC_OS_X_VERSION_MAX_ALLOWED < __MAC_10_2
        #define __AVAILABILITY_INTERNAL__MAC_10_2        __AVAILABILITY_INTERNAL_UNAVAILABLE
    #elif __MAC_OS_X_VERSION_MIN_REQUIRED < __MAC_10_2
        #define __AVAILABILITY_INTERNAL__MAC_10_2        __AVAILABILITY_INTERNAL_WEAK_IMPORT
    #else   
        #define __AVAILABILITY_INTERNAL__MAC_10_2
    #endif
    #if __MAC_OS_X_VERSION_MAX_ALLOWED < __MAC_10_1
        #define __AVAILABILITY_INTERNAL__MAC_10_1        __AVAILABILITY_INTERNAL_UNAVAILABLE
    #elif __MAC_OS_X_VERSION_MIN_REQUIRED < __MAC_10_1
        #define __AVAILABILITY_INTERNAL__MAC_10_1        __AVAILABILITY_INTERNAL_WEAK_IMPORT
    #else
        #define __AVAILABILITY_INTERNAL__MAC_10_1
    #endif
    #if __MAC_OS_X_VERSION_MAX_ALLOWED < __MAC_10_0
        #define __AVAILABILITY_INTERNAL__MAC_10_0        __AVAILABILITY_INTERNAL_UNAVAILABLE
    #elif __MAC_OS_X_VERSION_MIN_REQUIRED < __MAC_10_0
        #define __AVAILABILITY_INTERNAL__MAC_10_0        __AVAILABILITY_INTERNAL_WEAK_IMPORT
    #else
        #define __AVAILABILITY_INTERNAL__MAC_10_0
    #endif
    #define __AVAILABILITY_INTERNAL__MAC_NA             __AVAILABILITY_INTERNAL_UNAVAILABLE
    #if __MAC_OS_X_VERSION_MIN_REQUIRED >= __MAC_10_1
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_1        __AVAILABILITY_INTERNAL_DEPRECATED
    #else
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_1        __AVAILABILITY_INTERNAL__MAC_10_0
    #endif
    #if __MAC_OS_X_VERSION_MIN_REQUIRED >= __MAC_10_2
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_2        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_2        __AVAILABILITY_INTERNAL_DEPRECATED
    #else
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_2        __AVAILABILITY_INTERNAL__MAC_10_0
        #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_2        __AVAILABILITY_INTERNAL__MAC_10_1
    #endif
    #if __MAC_OS_X_VERSION_MIN_REQUIRED >= __MAC_10_3
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_3        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_3        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_3        __AVAILABILITY_INTERNAL_DEPRECATED
    #else
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_3        __AVAILABILITY_INTERNAL__MAC_10_0
        #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_3        __AVAILABILITY_INTERNAL__MAC_10_1
        #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_3        __AVAILABILITY_INTERNAL__MAC_10_2
    #endif
    #if __MAC_OS_X_VERSION_MIN_REQUIRED >= __MAC_10_4
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_4        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_4        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_4        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_4        __AVAILABILITY_INTERNAL_DEPRECATED
    #else
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_4        __AVAILABILITY_INTERNAL__MAC_10_0
        #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_4        __AVAILABILITY_INTERNAL__MAC_10_1
        #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_4        __AVAILABILITY_INTERNAL__MAC_10_2
        #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_4        __AVAILABILITY_INTERNAL__MAC_10_3
    #endif
    #if __MAC_OS_X_VERSION_MIN_REQUIRED >= __MAC_10_5
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_5        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_5        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_5        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_5        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_5        __AVAILABILITY_INTERNAL_DEPRECATED
    #else
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_5        __AVAILABILITY_INTERNAL__MAC_10_0
        #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_5        __AVAILABILITY_INTERNAL__MAC_10_1
        #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_5        __AVAILABILITY_INTERNAL__MAC_10_2
        #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_5        __AVAILABILITY_INTERNAL__MAC_10_3
        #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_5        __AVAILABILITY_INTERNAL__MAC_10_4
    #endif
    #if __MAC_OS_X_VERSION_MIN_REQUIRED >= __MAC_10_6
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_6        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_6        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_6        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_6        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_6        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_6        __AVAILABILITY_INTERNAL_DEPRECATED
    #else
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_6        __AVAILABILITY_INTERNAL__MAC_10_0
        #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_6        __AVAILABILITY_INTERNAL__MAC_10_1
        #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_6        __AVAILABILITY_INTERNAL__MAC_10_2
        #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_6        __AVAILABILITY_INTERNAL__MAC_10_3
        #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_6        __AVAILABILITY_INTERNAL__MAC_10_4
        #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_6        __AVAILABILITY_INTERNAL__MAC_10_5
    #endif
    #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_NA             __AVAILABILITY_INTERNAL__MAC_10_0
    #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_NA             __AVAILABILITY_INTERNAL__MAC_10_1
    #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_NA             __AVAILABILITY_INTERNAL__MAC_10_2
    #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_NA             __AVAILABILITY_INTERNAL__MAC_10_3
    #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_NA             __AVAILABILITY_INTERNAL__MAC_10_4
    #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_NA             __AVAILABILITY_INTERNAL__MAC_10_5
    #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_NA             __AVAILABILITY_INTERNAL__MAC_10_6
    #define __AVAILABILITY_INTERNAL__MAC_NA_DEP__MAC_NA               __AVAILABILITY_INTERNAL_UNAVAILABLE

#endif

#endif // __AVAILABILITY_INTERNAL__
