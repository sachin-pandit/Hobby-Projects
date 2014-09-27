create database e_auction;

use e_auction;

show tables;



create table BANK_ACCOUNT
(
Account_id integer NOT NULL,
Balance numeric(8,2) NOT NULL,
Fees_pc numeric(4,2) NOT NULL,
PRIMARY KEY(Account_id)
)ENGINE=InnoDB;



create table EA_BRANCH
(
Branch_id integer NOT NULL,
Location varchar(20) NOT NULL,
Brokerage numeric(4,2) NOT NULL,
B_acc_id integer NOT NULL,
INDEX a(B_acc_id),
PRIMARY KEY(branch_id),
FOREIGN KEY(B_acc_id) REFERENCES BANK_ACCOUNT(Account_id) ON UPDATE CASCADE ON DELETE CASCADE
)ENGINE=InnoDB;




create table EMPLOYEE
(
Uniq_id integer NOT NULL,
Name varchar(20) NOT NULL,
Email_id varchar(25) NOT NULL,
Phone varchar(10) NOT NULL,
Address varchar(30) NOT NULL,
Salary numeric(7,2) NOT NULL,
E_Branch_id integer NOT NULL,
INDEX a(E_Branch_id),
PRIMARY KEY(Uniq_id),
FOREIGN KEY(E_Branch_id) REFERENCES EA_BRANCH(Branch_id) ON UPDATE CASCADE ON DELETE CASCADE
)ENGINE=InnoDB;





create table SHIPMENT_AGENCY
(
Agency_id integer NOT NULL,
Agency_name varchar(20) NOT NULL,
Trans_fee numeric(4,2) NOT NULL,
A_acc_id integer NOT NULL,
INDEX a(A_acc_id),
PRIMARY KEY(Agency_id),
FOREIGN KEY(A_acc_id) REFERENCES BANK_ACCOUNT(Account_id) ON UPDATE CASCADE ON DELETE CASCADE
)ENGINE=InnoDB;




create table BIDDER
(
Uniq_id integer NOT NULL,
Name varchar(20) NOT NULL,
Email_id varchar(25) NOT NULL,
Phone varchar(10) NOT NULL,
Address varchar(30) NOT NULL,
PRIMARY KEY(Uniq_id)
)ENGINE=InnoDB;





create table SELLER
(
Uniq_id integer NOT NULL,
Name varchar(20) NOT NULL,
Email_id varchar(25) NOT NULL,
Phone varchar(10) NOT NULL,
Address varchar(30) NOT NULL,
S_acc_id integer NOT NULL,
INDEX a(S_acc_id),
PRIMARY KEY(Uniq_id),
FOREIGN KEY(S_acc_id) REFERENCES BANK_ACCOUNT(Account_id) ON UPDATE CASCADE ON DELETE CASCADE
)ENGINE=InnoDB;






create table ITEM
(
Item_id integer NOT NULL,
Name varchar(20) NOT NULL,
Category varchar(20) NOT NULL,
Price numeric(8,2) NULL,
Buyer_id integer NULL,
INDEX a(Buyer_id),
Seller_id integer NOT NULL,
INDEX b(Seller_id),
Ship_id integer NOT NULL,
INDEX c(Ship_id),
PRIMARY KEY(Item_id),
FOREIGN KEY(Buyer_id) REFERENCES BIDDER(Uniq_id) ON UPDATE CASCADE ON DELETE CASCADE,
FOREIGN KEY(Seller_id) REFERENCES SELLER(Uniq_id) ON UPDATE CASCADE ON DELETE CASCADE,
FOREIGN KEY(Ship_id) REFERENCES SHIPMENT_AGENCY(Agency_id) ON UPDATE CASCADE ON DELETE CASCADE
)ENGINE=InnoDB;






create table AUCTION
(
Auction_id integer NOT NULL,
Base_bid numeric(8,2) NOT NULL,
Max_bid numeric(8,2) NULL,
Max_count integer NOT NULL,
Bid_count integer DEFAULT 0,
E_uniq_id integer NOT NULL,
INDEX a(E_uniq_id),
A_item_id integer NOT NULL,
INDEX b(A_item_id),
PRIMARY KEY(Auction_id),
FOREIGN KEY(A_item_id) REFERENCES ITEM(Item_id) ON UPDATE CASCADE ON DELETE CASCADE,
FOREIGN KEY(E_uniq_id) REFERENCES EMPLOYEE(Uniq_id) ON UPDATE CASCADE ON DELETE CASCADE,
CONSTRAINT on_count CHECK (Bid_count <= Max_count)
)ENGINE=InnoDB;



create table BIDDER_PART_AUC
(
Bidder_id integer NOT NULL,
INDEX a(Bidder_id),
Auc_id integer NOT NULL, 
INDEX b(Auc_id),
Amount numeric(8,2) NOT NULL,
PRIMARY KEY(Bidder_id, Auc_id),
FOREIGN KEY(Bidder_id) REFERENCES BIDDER(Uniq_id) ON UPDATE CASCADE ON DELETE CASCADE,
FOREIGN KEY(Auc_id) REFERENCES AUCTION(Auction_id) ON UPDATE CASCADE ON DELETE CASCADE
)ENGINE=InnoDB;




/* INSERT IN BANK_ACCOUNT  ----  (1)*/
/* SHIPMENT_AGENCY */
insert into 
BANK_ACCOUNT
values(21, 123.23, 5.00);

insert into 
BANK_ACCOUNT
values(22, 313.53, 5.00);

insert into 
BANK_ACCOUNT
values(23, 521.54, 5.00);

insert into 
BANK_ACCOUNT
values(24, 2410.32, 5.00);

insert into 
BANK_ACCOUNT
values(25, 855.27, 5.00);

/* SELLER */

insert into 
BANK_ACCOUNT
values(1, 273.63, 5.00);

insert into 
BANK_ACCOUNT
values(2, 323.93, 5.00);

insert into 
BANK_ACCOUNT
values(3, 873.23, 5.00);

insert into 
BANK_ACCOUNT
values(4, 516.54, 5.00);

insert into 
BANK_ACCOUNT
values(5, 852.35, 5.00);


/* EA_BRANCH; */

insert into 
BANK_ACCOUNT
values(41, 563.23, 5.00);

insert into 
BANK_ACCOUNT
values(42, 935.23, 5.00);

insert into 
BANK_ACCOUNT
values(43, 893.23, 5.00);

insert into 
BANK_ACCOUNT
values(44, 914.13, 5.00);

insert into 
BANK_ACCOUNT
values(45, 1327.96, 5.00);



/* INSERT IN EA_BRANCH  ----  (2) */

insert into
EA_BRANCH
values(101, 'MYS', 5.0, 41);

insert into
EA_BRANCH
values(102,'GUL', 5.0, 42);

insert into
EA_BRANCH
values(103, 'DVG', 5.0, 43);

insert into
EA_BRANCH
values(104, 'BNG', 5.0, 44);

insert into
EA_BRANCH
values(105, 'SMG', 5.0, 45);



/* INSERT IN EMPLOYEE  ---- (3) */

insert into	
EMPLOYEE
values(201, 'gayle', 'gayle@yahoo.com', 543555, '#323,1st M,6th C,BDR', 21313.33, 102);

insert into	
EMPLOYEE
values(202, 'sarwan', 'sarwan@yahoo.com', 543433, '#37,5th M,3rd C,BDR', 22323.33, 104);

insert into	
EMPLOYEE
values(203, 'roach', 'roach@yahoo.com', 514323, '#123,2nd M,8th C,BDR', 22322.33, 103);

insert into	
EMPLOYEE
values(204, 'potter', 'prongs@godric.com', 724372, '#821,2nd M,9th C,HOG', 14369.33, 101);

insert into	
EMPLOYEE
values(205, 'granger', 'hermie@hogshead.com', 391638, '#6,14th M,1st C,ENG', 31751.33, 105);

insert into	
EMPLOYEE
values(206, 'severus', 'hbprince@dark.com', 416382, '#12,3rd M,8th C,NOC', 24732.00, 103);


/* INSERT IN SHIPMENT_AGENCY  ---- (4) */

insert into
SHIPMENT_AGENCY
values(301, 'SPEED', 5.0, 21);

insert into
SHIPMENT_AGENCY
values(302, 'WE_TRANS', 5.0, 22);

insert into
SHIPMENT_AGENCY
values(303, 'QUICK-POST', 5.0, 23);

insert into
SHIPMENT_AGENCY
values(304, 'OWLER', 5.0, 24);

insert into
SHIPMENT_AGENCY
values(305, 'ACCIO', 5.0, 25);



/* INSERT IN BIDDER  ---- (5) */

insert into
BIDDER
values( 401, 'morkel@gmail.com', 'morkel', 235455, '#121,3rd M,14th C,gulb');

insert into
BIDDER
values( 402, 'mark@gmail.com', 'mark', 232425, '#340,5th M,18th C,gulb');

insert into
BIDDER
values( 403, 'smith@ymail.com', 'smith', 242678, '#533,9th M,11th C,mys');

insert into
BIDDER
values( 404, 'graph@gmail.com', 'grimaldi', 142151, '#107,7th M,5th C,bang');

insert into
BIDDER
values( 405, 'voldy@gmail.com', 'tomriddle', 913196, '#523,1st M,18th C,azka');

/* INSERT IN SELLER  ---- (6) */

insert into
SELLER
values( 501, 'andrew', 'andrew@gmail.com', 436352, '#238,17th cross,dvg', 1);

insert into
SELLER
values( 502, 'trott', 'trott@gmail.com', 427738, '#218,23th cross,bng', 2);

insert into
SELLER
values( 503, 'anderson', 'anderson@gmail.com', 433778, '#678,34th cross,dvg', 3);

insert into
SELLER
values( 504, 'phill', 'phill@gmail.com', 140961, '#14,55th cross,mys', 4);
	
insert into
SELLER
values( 505, 'dabba', 'somnam@gmail.com', 314309, '#109,37th cross,man', 5);

/* INSERT IN ITEM  ---- (7) */

insert into
ITEM
values(601, 'PineIPod', 'Electronic', NULL, NULL, 505, 302);

insert into
ITEM
values(602, 'Mongoose_Bat', 'Sport', NULL, NULL, 502, 301);

insert into
ITEM
values(603, 'Swing_Chair', 'Furniture', NULL, NULL, 501, 302);

insert into
ITEM
values(604, 'Odyssey_Headphone', 'Electronic', NULL, NULL, 503, 304);

insert 
into ITEM
values(605, 'kingston_pendrive', 'Electronic', NULL, NULL, 503, 305);

insert 
into ITEM
values(606, 'avira_ironbox', 'Electronic', NULL, NULL, 504, 302);

insert 
into ITEM
values(607, 'ushafan', 'Electronic', NULL, NULL, 501, 304);

/* INSERT IN AUCTION  ---- (8) */

insert into
AUCTION
values(701, 2000.00, NULL, 10, 0, 201, 601);

insert into
AUCTION
values(702, 750.00, NULL, 10, 0, 204, 602);

insert into
AUCTION
values(703, 565.00, NULL, 6, 0, 203, 603);

insert into
AUCTION
values(704, 300.00, NULL, 8, 0, 203, 604);

insert 
into AUCTION
values(705, 300.00, NULL, 6, 0, 204, 605);

insert 
into AUCTION
values(706, 625.00, NULL, 6, 0, 205, 606);

insert 
into AUCTION
values(707, 1256.00, NULL, 6, 0, 202, 607);

/* INSERT IN BIDDER_PART_AUC  ---- (9) */

insert into
BIDDER_PART_AUC
values(401, 701, 2500.00);

/***/
update AUCTION
set Bid_count=AUCTION.Bid_count+1
where Auction_id=701;
/***/
/******/
update AUCTION
set Max_bid=
(
select MAX(Amount)
from BIDDER_PART_AUC
where Auc_id=701
)
where Auction_id=701
AND Max_count=Bid_count;
/******/


insert into
BIDDER_PART_AUC
values(402, 702, 950.00);

/***/
update AUCTION
set Bid_count=AUCTION.Bid_count+1
where Auction_id=702;
/***/
/******/
update AUCTION
set Max_bid=
(
select MAX(Amount)
from BIDDER_PART_AUC
where Auc_id=702
)
where Auction_id=702
AND Max_count=Bid_count;
/******/


insert into
BIDDER_PART_AUC
values(404, 707, 1554.00);

/***/
update AUCTION
set Bid_count=AUCTION.Bid_count+1
where Auction_id=707;
/***/
/******/
update AUCTION
set Max_bid=
(
select MAX(Amount)
from BIDDER_PART_AUC
where Auc_id=707
)
where Auction_id=707
AND Max_count=Bid_count;
/******/


insert into
BIDDER_PART_AUC
values(403, 703, 700.00);

/***/
update AUCTION
set Bid_count=AUCTION.Bid_count+1
where Auction_id=703;
/***/
/******/
update AUCTION
set Max_bid=
(
select MAX(Amount)
from BIDDER_PART_AUC
where Auc_id=703
)
where Auction_id=703
AND Max_count=Bid_count;
/******/


insert into
BIDDER_PART_AUC
values(403, 702, 1000.00);

/***/
update AUCTION
set Bid_count=AUCTION.Bid_count+1
where Auction_id=702;
/***/
/******/
update AUCTION
set Max_bid=
(
select MAX(Amount)
from BIDDER_PART_AUC
where Auc_id=702
)
where Auction_id=702
AND Max_count=Bid_count;
/******/


insert into
BIDDER_PART_AUC
values(405, 706, 765.00);

/***/
update AUCTION
set Bid_count=AUCTION.Bid_count+1
where Auction_id=706;
/***/
/******/
update AUCTION
set Max_bid=
(
select MAX(Amount)
from BIDDER_PART_AUC
where Auc_id=706
)
where Auction_id=706
AND Max_count=Bid_count;
/******/


insert into
BIDDER_PART_AUC
values(401, 703, 750.00);

/***/
update AUCTION
set Bid_count=AUCTION.Bid_count+1
where Auction_id=703;
/***/
/******/
update AUCTION
set Max_bid=
(
select MAX(Amount)
from BIDDER_PART_AUC
where Auc_id=703
)
where Auction_id=703
AND Max_count=Bid_count;
/******/


insert into
BIDDER_PART_AUC
values(402, 701, 2650.00);

/***/
update AUCTION
set Bid_count=AUCTION.Bid_count+1
where Auction_id=701;
/***/
/******/
update AUCTION
set Max_bid=
(
select MAX(Amount)
from BIDDER_PART_AUC
where Auc_id=701
)
where Auction_id=701
AND Max_count=Bid_count;
/******/


insert into
BIDDER_PART_AUC
values(404, 702, 1100.00);

/***/
update AUCTION
set Bid_count=AUCTION.Bid_count+1
where Auction_id=702;
/***/
/******/
update AUCTION
set Max_bid=
(
select MAX(Amount)
from BIDDER_PART_AUC
where Auc_id=702
)
where Auction_id=702
AND Max_count=Bid_count;
/******/


insert into
BIDDER_PART_AUC
values(402, 704, 325.00);

/***/
update AUCTION
set Bid_count=AUCTION.Bid_count+1
where Auction_id=704;
/***/
/******/
update AUCTION
set Max_bid=
(
select MAX(Amount)
from BIDDER_PART_AUC
where Auc_id=704
)
where Auction_id=704
AND Max_count=Bid_count;
/******/


insert into
BIDDER_PART_AUC
values(405, 705, 447.00);

/***/
update AUCTION
set Bid_count=AUCTION.Bid_count+1
where Auction_id=705;
/***/
/******/
update AUCTION
set Max_bid=
(
select MAX(Amount)
from BIDDER_PART_AUC
where Auc_id=705
)
where Auction_id=705
AND Max_count=Bid_count;
/******/



insert into
BIDDER_PART_AUC
values(404, 701, 2570.00);

/***/
update AUCTION
set Bid_count=AUCTION.Bid_count+1
where Auction_id=701;
/***/
/******/
update AUCTION
set Max_bid=
(
select MAX(Amount)
from BIDDER_PART_AUC
where Auc_id=701
)
where Auction_id=701
AND Max_count=Bid_count;
/******/


insert into
BIDDER_PART_AUC
values(403, 701, 2700.00);

/***/
update AUCTION
set Bid_count=AUCTION.Bid_count+1
where Auction_id=701;
/***/
/******/
update AUCTION
set Max_bid=
(
select MAX(Amount)
from BIDDER_PART_AUC
where Auc_id=701
)
where Auction_id=701
AND Max_count=Bid_count;
/******/


insert into
BIDDER_PART_AUC
values(405, 704, 400.00);

/***/
update AUCTION
set Bid_count=AUCTION.Bid_count+1
where Auction_id=704;
/***/
/******/
update AUCTION
set Max_bid=
(
select MAX(Amount)
from BIDDER_PART_AUC
where Auc_id=704
)
where Auction_id=704
AND Max_count=Bid_count;
/******/


insert into
BIDDER_PART_AUC
values(402, 703, 850.00);

/***/
update AUCTION
set Bid_count=AUCTION.Bid_count+1
where Auction_id=703;
/***/
/******/
update AUCTION
set Max_bid=
(
select MAX(Amount)
from BIDDER_PART_AUC
where Auc_id=703
)
where Auction_id=703
AND Max_count=Bid_count;
/******/


insert into
BIDDER_PART_AUC
values(401, 704, 375.00);

/***/
update AUCTION
set Bid_count=AUCTION.Bid_count+1
where Auction_id=704;
/***/
/******/
update AUCTION
set Max_bid=
(
select MAX(Amount)
from BIDDER_PART_AUC
where Auc_id=704
)
where Auction_id=704
AND Max_count=Bid_count;
/******/


insert into
BIDDER_PART_AUC
values(403, 704, 420.00);

/***/
update AUCTION
set Bid_count=AUCTION.Bid_count+1
where Auction_id=704;
/***/
/******/
update AUCTION
set Max_bid=
(
select MAX(Amount)
from BIDDER_PART_AUC
where Auc_id=704
)
where Auction_id=704
AND Max_count=Bid_count;
/******/


insert into
BIDDER_PART_AUC
values(401, 702, 1160.00);

/***/
update AUCTION
set Bid_count=AUCTION.Bid_count+1
where Auction_id=702;
/***/
/******/
update AUCTION
set Max_bid=
(
select MAX(Amount)
from BIDDER_PART_AUC
where Auc_id=702
)
where Auction_id=702
AND Max_count=Bid_count;
/******/


insert into
BIDDER_PART_AUC
values(404, 703, 922.00);

/***/
update AUCTION
set Bid_count=AUCTION.Bid_count+1
where Auction_id=703;
/***/
/******/
update AUCTION
set Max_bid=
(
select MAX(Amount)
from BIDDER_PART_AUC
where Auc_id=703
)
where Auction_id=703
AND Max_count=Bid_count;
/******/


insert into
BIDDER_PART_AUC
values(401, 705, 468.00);

/***/
update AUCTION
set Bid_count=AUCTION.Bid_count+1
where Auction_id=705;
/***/
/******/
update AUCTION
set Max_bid=
(
select MAX(Amount)
from BIDDER_PART_AUC
where Auc_id=705
)
where Auction_id=705
AND Max_count=Bid_count;
/******/


insert into
BIDDER_PART_AUC
values(403, 706, 730.00);

/***/
update AUCTION
set Bid_count=AUCTION.Bid_count+1
where Auction_id=706;
/***/
/******/
update AUCTION
set Max_bid=
(
select MAX(Amount)
from BIDDER_PART_AUC
where Auc_id=706
)
where Auction_id=706
AND Max_count=Bid_count;
/******/


insert into
BIDDER_PART_AUC
values(402, 706, 715.00);

/***/
update AUCTION
set Bid_count=AUCTION.Bid_count+1
where Auction_id=706;
/***/
/******/
update AUCTION
set Max_bid=
(
select MAX(Amount)
from BIDDER_PART_AUC
where Auc_id=706
)
where Auction_id=706
AND Max_count=Bid_count;
/******/


insert into
BIDDER_PART_AUC
values(401, 707, 1440.00);

/***/
update AUCTION
set Bid_count=AUCTION.Bid_count+1
where Auction_id=707;
/***/
/******/
update AUCTION
set Max_bid=
(
select MAX(Amount)
from BIDDER_PART_AUC
where Auc_id=707
)
where Auction_id=707
AND Max_count=Bid_count;
/******/


insert into
BIDDER_PART_AUC
values(402, 705, 499.00);

/***/
update AUCTION
set Bid_count=AUCTION.Bid_count+1
where Auction_id=705;
/***/
/******/
update AUCTION
set Max_bid=
(
select MAX(Amount)
from BIDDER_PART_AUC
where Auc_id=705
)
where Auction_id=705
AND Max_count=Bid_count;
/******/


insert into
BIDDER_PART_AUC
values(403, 707, 1380.00);

/***/
update AUCTION
set Bid_count=AUCTION.Bid_count+1
where Auction_id=707;
/***/
/******/
update AUCTION
set Max_bid=
(
select MAX(Amount)
from BIDDER_PART_AUC
where Auc_id=707
)
where Auction_id=707 
AND Max_count=Bid_count;
/******/
