// default_vs.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "default_vs.h"


// This is an example of an exported variable
DEFAULT_VS_API int ndefault_vs=0;

// This is an example of an exported function.
DEFAULT_VS_API int fndefault_vs(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see default_vs.h for the class definition
Cdefault_vs::Cdefault_vs()
{
    return;
}
