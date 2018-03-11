#include "formsessionlist.h"
#include "ui_formsessionlist.h"

#include <QPushButton>

FormSessionList::FormSessionList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormSessionList)
{
    ui->setupUi(this);
}

FormSessionList::~FormSessionList()
{
    delete ui;
}

void FormSessionList::updateListSessions(const QList<Session *> &sessions)
{
    m_model.setListSessions(sessions);
    refreshUi();
}

Session *FormSessionList::getSessionInfo(const QString &id)
{
    return m_model.getSession(id);
}

void FormSessionList::refreshUi()
{
    ui->tableWidget->setRowCount(0);
    QList<Session *> sessions = m_model.getListSessions();
    for (int i = 0; i < sessions.size(); ++i) {
        ui->tableWidget->insertRow(i);

        Session *ss = sessions.at(i);
        QTableWidgetItem *itemIdx = new QTableWidgetItem;
        itemIdx->setText(QString::number(i+1));
        itemIdx->setData(Qt::UserRole, ss->id());
        ui->tableWidget->setItem(i, 0, itemIdx);

        QTableWidgetItem *itemName = new QTableWidgetItem;
        itemName->setText(ss->className());
        ui->tableWidget->setItem(i, 1, itemName);

        QTableWidgetItem *itemTime = new QTableWidgetItem;
        itemTime->setText(QString::number(ss->startTime()));
        ui->tableWidget->setItem(i, 2, itemTime);

        // continue with other attributes


        QTableWidgetItem *itemSize = new QTableWidgetItem;
        itemSize->setText(QString::number(ss->students().size()));
        ui->tableWidget->setItem(i, 6, itemSize);

        QPushButton *pbEdit = new QPushButton("Sửa");
        connect(pbEdit, &QPushButton::clicked, this, [this, ss]() {
//            emit sigEditStudent(ss->id());
        });
        ui->tableWidget->setCellWidget(i, 7, pbEdit);

        QPushButton *pbDel = new QPushButton("Xóa");
        connect(pbDel, &QPushButton::clicked, this, [this, ss]() {
//            emit sigDeleteStudent(ss->id());
        });
        ui->tableWidget->setCellWidget(i, 8, pbDel);
    }
}
