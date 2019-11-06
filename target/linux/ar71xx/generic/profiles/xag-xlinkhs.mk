
define Profile/XAG9342
	NAME:=XAG XLinkHS
	PACKAGES:=kmod-usb-core kmod-usb2 kmod-usb-acm \
	arptables kmod-ath-hs-uart kmod-usb-net kmod-usb-net-asix \
	luci kmod-usb-net-rtl8152 kmod-usb-net-rndis atftp libstdcpp
endef

define Profile/XAG9342/Description
	Package set optimized for the XAG XLinkHS board.
endef

$(eval $(call Profile,XAG9342))