/****************** Includes ********************/

#include <QApplication>
#include <QScreen>

#include "window.h"

/**************** Implementation ****************/

int main(int argc, char **argv)
{
  QApplication app( argc, argv );
  const QList<QScreen*> screenList = QGuiApplication::screens();
  const QScreen *cv1Screen_p = nullptr;

  // Create main window
  window win;

  // Check if one screen is Oculus Rift CV1 resolution
  for( const QScreen *screen : screenList )
  {
    if( (screen->size().width() == 2160) && (screen->size().height() == 1200) )
    {
      cv1Screen_p = screen;
      break;
    }
  }

  // If Oculus Rift CV1 exists
  if( cv1Screen_p != nullptr )
  {
    // Show fullscreen on Rift
    win.move( cv1Screen_p->geometry().x(), cv1Screen_p->geometry().y() );
    win.resize( cv1Screen_p->geometry().width(), cv1Screen_p->geometry().height() );
    win.showFullScreen();
  }
  else
  {
    win.resize( 720 * 2, 576 );
    win.show();
  }

  // Execute event loop
  return app.exec();
}

// EOF
