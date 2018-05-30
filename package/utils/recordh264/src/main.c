/*****************************************************************************************

 * 文件名  main.cpp
 * 描述    ：多线程控制
 * 平台    ：linux
 * 版本    ：V1.0.0
 * 作者    ：Leo Huang  QQ：846863428
 * 邮箱    ：Leo.huang@junchentech.cn
 * 修改时间  ：2017-06-28

*****************************************************************************************/

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <assert.h> 
#include <signal.h>

#include "H264_UVC_TestAP.h"



static void sigint_handler(int sig)
{
    capturing = 0;//停止视频
    printf("-----@@@@@ sigint_handler  is over !\n");
    
}


int main (int argc, char **argv) 
{ 
    signal(SIGINT, sigint_handler);//信号处理

    Init_264camera();

	cap_video();
    
    return 0; 
}

