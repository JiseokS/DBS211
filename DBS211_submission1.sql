--DBS 211 NII Group 6
--Jiseok Shim (ID: 122758170)
--Anson Hammell (ID: 022458145)
--The SQL code below.

--Jiseok Shim
CREATE TABLE Passenger(
    PassengerNumber      INT PRIMARY KEY,
    DepartureStationID   varchar(255)NOT NULL,
    DestinationStationID varchar(255)NOT NULL,
    PassengerName        varchar(255)NOT NULL,
    Gender               varchar(1)NOT NULL,
    Fare                 INT NOT NULL,
    Age                  INT NOT NULL,
    SeatNumber           INT NOT NULL
);

INSERT ALL
    INTO Passenger VALUES (101, 'Ottawa', 'Markham', 'Hal Hammell', 'F', 150, 12, 1)
    INTO Passenger VALUES (102, 'Japan', 'Toronto', 'Anson Jim', 'M', 300, 52, 2)
    INTO Passenger VALUES (103, 'New York', 'Markham', 'Paul Bob', 'M', 80, 31, 3)
    INTO Passenger VALUES (104, 'Stouville', 'New York', 'Tony Fox', 'M', 100, 39, 4)
    INTO Passenger VALUES (105, 'Frog', 'Markham', 'Orus Boral', 'F', 60, 60, 5)
    INTO Passenger VALUES (106, 'Riverdale', 'Markham', 'John Madden', 'M', 30, 23, 6)
    INTO Passenger VALUES (107, 'Devotion', 'Calgary', 'Joe Bidden', 'F', 80, 37, 7)
    INTO Passenger VALUES (108, 'Quebec', 'Riverdale', 'Junko Hammell', 'F', 200, 76, 8)
    INTO Passenger VALUES (109, 'Calgary', 'Quebect', 'Answer Gear', 'M', 80, 3, 9)
    INTO Passenger VALUES (110, 'Markham', 'Markham', 'Avid Swimmer', 'F', 20, 2, 10)
SELECT * FROM dual;

CREATE TABLE Promotion(
    CouponNumber       INT PRIMARY KEY,
    DiscountPercentage INT NOT NULL,
    ExpiredDate        varchar(255) NOT NULL
);
    
INSERT ALL
    INTO Promotion VALUES (110, 10, '2021-12-31')
    INTO Promotion VALUES (105, 5, '2022-12-31')
    INTO Promotion VALUES (120, 20, '2021-12-31')
    INTO Promotion VALUES (120, 20, '2022-12-31')
    INTO Promotion VALUES (120, 20, '2021-06-30')
    INTO Promotion VALUES (110, 10, '2021-12-31')
    INTO Promotion VALUES (120, 20, '2021-06-30')
    INTO Promotion VALUES (110, 10, '2021-12-31')
    INTO Promotion VALUES (110, 10, '2021-06-30')
    INTO Promotion VALUES (110, 10, '2022-12-31')
SELECT * FROM dual;

CREATE TABLE Payment(
    PaymentNumber       INT PRIMARY KEY,
    Amount              INT NOT NULL,
    Date                INT NOT NULL,
    Method              varchar(255)NOT NULL,
    DiscountPercentage  INT NOT NULL,
    UserNumber          INT NOT NULL
);

INSERT ALL
    INTO Payment VALUES (110582, 150, '2021-11-23', 'Debit Card', 0, 1)
    INTO Payment VALUES (110621, 285, '2021-11-02', 'Debit Card', 5, 2)
    INTO Payment VALUES (110211, 80, '2021-11-21', 'Credit Card', 0, 3)
    INTO Payment VALUES (110214, 100, '2021-11-18', 'Credit Card', 0, 4)
    INTO Payment VALUES (110715, 54, '2021-11-04', 'Debit Card', 10, 5)
    INTO Payment VALUES (110144, 27, '2021-11-02', 'Credit Card', 10, 6)
    INTO Payment VALUES (110231, 64, '2021-11-07', 'Cash', 20, 7)
    INTO Payment VALUES (110911, 180, '2021-11-08', 'Credit Card', 10, 8)
    INTO Payment VALUES (110752, 76, '2021-11-30', 'Credit Card', 5, 9)
    INTO Payment VALUES (110555, 18, '2021-11-28', 'Credit Card', 10, 10)
SELECT * FROM dual;

CREATE TABLE Bill(
    ReceiptNumber       INT PRIMARY KEY,
    BillStatus          varchar(255)NOT NULL,
    Date                varchar(255)NOT NULL,
    Method              varchar(255)NOT NULL,
    PaymentNumber       INT NOT NULL
);

INSERT ALL
    INTO Bill VALUES (10582, 'Paid', '2021-11-23', 'Debit Card', 110582)
    INTO Bill VALUES (10621, 'Paid', '2021-11-02', 'Debit Card', 110621)
    INTO Bill VALUES (10211, 'Paid', '2021-11-21', 'Credit Card', 110211)
    INTO Bill VALUES (10214, 'Paid', '2021-11-18', 'Credit Card', 110214)
    INTO Bill VALUES (10715, 'Paid', '2021-11-04', 'Debit Card', 110715)
    INTO Bill VALUES (10144, 'Paid', '2021-11-02', 'Credit Card', 110144)
    INTO Bill VALUES (10231, 'Paid', '2021-11-07', 'Cash', 110231)
    INTO Bill VALUES (10911, 'Canceled', '2021-11-08', 'Credit Card', 110911)
    INTO Bill VALUES (10752, 'Paid', '2021-11-30', 'Credit Card', 110752)
    INTO Bill VALUES (10555, 'Paid', '2021-11-28', 'Credit Card', 110555)
SELECT * FROM dual;
--Anson Hammell
CREATE TABLE STATION (
    STATION_ID int,
    STATION_NAME varchar(255),
    PRIMARY KEY (STATION_ID)
);
INSERT ALL
    INTO STATION VALUES ( 1193, 'Englinton Station')
    INTO STATION VALUES ( 1293, 'Ero Station')
    INTO STATION VALUES ( 1393, 'China Station')
    INTO STATION VALUES ( 1493, 'Hero Station')
    INTO STATION VALUES ( 1593, 'Coloumn Station')
    INTO STATION VALUES ( 1693, 'Adea Station')
    INTO STATION VALUES ( 1793, 'Yu Station')
    INTO STATION VALUES ( 1893, 'Markham Station')
    INTO STATION VALUES ( 1993, 'Markville Station')
    INTO STATION VALUES ( 1093, 'PMALL Station')
SELECT * FROM dual;
CREATE TABLE TRAIN (
    TRAIN_NUMBER int,
    TRAIN_TYPE varchar(255),
    DEPARTURE_ID varchar(255),
    DESTINATION_ID varchar(255),
    ECONOMY_CLASS int,
    SLEEPER_CLASS int,
    PRESTIGE_CLASS int,
    PRIMARY KEY (TRAIN_NUMBER)
);
INSERT ALL
    INTO TRAIN VALUES (1, 'Bullet', 'Ottawa', 'Markham', 350, 50, 50)
    INTO TRAIN VALUES (2, 'Subway', 'Japan', 'Toronto', 650, 0, 0)
    INTO TRAIN VALUES (3, 'Bullet', 'New York', 'Markham', 350, 50, 50)
    INTO TRAIN VALUES (4, 'Bullet', 'Stouville', 'New York', 350, 50, 50)
    INTO TRAIN VALUES (5, 'Bullet', 'Frog', 'Markham', 350, 50, 50)
    INTO TRAIN VALUES (6, 'Subway', 'Riverdale', 'Markham', 650, 0, 0)
    INTO TRAIN VALUES (7, 'Bullet', 'Devotion', 'Calgary', 350, 50, 50)
    INTO TRAIN VALUES (8, 'Bullet', 'Quebec', 'Riverdale', 350, 50, 50)
    INTO TRAIN VALUES (9, 'Subway', 'Calgary', 'Quebect', 650, 0, 0)
    INTO TRAIN VALUES (53, 'Bullet', 'Markham', 'Markham', 350, 50, 50)
SELECT * FROM dual;
CREATE TABLE TRAIN_STATUS (
    TRAIN_NUMBER int,
    AVAILABLE_SEATS int,
    AVAILABLE_DATE DATE,
    BOOKED_SEATS int,
    UNAVAILABLE_DATE DATE,
    PRIMARY KEY (TRAIN_NUMBER)
);
INSERT ALL
    INTO TRAIN_STATUS VALUES (1, 236, '2021-10-19', 51, '2022-01-3')
    INTO TRAIN_STATUS VALUES (2, 136, '2021-11-29', 28, '2022-01-3')
    INTO TRAIN_STATUS VALUES (3, 206, '2021-03-12', 68, '2022-01-3')
    INTO TRAIN_STATUS VALUES (4, 36, '2021-10-14', 54, '2022-01-3')
    INTO TRAIN_STATUS VALUES (5, 123, '2021-06-16', 88, '2022-01-3')
    INTO TRAIN_STATUS VALUES (6, 321, '2021-05-15', 8, '2022-01-3')
    INTO TRAIN_STATUS VALUES (7, 163, '2021-10-21', 18, '2022-01-3')
    INTO TRAIN_STATUS VALUES (8, 33, '2021-11-21', 66, '2022-01-3')
    INTO TRAIN_STATUS VALUES (9, 22, '2021-01-13', 67, '2022-01-3')
    INTO TRAIN_STATUS VALUES (53, 54, '2021-02-09', 44, '2022-01-3')
SELECT * FROM dual;
CREATE TABLE RESERVATION (
    RESERVATION_NUMBER int,
    USER_NUMBER int,
    TRAIN_NUMBER int,
    PASSENGER_NUMBER int,
    RESERVED_STATUS varchar(1),
    RESERVATION_DATE DATE,
    PRIMARY KEY (RESERVATION_NUMBER),
    FOREIGN KEY (USER_NUMBER) REFERENCES USER(USER_NUMBER),
    FOREIGN KEY (TRAIN_NUMBER) REFERENCES TRAIN(TRAIN_NUMBER),
    FOREIGN KEY (PASSENGER_NUMBER) REFERENCES PASSENGER(PASSENGER_NUMBER)
);
INSERT ALL
    INTO RESERVATION VALUES (1, 1, 1, 25, 'Y', '2022-10-12')
    INTO RESERVATION VALUES (23, 2, 2, 21, 'Y', '2022-12-02')
    INTO RESERVATION VALUES (63, 3, 3, 5, 'Y', '2022-12-22')
    INTO RESERVATION VALUES (41, 4, 4, 2, 'Y', '2022-02-12')
    INTO RESERVATION VALUES (3, 5, 5, 3, 'N', '2022-03-21')
    INTO RESERVATION VALUES (53, 6, 6, 1, 'Y', '2022-07-15')
    INTO RESERVATION VALUES (76, 7, 7, 8, 'Y', '2022-06-12')
    INTO RESERVATION VALUES (44, 8, 8, 9, 'N', '2022-04-13')
    INTO RESERVATION VALUES (41, 9, 9, 10, 'Y', '2022-02-02')
    INTO RESERVATION VALUES (45, 10, 53, 1, 'N', '2022-09-07')
SELECT * FROM dual;
CREATE TABLE TrainUser(
    USER_NUMBER INT PRIMARY KEY,
    COUPON_NUMBER INT NOT NULL,
    FIRSTNAME varchar(255)NOT NULL,
    LASTNAME varchar(255)NOT NULL,
    ADDRESS varchar(255)NOT NULL,
    GENDER varchar(1)NOT NULL,
    PHONE varchar(255)NOT NULL,
    AGE INT NOT NULL,
    EMAIL varchar(255)NOT NULL
);
INSERT ALL
    INTO TrainUser VALUES (1, 110, 'Hal', 'Hammell', '954 Millhouse Drive', 'F','9054326943', 12, 'gimme21@email.com')
    INTO TrainUser VALUES (2, 105, 'Anson', 'Jim', '954 Millhouse Drive', 'M','9054326943', 52, 'gimme21@email.com')
    INTO TrainUser VALUES (3, 120, 'Paul', 'Bob', '914 Millhouse Drive', 'M','9054326943', 31, 'gimme21@email.com')
    INTO TrainUser VALUES (4, 120, 'Tony', 'Fox', '934 Millhouse Drive', 'M','9054326943', 39, 'gimme21@email.com')
    INTO TrainUser VALUES (5, 120, 'Orus', 'Boral', '944 Millhouse Drive', 'F','9054326943', 65, 'gimme21@email.com')
    INTO TrainUser VALUES (6, 110, 'John', 'Madden', '964 Millhouse Drive', 'M','9054326943', 23, 'gimme21@email.com')
    INTO TrainUser VALUES (7, 120, 'Joe', 'Bidden', '94 Millhouse Drive', 'F','9054326943', 37, 'gimme21@email.com')
    INTO TrainUser VALUES (8, 110, 'Junko', 'Hammell', '954 Millhouse Drive', 'F','9054326943', 76, 'gimme21@email.com')
    INTO TrainUser VALUES (9, 110, 'Answer', 'Gear', '54 Millhouse Drive', 'M','9054326943', 3, 'gimme21@email.com')
    INTO TrainUser VALUES (10, 110, 'Avid', 'Swimmer', '95 Millhouse Drive', 'F','9054326943', 2, 'gimme21@email.com')
SELECT * FROM dual;
COMMIT;
