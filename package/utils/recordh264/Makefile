include $(TOPDIR)/rules.mk

PKG_NAME:=h264_rec
PKG_VERSION:=1.0
PKG_BUILD_DIR:= $(BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/package.mk

define Package/h264_rec
	SECTION:=base
	CATEGORY:=Utilities
	TITLE:=record uvc h264 video
	DEPENDS:= +librt +libm +libdl
endef

define Package/h264_rec/description
	If you can't figure out what this program does, you're probably
	brain-dead and need immediate medical attention.
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Package/h264_rec/install
	$(INSTALL_DIR) $(1)/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/h264_rec $(1)/bin/
endef

$(eval $(call BuildPackage,h264_rec))
 