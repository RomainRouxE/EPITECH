/*
** EPITECH PROJECT, 2018
** babel
** File description:
** Login
*/

#include "Client.hpp"
#include "Login.hpp"
#include <iostream>
#include <QtWidgets>
#include <QtNetwork>
#include <QApplication>

Login::Login(QWidget *parent, Client *client)
    : QDialog(parent)
    , _client(client)
    , host_line(new QLineEdit)
    , portLineEdit(new QLineEdit)
    , username_line(new QLineEdit)
    , password_line(new QLineEdit)
    , connect_button(new QPushButton(tr("Connect Server")))
    , create_button(new QPushButton(tr("Create account")))
    , ready(false)
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    portLineEdit->setValidator(new QIntValidator(1, 65535, this));

    auto hostLabel = new QLabel(tr("&Server name:"));
    hostLabel->setBuddy(host_line);
    auto portLabel = new QLabel(tr("S&erver port:"));
    portLabel->setBuddy(portLineEdit);
    auto user_label = new QLabel(tr("Username:"));
    user_label->setBuddy(username_line);
    auto pass_label = new QLabel(tr("Password:"));
    pass_label->setBuddy(password_line);
    statusLabel = new QLabel(tr("Please connect to the server"));
    connect_button->setDefault(true);
    connect_button->setEnabled(false);
    create_button->setDefault(true);
    create_button->setEnabled(false);
    auto quitButton = new QPushButton(tr("Quit"));
    auto buttonBox = new QDialogButtonBox;
    buttonBox->addButton(create_button, QDialogButtonBox::ActionRole);
    buttonBox->addButton(connect_button, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);
    connect(host_line, &QLineEdit::textChanged,
            this, &Login::enableconnect_button);
    connect(portLineEdit, &QLineEdit::textChanged,
            this, &Login::enableconnect_button);
    connect(username_line, &QLineEdit::textChanged,
            this, &Login::enableconnect_button);
    connect(password_line, &QLineEdit::textChanged,
            this, &Login::enableconnect_button);
    connect(connect_button, &QAbstractButton::clicked,
            this, &Login::connect_server);
    connect(create_button, &QAbstractButton::clicked,
            this, &Login::create_user);
    connect(quitButton, &QAbstractButton::clicked, this, &QWidget::close);
    QGridLayout *loginlayout = nullptr;
    if (QGuiApplication::styleHints()->showIsFullScreen() || QGuiApplication::styleHints()->showIsMaximized()) {
        auto outerVerticalLayout = new QVBoxLayout(this);
        outerVerticalLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Ignored, QSizePolicy::MinimumExpanding));
        auto outerHorizontalLayout = new QHBoxLayout;
        outerHorizontalLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::MinimumExpanding, QSizePolicy::Ignored));
        auto groupBox = new QGroupBox(QGuiApplication::applicationDisplayName());
        loginLayout = new QGridLayout(groupBox);
        outerHorizontalLayout->addWidget(groupBox);
        outerHorizontalLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::MinimumExpanding, QSizePolicy::Ignored));
        outerVerticalLayout->addLayout(outerHorizontalLayout);
        outerVerticalLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Ignored, QSizePolicy::MinimumExpanding));
    } else {
        loginLayout = new QGridLayout(this);
    }
    loginLayout->addWidget(hostLabel, 0, 0);
    loginLayout->addWidget(host_line, 0, 1);
    loginLayout->addWidget(portLabel, 1, 0);
    loginLayout->addWidget(portLineEdit, 1, 1);
    loginLayout->addWidget(user_label, 2, 0);
    loginLayout->addWidget(username_line, 2, 1);
    loginLayout->addWidget(pass_label, 3, 0);
    loginLayout->addWidget(password_line,3, 1);
    loginLayout->addWidget(statusLabel, 4, 0, 1, 2);
    loginLayout->addWidget(buttonBox, 5, 0, 1, 2);

    setWindowTitle(QGuiApplication::applicationDisplayName());
    portLineEdit->setFocus();
    setLayout(loginLayout);
}   

Login::~Login()
{
}

void Login::create_user()
{
    create_button->setEnabled(false);
    _client->connect_server(getUser(), getPort(), getHost(), getPass());
    _client->empty_recvq();
    _client->seType(2);
}


void Login::connect_server()
{
    connect_button->setEnabled(false);
    _client->connect_server(getUser(), getPort(), getHost(), getPass());
    _client->empty_recvq();
    _client->seType(1);
}

void Login::call_handle()
{
    _client->handle_request();
}
void Login::enableconnect_button()
{
    connect_button->setEnabled(!host_line->text().isEmpty() && !portLineEdit->text().isEmpty());
    create_button->setEnabled(!host_line->text().isEmpty() && !portLineEdit->text().isEmpty());
}

std::string Login::getUser()
{
    std::cout << username_line->text().toUtf8().constData()<< std::endl;
    return username_line->text().toUtf8().constData();
}
std::string Login::getPass()
{
    return password_line->text().toUtf8().constData();
}

QString Login::getHost()
{
    return host_line->text();
}

int Login::getPort()
{
    return portLineEdit->text().toInt();
}
