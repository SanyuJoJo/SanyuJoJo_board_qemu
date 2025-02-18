
add_library(Qt5::MockServicePlugin1 MODULE IMPORTED)

_populate_Multimedia_plugin_properties(MockServicePlugin1 RELEASE "mediaservice/libmockserviceplugin1.so")

list(APPEND Qt5Multimedia_PLUGINS Qt5::MockServicePlugin1)
