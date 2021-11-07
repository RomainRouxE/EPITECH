/*
** EPITECH PROJECT, 2018
** babel
** File description:
** Registered
*/

#include "Registered.hpp"
#include "Client.hpp"
#include <QtWidgets>
#include <QtNetwork>
#include <QApplication>
#include <string>
#include <iostream>
#include <list>
#include <vector>


Registered::Registered(QWidget *parent, Client *client)
    : QDialog(parent)
    , _client(client)
    , call_button(new QPushButton(tr("Call")))
    , add_button(new QPushButton(tr("Add contact")))
    , remove_button(new QPushButton(tr("Remove contact")))
    , add_line(new QLineEdit)
    , listWidget(new QListWidget(this))
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    listWidget->setMinimumWidth(200000);
    listWidget->setMinimumHeight(2000000);
    listWidget->setFixedHeight(800);
    listWidget->setFixedWidth(800);
    add_button->setDefault(true);
    add_button->setEnabled(false);
    call_button->setDefault(false);
    call_button->setEnabled(false);
    remove_button->setDefault(true);
    remove_button->setEnabled(false);
    connect(add_button, &QAbstractButton::clicked,
            this, &Registered::add_contact);
    connect(add_line, &QLineEdit::textChanged,
            this, &Registered::enable_addbutton);
    connect(call_button, &QAbstractButton::clicked,
            this, &Registered::handle_call);
    connect(_client->getTcp(), SIGNAL(newpacketa(bool)), this, SLOT(call_handle()));
    connect(_client->getTcp(), SIGNAL(valueChanged(bool)), this, SLOT(displayError()));
    QGridLayout *mainLayout = nullptr;
    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(add_button, 0, 1);
    mainLayout->addWidget(call_button, 1, 1);
    mainLayout->addWidget(listWidget, 1, 0);
    mainLayout->addWidget(remove_button, 2, 1);
    mainLayout->addWidget(add_line, 0, 0);
    setWindowTitle(QGuiApplication::applicationDisplayName());
}

Registered::~Registered()
{
}

void Registered::handle_call()
{
    _client->make_call(getAdd());
}

void Registered::enable_addbutton()
{
    add_button->setEnabled(true);
    call_button->setEnabled(true);
}

void Registered::add_contact()
{
    _client->add_contact(getAdd());
    _client->empty_recvq();
}

std::string Registered::getAdd()
{
    return add_line->text().toUtf8().constData();
}

void Registered::call_handle()
{
    _client->handle_request();
}

void Registered::displayError()
{
    switch (_client->getTcp()->getError()) {
    case 0:
        break;
    case 1:
        QMessageBox::information(this, tr("Babel Client"),
                                 tr("The host was not found"));
        break;
    case 2:
        QMessageBox::information(this, tr("Babel Client"),
                                 tr("The connection was refused by the peer. "));
        break;
    case 3:
        QMessageBox::information(this, tr("Babel Client"),
                                 tr("The following error occurred: %1.")
                                 .arg(_client->getTcp()->getSocket()->errorString()));
    default:
        break;
    }
}
