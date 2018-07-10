#
# Copyright (C) 2008 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/kernel.mk


PKG_NAME:=qca-art_lsdk
PKG_RELEASE:=XAG-qca-art_lsdk

include $(INCLUDE_DIR)/package.mk

define KernelPackage/qca-art_lsdk
  SUBMENU:=Other modules
  TITLE:=athreos art_ver_lsdk driver
  FILES:=$(PKG_BUILD_DIR)/modules/art.ko
  KCONFIG:=
  #AUTOLOAD:=$(call AutoProbe,art)
  DEPENDS:=
endef

define KernelPackage/qca-art_lsdk/description
 kernel modules to generate art2_lsdk events
endef

EXTRA_KCONFIG:= \
	CONFIG_QCA_ART_LSDK=m

EXTRA_CFLAGS:= -DAP83 -DWASP \
	$(patsubst CONFIG_%, -DCONFIG_%=1, $(patsubst %=m,%,$(filter %=m,$(EXTRA_KCONFIG)))) \
	$(patsubst CONFIG_%, -DCONFIG_%=1, $(patsubst %=y,%,$(filter %=y,$(EXTRA_KCONFIG)))) \

MAKE_OPTS:= \
	ARCH="$(LINUX_KARCH)" \
	CROSS_COMPILE="$(TARGET_CROSS)" \
	M="$(PKG_BUILD_DIR)/modules" \
	SUBDIRS="$(PKG_BUILD_DIR)" \
	EXTRA_CFLAGS="-I $(PKG_BUILD_DIR)/modules/include $(EXTRA_CFLAGS)" \
	$(EXTRA_KCONFIG)

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Build/Compile
	$(MAKE) DEBUG=0 -C "$(LINUX_DIR)" \
		$(MAKE_OPTS) \
		modules
endef

$(eval $(call KernelPackage,qca-art_lsdk))
