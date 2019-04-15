#ifndef _LINK_H_
#define _LINK_H_

extern void CarrierTransmit(int client);

extern void LinkReceive(int client);

extern void LinkTransmit(int client);

extern void LinkTransmitPAPD(int chainNum );

extern void LinkTransmitPAPDWarmUp(int txChainMask);
extern void ForceLinkReset();

extern void LinkParameterSplice(struct _ParameterList *list);

extern void RfBbTestPointParameterSplice(struct _ParameterList *list);
extern void RfBbTestPoint(int client);

#endif
