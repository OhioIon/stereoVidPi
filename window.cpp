/****************** Includes ********************/

#include "window.h"
#include <QApplication>
#include <QCameraInfo>

/**************** Implementation ****************/

// Create window that shows stereo video signals from two frame-grabbers connected
window::window(QWidget *parent) : QWidget(parent)
{
  // Window has 2x PAL resolution next to each other
  resize( 720 * 2, 576 );

  // Check if enough cameras are connected
  const QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
  if( cameras.count() < 2 )
  {
    errLabel_p = new QLabel(this);
    errLabel_p->setText("Error: Not enough cameras found");
    return;
  }

  // Create left eye view and camera
  viewLeft_p = new QCameraViewfinder(this);
  camLeft_p = new QCamera(cameras[0], this);
  camLeft_p->setViewfinder(viewLeft_p);
  camLeft_p->start();

  // Create right eye view and camera
  viewRight_p = new QCameraViewfinder(this);
  camRight_p = new QCamera(cameras[1], this);
  camRight_p->setViewfinder(viewRight_p);
  camRight_p->start();

  // Handle layout
  layout_p = new QHBoxLayout();
  layout_p->addWidget(viewLeft_p);
  layout_p->addWidget(viewRight_p);
  layout_p->setSpacing(0);
  layout_p->setMargin(0);
  this->setLayout(layout_p);

  // Install keyboard event filter
  key_p = new keyReceiver();
  installEventFilter(key_p);

  // Connect signals to slots
  connect(key_p, SIGNAL(event_Esc()), QApplication::instance(), SLOT(quit()) );
  connect(key_p, SIGNAL(event_S()), this, SLOT(switchLeftRight()) );
  connect(key_p, SIGNAL(event_F()), this, SLOT(stopFullScreen()) );
}

// Switch left and right viewfinder
void window::switchLeftRight( void )
{
  if( layout_p->direction() == QBoxLayout::LeftToRight )
  {
    layout_p->setDirection( QBoxLayout::RightToLeft );
  }
  else
  {
    layout_p->setDirection( QBoxLayout::LeftToRight );
  }
}

// Stop full screen mode and move screen to monitor 1
void window::stopFullScreen( void )
{
  // Exit full screen mode
  close();

  // Open normal window mode (screen 1)
  show();
  resize( 720 * 2, 576);
  move( 100, 100 );
}

// EOF
