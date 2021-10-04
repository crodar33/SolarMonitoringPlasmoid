/*
    SPDX-FileCopyrightText: %{CURRENT_YEAR} %{AUTHOR} <%{EMAIL}>
    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef SOLARMONITORINGPLASMOIDDD_H
#define SOLARMONITORINGPLASMOIDDD_H


#include <Plasma/Applet>

class SolarMonitoringPlasmoidDD : public Plasma::Applet
{
    Q_OBJECT
    Q_PROPERTY(QString nativeText READ nativeText CONSTANT)

public:
    SolarMonitoringPlasmoidDD( QObject *parent, const QVariantList &args );
    ~SolarMonitoringPlasmoidDD();

    QString nativeText() const;

private:
    QString m_nativeText;
};

#endif
