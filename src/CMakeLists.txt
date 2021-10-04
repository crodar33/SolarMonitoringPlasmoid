# TODO: adapt "org.kde.plasma" here & elsewhere if needed (see README)
add_definitions(-DTRANSLATION_DOMAIN=\"plasma_applet_org.kde.plasma.solarmonitoringplasmoid\")

set(solarmonitoringplasmoid_SRCS
    solarmonitoringplasmoid.cpp
)

add_library(plasma_applet_solarmonitoringplasmoid MODULE ${solarmonitoringplasmoid_SRCS})

kcoreaddons_desktop_to_json(plasma_applet_solarmonitoringplasmoid package/metadata.desktop SERVICE_TYPES plasma-applet.desktop)

target_link_libraries(plasma_applet_solarmonitoringplasmoid
                      Qt5::Gui
                      Qt5::Network
                      KF5::Plasma
                      KF5::I18n)


install(TARGETS plasma_applet_solarmonitoringplasmoid DESTINATION ${KDE_INSTALL_PLUGINDIR}/plasma/applets)

plasma_install_package(package org.kde.plasma.solarmonitoringplasmoid)
