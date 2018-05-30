include $(TOPDIR)/rules.mk

PKG_NAME:=mjpg_rec
PKG_VERSION:=1.0
PKG_BUILD_DIR:= $(BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/package.mk

define Package/mjpg_rec
	SECTION:=base
	CATEGORY:=Utilities
	TITLE:=record uvc mjpg video
	DEPENDS:= +librt +libm +libdl +libstdcpp
endef

define Package/mjpg_rec/description
	record mjpg video and save as avi file
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Package/mjpg_rec/install
	$(INSTALL_DIR) $(1)/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/mjpg_rec $(1)/bin/
endef

$(eval $(call BuildPackage,mjpg_rec))