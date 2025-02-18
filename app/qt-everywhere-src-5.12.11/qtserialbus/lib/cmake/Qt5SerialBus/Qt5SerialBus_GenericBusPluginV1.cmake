
add_library(Qt5::GenericBusPluginV1 MODULE IMPORTED)

_populate_SerialBus_plugin_properties(GenericBusPluginV1 RELEASE "canbus/libqtcanbustestgenericv1.so")

list(APPEND Qt5SerialBus_PLUGINS Qt5::GenericBusPluginV1)
