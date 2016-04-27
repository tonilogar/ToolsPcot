#ifndef CHECKTRANSITION_H
#define CHECKTRANSITION_H

#include "widgetregistrotp_global.h"

#include <QObject>
#include <QEvent>
#include <QAbstractTransition>
#include <QCheckBox>

struct CheckEvent : public QEvent
  {
      CheckEvent(const Qt::CheckState &val)
      : QEvent(QEvent::Type(QEvent::User+1)),
        value(val) {}

      Qt::CheckState value;
  };


class WIDGETREGISTROTPSHARED_EXPORT CheckTransition : public QAbstractTransition
  {
      Q_OBJECT

  public:
      CheckTransition(const Qt::CheckState &value)
          : m_value(value) {}

  protected:
      virtual bool eventTest(QEvent *e)
      {
          if (e->type() != QEvent::Type(QEvent::User+1)) // StringEvent
              return false;
          CheckEvent *se = static_cast<CheckEvent*>(e);
          return (m_value == se->value);
      }

      virtual void onTransition(QEvent *) {}

  private:
      Qt::CheckState m_value;
  };


#endif // CHECKTRANSITION_H
