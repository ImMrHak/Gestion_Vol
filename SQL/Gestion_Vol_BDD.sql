CREATE DATABASE Gestion_VolDB;

USE Gestion_VolDB;

CREATE TABLE roles(
    id_role BIGINT PRIMARY KEY AUTO_INCREMENT,
    libellerole VARCHAR(150)
);

INSERT INTO roles(libellerole) VALUES('ADMIN');
INSERT INTO roles(libellerole) VALUES('USER');

CREATE TABLE users(
    id_user BIGINT PRIMARY KEY AUTO_INCREMENT,
    nom VARCHAR(150),
    prenom VARCHAR(150),
    adresse_mail VARCHAR(150) UNIQUE,
    username VARCHAR(150),
    password varchar(150),
    birthdate DATE,
    id_role BIGINT REFERENCES roles(id_role)
);

INSERT INTO users(nom, prenom, adresse_mail, username, password, birthdate, id_role) VALUES('Hakkou', 'Mohamed', 'hakkoumohamed23@gmail.com', 'hakkou2001', 'hakkou2001', '2001-11-23', 1);

CREATE TABLE logs(
    id_log BIGINT PRIMARY KEY AUTO_INCREMENT,
    motif VARCHAR(150),
    datelog DATE,
    id_user BIGINT REFERENCES users(id_user)
);

CREATE TABLE flights(
    id_flight BIGINT PRIMARY KEY AUTO_INCREMENT,
    apcode VARCHAR(150),
    pilot VARCHAR(150),
    model VARCHAR(150),
    stock INT,
    Manufacture_Date DATE,
    Departure_Date DATE,
    Arrival_Date DATE,
    Departure_City VARCHAR(150),
    Arrival_City VARCHAR(150)
);

CREATE TABLE passangers(
    id_passanger BIGINT PRIMARY KEY AUTO_INCREMENT,
    lastname VARCHAR(150),
    firstname VARCHAR(150),
	age INT,
    phonenumber VARCHAR(150),
    adresse VARCHAR(150),
    nationality VARCHAR(150),
    id_flight BIGINT REFERENCES flights(id_flight)
);

INSERT INTO flights(apcode, pilot, model, stock, Manufacture_Date, Departure_Date, Arrival_Date, Departure_City, Arrival_City) VALUES('ABC123', 'John Smith', 'Boeing 747', 500, '2020-01-01', '2020-01-02 10:00:00', '2020-01-02 12:00:00', 'New York', 'London');
INSERT INTO flights(apcode, pilot, model, stock, Manufacture_Date, Departure_Date, Arrival_Date, Departure_City, Arrival_City) VALUES('DEF456', 'Jane Doe', 'Airbus A320', 200, '2020-01-01', '2020-01-03 14:00:00', '2020-01-03 16:00:00', 'Paris', 'Tokyo');

INSERT INTO passangers(lastname, firstname, age, phonenumber, adresse, nationality, id_flight) VALUES('Smith', 'John', 10,'123-456-7890', '123 Main St', 'USA', 1);
INSERT INTO passangers(lastname, firstname, age, phonenumber, adresse, nationality, id_flight) VALUES('Johnson', 'Bob', 11,'345-678-9012', '789 Maple St', 'Singapore', 2);

COMMIT;