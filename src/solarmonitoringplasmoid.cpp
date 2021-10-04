/*
    SPDX-FileCopyrightText: 2021 Danil mcrodar@gmail.com
    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#include "solarmonitoringplasmoid.h"
#include <KLocalizedString>

SolarMonitoringPlasmoid::SolarMonitoringPlasmoid(QObject *parent, const QVariantList &args)
    : Plasma::Applet(parent, args),
      m_nativeText(i18n("Text coming from C++ plugin"))
{
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress::Any, 7798);
    connect(udpSocket, &QUdpSocket::readyRead,
            this, &SolarMonitoringPlasmoid::readPendingDatagrams);
}

SolarMonitoringPlasmoid::~SolarMonitoringPlasmoid()
{
    udpSocket->close();
}

QString SolarMonitoringPlasmoid::nativeText() const
{
    return m_nativeText;
}

void SolarMonitoringPlasmoid::readPendingDatagrams()
{
    while (udpSocket->hasPendingDatagrams()) {
        QNetworkDatagram datagram = udpSocket->receiveDatagram();
        //processTheDatagram(datagram);
    }
}

K_EXPORT_PLASMA_APPLET_WITH_JSON(solarmonitoringplasmoid, SolarMonitoringPlasmoid, "metadata.json")

#include "solarmonitoringplasmoid.moc"
