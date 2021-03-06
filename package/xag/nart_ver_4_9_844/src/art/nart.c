
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
//#include <execinfo.h>
#include <unistd.h>

#include "smatch.h"
#include "UserPrint.h"
#include "ErrorPrint.h"
#include "ParseError.h"
#include "NewArt.h"
#include "ParameterSelect.h"
#include "ChipIdentify.h"

#define MBUFFER 1024

int isQDART=0;

/*
static void _signal_handler(int signum)  
{  
    void *array[10];  
    size_t size;  
    char **strings;  
    size_t i;  
  
    signal(signum, SIG_DFL); // 还原默认的信号处理handler 
  
    size = backtrace (array, 10);  
    strings = (char **)backtrace_symbols (array, size);  
  
    fprintf(stderr, "widebright received SIGSEGV! Stack trace:\n");  
    for (i = 0; i < size; i++) {  
        fprintf(stderr, "%d %s \n",i,strings[i]);  
    }  
      
    free (strings);  
    exit(1);  
} 
*/

int main(int narg, char *arg[]) 
{
//	signal(SIGPIPE, _signal_handler);    // SIGPIPE，管道破裂。
//	signal(SIGSEGV, _signal_handler);    // SIGSEGV，非法内存访问
//	signal(SIGFPE, _signal_handler);     // SIGFPE，数学相关的异常，如被0除，浮点溢出，等等
//	signal(SIGABRT, _signal_handler);    // SIGABRT，由调用abort函数产生，进程非正常退出

	int iarg;
	int console;
    int instance=0;
    extern int setPcie(int Pcie);
#ifdef LINUX
    int pcie=0;
#endif
    int port;
	char startfile[MBUFFER];
    //
	// temporarily turn on console output while we parse the command line arguments
	//
	UserPrintConsole(1);
	//
	// Initialize system default to non-Qdart mode
	SetQdartMode(0);
	//
	// process command line options
	//
	SformatOutput(startfile,MBUFFER-1,"%s","nart.art");
	startfile[MBUFFER-1]=0;
    console=0;
    port = -1;
	for(iarg=1; iarg<narg; iarg++)
	{
        if(Smatch(arg[iarg],"-port"))
        {
            if(iarg+1<narg)
            {
                SformatInput(arg[iarg+1]," %d ",&port);
                iarg++;
            }
        }
        else if(Smatch(arg[iarg],"-console"))
		{
			console=1;
		}
		else if(Smatch(arg[iarg],"-instance"))
		{
			if(iarg<narg-1)
			{
				iarg++;
				SformatInput(arg[iarg]," %d ",&instance); 
			}
			else
			{
				ErrorPrint(ParseBadValue,"NULL","-instance");
			}
		}
#ifdef LINUX
		else if(Smatch(arg[iarg],"-pcie"))
		{
			if(iarg<narg-1)
			{
				iarg++;
				SformatInput(arg[iarg]," %d ",&pcie); 
			}
			else
			{
				ErrorPrint(ParseBadValue,"NULL","-pcie");
			}

                        setPcie(pcie);
		}
#endif
		else if(Smatch(arg[iarg],"-start"))
		{
			if(iarg<narg-1)
			{
				iarg++;
				SformatOutput(startfile,MBUFFER-1,"%s",arg[iarg]);
				startfile[MBUFFER-1]=0;
			}
			else
			{
				ErrorPrint(ParseBadValue,"NULL","-start");
			}
		}
		else if(Smatch(arg[iarg],"-log"))
		{            
			if(iarg<narg-1)
			{
				iarg++;
                                UserPrintFile(arg[iarg]);                
			}
			else
			{
				ErrorPrint(ParseBadValue,"NULL","-log");
			}
		}
		else if(Smatch(arg[iarg],"-help"))
		{
			ErrorPrint(ParseHelp,"-console");
			ErrorPrint(ParseHelp,"-log [log file name]");
			ErrorPrint(ParseHelp,"-port [port number]");
			ErrorPrint(ParseHelp,"-instance [device index]");
			ErrorPrint(ParseHelp,"-start [startup command file]");
			exit(0);
		}
		else if(Smatch(arg[iarg],"-qdart"))
		{
			// User select to run system in Qdart mode
			SetQdartMode(1);
		}
		else
		{
			ErrorPrint(ParseBadParameter,arg[iarg]);
		}
	}

	UserPrintConsole(console);
    if(instance == 0)
	{
		if(port<0)
		{
			port=2390;
		} 
	}
    else if(instance == 1)
	{
		if(port<0)
		{
#ifndef __APPLE__	
			port=2391;
#else
			port=2390;
#endif			
		}
    }
	else if(instance == 2)
	{
		if(port<0)
		{
#ifndef __APPLE__	
			port=2392;
#else
			port=2390;
#endif			
		}
    }
    else
    {
#ifndef __APPLE__	
        printf("Only instance 0, 1 and 2 are supported\n");
		exit(1);
#else
		if(port<0)
		{
			port=2390;
		} 	
#endif	
    }
    NewArt(instance,port,startfile);
	exit(0);
}


void SetQdartMode(int isQdart)
{	
	isQDART=isQdart;	
}

int GetQdartMode(void) 
{ 
	return isQDART;
}
