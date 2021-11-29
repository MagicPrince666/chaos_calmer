#
# Copyright (C) 2015 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

define Profile/CBox0864
	NAME:=CBox0864
	PACKAGES:=\
		kmod-ledtrig-netdev \
  		mountd \
		uhttpd rpcd rpcd-mod-iwinfo \
		rpcd-mod-rpcsys cgi-io spi-tools \
		kmod-sdhci-mt7620 kmod-fs-vfat kmod-fs-exfat kmod-fs-ext4 block-mount e2fsprogs \
		reg
endef

define Profile/CBox0864/Description
	widora 8MB flash/64MB ram base packages.
endef
$(eval $(call Profile,CBox0864))
