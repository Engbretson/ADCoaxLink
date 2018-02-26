/* Copyright Euresys 2014, 2017 */

#ifndef EURESYS_GENTL_HEADER_FILE
#define EURESYS_GENTL_HEADER_FILE

#error "EuresysGenTL.h cannot be #included anymore, please consult this file (EuresysGenTL.h) for further details"

// The class Euresys::GenTL that used to be declared in this header file
// (EuresysGenTL.h) has been renamed into Euresys::EGenTL. For consistency
// reasons, the class Euresys::EGenTL is now declared in the header file
// EGenTL.h.

// The rationale for this *breaking change* lies in the fact that the standard
// GenTL header file uses a new C++ namespace from version 1.5.
// Prior to version 1.5, the standard namespace was GenICam::Client,
// From version 1.5, the standard namespace is GenTL.

// This new standard namespace GenTL and the class Euresys::GenTL cannot
// co-exist in any C++ code that is "using namespace Euresys".
// These ambiguites are reported as compilation errors by the C++ compiler.
// Renaming the class Euresys::GenTL was the only option to avoid ambiguity.

// Migration guide
// ---------------
// 1. Replace #include <EuresysGenTL.h> by #include <EGenTL.h>
// 2. Replace the type GenTL (Euresys::GenTL) by EGenTL (Euresys::EGenTL)

#endif
