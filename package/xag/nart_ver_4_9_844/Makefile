include $(TOPDIR)/rules.mk

PKG_NAME:=nart_4_9_844
PKG_VERSION:=XAG-huangliquan-1.0
PKG_BUILD_DIR:= $(BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/package.mk

define Package/$(PKG_NAME)
	SECTION:=base
	CATEGORY:=Utilities
	TITLE:=nart ver 4.9.844
	SUBMENU:=XAG
	DEPENDS:= +libpthread +librt +kmod-qca-art2_4_9
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
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/nartbuild/nart.out $(PKG_BUILD_DIR)/art2.sh $(1)/usr/bin/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/nartbuild/*.so $(1)/usr/lib/
endef

$(eval $(call BuildPackage,nart_4_9_844))