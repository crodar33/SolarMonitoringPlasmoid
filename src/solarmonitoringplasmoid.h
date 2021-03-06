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

signals:
    void dataUpdate(float gridP, float loadP, float panelsP, float batteryP, float batteryC);
public slots:
        void cppSlot();
public:
    SolarMonitoringPlasmoid( QObject *parent, const QVariantList &args );
    ~SolarMonitoringPlasmoid();

    void readPendingDatagrams();

private:
    QUdpSocket* udpSocket;
};

#endif
