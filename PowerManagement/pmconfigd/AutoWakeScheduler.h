/*
 * Copyright (c) 2003 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */
/*
 * Copyright (c) 2003 Apple Computer, Inc.  All rights reserved. 
 *
 * HISTORY
 *
 * 30-Jan-03 ebold created
 *
 */
 
#ifndef _AutoWakeScheduler_h_
#define _AutoWakeScheduler_h_

#define kIOPMRepeatingAppName               "Repeating"

/* Flags for checkPendingWakeReqs() */
#define CHECK_UPCOMING          0x1
#define CHECK_EXPIRED           0x2
#define PREVENT_PURGING         0x4
#define ALLOW_PURGING           0x8

/* 
 * MIN_SLEEP_DURATION - Minimum duration(in secs) for which we like the system to sleep. Any user wake requests 
 *                      that are going to wake the system before this duration should prevent sleep.
 */
#if TARGET_OS_EMBEDDED
#define MIN_SLEEP_DURATION      15
#else
#define MIN_SLEEP_DURATION      60
#endif

__private_extern__ void             AutoWake_prime(void);
__private_extern__ void             AutoWakeCapabilitiesNotification(IOPMSystemPowerStateCapabilities old_cap, IOPMSystemPowerStateCapabilities new_cap);
__private_extern__ void             AutoWakeCalendarChange(void);
__private_extern__ IOReturn         createSCSession(SCPreferencesRef *prefs, uid_t euid, int lock);
__private_extern__ void             schedulePowerEventType(CFStringRef type);
__private_extern__ void             destroySCSession(SCPreferencesRef prefs, int unlock);
__private_extern__ CFAbsoluteTime   getWakeScheduleTime(CFDictionaryRef event);
__private_extern__ CFTimeInterval   getEarliestRequestAutoWake(void);
__private_extern__ CFDictionaryRef copyEarliestRequestAutoWakeEvent(void);
__private_extern__ bool             checkPendingWakeReqs(int options);


#endif // _AutoWakeScheduler_h_
