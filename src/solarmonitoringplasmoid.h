/*
    SPDX-FileCopyrightText: 2021 Danil mcrodar@gmail.com
    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef SOLARMONITORINGPLASMOID_H
#define SOLARMONITORINGPLASMOID_H


#include <Plasma/Applet>
#include <qt5/QtNetwork/QUdpSocket>
#include <qt5/QtNetwork/QNetworkDatagram>

class SolarMonitoringPlasmoid : public Plasma::Applet
{
    Q_OBJECT
    Q_PROPERTY(QString nativeText READ nativeText CONSTANT)

public:
    SolarMonitoringPlasmoid( QObject *parent, const QVariantList &args );
    ~SolarMonitoringPlasmoid();

    QString nativeText() const;
    void readPendingDatagrams();

private:
    QString m_nativeText;
    QUdpSocket* udpSocket;
};

#endif
