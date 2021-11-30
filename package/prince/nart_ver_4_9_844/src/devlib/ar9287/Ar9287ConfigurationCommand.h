#ifndef _AR9287CONFIGURATIONCOMMAND_H_
#define _AR9287CONFIGURATIONCOMMAND_H_

#include "ParameterSelect.h"
extern AR9287DLLSPEC int Ar9287GetParameterSplice(struct _ParameterList *list);
extern AR9287DLLSPEC int Ar9287SetParameterSplice(struct _ParameterList *list);
extern AR9287DLLSPEC int Ar9287SetCommand(int client);
extern AR9287DLLSPEC int Ar9287GetCommand(int client);

#endif
