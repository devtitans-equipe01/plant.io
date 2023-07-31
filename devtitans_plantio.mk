# Herda as configurações do emulador (produto sdk_phone_x86_64)
$(call inherit-product, $(SRC_TARGET_DIR)/product/sdk_phone_x86_64.mk)

# Sobrescreve algumas variáveis com os dados do novo produto
PRODUCT_NAME := devtitans_plantio
PRODUCT_DEVICE := plantio
PRODUCT_BRAND := PlantioBrand
PRODUCT_MODEL := PlantioModel

PRODUCT_PACKAGES +=  \
    plantio_client

BOARD_SEPOLICY_DIRS += device/devtitans/plantio/sepolicy

PRODUCT_SYSTEM_PROPERTIES += \
    ro.devtitans.name=Plantio

PRODUCT_PRODUCT_PROPERTIES += \
    ro.product.devtitans.version=1.0

PRODUCT_VENDOR_PROPERTIES += \
    ro.vendor.devtitans.hardware=ModelB

# Plantio AIDL Interface
PRODUCT_PACKAGES += devtitans.plantio

# Plantio Binder Service
PRODUCT_PACKAGES += devtitans.plantio-service

# Device Framework Matrix (Declara que o nosso produto Plantio precisa do serviço plantio)
DEVICE_FRAMEWORK_COMPATIBILITY_MATRIX_FILE := device/devtitans/plantio/device_framework_matrix.xml

PRODUCT_PACKAGES += plantio_service_client

