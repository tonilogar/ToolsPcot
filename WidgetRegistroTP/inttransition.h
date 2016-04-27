#ifndef INTTRANSITION_H
#define INTTRANSITION_H

#include <QObject>

#include "widgetregistrotp_global.h"

#include <QObject>
#include <QEvent>
#include <QAbstractTransition>

struct IntEvent : public QEvent
  {
      IntEvent(const int &val)
      : QEvent(QEvent::Type(QEvent::User+1)),
        value(val) {}

      int value;
  };


class WIDGETREGISTROTPSHARED_EXPORT IntTransition : public QAbstractTransition
  {
      Q_OBJECT

  public:
      IntTransition(const int &value)
          : m_value(value) {}

  protected:
      virtual bool eventTest(QEvent *e)
      {
          if (e->type() != QEvent::Type(QEvent::User+1)) // StringEvent
              return false;
          IntEvent *se = static_cast<IntEvent*>(e);
          return (m_value == se->value);
      }

      virtual void onTransition(QEvent *) {}

  private:
      int m_value;
  };

#endif // INTTRANSITION_H
