include $(TOPDIR)/rules.mk

PKG_NAME:=nart_lsdk_10_2_8
PKG_VERSION:=XAG-huangliquan-1.0
PKG_BUILD_DIR:= $(BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/package.mk

define Package/$(PKG_NAME)
	SECTION:=base
	CATEGORY:=Utilities
	TITLE:=nart ver lsdk 10.2.8
	SUBMENU:=XAG
	DEPENDS:= +libpthread +librt
endef

define Package/$(PKG_NAME)/description
	art firmware
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Package/$(PKG_NAME)/install
	$(INSTALL_DIR) $(1)/usr/bin $(1)/usr/lib
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/nartbuild/nart.out $(1)/usr/bin/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/nartbuild/*.so $(1)/usr/lib/
endef

$(eval $(call BuildPackage,nart_lsdk_10_2_8))