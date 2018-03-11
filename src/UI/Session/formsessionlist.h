#ifndef FORMSESSIONLIST_H
#define FORMSESSIONLIST_H

#include <QWidget>
#include "Model/sessionmodel.h"

namespace Ui {
class FormSessionList;
}

class FormSessionList : public QWidget
{
    Q_OBJECT

public:
    explicit FormSessionList(QWidget *parent = 0);
    ~FormSessionList();

    void updateListSessions(const QList<Session *> &sessions);
    Session *getSessionInfo(const QString &id);

private:
    Ui::FormSessionList *ui;

    SessionModel m_model;

    void refreshUi();
};

#endif // FORMSESSIONLIST_H
