SELECT TABLE IF EXISTS diploma;

CREATE TABLE diploma (
    id INT not null,
    diploma_name VARCHAR(40) not null,
    city VARCHAR(40) not null,
    CONSTRAINT PK__diploma PRIMARY KEY (id)
);

CREATE TABLE Doctor (
    surname VARCHAR(40) not null,
    firstname VARCHAR(40) not null
    job VARCHAR(40) not null,
    Efficiency INT not null
);

CREATE TABLE Patient (
    surname VARCHAR(40) not null,
    firstname VARCHAR(40) not null,
    dolor INT not null,
    entry_date TIMESTAMP not null,

ALTER TABLE diploma
ADD ID ID
ADD diploma diploma_name
ADD city city
