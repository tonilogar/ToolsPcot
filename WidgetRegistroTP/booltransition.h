#ifndef BOOLTRANSITION_H
#define BOOLTRANSITION_H

#include "widgetregistrotp_global.h"

#include <QObject>
#include <QEvent>
#include <QAbstractTransition>

struct BoolEvent : public QEvent
  {
      BoolEvent(const bool &val)
      : QEvent(QEvent::Type(QEvent::User+1)),
        value(val) {}

      bool value;
  };


class WIDGETREGISTROTPSHARED_EXPORT BoolTransition : public QAbstractTransition
  {
      Q_OBJECT

  public:
      BoolTransition(const bool &value)
          : m_value(value) {}

  protected:
      virtual bool eventTest(QEvent *e)
      {
          if (e->type() != QEvent::Type(QEvent::User+1)) // StringEvent
              return false;
          BoolEvent *se = static_cast<BoolEvent*>(e);
          return (m_value == se->value);
      }

      virtual void onTransition(QEvent *) {}

  private:
      bool m_value;
  };


#endif // BOOLTRANSITION_H
