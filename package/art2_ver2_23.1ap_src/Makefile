include $(TOPDIR)/rules.mk

PKG_NAME:=nart_firmwave
PKG_VERSION:=XAG-huangliquan-1.0
PKG_BUILD_DIR:= $(BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/package.mk

define Package/nart_firmwave
	SECTION:=base
	CATEGORY:=Utilities
	TITLE:=nart firmwave
	DEPENDS:= +libm
endef

define Package/nart_firmwave/description
	nart.out build art firmwave
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Package/nart_firmwave/install
	$(INSTALL_DIR) $(1)/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/art/obj/nart.out $(1)/bin/
endef

$(eval $(call BuildPackage,nart_firmwave))