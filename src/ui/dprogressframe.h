#ifndef DPROGRESSFRAME_H
#define DPROGRESSFRAME_H

#include <QStackedWidget>

class DRoteMovie;
class QLabel;
class DPushButton;
class DTips;
class DUsbList;
class DSerialFrameMovie;
class QParallelAnimationGroup;
class DDigitProgressMovie;
class QVBoxLayout;
class QMovie;
class DUsbProgressMovie;

class DProgressFrame : public QStackedWidget
{
    Q_OBJECT
public:
    explicit DProgressFrame(QWidget *parent = 0);

    QString isoFile() const;
    void setIsoFile(const QString &isoFile);

    QString usbDev() const;
    void setUsbDev(const QString &usbDev);

    void setProgress(int p);
signals:
    void isoFileSelected(const QString&);
    void changedUsbSeclet();
    void changedProgress();

public slots:
    void toggleShadow();
    void switchShowStatus();

    void slideUsbSeclect();
    void slideProcess();

    void usbDevSelected(const QString&);
    void finishSelectDev(const QString&);

    void switchProgress();

protected slots:
    void slideUsbDone();
    void slideProgressDone();

    void selectISO();
    void refreshUsbDrivers(const QStringList&);


protected:
    enum ShowStatus{
        ShowFirst,
        ShowSecond,
    };

    bool                    m_Active;
    int                     m_Speed;

    ShowStatus              m_ShowStatus;
    QWidget                 *m_TopShadow;
    QWidget                 *m_FirstWidget;
    QWidget                 *m_SecondWidget;
    QVBoxLayout             *m_FirstLayout;
    QLabel                  *m_ProcessLabel;
    //DDigitProgressAnimation *m_processLabel;
    DUsbProgressMovie       *m_ProcessUsb;
    DSerialFrameMovie       *m_IsoLabel;
    DSerialFrameMovie       *m_UsbLabel;
    QParallelAnimationGroup *m_AnimGroup;
    DUsbList                *m_UsbList;
    QString                 m_IsoFile;
    QString                 m_UsbDev;


public slots:

};

#endif // DPROGRESSFRAME_H