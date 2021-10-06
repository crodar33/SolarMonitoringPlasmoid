/*
    SPDX-FileCopyrightText: 2021 Danil mcrodar@gmail.com
    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#include "solarmonitoringplasmoid.h"
#include <KLocalizedString>
#include <QDebug>

SolarMonitoringPlasmoid::SolarMonitoringPlasmoid(QObject *parent, const QVariantList &args)
    : Plasma::Applet(parent, args)
{
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress::Any, 7798);
    connect(udpSocket, &QUdpSocket::readyRead,
            this, &SolarMonitoringPlasmoid::readPendingDatagrams);
}

SolarMonitoringPlasmoid::~SolarMonitoringPlasmoid() {
    udpSocket->close();
}

void SolarMonitoringPlasmoid::readPendingDatagrams() {
    while (udpSocket->hasPendingDatagrams()) {
        QNetworkDatagram datagram = udpSocket->receiveDatagram();
        auto data = datagram.data();
        qDebug() << "data len: " << data.length();
        if (data.length() == (3 + 5 * 4)) {
            const char* c = data.constData();
            float gridP = *((float*) (c+3));
            float loadP = *((float*) (c+7));
            float panelsP = *((float*) (c+11));
            float batteryP = *((float*) (c+15));
            float batteryC = *((float*) (c+19));
            emit dataUpdate(gridP, loadP, panelsP, batteryP, batteryC);
        }
    }
}

void SolarMonitoringPlasmoid::cppSlot() {
    emit dataUpdate(11, 12, 22, 33, 44);
}

K_EXPORT_PLASMA_APPLET_WITH_JSON(solarmonitoringplasmoid, SolarMonitoringPlasmoid, "metadata.json")

#include "solarmonitoringplasmoid.moc"
