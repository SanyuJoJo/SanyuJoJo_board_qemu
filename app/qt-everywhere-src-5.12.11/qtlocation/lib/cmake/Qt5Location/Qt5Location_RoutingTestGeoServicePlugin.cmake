
add_library(Qt5::RoutingTestGeoServicePlugin MODULE IMPORTED)

_populate_Location_plugin_properties(RoutingTestGeoServicePlugin RELEASE "geoservices/libqtgeoservices_routingplugin.so")

list(APPEND Qt5Location_PLUGINS Qt5::RoutingTestGeoServicePlugin)
