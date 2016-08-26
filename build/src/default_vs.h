// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the DEFAULT_VS_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// DEFAULT_VS_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef DEFAULT_VS_EXPORTS
#define DEFAULT_VS_API __declspec(dllexport)
#else
#define DEFAULT_VS_API __declspec(dllimport)
#endif

// This class is exported from the default_vs.dll
class DEFAULT_VS_API Cdefault_vs {
public:
	Cdefault_vs(void);
	// TODO: add your methods here.
};

extern DEFAULT_VS_API int ndefault_vs;

DEFAULT_VS_API int fndefault_vs(void);
