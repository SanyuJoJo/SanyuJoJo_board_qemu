
add_library(Qt5::MockServicePlugin2 MODULE IMPORTED)

_populate_Multimedia_plugin_properties(MockServicePlugin2 RELEASE "mediaservice/libmockserviceplugin2.so")

list(APPEND Qt5Multimedia_PLUGINS Qt5::MockServicePlugin2)
