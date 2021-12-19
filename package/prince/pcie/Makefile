include $(TOPDIR)/rules.mk

PKG_NAME:=pcie_user_space
PKG_VERSION:=huangliquan-1.0
PKG_BUILD_DIR:= $(BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/package.mk

define Package/$(PKG_NAME)
	SECTION:=base
	CATEGORY:=Utilities
	TITLE:=pcie user space read and write
	SUBMENU:=Prince
	DEPENDS:=+libstdcpp +libpciaccess +libkmod +zlib +pciutils
endef

define Package/$(PKG_NAME)/description
	pcie user space read and write
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Package/$(PKG_NAME)/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/pcie_user $(1)/usr/bin/
endef

$(eval $(call BuildPackage,$(PKG_NAME)))
