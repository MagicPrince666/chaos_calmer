#
# Copyright (C) 2008 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/kernel.mk


PKG_NAME:=qca-art2_4_9
PKG_RELEASE:=XAG-qca-art2_4_9

include $(INCLUDE_DIR)/package.mk

define KernelPackage/qca-art2_4_9
  #SUBMENU:=Other modules
  SUBMENU:=XAG_KERNELMODULES
  TITLE:=athreos art driver
  FILES:=$(PKG_BUILD_DIR)/modules/art.ko
  KCONFIG:=
  #AUTOLOAD:=$(call AutoProbe,art)
  DEPENDS:=
endef

define KernelPackage/qca-art2_4_9/description
 kernel modules to generate art events
endef

EXTRA_KCONFIG:= \
	CONFIG_QCA_ART_4_49_844=m

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
	$(MAKE) -C "$(LINUX_DIR)" \
		$(MAKE_OPTS) \
		modules
endef

$(eval $(call KernelPackage,qca-art2_4_9))
