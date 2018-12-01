#!/bin/sh

rmmod ath9k
rmmod ath9k_common
rmmod ath9k_hw

insmod art.ko

mknod /dev/dk0 c 63 0
mknod /dev/dk1 c 63 1

ln -s /dev/mtdblock5 /dev/caldata

sleep 1

./nart.out -console -instance 0&
./nart.out -console -instance 1&
