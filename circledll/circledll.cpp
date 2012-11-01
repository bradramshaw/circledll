// circledll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "circledll.h"
//#include "extcode.h"

using namespace std;

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call,  LPVOID lpReserved )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

_declspec (dllexport) int avg_num(double *a, double *b, int size, double *avg_a, double * avg_b){

	
	
	double avg_a_temp = 0;
	for(int i = 0; i < size; i ++){
		avg_a_temp += a[i];
	}

	double avg_b_temp = 0;
	for(int i = 0; i < size; i ++){
		avg_b_temp += b[i];
	}

	*avg_a = avg_a_temp/size;
	*avg_b = avg_b_temp/size;

	return 0;

}



_declspec (dllexport) int c_avg_num(double * re, double * im, int size, double * avg_re, double * avg_im){
	
	complex<double> *z_array = new complex<double>[size];

	for(int i = 0; i < size; i ++){
		z_array[i] = complex<double>(re[i], im[i]);
	}

	complex<double> temp_sum = complex<double>(0,0);
	for(int i = 0; i < size; i++){
		temp_sum += z_array[i];
	}
	temp_sum /= size;

	*avg_re = real(temp_sum);
	*avg_im = imag(temp_sum);

	delete[] z_array;

	return 0;

}