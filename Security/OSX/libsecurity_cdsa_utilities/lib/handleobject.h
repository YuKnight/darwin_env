/*
 * Copyright (c) 2000-2008,2011 Apple Inc. All Rights Reserved.
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


//
// handleobject - give an object a process-global unique handle
//
#ifndef _H_HANDLEOBJECT
#define _H_HANDLEOBJECT

#include <Security/cssm.h>
#include <security_cdsa_utilities/handletemplates.h>

//
// definitions kept here so other code doesn't have to modify #includes
//

namespace Security
{

typedef TypedHandle<CSSM_HANDLE> HandledObject;

typedef MappingHandle<CSSM_HANDLE> HandleObject;

} // end namespace Security

#endif //_H_HANDLEOBJECT
