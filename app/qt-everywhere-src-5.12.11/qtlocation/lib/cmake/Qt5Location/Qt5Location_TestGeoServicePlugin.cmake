
add_library(Qt5::TestGeoServicePlugin MODULE IMPORTED)

_populate_Location_plugin_properties(TestGeoServicePlugin RELEASE "geoservices/libqtgeoservices_qmltestplugin.so")

list(APPEND Qt5Location_PLUGINS Qt5::TestGeoServicePlugin)
