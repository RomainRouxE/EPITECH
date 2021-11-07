/*
** EPITECH PROJECT, 2018
** babel
** File description:
** Registered
*/

#ifndef REGISTERED_HPP_
#define REGISTERED_HPP_
#include <QDialog>
#include <QListWidget>
class Client;
class Registered :public QDialog {
    Q_OBJECT
	public:
		Registered(QWidget *parent=nullptr, Client *client=nullptr);
		~Registered();
        void enable_addbutton();
        void add_contact();
        std::string getAdd();
        void handle_call();
    private slots:
        void call_handle();
        void displayError();
	protected:
	private:
    QListWidget *listWidget;
    Client *_client;
    QPushButton *call_button = nullptr;
    QPushButton *add_button = nullptr;
    QPushButton *remove_button = nullptr;
    QLineEdit *add_line = nullptr;
};

#endif /* !REGISTERED_HPP_ */
