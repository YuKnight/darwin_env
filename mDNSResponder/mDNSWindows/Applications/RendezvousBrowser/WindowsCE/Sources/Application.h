/*
 * Copyright (c) 2002-2003 Apple Computer, Inc. All rights reserved.
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

    Change History (most recent first):
    
$Log: Application.h,v $
Revision 1.1  2003/08/21 02:16:10  bradley
Rendezvous Browser for HTTP services for Windows CE/PocketPC.

*/

#if !defined(AFX_APPLICATION_H__E2E51302_D643_458E_A7A5_5157233D1E5C__INCLUDED_)
#define AFX_APPLICATION_H__E2E51302_D643_458E_A7A5_5157233D1E5C__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include	"Resource.h"

//===========================================================================================================================
//	Application
//===========================================================================================================================

class	Application : public CWinApp
{
	public:
		
		Application();

		// ClassWizard generated virtual function overrides
		//{{AFX_VIRTUAL(Application)
		public:
		virtual BOOL InitInstance();
		//}}AFX_VIRTUAL

		//{{AFX_MSG(Application)
			// NOTE - the ClassWizard will add and remove member functions here.
			//    DO NOT EDIT what you see in these blocks of generated code !
		//}}AFX_MSG
		DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_APPLICATION_H__E2E51302_D643_458E_A7A5_5157233D1E5C__INCLUDED_)