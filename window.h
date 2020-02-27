#ifndef WINDOW_H
#define WINDOW_H

/****************** Includes ********************/

#include <QWidget>
#include <QCamera>
#include <QCameraViewfinder>
#include <QLabel>
#include <QLayout>

#include "keyReceiver.h"

/******************** Class *********************/

class window : public QWidget
{
  Q_OBJECT

public:
    explicit window(QWidget *parent = nullptr); // Constructor

private:
    QCamera *camLeft_p;             // Left eye camera
    QCamera *camRight_p;            // Right eye camera
    QCameraViewfinder *viewLeft_p;  // Left eye widget
    QCameraViewfinder *viewRight_p; // Right eye widget
    QHBoxLayout *layout_p;          // Window layout
    QRect *screenRes_p;             // Screen resolution (2nd screen)

    keyReceiver *key_p;             // Keyboard event receiver
    QLabel *errLabel_p;             // Label for error message

signals:

public slots:
    void switchLeftRight( void );
    void stopFullScreen( void );

};

#endif // WINDOW_H
