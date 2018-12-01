include $(TOPDIR)/rules.mk

PKG_NAME:=uart_test
PKG_VERSION:=XAG-huangliquan-1.0
PKG_BUILD_DIR:= $(BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/package.mk

define Package/uart_test
	SECTION:=base
	CATEGORY:=Utilities
	TITLE:=uart firmware
	DEPENDS:= +libpthread +libstdcpp
endef

define Package/uart_test/description
	uart firmware 
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Package/uart_test/install
	$(INSTALL_DIR) $(1)/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/uart_hs $(1)/bin/
endef

$(eval $(call BuildPackage,uart_test))