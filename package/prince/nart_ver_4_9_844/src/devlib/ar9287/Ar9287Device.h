#ifndef _AR9287DEVICE_h_
#define _AR9287DEVICE_h_

#include "ah.h"

#ifdef _WINDOWS
#ifdef AR9287DLL
		#define AR9287DLLSPEC __declspec(dllexport)
	#else
		#define AR9287DLLSPEC __declspec(dllimport)
	#endif
#else
	#define AR9287DLLSPEC
#endif


//
// clear all device control function pointers and set to default behavior
//
extern AR9287DLLSPEC int Ar9287DeviceSelect(void);

extern AR9287DLLSPEC int Ar9287SetCommand(int client);

extern AR9287DLLSPEC int Ar9287GetCommand(int client);
extern bool ar9287_calibration_data_read_flash(struct ath_hal *ah, long address,u_int8_t *buffer, int many);

#endif
