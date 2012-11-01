#include "stdafx.h"

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved);

_declspec (dllexport) int avg_num(double *a, double *b, int size, double *avg_a, double * avg_b);

_declspec (dllexport) int c_avg_num(double * re, double * im, int size, double * avg_re, double * avg_im);