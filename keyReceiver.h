#ifndef KEYRECEIVER_H
#define KEYRECEIVER_H

/****************** Includes ********************/

#include <QObject>

/******************** Class *********************/

class keyReceiver : public QObject
{
  Q_OBJECT

protected:
  bool eventFilter(QObject* obj, QEvent* event);

signals:
  void event_F  ( void ); // F key pressed
  void event_S  ( void ); // S key pressed
  void event_Esc( void ); // Escape key pressed

};

#endif // KEYRECEIVER_H
