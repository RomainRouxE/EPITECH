/*
** EPITECH PROJECT, 2018
** babel
** File description:
** ATcpCo
*/

#ifndef ATCPCO_HPP_
#define ATCPCO_HPP_

class ATcpCo {
	public:
		virtual ~ATcpCo(){}
        virtual int getId() = 0;
        virtual void write(std::string message) = 0;
        virtual void start() = 0;
        virtual void read() = 0;
        virtual void setInstr(Instructor *instr) = 0;
        virtual void close() = 0;
	protected:
	private:
    virtual void handle_write() = 0;
    virtual void handle_read() = 0;
    Instructor *instructor;
    int socket;
    std::string message_;
};

#endif /* !ATCPCO_HPP_ */
