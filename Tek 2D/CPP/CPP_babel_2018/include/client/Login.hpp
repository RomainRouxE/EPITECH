/*
** EPITECH PROJECT, 2018
** babel
** File description:
** Login
*/

#ifndef LOGIN_HPP_
#define LOGIN_HPP_
#include <QDialog>
#include <string>
class Client;
class QComboBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QGridLayout;

class Login : public QDialog {
    Q_OBJECT
	public:
		Login(QWidget *parent=nullptr, Client *client=nullptr);
		~Login();
        bool getReady(){
            return ready;
        }
        std::string getUser();
        std::string getPass();
        int getPort();
        QString getHost();
        void enableconnect_button();
        void connect_server();
        void create_user();
        void setAsklogin(bool input);
    private slots:
        void call_handle();
	protected:
	private:
    bool ready;
    Client *_client;
    QLineEdit *host_line = nullptr;
    QLineEdit *portLineEdit = nullptr;
    QLineEdit *username_line = nullptr;
    QLineEdit *password_line = nullptr;
    QLabel *statusLabel = nullptr;
    QPushButton *connect_button = nullptr;
    QPushButton *create_button = nullptr;
    QGridLayout *loginLayout = nullptr;
};

#endif /* !LOGIN_HPP_ */
