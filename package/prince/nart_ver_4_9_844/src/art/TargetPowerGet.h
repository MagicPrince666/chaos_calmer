#ifndef _TARGETPOWERGET_H_
#define _TARGETPOWERGET_H_
//
// interpolates into the stored data structure and returns the value that will be used
//
extern void TargetPowerGetCommand(int client);

extern void TargetPowerParameterSplice(struct _ParameterList *list);

//
// interpolates into the stored data structure and returns the value that will be used
//
extern void NoiseFloorGetCommand(int client);

extern void NoiseFloorGetParameterSplice(struct _ParameterList *list);

#endif
