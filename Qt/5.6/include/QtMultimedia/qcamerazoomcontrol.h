/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL21$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** As a special exception, The Qt Company gives you certain additional
** rights. These rights are described in The Qt Company LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QCAMERAZOOMCONTROL_H
#define QCAMERAZOOMCONTROL_H

#include <QtMultimedia/qmediacontrol.h>
#include <QtMultimedia/qmediaobject.h>

QT_BEGIN_NAMESPACE

// Required for QDoc workaround
class QString;

class Q_MULTIMEDIA_EXPORT QCameraZoomControl : public QMediaControl
{
    Q_OBJECT

public:
    ~QCameraZoomControl();

    virtual qreal maximumOpticalZoom() const = 0;
    virtual qreal maximumDigitalZoom() const = 0;

    virtual qreal requestedOpticalZoom() const = 0;
    virtual qreal requestedDigitalZoom() const = 0;
    virtual qreal currentOpticalZoom() const = 0;
    virtual qreal currentDigitalZoom() const = 0;

    virtual void zoomTo(qreal optical, qreal digital) = 0;

Q_SIGNALS:
    void maximumOpticalZoomChanged(qreal);
    void maximumDigitalZoomChanged(qreal);

    void requestedOpticalZoomChanged(qreal opticalZoom);
    void requestedDigitalZoomChanged(qreal digitalZoom);
    void currentOpticalZoomChanged(qreal opticalZoom);
    void currentDigitalZoomChanged(qreal digitalZoom);

protected:
    explicit QCameraZoomControl(QObject *parent = Q_NULLPTR);
};

#define QCameraZoomControl_iid "org.qt-project.qt.camerazoomcontrol/5.0"
Q_MEDIA_DECLARE_CONTROL(QCameraZoomControl, QCameraZoomControl_iid)

QT_END_NAMESPACE

#endif  // QCAMERAZOOMCONTROL_H