# Adiciona o nome do produto no lunch
COMMON_LUNCH_CHOICES := \
    devtitans_plantio-eng

# Arquivo de configuração principal do produto
PRODUCT_MAKEFILES := \
    $(LOCAL_DIR)/devtitans_plantio.mk

PRODUCT_SYSTEM_PROPERTIES += \
    ro.devtitans.name=Plant.io

PRODUCT_PRODUCT_PROPERTIES += \
    ro.product.devtitans.version=0.1.0

PRODUCT_VENDOR_PROPERTIES += \
    ro.vendor.devtitans.hardware=ModelB
