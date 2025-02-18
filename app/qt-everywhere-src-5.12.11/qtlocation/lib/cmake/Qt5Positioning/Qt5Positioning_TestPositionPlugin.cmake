
add_library(Qt5::TestPositionPlugin MODULE IMPORTED)

_populate_Positioning_plugin_properties(TestPositionPlugin RELEASE "position/libqtposition_testplugin.so")

list(APPEND Qt5Positioning_PLUGINS Qt5::TestPositionPlugin)
