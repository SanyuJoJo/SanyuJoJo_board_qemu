
add_library(Qt5::GenericBusPlugin MODULE IMPORTED)

_populate_SerialBus_plugin_properties(GenericBusPlugin RELEASE "canbus/libqtcanbustestgeneric.so")

list(APPEND Qt5SerialBus_PLUGINS Qt5::GenericBusPlugin)
