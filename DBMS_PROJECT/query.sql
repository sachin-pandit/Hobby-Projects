/* QUERIES */

select * from AUCTION;
select * from BANK_ACCOUNT;
select * from BIDDER;
select * from EA_BRANCH;
select * from EMPLOYEE;
select * from ITEM;
select * from SELLER;
select * from SHIPMENT_AGENCY;
select * from BIDDER_PART_AUC;

/* QUERIES */


/* SELECT */

select * from ITEM where Category='Electronic';

select * from AUCTION where E_uniq_id=204;

select * from BANK_ACCOUNT where Balance>=900;

select Name, Email_id from SELLER where Uniq_id=503;

select * from EMPLOYEE where Salary>=22000 AND (E_Branch_id=103 OR E_Branch_id=104);

/* SELECT */



/* ON DELETE CASCADE & ON UPDATE CASCADE */

select * from BANK_ACCOUNT;
select * from SHIPMENT_AGENCY;

delete 
from BANK_ACCOUNT 
where Account_id=21;

select * from BANK_ACCOUNT;
select * from SHIPMENT_AGENCY;
/******/

insert
into BANK_ACCOUNT
values (21, 1263.0, 5.00);

insert 
into SHIPMENT_AGENCY
values(301, 'SPEED', 5.0, 21);

/******/

select * from BANK_ACCOUNT;
select * from SHIPMENT_AGENCY;

update BANK_ACCOUNT
set Account_id=24 where Balance=1263.00;

select * from BANK_ACCOUNT;
select * from SHIPMENT_AGENCY;

update BANK_ACCOUNT
set Account_id=21 where Balance=1263.00;

select * from BANK_ACCOUNT;
select * from SHIPMENT_AGENCY;
/* ON DELETE CASCADE & ON UPDATE CASCADE */


/* ALTER */

alter table ITEM add Lname varchar(20);

select * from ITEM;

alter 
table SHIPMENT_AGENCY
add HeadQuarters varchar(20);

select * from SHIPMENT_AGENCY;

alter 
table ITEM
drop column Lname;

select * from ITEM;

alter 
table SHIPMENT_AGENCY
drop column HeadQuarters;

select * from SHIPMENT_AGENCY;
/* ALTER */



/* DROP */

create table company(
	Comp_id integer not null,
	Name varchar(20) not null,
	Location varchar(20) not null,
	Phone varchar(10) not null,
	PRIMARY KEY(Comp_id)
);

insert 
into company
values(999, 'Infy', 'Mys', 9784574646);

insert 
into company
values(998, 'TPS', 'Mys', 9745774435);

insert 
into company
values(996, 'NetKeys', 'Bglore', 9367427356);

select * from company;

drop table company;

select * from company;
/* DROP */



/* DELETE */	

create table company(
	Comp_id integer not null,
	Name varchar(20) not null,
	Location varchar(20) not null,
	Phone varchar(10) not null,
	PRIMARY KEY(Comp_id)
);

insert 
into company
values(999, 'Infy', 'Mys', 9784574646);

insert 
into company
values(998, 'TPS', 'Mys', 9745774435);

insert 
into company
values(996, 'NetKeys', 'Bglore', 9367427356);

select * from company;

delete 
from company
where Comp_id=999;

select * from company;

delete 
from company
where Location='Bglore';

select * from company;

delete 
from company
where Comp_id=998;

select * from company;

drop table company;
/* DELETE */



/* DESCRIBE */

desc AUCTION;
desc ITEM;
desc BANK_ACCOUNT;
/* DESCRIBE */



/* ORDER BY */

select * from ITEM order by Name;

select * 
from ITEM
order by Category;

select * 
from ITEM
order by Item_id;

select * from BANK_ACCOUNT order by Balance;

select * from AUCTION order by Base_bid;

/* ORDER BY */



/* VIEW */

create VIEW my_view1 AS select Uniq_id, Name, Email_id from SELLER;

create VIEW my_view2 AS select Name, Category from ITEM;

/* VIEW */


/* AGGREGATE */

select COUNT(DISTINCT Category) item_types from ITEM;

select SUM(Amount) AS transactions from BIDDER_PART_AUC;

/* AGGREGATE */


/* GROUP BY */

select E_Branch_id, SUM(Salary) AS salary_expend from EMPLOYEE group by E_Branch_id;

select Bidder_id AS bidder, COUNT(Bidder_id) AS number_of_bids from BIDDER_PART_AUC group by Bidder_id;

/* GROUP BY */


/* HAVING */

select E_Branch_id, SUM(Salary) AS salary_expend from EMPLOYEE 
group by E_Branch_id
having SUM(Salary)>25000;

select Bidder_id AS bidder, COUNT(Bidder_id) AS number_of_bids from BIDDER_PART_AUC 
group by Bidder_id
having COUNT(Bidder_id)<5;

/* HAVING */


/* UPDATE */

update AUCTION
set Max_bid IN 
( 
select MAX(Amount)
from BIDDER_PART_AUC
where Auc_id=701
)
where Auction_id=701 AND Max_count=Bid_count
;

/******/
update AUCTION
set Bid_count=AUCTION.Bid_count+1
where Auction_id=;
/******/

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

/**/
update ITEM
set Price=
(select Max_bid from AUCTION where Auction_id=707)
where Item_id=
(select A_Item_id from AUCTION where Auction_id=707);
/**/

/****/
update ITEM
set Buyer_id
=
(select Bidder_id from BIDDER_PART_AUC where Auc_id=707 AND Amount 
IN
(select Max_bid from AUCTION where Auction_id=707)
)
where Item_id
IN
(select A_Item_id from AUCTION where Auction_id=707);
/****/


