#ifndef _MYDELAY_H_
#define _MYDELAY_H_

#ifdef _WINDOWS
	#ifdef PARSEDLL
		#define PARSEDLLSPEC __declspec(dllexport)
	#else
		#define PARSEDLLSPEC __declspec(dllimport)
	#endif
#else
	#define PARSEDLLSPEC
#endif

extern PARSEDLLSPEC void MyDelay(int ms);

#endif
