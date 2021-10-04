/*
    SPDX-FileCopyrightText: %{CURRENT_YEAR} %{AUTHOR} <%{EMAIL}>
    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#include "solarmonitoringplasmoiddd.h"
#include <KLocalizedString>

SolarMonitoringPlasmoidDD::SolarMonitoringPlasmoidDD(QObject *parent, const QVariantList &args)
    : Plasma::Applet(parent, args),
      m_nativeText(i18n("Text coming from C++ plugin"))
{
}

SolarMonitoringPlasmoidDD::~SolarMonitoringPlasmoidDD()
{
}

QString SolarMonitoringPlasmoidDD::nativeText() const
{
    return m_nativeText;
}

K_EXPORT_PLASMA_APPLET_WITH_JSON(solarmonitoringplasmoiddd, SolarMonitoringPlasmoidDD, "metadata.json")

#include "solarmonitoringplasmoiddd.moc"
