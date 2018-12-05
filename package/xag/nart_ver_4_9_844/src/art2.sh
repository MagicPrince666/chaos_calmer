#!/bin/sh


usage_print()
{
    echo "Start art usage: art2"
    exit 1
}

rmmod_art()
{
    test=1                                                                      

    mod_installed="`lsmod | grep art`"


    if [ ! -n "${mod_installed}"  ]; then                                                
    	return                         
    fi                                     

    for i in `ps | grep nart | awk '{print $1}'`                                 
    do                                                                          
	if [ $$ = $i ]; then
        	break                                  
        fi                                     

        kill $i                                                                 
    done      

    for i in `ps | grep ART2 | awk '{print $1}'`                                 
    do                                                                          
	if [ $$ = $i ]; then
        	break                                  
        fi                                     

        kill $i                                                                 
    done      

    rmmod art
}

start_art()
{
    #/etc/rc.d/rc.tools up >/dev/null 2>&1

    #ifconfig br-lan 192.168.1.2
    #export LD_LIBRARY_PATH=/root/nartbuild:$LD_LIBRARY_PATH

    #insmod /root/nartbuild/art.ko
    insmod /lib/modules/'uname -r'/art.ko
    #insmod /lib/modules/2.6.31/net/art-dragonfly-pci.ko

    if [ ! -e /dev/dk0 ]; then
        mknod /dev/dk0 c 63 0
    fi

    if [ ! -e /dev/dk1 ]; then
        mknod /dev/dk1 c 63 1
    fi

    nart.out -console -port 2390 -instance 0 &
    nart.out -console -port 2391 -instance 1 &

    ln -s /dev/mtdblock5 /dev/caldata
}


if [ $# != 0 ]; then 
    usage_print
else
    rmmod_art
    start_art
    #echo $start_art
    #echo ${start_art} | awk '{run=$0; system(run)}'
fi

exit 0
