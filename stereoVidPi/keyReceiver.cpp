/****************** Includes ********************/

#include "keyReceiver.h"
#include <QEvent>
#include <QKeyEvent>

/**************** Implementation ****************/

// Handle key-pressed events
bool keyReceiver::eventFilter(QObject* obj, QEvent* event)
{
  // Check for KeyPress event
  if (event->type()==QEvent::KeyPress)
  {
    QKeyEvent* key = static_cast<QKeyEvent*>(event);
    switch( key->key() )
    {
      case Qt::Key_F     : emit event_F()  ; break;
      case Qt::Key_S     : emit event_S()  ; break;
      case Qt::Key_Escape: emit event_Esc(); break;

      default:
        // No key handeled here
        return QObject::eventFilter(obj, event);
    }
    return true;
  }
  else
  {
    // No KeyPress event
    return QObject::eventFilter(obj, event);
  }
}

// EOF
